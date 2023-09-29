#include <cstdio>
#include <cstring>
#define int long long
#define az [a][b][c][d][e][lim]
const int N = 65;
int n, k, op, num[N], len, f[N][N][2][2][4][4], vis[N][N][2][2][4][4];
int dp(int a, int b, int c, int d, int e, int lim){
    int ans = 0;
    if(b > k) return 0;
    if(a == ((n + 1) >> 1)){
        if(n & 1){
            for (int i = 0; i <= 1; i++){
                int mid = (n >> 1) + 1;
                if((lim == 2 && i >= num[mid]) || (lim == 1 && i > num[mid])) break;
                ans += ((b + (c ^ i) + (d ^ i)) <= k);
            }return ans;
        }else return (lim == 2) ? 0 : ((b + (c ^ d)) <= k);
    }
    if(vis az) return f az; vis az = 1;
    for (int i = 0; i < 4; i++){
        int tx = "1010"[i] - '0', ty = "1100"[i] - '0';
        if(e && (tx > ty)) continue;
        if(lim && tx > num[a]) continue;
        if(!lim) ans += dp(a - 1, b + (a < n) * ((c ^ tx) + (d ^ ty)), tx, ty, e && (tx == ty), 0); 
        else ans += dp(a - 1, b + (a < n) * ((c ^ tx) + (d ^ ty)), tx, ty, e && (tx == ty), ((num[a] > tx) ? 0 : ((ty > num[n - a + 1]) ? 2 : ((ty < num[n - a + 1]) ? 1 : lim))));
    }
    return f az = ans;
}
int solve(int x){
    for (int i = 1; i <= n; i++) num[i] = x & 1, x >>= 1;
    memset(vis, 0, sizeof(vis));
    memset(f, 0, sizeof(f));
    return dp(n, 0, 0, 0, 1, 1);
}
signed main(){
    scanf("%lld%lld%lld", &n, &k, &op);
    int l = 0, r = (1ll << n) - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(solve(mid) < op) l = mid + 1;
        else r = mid - 1;
    }r++;
    if(solve(r) < op) puts("NO SUCH STONE");
    else{
        for (int i = n; i; i--)
            printf((r >> (i - 1) & 1) ? "X" : "I");
        putchar('\n');
    }
    return 0;
}
