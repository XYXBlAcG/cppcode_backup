#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 8e4 + 5;
int n, m, s, t, deg[N], es[M], st[M], top;
int a[M], b[M], wl[M], wr[M], mp[N * N];
int cur[N], hd[N], to[M], nxt[M], c[M], d[N], q[N], tot;
void addw(int u, int v, int w) {
    to[++tot] = v, nxt[tot] = hd[u], c[tot] = w, hd[u] = tot;
}
void add(int u, int v, int w) {
    addw(u, v, w), addw(v, u, 0);
}
bool bfs() {
    memset(d, 0, sizeof(d));
    memcpy(cur, hd, sizeof(hd));
    int l = 1, r = 0;
    q[++r] = s, d[s] = 1;

    for (int x; l <= r;) {
        x = q[l++];

        for (int i = hd[x], v; i; i = nxt[i])
            if (c[i] && !d[v = to[i]]) {
                d[v] = d[x] + 1, q[++r] = v;

                if (v == t)
                    return 1;
            }
    }

    return 0;
}
int dinic(int x, int flow) {
    if (x == t)
        return flow;

    int rest = flow, k;

    for (int &i = cur[x], v; i && rest; i = nxt[i])
        if (c[i] && d[v = to[i]] == d[x] + 1) {
            k = dinic(v, min(rest, c[i]));

            if (!k)
                d[v] = 0;

            c[i] -= k, c[i ^ 1] += k, rest -= k;
        }

    return flow - rest;
}
bool check(int mid) {
    memset(hd, 0, sizeof(hd)), tot = 1;
    memset(deg, 0, sizeof(deg));
    puts("-----------");
    for (int i = 1; i <= m; ++i) {
        --deg[a[i]], ++deg[b[i]];
        if (wr[i] <= mid)
            add(b[i], a[i], 1), es[i] = tot - 1, printf("%d -> %d\n", b[i], a[i]);
        else
            es[i] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (deg[i] > 0)
            ans += deg[i] / 2, add(s, i, deg[i] / 2);
        else if (deg[i] < 0)
            add(i, t, -deg[i] / 2);
    while (bfs())
        ans -= dinic(s, 1e9);

    return !ans;
}
void dfs(int x) {
    for (int &i = hd[x]; i; i = nxt[i])
        if (c[i])
            c[i] = 0, dfs(to[i]);

    st[++top] = x;
}
int main() {
    scanf("%d%d", &n, &m);
    s = n + 1, t = s + 1;
    int l = 0, r = 0;

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", a + i, b + i, wl + i, wr + i);
        ++deg[a[i]], ++deg[b[i]];
        mp[a[i]*N + b[i]] = mp[b[i] * N + a[i]] = i;

        if (wl[i] > wr[i])
            swap(a[i], b[i]), swap(wl[i], wr[i]);

        l = max(l, wl[i]), r = max(r, wr[i]);
    }

    for (int i = 1; i <= n; ++i)
        if (deg[i] & 1)
            return puts("NIE"), 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    printf("%d\n", l), check(l);
    memset(hd, 0, sizeof(hd));

    for (int i = 1; i <= m; ++i)
        if (es[i] == -1 || c[es[i]])
            printf("id = %d ", es[i]), add(a[i], b[i], 1), printf("%d -> %d !\n", a[i], b[i]);
        else
            add(b[i], a[i], 1), printf("%d -> %d ?\n", b[i], a[i]);;

    dfs(1);

    for (int i = top - 1; i; --i)
        printf("%d ", mp[st[i]*N + st[i + 1]]);

    return 0;
}