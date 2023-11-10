#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e6 + 5;
int n, a[N], ans;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    std::sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++){
        int b = 1, len = 1;
        while(a[i] >= b * 10) b *= 10, len++;
        ans += i + len * (i - 1) - (std::lower_bound(a + 1, a + i, b * 10 - a[i]) - a);
    }
    printf("%lld\n", ans);
    return 0;
}