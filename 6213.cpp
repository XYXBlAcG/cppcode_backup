#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define nd(u) node[u]
#define f0(u) node[u].f[0]
#define f1(u) node[u].f[1]
#define g0(u) node[u].g[0]
#define g1(u) node[u].g[1]
#define int unsigned long long
const int N = 2e5 + 5, lim = ~0;
int n, m, k, fst[N], hsz[N], hv[N], sz[N], fa[N], dfn[N], pdfn, dep[N], id[N], op[N], val[N];
std::vector<int> st[N];
struct Node{
    int f[2], g[2];
    Node(){f[0] = f[1] = g[0] = g[1] = 0;}
    bool empty(){
        return f[0] == 0 && f[1] == 0 && g[0] == 0 && g[1] == 0;
    }
}node[N << 2], ept;
Node operator+(Node a, Node b){
    // if(a.empty()) return b;
    // if(b.empty()) return a;
    Node tmp;
    tmp.f[0] = (a.f[0] & b.f[1]) | ((~a.f[0]) & b.f[0]);
    tmp.f[1] = (a.f[1] & b.f[1]) | ((~a.f[1]) & b.f[0]);
    tmp.g[0] = (b.g[0] & a.g[1]) | ((~b.g[0]) & a.g[0]);
    tmp.g[1] = (b.g[1] & a.g[1]) | ((~b.g[1]) & a.g[0]);
    return tmp;
}
int cal(int idx, int num){
    if(op[idx] == 1) return val[idx] & num;
    if(op[idx] == 2) return val[idx] | num;
    return val[idx] ^ num;
}
void print(Node a){
    printf("Node %llu %llu %llu %llu\n", a.f[0], a.f[1], a.g[0], a.g[1]);
}
struct Tree{
    void pushup(int u){nd(u) = nd(ls(u)) + nd(rs(u));}
    void build(int u, int l, int r){
        if(l == r){
            g0(u) = f0(u) = cal(id[l], 0), g1(u) = f1(u) = cal(id[l], lim);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid);
        build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int p){
        if(l > p || r < p) return;
        if(l == r){
            g0(u) = f0(u) = cal(id[l], 0), g1(u) = f1(u) = cal(id[l], lim);
            return;
        }
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, p);
        modify(rs(u), mid + 1, r, p);
        pushup(u);
    }
    Node query(int u, int l, int r, int ql, int qr){
        if(l == ql && r == qr) return nd(u);
        // if(l > qr || r < ql) return (Node){};
        // if(ql <= l && r <= qr) return nd(u);
        int mid = (l + r) >> 1;
        if(mid >= qr) return query(ls(u), l, mid, ql, qr);
        else if(mid < ql) return query(rs(u), mid + 1, r, ql, qr);
        else return query(ls(u), l, mid, ql, mid) + query(rs(u), mid + 1, r, mid + 1, qr);
        // Node L = query(ls(u), l, mid, ql, qr), R = query(rs(u), mid + 1, r, ql, qr);
        // puts("L"), print(L), puts("R"), print(R);
        // pushup(u);
        // puts("L + R");
        // print(L + R);
        // return L + R;
    }
}tree;
struct Lian{
    Node ans[N], ans2[N];
    void dfs1(int u){
        dep[u] = dep[fa[u]] + 1;
        for (auto v : st[u]){
            if(fa[u] == v) continue;
            fa[v] = u;
            dfs1(v);
            sz[u] += sz[v];
            if(sz[hv[u]] < sz[v]) hv[u] = v;
        }
        sz[u]++;
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
        dfs1(1), fst[1] = 1; dfs2(1);
        for (int i = 1; i <= n; i++) id[dfn[i]] = i;
    }
    Node query(int x, int y){
        signed pans = 0, pans2 = 0; Node res;
        while(fst[x] != fst[y]){
            if(dep[fst[x]] < dep[fst[y]]) {
                ans2[++pans2] = tree.query(1, 1, n, dfn[fst[y]], dfn[y]);
                // printf("ret val = %llu %llu %llu %llu\n", ans2[pans2].f[0], ans2[pans2].f[1], ans2[pans2].g[0], ans2[pans2].g[1]);
                y = fa[fst[y]];
            }else{
                ans[++pans] = tree.query(1, 1, n, dfn[fst[x]], dfn[x]);
                // printf("ret val = %llu %llu %llu %llu\n", ans[pans].f[0], ans[pans].f[1], ans[pans].g[0], ans[pans].g[1]);
                x = fa[fst[x]];
            }
        }
        if(dep[x] <= dep[y]) ans2[++pans2] = tree.query(1, 1, n, dfn[x], dfn[y]);
        else ans[++pans] = tree.query(1, 1, n, dfn[y], dfn[x]);
        for (signed i = 1; i <= pans; i++) std::swap(ans[i].f, ans[i].g);
        // for (signed i = 1; i <= pans; i++){
        //     printf("ans -> %llu %llu\n", ans[i].f[0], ans[i].f[1]);
        // }
        // for (signed i = pans2; i; i--){
        //     printf("ans2 -> %llu %llu\n", ans2[i].f[0], ans2[i].f[1]);
        // }
        if(pans){
            res = ans[1];
            for (signed i = 2; i <= pans; i++) res = res + ans[i];
            if(pans2) res = res + ans2[pans2];
        }else res = ans2[pans2];
        for (signed i = pans2 - 1; i > 0; i--) res = res + ans2[i];
        // printf("res = %llu %llu %llu %llu\n", res.f[0], res.f[1], res.g[0], res.g[1]);
        return res;
    }
}lian;
signed main(){
    scanf("%llu%llu%llu", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%llu%llu", op + i, val + i);
    for (int i = 1, u, v; i < n; i++){
        scanf("%llu%llu", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    lian.init();
    tree.build(1, 1, n);
    for (int i = 1, q, x, y, z; i <= m; i++){
        scanf("%llu%llu%llu%llu", &q, &x, &y, &z);
        if(q == 1) {
            Node res = lian.query(x, y);
            int ans = 0;
            for (signed j = 63; j >= 0; j--){
                if(res.f[0] >> j & 1) ans += (1llu << j);
                else if((res.f[1] >> j & 1) && z >= (1llu << j)) ans += (1llu << j), z -= (1llu << j);
            }
            printf("%llu\n", ans);
        }
        else op[x] = y, val[x] = z, tree.modify(1, 1, n, dfn[x]);
    }
    return 0;
}