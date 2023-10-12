#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 6e5 + 5;
int n, head[N], m, pedge = 1, dfn[N], sta[N], psta, low[N], pdfn, used[N << 1], vbcc[N << 1], pvbcc, pres;
std::vector<int> st[N];
struct Edge{
    int nxt, ver;
}edge[N];
struct Ans{
    int u, v;
    bool operator==(Ans a) const{
        return a.u == u && a.v == v;
    }
}res[N];
bool cmp(Ans a, Ans b){
    if(a.v ^ b.v) return a.v < b.v;
    return a.u < b.u;
}
std::vector<int> ans[N];
void addedge(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
void add(int u, int v){
    res[++pres] = {u, v};
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
                add(pvbcc + n, u);
                while(used[i >> 1]){
                    int top = sta[psta--];
                    ans[pvbcc].push_back(top >> 1);
                    vbcc[top >> 1] = 1;
                    used[top >> 1] = 0;
                    add(pvbcc + n, edge[top].ver);
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
        addedge(u, v);
        addedge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    printf("%d\n", pvbcc);
    for (int i = 1; i <= pvbcc; i++){
        printf("%d ", (int)ans[i].size());
        for (auto v : ans[i]){
            printf("%d ", v);
        }
        putchar('\n');
    }
    std::sort(res + 1, res + 1 + pres, cmp);
    pres = std::unique(res + 1, res + 1 + pres) - res - 1;
    printf("%d\n", pres);
    for (int i = 1; i <= pres; i++){
        printf("%d %d\n", res[i].v, res[i].u - n);
    }
    return 0;
}