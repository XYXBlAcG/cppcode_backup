#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int m, n;
int map[N][N];
int vis[N][N][N][N];
int dp[N][N][N][N];

int down(int i, int j, int k, int o){
    if (i == m + 1 || k == m + 1 || j == n + 1 || o == n + 1){
        return -10000000;
    }
    if (i == k && j == o) {
        return map[i][j];
    }
    if (i == m && j == n && k == m && o == n) {
        return map[i][j];
    }
    if (vis[i][j][k][o]) {
        return dp[i][j][k][o];
    }
    vis[i][j][k][o] = 1;
    dp[i][j][k][o] = max(max(down(i + 1, j, k + 1, o) , down(i, j + 1, k + 1, o)) , max(down(i + 1, j, k, o + 1) , down(i, j + 1, k, o + 1))) + map[i][j] + map[k][o];
    return dp[i][j][k][o];
}

int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", down(1, 1, 1, 1));
    return 0;
}
