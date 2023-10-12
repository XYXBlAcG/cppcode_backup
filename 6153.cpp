#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 4e5 + 5;
int n, m, fa[N][22], dep[N], maxx, l_[N], r_[N], v[N], tl[N], tr[N], dfncnt = 0, head[N], pedge, lcaa[N];
struct Node{
    int op, x, t, res;
}node[N], n1[N], n2[N];
// std::vector<int> st[N];
struct Edge{
    int nxt, ver;
}edge[N];
void add(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
void dfs(int u, int fath){
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    tl[u] = ++dfncnt;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    // for (int v : st[u]){
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(v != fath){
            dfs(v, u);
        }
    }
    tr[u] = dfncnt;
}
int lca(int u, int v){
    // printf("u = %d, v = %d\n", u, v);
    if(u == v) return u;
    if(dep[u] < dep[v]) std::swap(u, v);
    for (int i = 19; ~i; i--) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if(u == v) return u;
    for (int i = 19; ~i; i--) 
        if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
bool cmp(Node a, Node b){return a.t < b.t;}
struct Tree{
    int node[N << 1];
    int lowbit(int u){return u & -u;}
    void add(int u, int val){for (; u <= n; u += lowbit(u)) node[u] += val;}
    int query(int u){
        int ans = 0;
        for(; u; u -= lowbit(u)) ans += node[u];
        return ans;
    }
    void modify(int u, int v, int lc, int val){
        // printf("u = %d, v = %d\n", u, v);
        // int lc = lca(u, v);
        // printf("u = %d, v = %d, lca = %d\n", u, v, lc);
        add(tl[u], val), add(tl[v], val), add(tl[lc], -val);
        if(fa[lc][0]) add(tl[fa[lc][0]], -val);
    }
}tree;
void solve(int l, int r, int ll, int rr){
    // printf("l r ll rr = %d %d %d %d\n", l, r, ll, rr);
    int mid = (l + r) >> 1, L = 0, R = 0, way = 0;
    // if(ll > rr) return;
    if(l == r){
        for (int i = ll; i <= rr; i++) if(node[i].op == 2) node[i].res = l/*, printf("i = %d, res = %d\n", i, node[i].res)*/;
        return;
    }
    for (int i = ll; i <= rr; i++){
        // printf("i = %d\n", i); 
        if(node[i].op <= 1){
            if(v[node[i].x] <= mid) n1[++L] = node[i];
            else{
                way += node[i].op ? -1 : 1;
                tree.modify(l_[node[i].x], r_[node[i].x], lcaa[node[i].x], node[i].op ? -1 : 1);
                n2[++R] = node[i];
            }
        }else{
            // printf("l = %d, r = %d\n", tl[node[i].x], tr[node[i].x]);
            if(tree.query(tr[node[i].x]) - tree.query(tl[node[i].x] - 1) == way) n1[++L] = node[i];
            else n2[++R] = node[i];
        }
        // fflush(stdout);
    }
    // for (int i = ll; i <= rr; i++) 
    for (int i = 1; i <= R; i++) if(n2[i].op <= 1) tree.modify(l_[n2[i].x], r_[n2[i].x], lcaa[n2[i].x], n2[i].op ? 1 : -1);
    for (int i = 1; i <= L; i++) node[ll + i - 1] = n1[i];
    for (int i = L + 1; i <= L + R; i++) node[ll + i - 1] = n2[i - L];
    if(L) solve(l, mid, ll, ll + L - 1);
    if(R) solve(mid + 1, r, ll + L, rr);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        // st[u].push_back(v), st[v].push_back(u);
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++){
    //     printf("l = %d, r = %d\n", tl[i], tr[i]);
    // }
    for (int i = 1, op, a, b, val, t; i <= m; i++){
        scanf("%d", &op);
        if(op == 0){
            scanf("%d%d%d", &a, &b, &val);
            l_[i] = a, r_[i] = b, v[i] = val;
            lcaa[i] = lca(a, b);
            node[i] = {op, i, i, 0};
            maxx = std::max(maxx, val);
        }else{
            scanf("%d", &t);
            node[i] = {op, t, i, 0};
        }
    }
    solve(-1, maxx, 1, m);
    std::stable_sort(node + 1, node + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
        if(node[i].op == 2) printf("%d\n", node[i].res);
    return 0;
}