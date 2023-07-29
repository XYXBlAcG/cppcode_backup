#include <cstdio>
#include <vector>
#include <cstring>
const int N = 2005;
int n, m;
int map[N][N];
bool vis[N][N];
int dist[N][N];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct Node{
    int x, y;
}tong[10][N * N];
int cnt[11];
int l = 0, r = 1;
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
void bfs(){
    int x = 1, y = 1;
    dist[1][1] = map[1][1];
    tong[l][++cnt[l]] = ((Node){1, 1});
    while(!vis[n][m]){ 
        // if(que[l % 10].empty()) l++;
        // while(que[l % 10].empty()) l++;
        // if(l == 10) return;
        // if(l >= r) break;
        while (cnt[l]){
            int tmpx = tong[l][cnt[l]].x, tmpy = tong[l][cnt[l]].y;
            tong[l][cnt[l]--] = (Node){0, 0};
            for (int i = 0; i <= 3; i++){
                x = tmpx + dir[i][0];
                y = tmpy + dir[i][1];
                if(x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y]){
                    vis[x][y] = 1;
                    if(tmpx == n && tmpy == m){
                        dist[n][m] += map[n][m];
                        return;
                    }
                    if(dist[tmpx][tmpy] + map[x][y] < dist[x][y]){
                        dist[x][y] = dist[tmpx][tmpy] + map[x][y];
                        int tt = (l + map[x][y]) % 10;
                        tong[tt][++cnt[tt]] = ((Node){x, y});
                        // que[r++]. = (Node){x, y};
                    }
                }
            }
        }
        ++l %= 10;
    }
    // return dist[n][m];
}
int main(){
    n = read(); m = read();
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            map[i][j] = read();
        }
    }bfs();
    printf("%d ", dist[n][m]);
    return 0;
}