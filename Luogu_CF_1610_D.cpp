#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, a[N], odd, ans, even, fac[N];
int qp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
void pre(){
    fac[0] = 1;
    for (int i = 1; i <= 2e5; i++){
        fac[i] = fac[i - 1] * i % mod;
    }
}
signed main(){
    scanf("%lld", &n);
    pre();
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= n; i++){
        if(a[i] & 1) odd++;
    }
    even = n - odd;
    ans = fac[even] * even % mod;
    ans *= fac[odd] * odd % mod;
    printf("%lld\n", ans);
    return 0;
}