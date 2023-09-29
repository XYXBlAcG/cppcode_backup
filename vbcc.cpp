#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 4e6 + 6;
int n, m, vis[N], sta[N], psta, vbcc[N], pvbcc, head[N], pedge = 1, dfn[N], low[N], dfncnt;
struct Node{
    int u, v;
};
bool cmp(Node a, Node b){
    if(a.u == b.u) return a.v < b.v;
    return a.u < b.u;
}
bool cmp2(Node a, Node b){
    return (a.u == b.u) && (a.v == b.v);
}
std::vector<int> st[N];
std::vector<int> tvbc[N];
std::vector<Node> ans;
struct Edge{
    int u, nxt, ver;
}edge[N];
void add(int u, int v){
    edge[++pedge] = {u, head[u], v};
    head[u] = pedge;
}
void add2(int u, int v){
    ans.push_back({u, v});
}
void tarjan(int u){
    dfn[u] = low[u] = ++dfncnt;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(!vis[i >> 1] && !vbcc[i >> 1])
            vis[(sta[++psta] = i) >> 1] = 1;
        if(!dfn[v]){
            tarjan(v);
            if(dfn[u] == low[v]){
                pvbcc++;
                add2(pvbcc , u);
                while(vis[i >> 1]){
                    int top = sta[psta--];
                    vbcc[top >> 1] = pvbcc;
                    tvbc[pvbcc].push_back(top >> 1);
                    add2(pvbcc , edge[top].ver);
                    vis[top >> 1] = 0;
                }
            }
            low[u] = std::min(low[u], low[v]);
        }else{
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    printf("%d\n", pvbcc);
    for (int i = 1; i <= pvbcc; i++){
        printf("%d ", (int)tvbc[i].size());
        for (int v : tvbc[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    // std::sort(ans.begin(), ans.end(), cmp);
    // ans.erase(std::unique(ans.begin(), ans.end(), cmp2), ans.end());
    // printf("%d\n", (int)ans.size());
    // for (auto v : ans){
    //     // if(v.u > n) v.u -= n;
    //     // if(v.v > n) v.v -= n;
    //     printf("%d %d\n", v.v, v.u);
    // }
    return 0;
}