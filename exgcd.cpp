#include <cstdio>
#define int long long
int a, b, c, T, ax, ay;
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
int power(int a, int n, int mod){
    a %= mod;
    int ans = 1;
    for (; n > 0; n >>= 1){
        if(n & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
    }
    return ans;
}
int inv(int a, int mod){
    return power(a, mod - 2, mod);
}
int inv2(int a, int mod){
    int x, y; int g = exgcd(a, mod, x, y);
    return (g != 1) ? -1 : (x % mod + mod) % mod;
}
signed main(){
    int tma = 0, tmb = 0;
    scanf("%lld%lld", &tma, &tmb);
    exgcd(tma, tmb, ax, ay);
    printf("%lld %lld\n", ax, ay);
    return 0;
}