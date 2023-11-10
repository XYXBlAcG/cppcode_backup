#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define mn(u) node[u].mn
#define ss(u) node[u].s
#define int long long
#define No puts("N0T-FOUND")
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 6e5 + 5;
int n, q, dfn[N], pdfn, fa[N], id[N];
bool chklian = 1, chkju = 1;
int dis[N];
struct Node {
    int v, w;
};
int lef[N];
std::vector<Node> st[N];
void dfs1(int u, int fath) {
    dfn[u] = ++pdfn, fa[u] = fath, id[pdfn] = u;
    if (st[u].size() == 1 && u != 1) {
        lef[pdfn] = u;
    }
    for (auto v : st[u]) {
        if (v.v == fath)
            continue;
        dfs1(v.v, u);
    }
}
namespace pt20 {
std::vector<int> Qry;
int viser[N];
int anser;
void clean() {
    for (auto v : Qry) viser[v] = 0;
    Qry.clear();
}
void dfspt(int u, int fath, int maxv) {
    if (viser[u])
        anser = std::min(anser, maxv);
    for (auto v : st[u]) {
        if (v.v == fath)
            continue;
        dfspt(v.v, u, maxv + v.w);
    }
}
void main() {
    for (int i = 1; i <= q; i++) {
        anser = INF;
        int u, l, r, cnt = 0;
        scanf("%lld%lld%lld", &u, &l, &r);
        for (int j = l; j <= r; j++)
            if (lef[j])
                viser[id[j]] = 1, cnt++, Qry.push_back(id[j]);
        if (!cnt) {
            No;
            continue;
        }
        if (viser[u]) {
            puts("0");
            clean();
            continue;
        }
        dfspt(u, 0, 0);
        printf("%lld\n", anser);
        clean();
    }
}
}  // namespace pt20
namespace lian {
void liandfs(int u, int fath) {
    for (auto v : st[u]) {
        if (v.v == fath)
            continue;
        liandfs(v.v, u);
        dis[u] = dis[v.v] + v.w;
    }
}
void main() {
    memset(dis, 0, sizeof(dis));
    liandfs(1, 0);
    for (int i = 1; i <= q; i++) {
        int u, l, r;
        scanf("%lld%lld%lld", &u, &l, &r);
        if (r < n) {
            No;
            continue;
        }
        if (u == n) {
            puts("0");
            continue;
        }
        printf("%lld\n", dis[u]);
    }
}
}  // namespace lian
#define ls(u) u << 1
#define rs(u) u << 1 | 1
struct Noder{
    int mn, s;
    Noder(int a = 0, int b = 0){mn = a, s = b;}
}node[N];
Noder operator+(Noder a, Noder b){
    Noder res;
    res.mn = std::min(a.mn, b.mn);
    res.s = a.s + b.s;
    return res;
}
struct Tree {
    void pushup(int u){
        mn(u) = std::min(mn(ls(u)), mn(rs(u)));
        ss(u) = ss(ls(u)) + ss(rs(u));
    }
    void build(int u = 1, int l = 2, int r = n) {
        if (l == r) {
            mn(u) = dis[id[l]];
            if(lef[l]) ss(u) = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    Noder query(int ql, int qr, int u = 1, int l = 2, int r = n) {
        if (l > qr || r < ql)
            return {INF, 0};
        if (ql <= l && r <= qr)
            return node[u];
        int mid = (l + r) >> 1;
        return query(ql, qr, ls(u), l, mid) + query(ql, qr, rs(u), mid + 1, r);
    }
} tree;
namespace juhua {
void judfs(int u) {
    for (auto v : st[u]) {
        dis[v.v] = v.w;
    }
}
void main() {
    memset(dis, 0, sizeof(dis));
    judfs(1);
    tree.build();
    for (int i = 1; i <= q; i++) {
        int u, l, r;
        scanf("%lld%lld%lld", &u, &l, &r);
        if (l == 1 && r == 1) {
            No;
            continue;
        }
        if (id[l] <= u && u <= id[r]) {
            puts("0");
            continue;
        }
        // printf("dfn[l] = %lld, dfn[r] = %lld\n", dfn[l], dfn[r]);
        printf("%lld\n", tree.query(l, r).mn + dis[u]);
    }
}
}  // namespace juhua
namespace qry {
void qrydfs(int u, int fath, int maxv) {
    if (lef[dfn[u]]) {
        dis[u] = maxv;
    } else
        dis[u] = INF;
    for (auto v : st[u]) {
        if (v.v == fath)
            continue;
        qrydfs(v.v, u, maxv + v.w);
    }
}
void main() {
    qrydfs(1, 0, 0);
    tree.build();
    for (int i = 1; i <= q; i++) {
        int u, l, r;
        scanf("%lld%lld%lld", &u, &l, &r);
        Noder res = tree.query(l, r);
        if(!res.s){
            No;
            continue;
        }
        printf("%lld\n", res.mn);
    }
}
}  // namespace qry
signed main() {
    #ifdef ONLINE_JUDGE
    freopen("kings.in", "r", stdin);
    freopen("kings.out", "w", stdout);
    #endif

    scanf("%lld%lld", &n, &q);
    for (int i = 1, u, v, t; i < n; i++) {
        scanf("%lld%lld%lld", &u, &v, &t);
        st[u].push_back({ v, t });
        st[v].push_back({ u, t });
        if (u != i || v != i + 1)
            chklian = 0;
        if (u != 1)
            chkju = 0;
    }
    dfs1(1, 0);
    if (n <= 200 || q == 1) {
        pt20::main();
    } else if (chklian) {
        lian::main();
    } else if (chkju) {
        juhua::main();
    } else {
        qry::main();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}