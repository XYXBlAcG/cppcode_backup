#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mx(u) node[u].mx
#define mn(u) node[u].mn
#define to(u) node[u].to
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 4e5 + 5;
int n, m, v[N], dep[N], size[N], fa[N], hv[N], dfn[N], pdfn, fst[N], hsz[N], id[N];
std::vector<int> st[N];
struct Node{
    int mx, mn, to;
}node[N << 2];
struct Qry{
    int mx, mn;
};
struct Tree{
    void pushup(int u){
        mx(u) = std::max(mx(ls(u)), mx(rs(u)));
        mn(u) = std::min(mn(ls(u)), mn(rs(u)));
    }
    void pushdown(int u){
        mx(ls(u)) += to(u), mn(ls(u)) += to(u);
        mx(rs(u)) += to(u), mn(rs(u)) += to(u);
        to(ls(u)) += to(u);
        to(rs(u)) += to(u);
        to(u) = 0;
    }
    void build(int u, int l, int r){
        if(l == r){
            node[u] = {v[id[l]], v[id[l]], 0};
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, int mdf){
        // printf("l = %lld, r = %lld, ql = %lld, qr = %lld\n", l, r, ql, qr);
        if(l > qr || ql > r) return;
        if(ql <= l && r <= qr) {
            to(u) += mdf;
            mn(u) += mdf;
            mx(u) += mdf;
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, mdf);
        modify(rs(u), mid + 1, r, ql, qr, mdf);
        pushup(u);
    }
    Qry query(int u, int l, int r, int ql, int qr){
        if(l > qr || ql > r) return {-INF, INF};
        if(ql <= l && r <= qr) return {node[u].mx, node[u].mn};
        pushdown(u);
        int mid = (l + r) >> 1;
        Qry L = query(ls(u), l, mid, ql, qr), R = query(rs(u), mid + 1, r, ql, qr);
        pushup(u);
        // printf("mx = %lld, mn = %lld\n", std::max(L.mx, R.mx), std::min(L.mn, R.mn));
        return {std::max(L.mx, R.mx), std::min(L.mn, R.mn)};
    }
}tree;
struct Lian{
    void dfs1(int u){
        dep[u] = dep[fa[u]] + 1;
        for (auto v : st[u]){
            if(fa[u] == v) continue;
            dfs1(v);
            size[u] += size[v];
            if(size[hv[u]] < size[v]) hv[u] = v;
        }
        size[u]++;
    }
    void dfs2(int u){
        dfn[u] = ++pdfn;
        if(hv[u]) fst[hv[u]] = fst[u], dfs2(hv[u]);
        hsz[u] = hsz[hv[u]] + 1;
        for (auto v : st[u]){
            if(fa[u] == v || hv[u] == v) continue;
            fst[v] = v, dfs2(v);
        }
    }
    void init(){
        // for (int i = 1; i <= n; i++)
        //     if(!size[i]) dfs1(i), fst[i] = i, dfs2(i);
        dfs1(1), fst[1] = 1, dfs2(1);
    }
    void debug(){
        puts("-------------");
        for (int i = 1; i <= n; i++){
            printf("%lld %lld %lld %lld %lld %lld\n", i, dfn[i], fst[i], fa[i], size[i], dep[i]);
        }
        puts("-------------");
    }
    Qry query_son(int v){
        return tree.query(1, 1, n, dfn[v], dfn[v] + size[v] - 1);
    }
    Qry query_lian(int x, int y){
        int mxx = -INF, mnn = INF;
        while(fst[x] != fst[y]){
            // printf("x = %lld, y = %lld fst = %lld %lld %lld %lld\n", x, y, fst[x], fst[y], fa[fst[x]], fa[fst[y]]);
            if(dep[fst[x]] < dep[fst[y]]) std::swap(x, y);
            // printf("dfn[] - %lld %lld\n", dfn[fst[x]], dfn[x]);
            Qry res = tree.query(1, 1, n, dfn[fst[x]], dfn[x]);
            // printf("query %lld %lld\n", dfn[fst[x]], dfn[x]);
            // printf("res %lld %lld\n", res.mx, res.mn);
            x = fa[fst[x]];
            mxx = std::max(mxx, res.mx), mnn = std::min(mnn, res.mn);
        }
        if(dep[x] >= dep[y]) std::swap(x, y);
        Qry res = tree.query(1, 1, n, dfn[x], dfn[y]);
        // printf("query %lld %lld\n", dfn[x], dfn[y]);
        mxx = std::max(mxx, res.mx), mnn = std::min(mnn, res.mn);
        return {mxx, mnn};
    }
    void modify_son(int v, int val){
        // printf("dfn = %lld %lld\n", dfn[v], dfn[v] + size[v] - 1);
        tree.modify(1, 1, n, dfn[v], dfn[v] + size[v] - 1, val);
    }
    void modify_lian(int x, int y, int val){
        while(fst[x] != fst[y]){
            if(dep[fst[x]] < dep[fst[y]]) std::swap(x, y);
            tree.modify(1, 1, n, dfn[fst[x]], dfn[x], val);
            x = fa[fst[x]];
        }
        if(dep[x] >= dep[y]) std::swap(x, y);
        tree.modify(1, 1, n, dfn[x], dfn[y], val);
    }
}lian;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", v + i);
    fa[1] = 1;
    for (int i = 2; i <= n; i++){
        scanf("%lld", fa + i);
        st[fa[i]].push_back(i);
    }
    lian.init();
    for (int i = 1; i <= n; i++) id[dfn[i]] = i;
    tree.build(1, 1, n);
    // for (int i = 1; i <= n; i++){
    //     printf("dfn %lld = %lld\n", i, dfn[i]);
    // }
    for (int i = 1; i <= m; i++){
        int op, u, v, w;
        scanf("%lld", &op);
        // lian.debug();
        if(op == 1){
            scanf("%lld%lld%lld", &u, &v, &w);
            lian.modify_lian(u, v, w);
        }else if(op == 2){
            scanf("%lld%lld", &u, &v);
            Qry res = lian.query_lian(u, v);
            printf("%lld %lld\n", res.mx, res.mn);
        }else if(op == 3){
            scanf("%lld%lld", &u, &w);
            lian.modify_son(u, w);
        }else{
            scanf("%lld", &u);
            Qry res = lian.query_son(u);
            printf("%lld %lld\n", res.mx, res.mn);
        }
    }
    return 0;
}