#include <cstdio>
#define int long long
int T, a, b, c;
int exgcd(int a, int b, int& x, int& y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int tmp = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return tmp;
}
int gcd(int a, int b) {return b ? gcd(b, a % b) : a; }
signed main(){
    scanf("%lld", &T);
    while(T--){
        scanf("%lld%lld%lld", &a, &b, &c);
        int ax = 0, ay = 0, fuck = gcd(a, c);
        if(b % fuck) {puts("No solution"); continue;}
        a /= fuck, b /= fuck, c /= fuck;
        exgcd(a, c, ax, ay);
        int az = (b * ax);
        printf("%lldk+%lld\n", c, (az % c + c) % c); 
    }
    return 0;
}