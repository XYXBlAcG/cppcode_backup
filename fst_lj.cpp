#include <cstdio>
#include <algorithm>
struct IO {
    IO() { freopen("chicken.in", "r", stdin), freopen("chicken.out", "w", stdout); }
    ~IO() { fclose(stdin), fclose(stdout); }
} io;
#define int long long
const int inf = 1e18;
const int maxn = 2.5e4 + 3;
const int maxs = 1e5 + 3;
struct Line {
    bool op;
    int id, len;
};
struct Node {
    int lv, rv, cnt0, cnt1;
    friend Node operator+(const Node &x, const Node &y) {
        return { x.lv, y.rv, x.cnt0 + y.cnt0 + (!x.rv || !y.lv), x.cnt1 + y.cnt1 - (x.rv && y.lv) };
    }
};
struct Segment_Tree {
    Node seg[maxs];
    int ls(int u) { return u << 1; }
    int rs(int u) { return u << 1 | 1; }
    void pushup(int u) { seg[u] = seg[ls(u)] + seg[rs(u)]; }
    void build(int u, int l, int r) {
        seg[u] = { 0, 0, r - l, 0 };
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void mdf(int u, int l, int r, int p) {
        if (p < l || r < p)
            return;
        if (p == l && p == r)
            return void(seg[u] = { 1, 1, 0, 1 });
        int mid = (l + r) >> 1;
        mdf(ls(u), l, mid, p), mdf(rs(u), mid + 1, r, p);
        pushup(u);
    }
    int qry() { return seg[1].cnt0 - seg[1].cnt1 + !!seg[1].cnt1; }
} sa, sb;
int a, b, n, m, aa[maxn], bb[maxn], cnt, ans;
Line l[maxs];
signed main() {
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m), cnt = n + m + 2;
    for (int i = 1; i <= n; i++) scanf("%lld", &aa[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &bb[i]);
    std::sort(aa + 1, aa + n + 1), std::sort(bb + 1, bb + m + 1);
    aa[n + 1] = a, bb[m + 1] = b;
    for (int i = 1; i <= n + 1; i++) l[i] = { false, i, aa[i] - aa[i - 1] };
    for (int i = 1; i <= m + 1; i++) l[i + n + 1] = { true, i, bb[i] - bb[i - 1] };
    std::sort(l + 1, l + cnt + 1, [](Line x, Line y) { return x.len < y.len; });
    sa.build(1, 1, n + 1), sb.build(1, 1, m + 1);
    bool flg = false;
    for (int i = 1; i <= cnt; i++) {
        ans += l[i].len * (l[i].op ? sa.qry() : sb.qry());
        if (flg) {
            l[i].op ? sb.mdf(1, 1, m + 1, l[i].id) : sa.mdf(1, 1, n + 1, l[i].id);
        } else if (l[i].op != l[1].op) {
            flg = true;
            for (int j = 1; j <= i; j++)
                l[j].op ? sb.mdf(1, 1, m + 1, l[j].id) : sa.mdf(1, 1, n + 1, l[j].id);
        }
    }
    printf("%lld\n", ans);
    return 0;
}