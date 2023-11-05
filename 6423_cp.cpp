#include <bits/stdc++.h>
using namespace std;
const int N = 209, M = 20809;
int he[N], cur[N], to[M], ne[M], len[M], d[N], q[N], ans[M], h[N], t = 1, w, S, T;
void add(int x, int y, int z) {
    ne[++t] = he[x], to[t] = y, len[t] = z, he[x] = t;
    ne[++t] = he[y], to[t] = x, he[y] = t;
}
bool bfs() {
    int h = 0, t = 1, i, j, k;
    memset(d, 0, T * 4 + 4), d[q[1] = S] = 1;

    while (h < t)
        for (j = he[i = q[++h]]; j; j = ne[j])
            if (len[j] && !d[k = to[j]])
                d[k] = d[i] + 1, q[++t] = k;

    return d[T];
}
int dfs(int x, int y) {
    if (x == T)
        return y;

    int &i = cur[x], j, u = 0, w;

    for (; i; i = ne[i])
        if (len[i] && d[j = to[i]] == d[x] + 1) {
            w = dfs(j, min(y - u, len[i])), len[i] -= w, len[i ^ 1] += w, u += w;

            if (u == y)
                break;
        }

    return u;
}
int main() {
    int n, m, i, j, k, l;
    scanf("%d%d", &n, &m), S = n + 1, T = n + 2;

    for (i = 1; i <= m; ++i)
        scanf("%d%d%d", &j, &k, &l), add(j, k, 1 - l), h[j] -= l, h[k] += l, ans[i] = l;

    for (i = 1; i <= n; ++i)
        if (h[i] > 0)
            add(S, i, h[i]), w -= h[i];
        else
            add(i, T, -h[i]);

    while (bfs())
        memcpy(cur, he, T * 4 + 4), w += dfs(S, 1e9);

    if (w)
        puts("NO");
    else
        for (i = 1, puts("YES"); i <= m; ++i)
            printf("%d\n", ans[i] + len[i * 2 + 1]);

    return 0;
}