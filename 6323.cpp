#include <cstdio>
#include <vector>
#define n2 2 * n
#define n3 3 * n
#define tow town[j + 1]
#define las town[j]
#define yes puts("TAK")
#define no puts("NIE")
const int N = 4e6 + 5;
int n, m, k, dfn[N], low[N], dfncnt, sta[N], psta, vis[N], pscc, scc[N], town[N];
std::vector<int> st[N];
void dfs(int u){
    dfn[u] = low[u] = ++dfncnt;
    vis[sta[++psta] = u] = 1;
    for (auto v : st[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        }else if(vis[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        pscc++;
        int top;
        do{
            top = sta[psta--];
            vis[top] = 0;
            scc[top] = pscc;
        }while(top != u);
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u + n].push_back(v);
        st[v + n].push_back(u);
    }
    for (int i = 1, w; i <= k; i++){
        scanf("%d", &w);
        for (int j = 1; j <= w; j++) scanf("%d", town + j);
        for (int j = 1; j <= w; j++){
            st[las + n2].push_back(las + n);
            st[las + n3].push_back(las + n);
            if(j != w){
                st[tow + n2].push_back(las + n2);
                st[las + n3].push_back(tow + n3);
                st[las].push_back(tow + n3);
                st[tow].push_back(las + n2);
            }
        }
    }
    for (int i = 1; i <= n2; i++) if(!dfn[i]) dfs(i);
    for (int i = 1; i <= n; i++)
        if(scc[i] == scc[i + n]) return no, 0;
    return yes, 0;
}