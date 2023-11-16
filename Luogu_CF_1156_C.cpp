#include <cstdio>
#include <algorithm>
#define int long long
const int N = 4e5 + 5;
int n, z, x[N];
bool chk(int a){
    for (int i = 1; i <= a; i++)
        if(x[n - a + i] - x[i] < z) return 0;
    return 1;
}
int bin(){
    int l = 0, r = n >> 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
signed main(){
    scanf("%lld%lld", &n, &z);
    for (int i = 1; i <= n; i++) scanf("%lld", x + i);
    std::sort(x + 1, x + 1 + n);
    printf("%lld\n", bin());
    return 0;
}