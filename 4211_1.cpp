#include <cstdio>
#include <cstring>
#define int long long
const int N = 2e3 + 5;
int t, n, m, q, rec[N][N], vis[N][N];
int c(int m, int n){
    if(vis[m][n]) return rec[m][n]; vis[m][n] = 1;
    if(m == 0 && n == 0) return 1;
    if(n == 0) return 0;
    if(m == 0) return 1;
    return rec[m][n] = (c(m, n - 1) + c(m - 1, n - 1)) % q;
}
signed main(){
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++){
        memset(vis, 0, sizeof(vis));
        memset(rec, 0, sizeof(rec));
        scanf("%lld%lld%lld", &n, &m, &q);
        printf("%lld\n", c(m, n) % q);
    }
    return 0;
}
