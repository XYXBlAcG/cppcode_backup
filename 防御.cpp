#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
const int N = 1e5 + 5;
int n, m, dfn[N], low[N], pdfn, pvbcc, vbcc[N], sta[N], psta, used[N], size[N], in[N], anc[N][21], fa[N], dep[N], sz[N];
std::vector<int> st[N], ed[N], st2[N];
std::queue<int> que;
struct FileIO{
    FileIO(){
        freopen("defense.in", "r", stdin);
        freopen("defense.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
};
struct Edge{
    int u, v;
    bool operator==(Edge a) const{
        return a.u == u && a.v == v;
    }
}edge[N * 5], edge2[N * 5];
bool cmp(Edge a, Edge b){
    if(a.u ^ b.u) return a.u < b.u;
    return a.v < b.v;
}
FileIO fileio;
void tarjan(int u){
    dfn[u] = low[u] = ++pdfn;
    sta[++psta] = u, used[u] = 1;
    for (auto v : st[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }else if(used[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        pvbcc++;
        while(used[u]){
            int top = sta[psta--];
            used[top] = 0;
            vbcc[top] = pvbcc;
            sz[pvbcc]++;
        }
    }
}
int lca(int a, int b){
    if(a == b) return a;
    if(dep[a] < dep[b]) std::swap(a, b);
    for (int i = 19; ~i; i--){
        if(dep[anc[a][i]] >= dep[b]) a = anc[a][i];
    }
    if(a == b) return a;
    for (int i = 19; ~i; i--){
        if(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}
void dfs(int u){
    // printf("u = %d\n", u);
    size[u] = sz[u];
    for (auto v : st2[u]){
        dfs(v);
        size[u] += size[v];
    }
}
void addedge(int u, int v){
    st2[u].push_back(v);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        // edge[i] = {v, u};
    }
    for (int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    // for (int i = 1; i <= n; i++){
    //     printf("vbcc[%d] = %d\n", i, vbcc[i]);
    // }
    // for (int i = 1; i <= m; i++)
    //     edge2[i] = {vbcc[edge[i].u], vbcc[edge[i].v]};
    // std::sort(edge2 + 1, edge2 + 1 + m, cmp);
    // int len = std::unique(edge2 + 1, edge2 + 1 + m) - edge2 - 1;
    // for (int i = 1; i <= len; i++){
    //     // printf("%d -> %d\n", edge2[i].u, edge2[i].v);
    //     if(edge2[i].u ^ edge2[i].v){
    //         printf("ed -> %d -> %d\n", edge2[i].v, edge2[i].u);
    //         ed[edge2[i].u].push_back(edge2[i].v);
    //         in[edge2[i].v]++;
    //     }
    // }
    for (int i = 1; i <= n; i++){
        for (auto v : st[i]){
            if(vbcc[i] != vbcc[v]){
                ed[vbcc[v]].push_back(vbcc[i]);
                in[vbcc[i]]++;
            }
        }
    }
    memset(fa, -1, sizeof(fa));
    for (int i = 1; i <= pvbcc; i++){
        if(!in[i]){
            que.push(i);
            fa[i] = 0;
        }
    }
    while(que.size()){
        int x = que.front();
        que.pop();
        addedge(fa[x], x);
        anc[x][0] = fa[x];
        dep[x] = dep[fa[x]] + 1;
        for (int i = 1; i < 20; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
        for (auto v : ed[x]){
            if(fa[v] == -1) fa[v] = x;
            else fa[v] = lca(fa[v], x);
            if(--in[v] == 0) que.push(v);
        }
    }
    // for (int i = 2; i <= pvbcc; i++) st2[fa[i]].push_back(i);
    dfs(0);
    // for (int i = 1; i <= n; i++){
    //     printf("%d -> %d\n", i, vbcc[i]);
    // }
    // for (int i = 1; i <= pvbcc; i++){
    //     printf("%d\n", size[i]);
    // }
    for (int i = 1; i <= n; i++){
        printf("%d\n", size[vbcc[i]]);
    }
    // for (int i = 1; i <= n; i++){
    //     printf("%d\n", size[vbcc[i]] + sz[vbcc[i]] - 1);
    // }
    

    
    
    return 0;
}