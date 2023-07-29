#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 505;
int n, m, q;
struct Node{
    int dis, k;
}dist[N][N];

int cost[N][N], path[N][N];
void floyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(dist[i][j].dis == INF){
                    dist[i][j].k = std::min(dist[i][k].k, std::min(dist[k][j].k, std::max(i, j)));
                }
                if(dist[i][k].dis + dist[k][j].dis < dist[i][j].dis || \
                (dist[i][k].dis + dist[k][j].dis == dist[i][j].dis && dist[i][j].k > k)){
                    dist[i][j].dis = dist[i][k].dis + dist[k][j].dis;
                    dist[i][j].k = std::min(dist[i][k].k, std::min(dist[k][j].k, k));
                }
            }
        }
    }
}
void getAns(int u, int v){
    if(dist[u][v].k > n || u == v) return;
    printf("当前解决从%d->%d的子问题,对于k为%d的情况\n",u,v,dist[u][v].k); fflush(stdout);
    getAns(u, dist[u][v].k);
    printf("%d ", dist[u][v].k);
    getAns(dist[u][v].k, v);
}
void init(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cost[i][j] = dist[i][j].dis = INF;
            dist[i][j].k = INF;
        }cost[i][i] = dist[i][i].dis = 0;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    init();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        cost[u][v] = std::min(w, cost[u][v]);
        dist[u][v].dis = std::min(w, dist[u][v].dis);
    }
    floyd();
    for(int i = 1; i <= q; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        if(dist[u][v].dis >= (INF >> 1)){
            printf("-1\n"); continue;
        }else{
            printf("%d ", dist[u][v].dis);
            printf("%d ", u);
            getAns(u, v); 
            printf("\n");
        }
    }
    return 0;
}