#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 2010;
typedef unsigned long long llu;
int map[N][N];
int dist[N][N];
int n, m, q;
int bfs(int sx, int sy){
    return -1;
}
int main(){
    scanf("%d%d%d", &n, &m, &q);
    int t;
    memset(map, -1, sizeof(map));
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &t);
            map[i][j] = t + 1; // 0 block 1 walk
        }
    }
    for (int i = 1; i <= q; i++){
        int sx = 0, sy = 0;
        scanf("%d%d", &sx, &sy);
        printf("%d\n", bfs(sx, sy));
    }
    return 0;
}