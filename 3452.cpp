#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int N = 15, M = 1e5 + 3;
int n, m, a[N][M], k, id[N][M], vis[N][1 << N], rec[N][1 << N], ok[1 << N];
ll f(int i, unsigned S){
    if(i == n + 1) return 0;
    if(vis[i][S]) return rec[i][S]; vis[i][S] = 1;
    ll ans = INF;
    for (unsigned t = S; t; t = S & (t - 1))
        if(ok[S]) ans = std::min(ans, f(i - 1, S & ~t) + a[i][t]);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d",&a[i][j]);
    for (int i = 1; i <= n; i++){
        scanf("%d", &k); 
        for (int j = 1; j <= k; j++) scanf("%d", &id[i][j]);
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            
        }
    }
    

    printf("%lld\n", f(n, (1 << n) - 1));
    return 0;
}