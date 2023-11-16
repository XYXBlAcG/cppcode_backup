#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 2e5 + 5;
int t, n, cur, res, st, ed;
char ch[2][N];
bool vis[2][N];
int rec[2][N];
// int dp(int x, int y){
//     if(y == ed + 1) return 0;
//     if(vis[x][y]) return rec[x][y]; vis[x][y] = 1;
//     if(ch[0][y] == '*' && ch[1][y] == '*') return puts("!!!"), rec[x][y] = dp(!x, y + 1) + 1 + (y != ed);
//     if(ch[0][y] == '*') return puts("???"), rec[x][y] = dp(0, y + 1) + (x != 0) + (y != ed);
//     if(ch[1][y] == '*') return puts("..."), rec[x][y] = dp(1, y + 1) + (x != 1) + (y != ed);
//     puts("fuck");
//     return rec[x][y] = std::min(dp(0, y + 1), dp(1, y + 1)) + (y != ed);
// }
int dp(int x, int y){
    if(y == ed + 1) return 0;
    if(vis[x][y]) return rec[x][y]; vis[x][y] = 1;
    if(ch[0][y] == '*' && ch[1][y] == '*') return rec[x][y] = dp()
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%s%s", &n, ch[0], ch[1]), st = 0, ed = 0;
        for (int i = 0; i < n; i++)
            if(!st && (ch[0][i] == '*' || ch[1][i] == '*')) {st = i; break;}
        for (int i = n - 1; ~i; i--)
            if(!ed && (ch[0][i] == '*' || ch[1][i] == '*')) {ed = i; break;}
        // printf("st = %d, ed = %d\n", st, ed);
        printf("%d\n", std::min(dp(0, st), dp(1, st)));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 2; j++){
                printf("%d %d -> %d\n", j, i, rec[j][i]);
            }
        }
        for (int i = 0; i <= n; i++){
            vis[0][i] = vis[1][i] = rec[0][i] = rec[1][i] = 0;
        }
    }
    return 0;
}