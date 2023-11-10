#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e5 + 5;
int t, n, k, num[N], di, ans;
bool cmp(int a, int b){return a > b;}
signed main(){
    scanf("%lld", &t);
    while(t--){
        ans = 0, di = 1, scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", num + i);
        for (int i = 1; i <= n; i++){
            if(num[i] >= k) ans += num[i] - k;
            else di *= 2, ans += num[i] / di;
        }
        printf("%lld\n", ans);
    }
    return 0;
}