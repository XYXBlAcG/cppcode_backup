#include <cstdio>
#include <algorithm>
const int N = 1e3 + 5;
typedef unsigned long long llu;
int n, m;
bool board[N][N], vis[N][N]; //0 wall 1 space 
int sx, sy, ex, ey;
int res[N][N];
struct Node{
    int x, y;
}que[N * N];
int l = 0, r = 1;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(){
    int x = 0, y = 0;
    que[l] = (Node){sx, sy};
    while(l < r){
        int tmpx = que[l].x, tmpy = que[l].y; 
        // printf("tmpx = %d, tmpy = %d\n", tmpx, tmpy);
        for (int i = 0; i <= 3; i++){
            x = tmpx + dir[i][0];
            y = tmpy + dir[i][1];
            if(x >= 1 && x <= n && y >= 1 && y <= m && board[x][y] && !vis[x][y]){
                // printf("in x:%d y:%d\n", x, y);
                if(x == ex && y == ey){
                    return res[tmpx][tmpy] += 1;
                }
                vis[x][y] = 1;
                que[r++] = (Node){x, y};
                res[x][y] = res[tmpx][tmpy] + 1;
            }
        }
        l++;
    }
    return -1; 
}
int main(){
    scanf("%d%d ",&n,&m);
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for (char c = getchar(); c > 32; c = getchar()){
            if(c == '.')
                board[i][++cnt] = 1;
            else if(c == '*')
                board[i][++cnt] = 0;
            else if(c == 'S'){
                sx = i; sy = ++cnt;
                board[i][cnt] = 1;
            }else if(c == 'T'){
                ex = i; ey = ++cnt;
                board[i][cnt] = 1;
            }
        }
    }
    printf("%d",bfs());
    


    return 0;
}