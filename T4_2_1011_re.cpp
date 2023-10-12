#include <cstdio>
#include <algorithm>
using std::min;

const int MAXN = 1e6 + 5;
int N, K;
int A[MAXN];
namespace Segment_Tree {
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
int tr[MAXN << 2], tag[MAXN << 2];
void push_up(int p) { tr[p] = min(tr[ls(p)], tr[rs(p)]); }
void push_down(int p) {
    if (!tag[p])
        return;
    tag[ls(p)] += tag[p];
    tr[ls(p)] -= tag[p];
    tag[rs(p)] += tag[p];
    tr[rs(p)] -= tag[p];
    tag[p] = 0;
}
void build(int p, int l, int r) {
    if (l == r) {
        tr[p] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}
void modify(int p, int l, int r, int ql, int qr, int num) {
    if (ql <= l && r <= qr) {
        tr[p] -= num;
        tag[p] += num;
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(ls(p), l, mid, ql, qr, num);
    if (qr > mid)
        modify(rs(p), mid + 1, r, ql, qr, num);
    push_up(p);
}
int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tr[p];
    }
    push_down(p);
    int res = 1e9, mid = (l + r) >> 1;
    if (ql <= mid)
        res = min(res, query(ls(p), l, mid, ql, qr));
    if (qr > mid)
        res = min(res, query(rs(p), mid + 1, r, ql, qr));
    return res;
}
}  // namespace Segment_Tree
using namespace Segment_Tree;

int main() {
    freopen("zero.in", "r", stdin);
    freopen("zero.out", "w", stdout);
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    build(1, 1, N);
    int l = 1, r = K;
    long long ans = 0;
    for (; r <= N; l++, r++) {
        int num = query(1, 1, N, l, r);
        if (num)
            modify(1, 1, N, l, r, num), ans += num;
    }
    for (int i = 1; i <= N; i++) {
        ans += query(1, 1, N, i, i);
    }
    printf("%lld\n", ans);
    return 0;
}