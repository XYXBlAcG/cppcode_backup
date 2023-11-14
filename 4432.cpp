#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
// #define de(x) std::cout << #x << " = " << x << std::endl;
const int N = 1e5 + 5;
int n, m, a[N], p = 1000000007;

struct Segment_Tree {
    int sum[4 * N], mul[4 * N], add[4 * N], ll[4 * N], rl[4 * N];
    

    inline int ls(int u) { return u << 1; }
    inline int rs(int u) { return u << 1 | 1; }
    inline int len(int u) { return rl[u] - ll[u] + 1; }

    inline void pushdown(int u){
        // if(u <= 2 * n){
            add[ls(u)] = (add[ls(u)] * mul[u] + add[u]) % p;
            (mul[ls(u)] *= mul[u]) %= p;
            sum[ls(u)] = (sum[ls(u)] * mul[u] + (add[u] * len(ls(u))) % p) % p;
            
            add[rs(u)] = (add[rs(u)] * mul[u] + add[u]) % p;
            (mul[rs(u)] *= mul[u]) %= p;
            sum[rs(u)] = (sum[rs(u)] * mul[u] + (add[u] * len(rs(u))) % p) % p;
        // }
        mul[u] = 1, add[u] = 0;
    }

    inline void pushup(int u) {
        sum[u] = (sum[ls(u)] + sum[rs(u)]) % p;
    }

    inline void build(int u, int l, int r, int *a) {
        mul[u] = 1, ll[u] = l, rl[u] = r;
        if (l == r) {
            sum[u] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, a);
        build(rs(u), mid + 1, r, a);
        pushup(u);
    }

    inline void modify(int u, int l, int r, int L, int R, int val, int op) {
        if (l > R || r < L)
            return;
        pushdown(u);
        if (L <= l && r <= R) {
            if(op == 1) add[u] += val, sum[u] += (val * len(u));
            if(op == 2) sum[u] *= val, add[u] *= val, mul[u] *= val;
            sum[u] %= p, add[u] %= p, mul[u] %= p;
            return;
        }
        
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, L, R, val, op);
        modify(rs(u), mid + 1, r, L, R, val, op);
        pushup(u);
    }

    inline int query(int u, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;
        pushdown(u);
        if (ql <= l && r <= qr)
            return sum[u];
        int mid = (l + r) >> 1;
        return
            (query(ls(u), l, mid, ql, qr) +
            query(rs(u), mid + 1, r, ql, qr)) % p;
    }
} tree;

signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }
    tree.build(1, 1, n, a);
    for (int i = 1; i <= m; i++){
        int op, x, y, c;
        scanf("%lld%lld%lld", &op, &x, &y);
        if (op == 0){
            printf("%lld\n", tree.query(1, 1, n, x, y));
        }else{
            scanf("%lld", &c);
            tree.modify(1, 1, n, x, y, c, op);
        }
    }
    return 0;
}