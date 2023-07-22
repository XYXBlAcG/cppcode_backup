#include <cstdio>
const int N = 9;
int n, m, ans, t;
int color[N][N];
void dfs(int x, int y){
    if (x == n){
        ++ans;
        return;
    }
    int x1 = x, y1 = y + 1;
    if (y1 == m){
        x1++;
        y1 = 0;
    }
    color[x][y] = 0;//blue
    dfs(x1,y1);
    int ok = 1;
    if(color[x-1][y] == 1 || color[x-1][y] == 2 || x == 0){//red
        ok = 0;
    }
    if(color[x][y-1] == 1 || color[x][y-1] == 2 || y == 0){//red
        ok = 0;
    }
    
    if (ok){
        // for (color[x][y] = 0; color[x][y] <= 1; color[x][y]++){
            color[x][y] = 1;//red
            // printf("%d ",color[x][y]);
            dfs(x1,y1);
            color[x][y] = 2;
        // }
        
    }
}
int main(){
    
    scanf("%d%d%d",&n,&m,&t);
    int ax,ay;
    for (int i = 0; i <= n + 1; i++){
        for (int x = 0; x <= m + 1; x++){
            color[i][x] = 1;
        }
        
    }
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= m; x++){
            color[i][x] = 0;
        }
        
    }
    for (int i = 1; i <= t; i++){
        scanf("%d%d",&ax,&ay);
        color[ax][ay] = 0;
    }
    dfs(0,0);
    printf("%d\n",ans);
}