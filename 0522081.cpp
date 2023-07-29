#include <cstdio>
#include <algorithm>
#define int unsigned long long
const int N = 1e6 + 5;
int n, k, a[N];
int solve(int sec){
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (sec / a[i]);
    return ans;
}
signed main(){
    freopen("ikun.in", "r", stdin);
    freopen("ikun.out", "w", stdout);
    scanf("%llu%llu", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%llu", a + i);
    std::sort(a + 1, a + 1 + n);
    int l = 1, r = 1e19, mid = 0;
    while(l < r){
        mid = (l + r + 1) >> 1;
        if(solve(mid) >= k) r = mid - 1;
        else l = mid;
    }
    while(solve(mid) < k) mid++;
    printf("%llu\n", mid);
    fclose(stdin);
    fclose(stdout);
    return 0;
}