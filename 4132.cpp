#include <cstdio>
#include <algorithm>
long long n, k, ans;
int main(){
    scanf("%lld%lld",&n,&k);
    for (long long l = 1, t, r; l <= n; l = r + 1){
        t = k / l;
        r = t ? std::min(k / t, n) : n;
        ans += ((r - l + 1) * t * (l + r)) >> 1;
    }
    printf("%lld\n", n * k - ans);
    return 0;
}