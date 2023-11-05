#include <cstdio>
#include <algorithm>
#define int long long
int n, k, ans;
signed main(){
    scanf("%lld%lld", &n, &k);
    for (int i = 1, j, t; i <= n; i = j + 1){
        t = k / i;
        j = t ? std::min(k / t, n) : n;
        ans += t * (j - i + 1) * (j + i) / 2;
    }
    printf("%lld\n", n * k - ans);
    return 0;
}