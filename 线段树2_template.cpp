#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define add(u) node[u].add
#define val(u) node[u].val
#define tim(u) node[u].tim
#define sum(u) node[u].sum
const int N = 4e5 + 5;
int n, q, m, a[N];
struct Node{
    int val, add, tim, sum;
}node[N << 2];
struct Tree{
    void pushdown(int u, int l, int r){
        // if(tim(u) != 1) {
            (sum(ls(u)) *= tim(u)) %= m;
            (sum(rs(u)) *= tim(u)) %= m;
            (tim(ls(u)) *= tim(u)) %= m;
            (tim(rs(u)) *= tim(u)) %= m;
            
        // }
        // printf("u = %lld, add %lld = %lld, r = %lld, l = %lld\n", u, u, add(u), r, l);
        int mid = (l + r) >> 1;
        (sum(ls(u)) += add(u) * (mid - l + 1)) %= m;
        (sum(rs(u)) += add(u) * (r - mid)) %= m;
        ((add(ls(u)) *= tim(u)) += add(u)) %= m;
        ((add(rs(u)) *= tim(u)) += add(u)) %= m;
        tim(u) = 1;
        add(u) = 0;
    }
    void pushup(int u){
        sum(u) = sum(ls(u)) + sum(rs(u));
    }
    void debug(int u, int l, int r){
        if(l == r){
            printf("%lld at %lld sum %lld add %lld tim %lld\n", u, l, sum(u), add(u), tim(u));
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        printf("%lld [%lld, %lld] sum %lld add %lld tim %lld\n", u, l, r, sum(u), add(u), tim(u));
        debug(ls(u), l, mid), debug(rs(u), mid + 1, r);
        pushup(u);
    }
    void build(int u, int l, int r){
        if(l == r){
            node[u] = {a[l], 0, 1, a[l]};
            return;
        }
        tim(u) = 1;
        int mid = (l + r) >> 1;
        build(ls(u), l, mid);
        build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, int val, int op){
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr) {
            if(op == 2) (add(u) += val) %= m, (sum(u) += val * (r - l + 1)) %= m;
            else if(val) (tim(u) *= val) %= m, (add(u) *= val) %= m, (sum(u) *= val) %= m;
            // pushdown(u, l, r);
            // printf("add %lld = %lld\n", u, add(u));
            // pushdown(u, l, r);
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, val, op);
        modify(rs(u), mid + 1, r, ql, qr, val, op);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) {
            // pushdown(u, l, r);
            return sum(u);
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        int ans = (query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr) + m) % m;
        pushup(u);
        return ans;
    }
    void de(){
        puts("start -----");
        debug(1, 1, n);
        puts("end -----");
    }
}tree;
signed main(){
    scanf("%lld%lld%lld", &n, &q, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    tree.build(1, 1, n);
    for (int i = 1; i <= q; i++){
        int op = 0, x = 0, y = 0, k = 0;
        scanf("%lld%lld%lld", &op, &x, &y);
        if(op != 3){
            scanf("%lld", &k);
            tree.modify(1, 1, n, x, y, k, op);
        }else{
            printf("%lld\n", (tree.query(1, 1, n, x, y) + m) % m);
        }
        // tree.de();
    }
    return 0;
}