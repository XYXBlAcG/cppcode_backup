#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define int long long
#define deb(x) std::cout << #x << " = " << x << std::endl
const int mod = 1000000007, N = 305, M = 1e5;
int t, n, visf[N][N], recf[N][N], visg[N][N], recg[N][N], ans, sum[N];
int f(int i, int j){
    if(i < 0 or j < 0) return 0;
    // deb(i), deb(j);
    if(i == 0){
        if(j == 0) return 1;
        return 0;
    }
    if(visf[i][j]) return recf[i][j];
    visf[i][j] = 1;
    return recf[i][j] = (f(i - 1, j - ceil(sqrt(n))) + f(i, j - i)) % mod;
}
int g(int i, int j){
    if(i < 0 or j < 0) return 0;
    // deb(i), deb(j);
    if(i == 0){
        if(j == 0) return 1;
        return 0;
    } if(j == 0) return 1;
    if(visg[i][j]) return recg[i][j];
    visg[i][j] = 1;
    return recg[i][j] = (g(i - 1, j) + g (i, j - 1)) % mod;
}
signed main(){
    scanf("%lld", &t);
    for (int j = 0; j <= floor(sqrt(M)); j++){
        (sum[j] = sum[(j - 1 > 0) ? j - 1 : 0] + f(j, n)) %= mod;
    }
    for (int i = 1; i <= t; i++){
        scanf("%lld", &n);
        
        printf("f = %lld, g = %lld\n", ans, g(floor(sqrt(n)), n));
        (ans *= g(floor(sqrt(n)), n)) %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}