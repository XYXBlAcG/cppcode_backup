#include <cstdio>
#include <algorithm>
const int N = 2010;
typedef unsigned long long llu;
int n, m;
int wall[N][N];
int super;
int normal;
int head[N];
struct Edge{
    int verx, very, nxt;
    int type;
}edge[N];
bool vis[N][N];//是否被访问过
bool anc[N][N];//是当前点的祖先或自己
void dfs(int x, int y){ 
    if(x < 1 || y < 1 || x > n || y > m) return;
    if(vis[x][y]){
        return;
    }
    vis[x][y] = 1;
    if(wall[x][y] == 1 && wall[x - 1][y] == 1 && vis[x - 1][y] == 0){
        // printf("x:%d y:%d x - 1\n", x, y);
        dfs(x - 1, y);
        normal++;
    }
    if(wall[x][y] == 1 && wall[x + 1][y] == 1 && vis[x + 1][y] == 0){
        // printf("x:%d y:%d x + 1\n", x, y);
        dfs(x + 1, y);
        normal++;
    }
    if(wall[x][y] == 1 && wall[x][y - 1] == 1 && vis[x][y - 1] == 0){
        // printf("x:%d y:%d y - 1\n", x, y);
        dfs(x, y - 1);
        normal++;
    }
    if(wall[x][y] == 1 && wall[x][y + 1] == 1 && vis[x][y + 1] == 0){
        // printf("x:%d y:%d y + 1\n", x, y);
        dfs(x, y + 1);
        normal++;
    }
    
}
   
 
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
int main(){
    n = read(); m = read();
    for (int i = 1; i <= n; i++){
        int a = 1;
        for (char c = getchar(); c > 32; c = getchar()){
            wall[i][a++] = (int)c - '0';
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(vis[i][j] == 0 && wall[i][j] == 1){
                super++;
                dfs(i, j);
            }
        }
    }
    printf("%d %d\n", super, normal);
    return 0;
}