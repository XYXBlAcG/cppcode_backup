#include <cstdio>
#include <algorithm>
#include <iostream>
int n, q, head[100011], pedge, dfn[100011], pdfn, siz[100011], minn[400011];
int root = 1, a[100011], st[25][100011], dep[100011], id[100011];
struct Edge {
    int ver, nxt;
} edge[100011 * 2];
void add_edge(int u, int v) {
    edge[++pedge] = { v, head[u] };
    head[u] = pedge;
}
void dfs(int x, int fa) {
    dfn[x] = ++pdfn;
    siz[x] = 1;
    dep[x] = dep[fa] + 1;
    st[0][x] = fa;
    for (int i = 1; i <= 20; i++) st[i][x] = st[i - 1][st[i - 1][x]];
    for (int i = head[x]; i; i = edge[i].nxt) {
        int v = edge[i].ver;
        if (v == fa)
            continue;
        dfs(v, x);
        siz[x] += siz[v];
    }
}
int lca(int x, int y) {
    if(x == y) return x;
    if (dep[x] < dep[y])
        std::swap(x, y);
    for (int i = 20; i >= 0; i--)
        if(dep[st[i][x]] >= dep[y])
            x = st[i][x];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (st[i][x] != st[i][y])
            x = st[i][x], y = st[i][y];
    return st[0][x];
}
void pushup(int x) { minn[x] = std::min(minn[x << 1], minn[x << 1 | 1]); }
void modify(int x, int l, int r, int pos, int v) {
    if (l > pos || r < pos)
        return;
    if (l == r) {
        minn[x] = v;
        return;
    }
    int mid = (l + r) >> 1;
    modify(x << 1, l, mid, pos, v), modify(x << 1 | 1, mid + 1, r, pos, v);
    pushup(x);
}
int query(int x, int l, int r, int L, int R) {
    if (R < l || r < L)
        return 0x3f3f3f3f;
    if (L <= l && r <= R)
        return minn[x];
    int mid = (l + r) >> 1;
    return std::min(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
}
void build(int x, int l, int r) {
    if (l == r) {
        minn[x] = a[id[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
    pushup(x);
}
int main() {
    scanf("%d%d", &n, &q);
    int f;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &f, a + i);
        add_edge(f, i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) id[dfn[i]] = i;
    build(1, 1, n);
    char c;
    int x, y;
    for (int i = 1; i <= q; i++) {
        std::cin >> c;
        if (c == 'V') {
            scanf("%d%d", &x, &y);
            modify(1, 1, n, dfn[x], y);
        }
        if (c == 'E') {
            scanf("%d", &x);
            root = x;
        }
        if (c == 'Q') {
            scanf("%d", &x);
            if(x == root) printf("%d\n", query(1, 1, n, 1, n));
            else if (lca(x, root) == x)
                printf("%d\n", std::min(query(1, 1, n, 1, dfn[x] - 1), query(1, 1, n, dfn[x] + siz[x], pdfn)));
            else
                printf("%d\n", query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1));
        }
    }
    return 0;
}