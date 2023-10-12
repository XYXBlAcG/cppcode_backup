#include <bits/stdc++.h>
typedef long long lld;
const int N = 305;
const lld inf = 1e12;
int n, m, p[N], P, rt, o[N], son[N], bro[N];
int *id[N], pid, s[N], c[N];
void dfs(int u) {
    if (!u)
        return;
    dfs(son[u]), dfs(bro[u]);
    c[u] = s[son[u]] + 1, s[u] = c[u] + s[bro[u]];
}
lld dpf[N][N][N], dpg[N][N][N];
bool visf[N][N][N], visg[N][N][N];
lld g(int, int, int);
lld f(int u, int i, int x) {
    if (!x)
        return inf;
    lld& F = dpf[u][i][x];
    if (visf[u][i][x])
        return F;
    visf[u][i][x] = true;
    // F = x + 1 >= p[u] ? g(son[u], i, x) + o[x + 1] - o[p[u]] : inf;
    return F = std::min(f(u, i, x - 1), x >= p[u] ? g(son[u], i - 1, x) + o[x] - o[p[u]] : g(son[u], i, x));
}
lld g(int u, int i, int x) {
    if (i < 0)
        return inf;
    lld& G = dpg[u][i][x];
    if (visg[u][i][x])
        return G;
    visg[u][i][x] = true;
    if (!u)
        return G = !i ? 0 : inf;
    G = inf;
    for (int j = std::max(0, i - s[bro[u]]); j <= std::min(i, c[u]); j++)
        G = std::min(G, g(bro[u], i - j, x) + f(u, j, x));
    return G;
}

int main() {
    // freopen("radar.in", "r", stdin), freopen("radar.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int u = 1, fa; u <= n; u++) {
        scanf("%d%d", &fa, p + u), id[++pid] = &p[u], bro[u] = son[fa], son[fa] = u;
        if (fa == -1)
            rt = u;
    }
    P = 1;
    std::sort(id + 1, id + pid + 1, [](int* x, int* y) { return *x < *y; });
    for (int i = 1; i <= pid; i++) o[P] = *id[i], *id[i] = i < pid && *id[i] != *id[i + 1] ? P++ : P;
    for (int i = 1; i <= n; i++) printf("%d\n", o[i]);
    printf("P = %d\n", P);
    dfs(rt);
    for (int i = 1; i <= n; i++){
        printf("%d %d %d %d\n", son[i], bro[i], s[i], c[i]);
    }
    printf("%lld\n", f(rt, m, P));
    return 0;
}