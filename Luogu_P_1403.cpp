#include <cstdio>
#define int long long
int n, ans;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        ans += n / i;
    printf("%lld\n", ans);
    return 0;
}