#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 6e5 + 5, M = 6e5 + 5;
int n, m, dfn[N], low[N], ebcc[N], pebcc, pdfn, sta[N], psta, head[M], pedge = 1, brg[N];
struct Edge{
    int nxt, ver; 
}edge[M];
void add(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
std::vector<int> aebcc[N];
std::vector<std::pair<int, int>> ans;
void tarjan(int u, int from = 0){
    dfn[u] = low[u] = ++pdfn;
    sta[++psta] = u;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(!dfn[v]){
            tarjan(v, i);
            low[u] = std::min(low[u], low[v]);
        }else if((from ^ i) != 1){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        pebcc++;
        brg[from >> 1] = 1;
        while(!ebcc[u]){
            int top = sta[psta--];
            ebcc[top] = pebcc;
            aebcc[pebcc].push_back(top);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i);
    }
    printf("%d\n", pebcc);
    for (int i = 1; i <= pebcc; i++){
        printf("%d ", (int)aebcc[i].size());
        for (auto v : aebcc[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    for (int i = 1; i <= n; i++){
        for (int j = head[i]; j; j = edge[j].nxt){
            int v = edge[j].ver;
            if(brg[j >> 1]){
                ans.push_back({ebcc[i], ebcc[v]});
                brg[j >> 1] = 0;
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto v : ans){
        printf("%d %d\n", v.first, v.second);
    }

    return 0;
}