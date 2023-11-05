#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define sum(u) node[u].sum
#define to(u) node[u].to
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 4e5 + 5;
int n, m, v[N], dep[N], size[N], fa[N], hv[N], dfn[N], pdfn, fst[N], hsz[N], id[N];
std::vector<int> st[N];
struct Node {
    int sum, to;
} node[N << 2];
struct Tree {
    void pushup(int u) {
        sum(u) = sum(ls(u)) + sum(rs(u));
    }
    void pushdown(int u, int l, int r) {
        int mid = (l + r) >> 1;
        sum(ls(u)) += to(u) * (mid - l + 1), sum(rs(u)) += to(u) * (r - mid);
        to(ls(u)) += to(u), to(rs(u)) += to(u);
        to(u) = 0;
    }
    void build(int u, int l, int r) {
        if (l == r) {
            node[u] = { v[id[l]], 0 };
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, int mdf) {
        if (l > qr || ql > r)
            return;
        if (ql <= l && r <= qr) {
            to(u) += mdf;
            sum(u) += mdf * (r - l + 1);
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, mdf);
        modify(rs(u), mid + 1, r, ql, qr, mdf);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr) {
        if (l > qr || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return sum(u);
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        int ans = query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
        pushup(u);
        return ans;
    }
} tree;
struct Lian {
    void dfs1(int u, int fath) {
        fa[u] = fath;
        dep[u] = dep[fath] + 1;
        for (auto v : st[u]) {
            if (fath == v)
                continue;
            dfs1(v, u);
            size[u] += size[v];
            if (size[hv[u]] < size[v])
                hv[u] = v;
        }
        size[u]++;
    }
    void dfs2(int u) {
        dfn[u] = ++pdfn;
        if (hv[u])
            fst[hv[u]] = fst[u], dfs2(hv[u]);
        hsz[u] = hsz[hv[u]] + 1;
        for (auto v : st[u]) {
            if (fa[u] == v || hv[u] == v)
                continue;
            fst[v] = v, dfs2(v);
        }
    }
    void init() {
        dfs1(1, 0), fst[1] = 1, dfs2(1);
    }
    int query_lian(int x, int y) {
        int res = 0;
        while (fst[x] != fst[y]) {
            if (dep[fst[x]] < dep[fst[y]])
                std::swap(x, y);
            res += tree.query(1, 1, n, dfn[fst[x]], dfn[x]);
            x = fa[fst[x]];
        }
        if (dep[x] >= dep[y])
            std::swap(x, y);
        res += tree.query(1, 1, n, dfn[x], dfn[y]);
        return res;
    }
    void modify_son(int v, int val) {
        tree.modify(1, 1, n, dfn[v], dfn[v] + size[v] - 1, val);
    }
} lian;
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", v + i);
    fa[1] = 1;
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%lld%lld", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    lian.init();
    for (int i = 1; i <= n; i++) id[dfn[i]] = i;
    tree.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, u, w;
        scanf("%lld", &op);
        if (op == 1) {
            scanf("%lld%lld", &u, &w);
            tree.modify(1, 1, n, dfn[u], dfn[u], w);
        } else if (op == 2) {
            scanf("%lld%lld", &u, &w);
            lian.modify_son(u, w);
        } else {
            scanf("%lld", &u);
            printf("%lld\n", lian.query_lian(1, u));
        }
    }
    return 0;
}