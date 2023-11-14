#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int dfn[N], pdfn, low[N], n, m, sta[N], psta, vis[N], pbcc;
std::vector<int> st[N], bcc[N];
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
        pbcc++;
        while(vis[u]){
            int top = sta[psta--];
            vis[top] = 0;
            bcc[pbcc].push_back(top);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    printf("%d\n", pbcc);
    for (int i = pbcc; i; i--){
        printf("%d ", (int)bcc[i].size());
        for (auto v : bcc[i])
            printf("%d ", v);
        putchar('\n');
    }
    return 0;
}