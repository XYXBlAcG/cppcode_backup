#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e5 + 5;
int n, m, fath[N], dep[N], point;
std::vector<int> st[N];
struct UFS{
    int fa[N], si[N], num;
    void init(){
        for (int i = 1; i <= n; i++) fa[i] = i, si[i] = 1; 
        num = n;
    }
    int size(int u){return si[find(u)];};
    bool same(int u, int v){return find(u) == find(v);}
    int find(int x){return (fa[x] == x) ? x : fa[x] = find(fa[x]);}
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        fa[u] = v, si[v] += si[u], si[u] = 0, num--;
    }
}cc, bcc;
void ins(int u, int v){
    st[u].push_back(v);
    st[v].push_back(u);
}
void dfs(int u, int fa){
    fath[u] = fa, dep[u] = dep[fa] + 1;
    for (auto v : st[u])
        if(v != fa) dfs(v, u);
}
void cc_merge(int u, int v){
    if(cc.size(u) < cc.size(v)) std::swap(u, v);
    dfs(v, u);
    cc.merge(u, v);
    ins(u, v);
}
void bcc_merge(int u, int v){
    
}
int main(){
    scanf("%d%d", &n, &m);
    cc.init(), bcc.init();
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        if(cc.same(u, v)) bcc_merge(u, v);
        else cc_merge(u, v);
        printf("%d %d %d\n", cc.num, bcc.num, point);
    }
    return 0;
}