#include <cstdio>

#define int long long

const int maxn = 1e5 + 3;
const int maxs = 4e5 + 3;

struct Segment_Tree {
    int sum[maxs];

    inline int ls(int u) { return u << 1; }
    inline int rs(int u) { return u << 1 | 1; }

    inline void pushup(int u) {
        sum[u] = sum[ls(u)] + sum[rs(u)];
    }

    inline void build(int u, int l, int r, int *a) {
        if (l == r) {
            sum[u] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, a);
        build(rs(u), mid + 1, r, a);
        pushup(u);
    }

    inline void modify(int u, int l, int r, int id, int val) {
        if (id < l || r < id)
            return;
        if (l == id && r == id) {
            sum[u] += val;
            return;
        }
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, id, val);
        modify(rs(u), mid + 1, r, id, val);
        pushup(u);
    }

    inline int query(int u, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return sum[u];
        int mid = (l + r) >> 1;
        return
            query(ls(u), l, mid, ql, qr) +
            query(rs(u), mid + 1, r, ql, qr);
    }
} tree;

int n, m;
int a[maxn];

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    tree.build(1, 1, n, a);
    while (m--) {
        int op, x, y;
        scanf("%lld%lld%lld", &op, &x, &y);
        if (op) tree.modify(1, 1, n, x, y);
        else printf("%lld\n", tree.query(1, 1, n, x, y));
    }
    return 0;
}