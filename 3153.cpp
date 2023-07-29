#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int M = 1e5 + 5;
int n, m, cost[M], dist[N], ans[N];
std::vector<int> st[N];
void f(){
    for (int v = 1; v <= n; v++){
        for (int i = 0; i < st[v].size(); i++){
            dist[v] = std::min(dist[st[v][i]] + cost[st[v][i]], dist[v]);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    memset(dist, INF, sizeof(dist));
    for (int i = 1; i <= n; i++){
        scanf("%d",&cost[i]);
    }
    for (int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        st[u].push_back(v);
    }
    f();
    for (int i = 1; i <= n; i++){
        if(dist[i] == INF){
            printf("No path.\n");
        }else{
            printf("%d \n", dist[i]);
            
        }
    }
    return 0;
}