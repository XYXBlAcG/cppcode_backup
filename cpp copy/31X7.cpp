#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
const int N = 305;
int n, m;
int dist[N][N], cost[N][N], dist2[N][N];
void floyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(dist[i][k] + dist[k][j] != cost[j][i])
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                else dist[i][j] = INF;
            }
        }
    }
}
int main(){
    memset(dist, INF, sizeof(dist));
    memset(cost, INF, sizeof(cost));
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v] = std::min(dist[u][v], w);
        cost[u][v] = std::min(cost[u][v], w);
        dist[v][u] = std::min(dist[v][u], w);
        cost[v][u] = std::min(cost[v][u], w);
    }
    floyd(); 
    // floyd2();
    int ans = INF;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(cost[j][i] != INF){
                ans = std::min(ans, dist[i][j] + cost[j][i]);
            }
        }
    }
    if(ans == INF) printf("No solution."); else printf("%d\n", ans);
    return 0;
}