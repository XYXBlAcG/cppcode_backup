#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
int lcm(int a, int b){return a * b / gcd(a, b);}
int n, k, lc = 1, v;
signed main(){
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v);
        if(!lc) break;
        lc = lcm(lc, v);
        lc %= k;
    }
    puts(lc ? "No" : "Yes");
    return 0;
}