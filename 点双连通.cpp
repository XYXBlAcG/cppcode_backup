#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 6e5 + 5;
struct Edge{
    int nxt, ver;
}edge[N];
int n, m, pans, head[N], pedge = 1, dfn[N], sta[N], psta, low[N], pdfn, used[N], vbcc[N], pvbcc;
void add(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
std::pair<int, int> ans[N];
std::vector<int> avbcc[N];
void ins(int u, int v){
    ans[++pans] = {u, v};
}
void tarjan(int u){
    dfn[u] = low[u] = ++pdfn;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(!used[i >> 1] && !vbcc[i >> 1])
            used[(sta[++psta] = i) >> 1] = 1;
        if(!dfn[v]){
            tarjan(v);
            if(dfn[u] == low[v]){
                ++pvbcc;
                ins(u, pvbcc);
                while(used[i >> 1]){
                    int top = sta[psta--];
                    used[top >> 1] = 0;
                    vbcc[top >> 1] = pvbcc;
                    avbcc[pvbcc].push_back(top >> 1);
                    ins(edge[top].ver, pvbcc);
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
        printf("%d ", (int)avbcc[i].size());
        for (auto v : avbcc[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    std::sort(ans + 1, ans + 1 + pans);
    pans = std::unique(ans + 1, ans + 1 + pans) - ans - 1;
    printf("%d\n", pans);
    for (int i = 1; i <= pans; i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    return 0;
}