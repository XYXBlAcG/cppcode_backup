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
signed main(){
    scanf("%lld",&T);
    for (int i = 1; i <= T; i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        int g = gcd(a, c);
        if(b % g != 0) {printf("No solution\n"); continue;}
        ax = ay = 0;
        a /= g, b /= g, c /= g;
        exgcd(a, c, ax, ay);
        printf("%lldk+%lld\n", c, ((b * ax % c) + c) % c);
    }
    return 0;
}