#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#define int long long
const int N = 25;
int n, m, a[N], sum, ans;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), sum += a[i];
    if(sum < m) ans--;
    for (int i = 0; i < (1 << n); i++){
        int mn = INT_MAX, s = 0;
        for (int j = 1; j <= n; j++){
            if(i & (1 << (j - 1))) s += a[j];
            else mn = std::min(mn, a[j]);
        }
        if(s < m && s + mn >= m) ans++;
    }
    printf("%lld\n", std::max(ans, 1ll));
    return 0;
}
