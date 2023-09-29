#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e5 + 5;
int n, m, fath[N], dep[N];
struct UFS{
    int fa[N], si[N], num;
    void init(){
        for (int i = 1; i <= n; i++) fa[i] = i, si[i] = 1; 
        num = n;
    }
    int size(int u){return si[find(u)];};
    bool same(int u, int v){return find(u) == find(v);}
    int find2(int x){return (fa[x] == x) ? x : find2(fa[x]);}
    int find(int x){return (fa[x] == x) ? x : fa[x] = find(fa[x]);}
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        // if(si[v] < si[u]) std::swap(u, v);
        fa[u] = v, si[v] += si[u], si[u] = 0, num--;
    }
}cc, bcc;
std::vector<int> st[N];
void ins(int u, int v){
    st[u].push_back(v);
    st[v].push_back(u);
}
void dfs(int u, int fa){
    fath[u] = fa, dep[u] = dep[fa] + 1;
    for (auto v : st[u]){
        if(v != fa){
            dfs(v, u);
        }
    }
    if (dep[u] < dep[bcc.find(u)]) {
        bcc.fa[bcc.find(u)] = u;
        bcc.fa[u] = u; 
    }
}
void cc_merge(int u, int v){
    if(cc.size(u) < cc.size(v)) std::swap(u, v);
    dfs(v, u);
    cc.merge(v, u);
    ins(u, v);
}
void bcc_merge(int u, int v){
    // printf("u, v = %d %d\n", u, v);
    u = bcc.find(u), v = bcc.find(v);
    while(u != v){
        // printf("! u, v = %d %d\n", dep[u], dep[v]);
        if(dep[u] < dep[v]) std::swap(u, v);
        // printf("! fa[u], u = %d %d\n", fath[u], u);
        bcc.merge(u, fath[u]);
        u = bcc.find(u);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fath[i] = i, dep[i] = 1;
    cc.init(), bcc.init();
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        if(cc.same(u, v)) bcc_merge(u, v);
        else cc_merge(u, v);
        printf("%d %d\n", cc.num, bcc.num);
    }
    return 0;
}