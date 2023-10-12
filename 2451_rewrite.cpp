#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e6 + 5;
int n, h[N], l[N], r[N], s[N], ps, ans;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", h + i);
        r[i] = n + 1;
        while(ps && h[s[ps]] > h[i]) r[s[ps--]] = i;
        s[++ps] = i, l[i] = s[ps - 1];
    }
    for (int i = 1; i <= n; i++) ans = std::max(ans, (r[i] - l[i] - 1) * h[i]);
    printf("%lld\n", ans);
    return 0;
}