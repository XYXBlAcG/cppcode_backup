#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
int T, a, b, c;
int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = y;
    x = t;
    y = t - (a / b) * x;
    return d;
}
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
int read(){
    int x = 0, f = 1;
    char c = getchar();
    for (; c > '9' || c < '0'; c = getchar())
        if(c == '-') f = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x * f;
}
signed main(){
    T = read();
    while(T--){
        a = read(), b = read(), c = read();
        int ab = gcd(a, b);
        if(c % ab) {
            puts("-1");
            continue;
        }
        a /= ab, b /= ab, c /= ab;
        int x = 0, y = 0, res = exgcd(a, b, x, y);
        x *= ab, y *= ab;
        printf("%lld\n", res);
    }
    return 0;
}