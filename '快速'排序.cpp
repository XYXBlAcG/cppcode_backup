#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 1e3 + 5, MOD = 1e9 + 7;
int x, y, n, m;
int rec[N][N], vis[N][N];
int chai(int x){
    int ans = 0;
    while(x) ans += x % 10, x /= 10;
    return ans;
}
int dp(int o, int p){
    if(!o) return (p == y);
    if(vis[o][p]) return rec[o][p];
    vis[o][p] = 1;
    int ans = 0;
    for (int i = 0; i < 7; i++)
        if(7 * p + i <= m) (ans += dp(o - 1, 7 * p + i)) %= MOD;
    (ans += dp(o - 1, chai(p))) %= MOD;
    return rec[o][p] = ans;
}
int main(){
    scanf("%d%d%d%d", &x, &y, &n, &m);
    printf("%d\n", dp(n, x));
    return 0;
}