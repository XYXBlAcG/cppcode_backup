#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define inf 0x3f3f3f3f
#define de(x) std::cout << #x << " = " << x << std::endl
const int N = 55;
int m, n;
int map[N][N];
bool vis[N][N][N][N];
int dp[N][N][N][N];
int down(int i, int j, int k, int o){
    if (i >= m + 1 or k >= m + 1) return -inf;
    if (j >= n + 1 or o >= n + 1) return -inf;
    if (i == m && j == n && k == m && o == n) return 0;
    if (i == k && j == o && (i != 1 || j != 1)) return -inf;
    if(vis[i][j][k][o]) return dp[i][j][k][o];
    vis[i][j][k][o] = 1;
    dp[i][j][k][o] = \
    std::max(std::max(down(i + 1, j, k + 1, o)\
     , down(i, j + 1, k + 1, o)) \
    , std::max(down(i + 1, j, k, o + 1)\
     , down(i, j + 1, k, o + 1)))\
     + map[i][j] + map[k][o];
    // printf("%d %d %d %d\n", i, j, k, o);
    return dp[i][j][k][o];
}
int main(){
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    // int dow = down(1, 1, 1, 1);
    printf("%d\n", down(1, 1, 1, 1) - map[m][n]);
    return 0;
}