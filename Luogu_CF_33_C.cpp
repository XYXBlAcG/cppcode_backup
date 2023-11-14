#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e5 + 5;
int n, a[N], ans, dp[N], sum;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), sum += a[i];
    if(n == 1) return printf("%lld\n", std::abs(a[1])), 0;
    for (int i = 1; i <= n; i++)
        dp[i] = std::max(dp[i], dp[i - 1] + a[i]), ans = std::max(ans, dp[i]);
    printf("%lld\n", ans * 2 - sum);
    return 0;
}