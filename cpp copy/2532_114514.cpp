#include <cstdio>
#include <algorithm>

#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)

using std::max;

const int maxn = 1e6 + 1;
const int maxs = 4e6 + 1;
const int inf = 0x3f3f3f3f;

int n, m;
int l, r;
int a[maxn];
int mx[maxs];

void build(int u, int l, int r) {
    if (l == r) {
        mx[u] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    mx[u] = max(mx[ls(u)], mx[rs(u)]);
}

int query(int u, int l, int r, int st, int ed) {
    if (r < st || ed < l)
        return -inf;
    if (st <= l && r <= ed)
        return mx[u];
    int mid = (l + r) >> 1;
    return max(
        query(ls(u), l, mid, st, ed), 
        query(rs(u), mid + 1, r, st, ed)
    );
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        printf("%d ", query(1, 1, n, l, r));
    }
    return 0;
}