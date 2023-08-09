#include <cstdio>
#include <algorithm>
#include <iostream>
#define int long long
#define de(x) std::cout << #x << " = " << x << std::endl
const int N = 1e5 + 5;
int n, m, a[N], op, l, r;

struct Segment_Tree {
    int sum[4 * N], tag[4 * N], rev[4 * N], mi[4 * N], lm[4 * N], rm[4 * N], rl[4 * N], ll[4 * N];
    
    inline int ls(int u) { return u << 1; }
    inline int rs(int u) { return u << 1 | 1; }
    inline int len(int u) { return rl[u] - ll[u] + 1; }
    
    inline void pushdown(int u, int v){
        sum[ls(u)] = len(ls(u)) * tag[u], sum[rs(u)] = len(rs(u)) * tag[u];
        tag[ls(u)] = tag[rs(u)] = v, rev[ls(u)] = rev[rs(u)] = 0;
    }

    inline void pushup(int u) {
        sum[u] = (sum[ls(u)] + sum[rs(u)]);
    }

    inline void build(int u, int l, int r, int *a) {
        tag[u] = -1, ll[u] = l, rl[u] = r;
        if (l == r) {
            sum[u] = a[l];
            mi[a[l]] = lm[a[l]] = rm[a[l]] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, a);
        build(rs(u), mid + 1, r, a);
        pushup(u);
    }

    inline void modify(int u, int l, int r, int L, int R, int val, int op){
        if(l > R || r < L) return;
        // pushdown(u);
        if(L <= l && r <= R){
            if(op == 1)
        }
    }
    // inline void modify(int u, int l, int r, int L, int R, int val, int op) {
    //     if (l > R || r < L)
    //         return;
    //     // pushdown(u);
    //     if (L <= l && r <= R) {
            
    //         return;
    //     }
        
    //     int mid = (l + r) >> 1;
    //     modify(ls(u), l, mid, L, R, val, op);
    //     modify(rs(u), mid + 1, r, L, R, val, op);
    //     pushup(u);
    // }

    // inline int query(int u, int l, int r, int ql, int qr) {
    //     if (qr < l || r < ql)
    //         return 0;
    //     // pushdown(u);
    //     if (ql <= l && r <= qr)
    //         return sum[u];
    //     int mid = (l + r) >> 1;
    //     // pushdown(u);
    //     return
    //         (query(ls(u), l, mid, ql, qr) +
    //         query(rs(u), mid + 1, r, ql, qr)) ;
    // }
} tree;

signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    tree.build(1, 1, n, a);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l, &r);
        if(op == 0){
            tree.modify(1, 1, n, l, r, );
        }else if(op == 1){
            
        }else if(op == 2){

        }else if(op == 3){

        }else if(op == 4){

        }
    }
    return 0;
}