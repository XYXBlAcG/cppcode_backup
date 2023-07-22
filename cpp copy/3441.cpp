#include <cstdio>
typedef long long ll;
const int N = 2001, M = 13, mod = 998244353;
int map[N][M], n, m; ll rec[N][M][1 << M]; bool vis[N][M][1 << M];
ll f(int i, int j, unsigned S){
    if(i > n) return 1;
    if(vis[i][j][S]) return rec[i][j][S]; vis[i][j][S] = 1;
    if(j == m) return rec[i][j][S] = f(i + 1, 0, ((S & (1 << m) - 1) << 1)) % mod;
    rec[i][j][S] = f(i, j + 1, S & (~(1 << j)));
    if(!(S << 1 >> j & 15) && !map[i][j]) rec[i][j][S] += f(i, j + 1, S | (1 << j)); 
    return rec[i][j][S] %= mod;
}
int main(){
    scanf("%d%d ",&n,&m);
    for (int i = 1, j = 0; i <= n; i++, j = 0) for (char c = getchar(); c > 32; c = getchar(), j++) map[i][j] = (c == '1');
    printf("%lld\n", f(1, 0, 0));
    return 0;
}