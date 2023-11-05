#include <bits/stdc++.h>
using namespace std;
const int N = 50009, M = 350009;
int he[N], cur[N], to[M], ne[M], len[M], d[N], q[N], h[N], t = 1, w, S, T;
void add(int x, int y, int z) {
    ne[++t] = he[x], to[t] = y, len[t] = z, he[x] = t;
    ne[++t] = he[y], to[t] = x, he[y] = t;
}
bool bfs() {
    int h = 0, t = 1, i, j, k;
    memset(d, 0, N * 4), d[q[1] = S] = 1;

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
void dinic() {
    while (bfs())
        memcpy(cur, he, N * 4), w += dfs(S, 1e9);
}
int main() {
    int n, m, s, t, i, j, k, l;
    scanf("%d%d%d%d", &n, &m, &s, &t), S = n + 1, T = n + 2;

    while (m--)
        scanf("%d%d%d%d", &i, &j, &k, &l), add(i, j, l - k), h[i] -= k, h[j] += k;

    for (i = 1, add(t, s, 1e9); i <= n; ++i)
        if (h[i] > 0)
            add(S, i, h[i]), w -= h[i];
        else
            add(i, T, -h[i]);
    if (dinic(), w)
        puts("please go home to sleep");
    else
        S = t, T = s, w = -1e9, dinic(), printf("%d", -w);

    return 0;
}