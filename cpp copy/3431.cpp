#include <cstdio>
#include <algorithm>
typedef long long ll; 
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 21;
ll n, dis[N][N], vis[1 << N][N], ans = INF, rec[1 << N][N];
void floyd(){
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}
ll f(unsigned S, ll v){
    if(vis[S][v]) return rec[S][v]; vis[S][v] = 1;
    ll tmp = INF; unsigned TMP = S - (1 << v);
    if(!TMP) return rec[S][v] = dis[0][v];
    if(!S) return rec[S][v] = (!v ? 0 : INF);
    for (int i = 0; i < n; i++) if(TMP >> i & 1 && i != v) tmp = std::min(f(TMP, i) + dis[i][v], tmp);
    return rec[S][v] = tmp;
}
int main(){
    scanf("%lld",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lld", &dis[i][j]);
    floyd();
    ans = std::min(ans, f((1 << n) - 1, 0));
    printf("%lld\n", ans);
    return 0;
}