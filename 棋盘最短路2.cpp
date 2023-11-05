#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
const int N = 2005;
int n, m, mp[N][N], dist[N][N], ans = INF;
struct Pos{
    int x, y, dis;
    bool operator==(Pos a) const{
        return a.x == x && a.y == y;
    }
}ed;
std::queue<Pos> q;
bool chk(int i, int j){
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
void bfs(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dist[i][j] = INF;
        }
    }
    q.push({1, 1, mp[1][1]});
    while(q.size()){
        Pos u = q.front(); q.pop();
        if(u == ed){ans = std::min(ans, u.dis);}
        for (int i = 0; i < 4; i++){
            int tx = u.x + "1120"[i] - '1', ty = u.y + "0211"[i] - '1';
            Pos t = {tx, ty, u.dis + mp[tx][ty]};
            if(t.dis >= dist[tx][ty]) continue;
            dist[tx][ty] = t.dis;
            if(chk(tx, ty)) q.push(t);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m), ed = {n, m, 0};
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &mp[i][j]);
        }
    }
    bfs();
    printf("%d\n", ans);
    return 0;
}