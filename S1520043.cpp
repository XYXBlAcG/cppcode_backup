#include <cstdio>
#define int long long
int t, a, b, n;
signed main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld", &a, &b, &n);
        int ans = 0;
        for (int i = b + a; i <= b + n * a; i += a) {
            ans += __builtin_popcountll(i);
        }
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}