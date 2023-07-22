#include <cstdio>
#include <algorithm>
#define int long long
const int N = 605, mod = 1000000007;
int n, mx[N][N];
int power(int x, int p, int q){
    long long ans = 1;
    for (; p; p >>= 1, x = x * x % q)
        if (p & 1) ans = ans * x % q;
    return ans;
}
void solve(){
    int flag = 0;
    for (int i = 1; i <= n; i++){
        flag = i;
        for (int j = i + 1; j <= n; j++) if(mx[j][i] > mx[flag][i]) flag = j;
        std::swap(mx[i], mx[flag]);
        if(!mx[i][i]) {puts("No solution"); return;}
        int tmp = power(mx[i][i], mod - 2, mod);
        for (int j = 1; j <= n; j++){
            if(j == i) continue;
            int tmp2 = tmp * mx[j][i];
            for (int k = i; k <= n * 2; k++)
                mx[j][k] = ((mx[j][k] - (tmp2 % mod) * mx[i][k]) % mod + mod) % mod;
        }
        for (int j = 1; j <= n * 2; j++)
            mx[i][j] = mx[i][j] * tmp % mod;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= n * 2; j++)
            printf("%lld ", mx[i][j]);
        putchar('\n');
    }
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &mx[i][j]);
    for (int i = 1; i <= n; i++)
        mx[i][i + n] = 1;
    solve();
    return 0;
}