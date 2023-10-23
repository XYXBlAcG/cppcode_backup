#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define f(u, v) node[u].f[v]
#define g(u, v) node[u].g[v]
#define mul(u) node[u].mulw
#define mdf(u) node[u].mdfv
#define to(u) node[u].to
const int N = 6e5 + 5, M = 23;
int n, m, q, ww[N], vv[N];
struct Mdf{
    int v, w;
};
struct Node{
    int mulw, mdfv, f[M], g[M];
    Mdf to;
    inline void init(){
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
    }
}node[N << 2];
void mx(int& a, int b){
    a = std::max(a, b);
}
struct Tree{
    void pushup(int u){
        for (int i = 0; i <= m; i++){
            for (int k = 0; k <= i; k++){
                mx(f(u, i), f(ls(u), k) + f(rs(u), i - k)); 
                mx(g(u, i), g(ls(u), k) + g(rs(u), i - k));
            }
        }
    }
    void upd(int u){
        if(to(u).v || to(u).w) {
            for (int i = 0; i <= m; i++){
                // f(u, i) = to(u).v * (i / to(u).w);
                // g(u, i) = i / to(u).w;
                f(u, i) = to(u).v * (i >= to(u).w);
                g(u, i) = (i >= to(u).w);
            }
            to(u) = {0, 0};
        }
        if(mul(u) != 1) {
            for (int i = 0; i <= m; i++){
                if(i * mul(u) <= m) f(u, i) = f(u, i * mul(u)), g(u, i) = g(u, i * mul(u));
                else f(u, i) = 0, g(u, i) = 0;
            }
            mul(ls(u)) *= mul(u);
            mul(rs(u)) *= mul(u);
            mul(u) = 1;
        }
        if(mdf(u)) {
            for (int i = 0; i <= m; i++)
                f(u, i) = g(u, i) * mdf(u);
            mdf(ls(u)) = mdf(rs(u)) = mdf(u);
            mdf(u) = 0;
        }
    }
    void pushdown(int u){
        upd(ls(u));
        upd(rs(u));
    }
    void print(int u, int l, int r){
        if(l == r){
            printf("id %d, mul = %d, mdf = %d\n", u, mul(u), mdf(u));
            return;
        }
        pushdown(u);
        int amx = 0;
        for (int i = 0; i <= m; i++){
            mx(amx, f(u, i));
        }
        printf("[%d, %d] ans %d\n", l, r, amx);
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
                // f(u, i) = vv[l] * (i / ww[l]);
                f(u, i) = vv[l] * (i >= ww[l]);
                // g(u, i) = i / ww[l];
                g(u, i) = (i >= ww[l]);
                printf("id = %d, f(u, %d) = %d\n", l, i, f(u, i));
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
            if(op == 1) to(u) = val;
            if(op == 2) mul(u) *= val.w;
            if(op == 3) mdf(u) = val.v;
            upd(u);
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, val, op);
        modify(rs(u), mid + 1, r, ql, qr, val, op);
        pushup(u);
    }
    Node query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return {};
        if(ql <= l && r <= qr) {
            return node[u];
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        Node a = query(ls(u), l, mid, ql, qr), b = query(rs(u), mid + 1, r, ql, qr), ans;
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= i; j++){
                
            }
        }
        pushup(u);
    }
}tree;

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%d", ww + i);
    for (int i = 1; i <= n; i++) scanf("%d", vv + i);
    tree.build(1, 1, n);
    for (int i = 1; i <= q; i++){
        int op, id, w, v, l, r;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d%d%d", &id, &w, &v);
            tree.modify(1, 1, n, id, id, {v, w}, 1);
        }else if(op == 2){
            scanf("%d%d%d", &l, &r, &w);
            tree.modify(1, 1, n, l, r, {0, w}, 2);
        }else if(op == 3){
            scanf("%d%d%d", &l, &r, &v);
            tree.modify(1, 1, n, l, r, {v, 0}, 3);
        }else{
            scanf("%d%d", &l, &r);
            printf("%d\n", tree.query(1, 1, n, l, r));
        }
        // tree.debug();
    }
    return 0;
}