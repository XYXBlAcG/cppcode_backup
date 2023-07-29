#include <cstdio>
#include <iostream>
#include <algorithm>
int m, n;
int map[110][110];
int vis[110][110];
int dp[110][110];
int down(int i, int j, int k, int o){
    if (i == m + 1 or k == m + 1){
        return -100000;
    }
    if (j == n + 1 or o == n + 1){
        return -100000;
    }
    if (i == k && j == o) return 0;
    if (i == m && j == n && k == m && o == n)return 0;
    dp[i][j] = std::max(std::max(down(i + 1, j, k + 1, o) , down(i, j + 1, k + 1, o)) , std::max(down(i + 1, j, k, o + 1) , down(i, j + 1, k, o + 1))) + map[i][j] + map[k][o];
    return dp[i][j];
}
int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            std::cin >> map[i][j];
        }
    }

    // int dow = down(1, 1, 1, 1);
    printf("%d\n",down(1, 1, 1, 1));
    return 0;
}