#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define INF 0x3f3f3f3f
const int N = 2e5 + 5;
int n, m, Q, dfn[N], low[N], dfncnt, vis[N], sta[N], psta, pedge = 1, head[N], vbcc[N], pvbcc, dep[N], point[N], pp, fath[N][22], d[N];
std::vector<int> st[N << 1];
struct Node{
    int nxt, ver;
}edge[N << 1];
void add(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
void readd(int u, int v){
    st[u].push_back(v);
    st[v].push_back(u);
}
std::set<std::pair<int, int>> se;
// void dfs(int u){
//     dfn[u] = low[u] = ++dfncnt; sta[++psta] = u;
//     for (int i = head[u]; i;i = edge[i].nxt){
//         int v = edge[i].ver;
//         if (!dfn[v]){
//             dfs(v);
//             low[u] = std::min(low[u], low[v]);
//             if (low[v] >= dfn[u]){
//                 pvbcc++;
//                 readd(u, pvbcc);
//                 int top;
//                 do{
//                     top = sta[psta--];
//                     readd(pvbcc, top); 
//                 }while (top ^ v);
//             }
//         }
//         else low[u] = std::min(low[u], dfn[v]);
//     }
// }
void dfs(int u){
    dfn[u] = low[u] = ++dfncnt;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(!vis[i >> 1] && !vbcc[i >> 1])
            vis[(sta[++psta] = i) >> 1] = 1;
        if(!dfn[v]){
            dfs(v);
            if(dfn[u] == low[v]){
                pvbcc++;
                // readd(pvbcc, u);
                se.insert({pvbcc, u});
                while(vis[i >> 1]){
                    int top = sta[psta--];
                    vbcc[top >> 1] = pvbcc;
                    // readd(pvbcc, edge[top].ver);
                    se.insert({pvbcc, edge[top].ver});
                    vis[top >> 1] = 0;
                }
            }
            low[u] = std::min(low[u], low[v]);
        }else low[u] = std::min(low[u], dfn[v]);
    }
}
void dfs2(int u, int fa){
    point[++pp] = u, fath[u][0] = fa;
    for (int i = 1; i <= 19; i++) fath[u][i] = fath[fath[u][i - 1]][i - 1];
    for (auto v : st[u]){
        if(v == fa) continue;
        // printf("%d %d\n", u, v);
        dep[v] = dep[u] + 1;
        dfs2(v, u);
    }
}
int lca(int x, int y){
    if(dep[x] > dep[y]) std::swap(x, y);
    for (int i = 19; ~i; i--)
        if(dep[fath[y][i]] >= dep[x]) y = fath[y][i];
    if(x == y) return x;
    for (int i = 19; ~i; i--)
        if(fath[y][i] ^ fath[x][i]) y = fath[y][i], x = fath[x][i];
    return fath[x][0];
}
int main(){
    scanf("%d%d%d", &n, &m, &Q), pvbcc = n;
    for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
    // for (int i = 1; i <= n; i++) if(!dfn[i]) dfs(i);
    dfs(1);
    for (auto v : se) st[v.first].push_back(v.second), st[v.second].push_back(v.first); 
    dep[1] = 1;
    dfs2(1, 0);
    for (int i = 1, p, q; i <= Q; i++) {
        scanf("%d%d", &p, &q);
        int anc = lca(p, q);
        // printf("anc = %d\n", anc);
        d[p]++, d[q]++, d[anc]--, d[fath[anc][0]]--;
    }
    for (int i = pvbcc; i; i--)
        d[fath[point[i]][0]] += d[point[i]];
    for (int i = 1; i <= n; i++) printf("%d\n", d[i]);
    return 0;
}
/*
1 6
6 3
6 2
1 5
5 4
anc = 1
anc = 1
2
1
1
2
*/