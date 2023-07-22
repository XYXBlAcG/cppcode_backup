#include <cstdio>
#include <algorithm>
typedef long long ll;
const ll N = 21, INF = 0x3f3f3f3f;
int n, w[N][N], cnt[1 << N], vis[1 << N]; ll rec[1 << N];
ll f(unsigned S){
    if(vis[S]) return rec[S]; vis[S] = 1;
    for (int i = 0; i < n; i++) if(!((S >> i) & 1)) rec[S] = std::max(rec[S], f(S | (1 << i)) + w[cnt[S] + 1][i]);
    return rec[S];
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) for (int j = 0; j < n; j++) scanf("%d",&w[i][j]);
    for (unsigned i = 1; i < (1 << n) - 1; i++) cnt[i] = cnt[i & (i - 1)] + 1;
    printf("%lld\n", f(0));
    return 0;
}