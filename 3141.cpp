#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 510;
typedef unsigned long long llu;
int n, m, q, in;
int vis[N][N];
int cost[N][N];
int path[N][N];
int pre[N][N];
int dist[N][N];
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
void output(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if(i != k && cost[i][k] + dist[k][j] == dist[i][j]){
                    path[i][j] = k;
                    break;
                }
            }
        }
    }
}
void fprint(int u, int v){
    if (u == v)
        return;
    printf("%d ", path[u][v]);
    fprint(path[u][v], v);
}
int main() {
    dist[0][0] = INF;
    memset(path, INF, sizeof(path));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j){
                dist[i][j] = 0;
                cost[i][j] = 0;
            }else{
                dist[i][j] = INF;
                cost[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int u = 0, v = 0, w = 0;
        scanf("%d%d%d", &u, &v, &w);
        cost[u][v] = std::min(w, cost[u][v]);
        dist[u][v] = std::min(w, dist[u][v]);
    }
    floyd();
    output(); 
    for (int i = 1; i <= q; i++) {
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        // 
        if (dist[u][v] > 500000) {
            printf("-1\n");
            continue;
        } else
            printf("%d ", dist[u][v]);
        printf("%d ", u);
        fprint(u, v);
        // if(u != v) printf("%d ", v);
        printf("\n");

        // printf("%d ", u);
        // print(u, v);
        // if (u != v)
        //     printf("%d", v);
        // printf("\n");
    }
    return 0;
}
