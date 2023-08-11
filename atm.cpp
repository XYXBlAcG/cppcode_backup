#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define int long long
const int N = 3e5 + 5;
int n, a[N], q, b[N], mon[N], num[N];
signed main(){
    freopen("atm.in", "r", stdin);
    freopen("atm.out", "w", stdout);
    scanf("%lld", &n);
    a[0] = INF;
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    scanf("%lld", &q);
    for (int i = 1; i <= q; i++) scanf("%lld", b + i);
    for (int i = 1; i < n; i++){
        int w = (a[i + 1] - 1 - mon[i]) / a[i];
        mon[i + 1] = mon[i] + w * a[i], num[i + 1] = num[i] + w;
    }
    for (int i = 1; i <= q; i++){
        int w = std::upper_bound(a + 1, a + 1 + n, b[i]) - a - 1;
        int tmp = (b[i] - mon[w]) / a[w];
        printf("%lld %lld\n", mon[w] + tmp * a[w], num[w] + tmp);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}