#include <cstdio>
#include <algorithm>
#define MAX 2147483648
#define int long long
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
using std::max;
const int N = 5e4 + 5;
int n, az[N], L, R, q, rev[N];
struct T{ int sum, ll, rr, ml, mr, mm; };
T operator+(T a, T b){
    bool f1 = (a.rr <= b.ll), f2 = (a.sum == a.ml), f3 = (b.sum == b.mr);
    return {a.sum + b.sum, a.ll, b.rr, (f1 && f2) ? (a.sum + b.ml) : a.ml, \
    (f1 && f3) ? (b.sum + a.mr) : b.mr, max(max(a.mm, b.mm), (f1 ? (a.mr + b.ml) : 0))};
}
struct Tree{
    T tr[N << 2];
    void build(int u, int l, int r, int *who){
        if(l == r){
            tr[u] = {1, who[l], who[l], 1, 1, 1};
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, who);
        build(rs(u), mid + 1, r, who);
        tr[u] = tr[ls(u)] + tr[rs(u)];
    }
    T query(int u, int l, int r){
        if(L <= l && r <= R) return tr[u];
        int mid = (l + r) >> 1;
        if(L >= mid + 1) return query(rs(u), mid + 1, r);
        if(R <= mid) return query(ls(u), l, mid);
        return query(ls(u), l, mid) + query(rs(u), mid + 1, r);
    }

}up, down;
signed main(){
    scanf("%lld", &n); 
    for (int i = 1; i <= n; i++) scanf("%lld", az + i), rev[i] = MAX - az[i];
    up.build(1, 1, n, az); down.build(1, 1, n, rev);
    scanf("%lld", &q);
    for (int i = 1; i <= q; i++){
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", max(up.query(1, 1, n).mm, down.query(1, 1, n).mm));
    }
    return 0;
}