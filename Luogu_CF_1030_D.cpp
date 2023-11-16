#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
int n, m, k, on, om, ok;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &k), on = n, om = m, ok = k;
    if(n * m * 2 % k) return puts("NO"), 0;
    puts("YES");
    if((k & 1) == 0) k >>= 1;
    int gc = gcd(n, k);
    n /= gc, m /= (k / gc);
    printf("%d %d\n", 0, 0);
    if(ok & 1){
        if(n * 2 <= on) n *= 2;
        else m *= 2;
    }
    printf("%lld %d\n", n, 0);
    printf("%d %lld\n", 0, m);
    return 0;
}