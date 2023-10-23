#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 1e5 + 5;
int dfn[N], low[N], pdfn, sta[N], psta, vis[N], pscc, n, m;
std::vector<int> scc[N], st[N];
void tarjan(int u){
    dfn[u] = low[u] = ++pdfn;
    vis[sta[++psta] = u] = 1;
    for (auto v : st[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }else if(vis[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        ++pscc;
        while(vis[u]){
            int top = sta[psta--];
            vis[top] = 0;
            scc[pscc].push_back(top);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i);
    }
    printf("%d\n", pscc);
    for (int i = pscc; i; i--){
        printf("%d ", (int)scc[i].size());
        for (auto v : scc[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    return 0;
}