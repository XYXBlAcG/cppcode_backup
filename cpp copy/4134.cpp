#include <cstdio>
#include <cmath>
#define int long long
int n, k, p;
int power(int x, int p, int q){
    long long ans = 1;
    for (; p; p >>= 1, x = x * x % q)
        if (p & 1) ans = ans * x % q;
    return ans;
}
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
int inv(int a, int mod){
    int x, y; int g = exgcd(a, mod, x, y);
    return (g != 1) ? 0 : (x % mod + mod) % mod;
}
signed main(){
    scanf("%lld%lld%lld",&n,&k,&p);
    int mod = power(p, k, 0x3f3f3f3f), ans = 1;
    int ca = 0, cb = 0, res = 1;
    for (int i = 1; i <= n; i++){
        int a, b;
        scanf("%lld%lld", &a, &b);
        int ta = a, tb = b;
        while(ta % p == 0) ta /= p, ca++;
        while(tb % p == 0) tb /= p, cb++;
        // printf("ca - cb = %lld\n", ca - cb);
        (res *= ta % mod * inv(tb, mod) % mod) %= mod;
        printf("%lld\n", ((power(p, ca - cb, mod) % mod) * res % mod));
        
    }
    return 0;
}