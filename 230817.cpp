#include <cstdio>
#define int long long
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
#define len(u) t[u].r - t[u].l + 1
const int N = 2e5 + 5, mod = 1000000007;
int a[N], n, m, L, R;
struct Tree{
    int sum, time, l, r, add;
}t[N << 2];
void mmm(int &in){
    (in += mod) %= mod;
}
void pushdown(int u){
    if(u <= 2 * n){
        printf("%lld %lld %lld\n", t[u].time, t[u].add, t[u].sum);

        t[ls(u)].add = ((t[ls(u)].add * t[u].time + mod) % mod + t[u].add + mod) % mod;
        (t[ls(u)].time *= t[u].time) %= mod;
        t[ls(u)].sum = ((t[ls(u)].sum * t[u].time + mod) % mod + (t[u].add * len(ls(u))) % mod) % mod;
        t[rs(u)].add = ((t[rs(u)].add * t[u].time + mod) % mod + t[u].add + mod) % mod;
        (t[rs(u)].time *= t[u].time) %= mod;
        t[rs(u)].sum = ((t[rs(u)].sum * t[u].time + mod) % mod + (t[u].add * len(rs(u))) % mod) % mod;

        printf("%lld %lld %lld\n", t[ls(u)].time, t[ls(u)].add, t[ls(u)].sum);
        printf("%lld %lld %lld\n", t[rs(u)].time, t[rs(u)].add, t[rs(u)].sum);
    }
    t[u].add = 0, t[u].time = 1;
}
void pushup(int u){
    t[u].sum = (t[ls(u)].sum + t[rs(u)].sum + mod) % mod;
}
// void build(int u, int l, int r){
//     t[u].l = l, t[u].r = r, t[u].time = 1;
//     // pushdown(u);
//     if (l == r){
//         t[u].sum = a[l];
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(ls(u), l, mid);
//     build(rs(u), mid + 1, r);
//     pushup(u);
// }
// void modify(int u, int l, int r, int op, int c){
//     if(l > L || r < R) return;
//     pushdown(u);
//     if(l >= L && R >= r) {
//         if(op == 2) t[u].time *= c, t[u].sum *= c, t[u].add *= c;
//         if(op == 1) t[u].add += c, t[u].sum += c * len(u);
//         mmm(t[u].time), mmm(t[u].add), mmm(t[u].sum);
//         return;
//     }
//     int mid = (l + r) >> 1;
//     modify(ls(u), l, mid, op, c);
//     modify(rs(u), mid + 1, r, op, c);
//     pushup(u);
// }
// int query(int u, int l, int r){
//     if(l > L || r < R) return 0;
//     pushdown(u);
//     if(l >= L && R >= r){
//         return t[u].sum;
//     }
//     int mid = (l + r) >> 1;
//     // pushup(u);
//     return (query(ls(u), l, mid) + query(rs(u), mid + 1, r)) % mod;
// }
inline void build(int u, int l, int r) {
        t[u].time = 1, t[u].l = l, t[u].r = r;
        if (l == r) {
            t[u].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid);
        build(rs(u), mid + 1, r);
        pushup(u);
    }

    inline void modify(int u, int l, int r, int val, int op) {
        if (l > R || r < L)
            return;
        pushdown(u);
        if (L <= l && r <= R) {
            if(op == 1) t[u].add += val, t[u].sum += (val * len(u));
            if(op == 2) t[u].sum *= val, t[u].add *= val, t[u].time *= val;
            t[u].sum %= mod, t[u].add %= mod, t[u].time %= mod;
            return;
        }
        
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, val, op);
        modify(rs(u), mid + 1, r, val, op);
        pushup(u);
    }

    inline int query(int u, int l, int r) {
        if (R < l || r < L)
            return 0;
        pushdown(u);
        if (L <= l && r <= R)
            return t[u].sum;
        int mid = (l + r) >> 1;
        // pushdown(u);
        return
            (query(ls(u), l, mid) +
            query(rs(u), mid + 1, r)) % mod;
    }
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    build(1, 1, n);
    for (int i = 1; i <= m; i++){
        int op, c;
        scanf("%lld", &op);
        if(!op){
            scanf("%lld%lld", &L, &R);
            printf("%lld\n", query(1, 1, n));
        }else{
            scanf("%lld%lld%lld", &L, &R, &c);
            modify(1, 1, n, c, op);
        }
    }
}