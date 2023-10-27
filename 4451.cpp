#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define f(u, v) node[u].f[v]
#define g(u, v) node[u].g[v]
#define mul(u) node[u].mulw
#define mdf(u) node[u].mdfv
#define to(u) node[u].to
const int N = 6e5 + 12, M = 25;
int n, m, q, ww[N], vv[N];
struct Mdf{
    int v, w;
};
struct Node{
    int mulw, mdfv, f[M], g[M];
    Mdf to;
    inline void init(){
        to = {0, 0};
        mdfv = 0;
        mulw = 1;
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
    }
    inline void print(){
        puts("start ---------------");
        printf("mul = %lld, mdf = %lld, to = {%lld, %lld}\n", mulw, mdfv, to.v, to.w);
        for (int i = 0; i <= m; i++){
            printf("f[%lld] = %lld, g[%lld] = %lld\n", i, f[i], i, g[i]);
        }
        puts("end ---------------");
    }
}node[N << 2], ept;
void mx(int& a, int b){a = std::max(a, b);}
Node operator+(Node a, Node b){
    Node u; u.init();
    for (int i = 0; i <= m; i++)
        for (int k = 0; k <= i; k++){
            mx(u.f[i], a.f[k] + b.f[i - k]); 
            mx(u.g[i], a.g[k] + b.g[i - k]);
        }
    return u;
}
struct Tree{
    void pushup(int u){
        node[u] = node[ls(u)] + node[rs(u)];
    }
    void upd(int u){
        // printf("mul -> %lld\n", mul(u));
        if(mul(u) > 1) {
            for (int i = m; i >= 0; i--){
                // printf("%lld %lld\n", i, i * mul(u));
                f(u, i) = f(u, i / mul(u)), g(u, i) = g(u, i / mul(u));
            }
            mul(ls(u)) *= mul(u);
            mul(rs(u)) *= mul(u);
            if(mul(ls(u)) > m) mul(ls(u)) = m + 1;
            if(mul(rs(u)) > m) mul(rs(u)) = m + 1;
            mul(u) = 1;
        }
        if(mdf(u)) {
            for (int i = 0; i <= m; i++)
                f(u, i) = g(u, i) * mdf(u);
            mdf(ls(u)) = mdf(rs(u)) = mdf(u);
            mdf(u) = 0;
        }
        if(to(u).v || to(u).w) {
            for (int i = 0; i <= m; i++){
                f(u, i) = to(u).v * (i >= to(u).w);
                g(u, i) = (i >= to(u).w);
            }
            to(u) = {0, 0};
        }
    }
    void pushdown(int u){
        upd(ls(u));
        upd(rs(u));
    }
    void print(int u, int l, int r){
        if(l == r){
            printf("id %lld, mul = %lld, mdf = %lld\n", u, mul(u), mdf(u));
            return;
        }
        pushdown(u);
        int amx = 0;
        for (int i = 0; i <= m; i++){
            mx(amx, f(u, i));
        }
        printf("[%lld, %lld] ans %lld\n", l, r, amx);
        int mid = (l + r) >> 1;
        print(ls(u), l, mid);
        print(rs(u), mid + 1, r);
        pushup(u);
    }
    void debug(){
        print(1, 1, n);
    }
    void build(int u, int l, int r){
        if(l == r){
            mul(u) = 1;
            for (int i = 0; i <= m; i++){
                f(u, i) = vv[l] * (i >= ww[l]);
                g(u, i) = (i >= ww[l]);
                // printf("id = %lld, f(u, %lld) = %lld\n", l, i, f(u, i));
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, Mdf val, int op){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr){
            // printf("val -> %lld %lld\n", val.v, val.w);
            if(op == 1) to(u) = val;
            if(op == 2) mul(u) *= val.w;
            if(op == 3) mdf(u) = val.v;
            upd(u);
            return;
        }
        // printf("l = %lld, r = %lld\n", l, r);
        // fflush(stdout);
        pushdown(u);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, val, op);
        modify(rs(u), mid + 1, r, ql, qr, val, op);
        pushup(u);
    }
    Node query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return ept;
        if(ql <= l && r <= qr) {
            /*puts("query");printf("l = %lld, r = %lld\n", l, r);*/
            // node[u].print(); 
            return node[u];
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        Node a = query(ls(u), l, mid, ql, qr), b = query(rs(u), mid + 1, r, ql, qr);
        // a.print(), b.print();
        pushup(u);
        return a + b;
    }
}tree;

signed main(){
    scanf("%lld%lld%lld", &n, &m, &q), ept.init();
    for (int i = 1; i <= n; i++) scanf("%lld", ww + i);
    for (int i = 1; i <= n; i++) scanf("%lld", vv + i);
    tree.build(1, 1, n);
    for (int i = 1; i <= q; i++){
        int op, id, w, v, l, r;
        scanf("%lld", &op);
        if(op == 1){
            scanf("%lld%lld%lld", &id, &w, &v);
            // printf("v = %lld, w = %lld\n", v, w);
            tree.modify(1, 1, n, id, id, {v, w}, 1);
        }else if(op == 2){
            scanf("%lld%lld%lld", &l, &r, &w);
            tree.modify(1, 1, n, l, r, {0, w}, 2);
        }else if(op == 3){
            scanf("%lld%lld%lld", &l, &r, &v);
            tree.modify(1, 1, n, l, r, {v, 0}, 3);
        }else{
            scanf("%lld%lld", &l, &r);
            Node ans = tree.query(1, 1, n, l, r);
            int res = 0;
            for (int i = 0; i <= m; i++){
                // printf("ans.f[%lld] = %lld\n", i, ans.f[i]);
                mx(res, ans.f[i]);
            }
            printf("%lld\n", res);
        }
        // tree.debug();
    }
    return 0;
}