#include <cstdio>
typedef long long ll;
const ll N = 1e3 + 5, M = (1 << 10), mod = 1000000007;
int n, m; bool vis[M][N], map[N][12]; ll rec[M][N];
ll f(unsigned Sy, ll x){
    if(Sy == (1 << m) - 1) return 1;
    if(x > n && Sy != (1 << m) - 1) return 0;
    if(vis[Sy][x]) return rec[Sy][x]; vis[Sy][x] = 1;
    for (int i = 0; i < m; i++) if(!((Sy >> i) & 1) && !map[x][i]) (rec[Sy][x] += f(Sy | (1 << i), x + 1)) %= mod;
    return (rec[Sy][x] += f(Sy, x + 1)) %= mod;
}
int main(){
    scanf("%d%d ",&n,&m);
    for (int i = 1, j = 0; i <= n; i++, j = 0) for (char c = getchar(); c > 32; c = getchar(), j++) map[i][j] = (c == '1');
    printf("%lld\n", f(0, 1) % mod);
    return 0;
}