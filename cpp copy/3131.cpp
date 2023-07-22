#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
const int E = 2e6 + 5;
const int P = 3000 + 5;
typedef unsigned long long llu;
int n, m;
int dist[P], from[P];
bool used[E];
int edge[P][P];
int dijkstra(int s){
    for (int i = 0; i <= n; i++){
        dist[i] = INF;
    }dist[s] = 0;
    while(true){
        int v = 0;
        for (int j = 1; j <= n; j++){
            if(!used[j] && dist[v] > dist[j]){
                v = j;
            }
        }
        if(v == 0){
            break;
        }
        used[v] = 1;
        for (int u = 1; u <= n; u++){
            if(dist[u] > dist[v] + edge[v][u]){
                dist[u] = dist[v] + edge[v][u];
                from[u] = v;
            }else if(dist[u] == dist[v] + edge[v][u]){
                if(from[u] > v) from[u] = v; 
            }
        }
    }
    return dist[1];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(edge, INF, sizeof(edge));
    memset(from, INF, sizeof(from));
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0, w = 0;
        scanf("%d%d%d",&v,&u,&w);
        if(edge[u][v])
            edge[u][v] = std::min(edge[u][v], w);
        else
            edge[u][v] = w;
    }
    
    int a = dijkstra(n);
    if(a == INF) {
        printf("-1\n");
    }else{
        printf("%d\n",a);
        for (int i = 1; i != n; i = from[i]){
            printf("%d ", i);
        }
        printf("%d ", n);
    }

    return 0;
}