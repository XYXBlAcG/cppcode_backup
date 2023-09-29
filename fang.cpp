#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
const int N = 25;
int l, r, k, num[N], rec[N][N * 10000];
int f(int i, int sum, int bp, bool lim){
    if(sum < 0) return 0;
    if(!i) return std::max(sum, 0ll);
    if(!lim && rec[i][sum]) return rec[i][sum];
    int top = lim ? num[i] : (k - 1), ans(0);
    for (int j = 0; j <= top; j++)
        ans += f(i - 1, sum + ((bp == 1) ? (j * (i - 1)) : \
        ((i < bp) ? -j : j)), bp, lim && (j == top));
    if(!lim) rec[i][sum] = ans;
    return ans;
}
int solve(int x){
    int ans(0), len(0);
    while(x) num[++len] = x % k, x /= k;
    memset(rec, 0, sizeof(rec));
    ans = f(len, 0, 1, 1);
    for (int i = 2; i <= len; i++)
        memset(rec, 0, sizeof(rec)), ans -= f(len, 0, i, 1);
    return ans;
}
signed main(){
    scanf("%lld%lld%lld", &l, &r, &k);
    printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}