#include <cstdio>
typedef long long ll;
const ll N = 10, M = 1 << 10;
int n, k, vis[N][N][M][N * N]; ll rec[N][N][M][N * N];
ll f(int i, int j, unsigned S, int s){
    if(s == k) return 1; if(i > n && s != k) return 0;
    if(vis[i][j][S][s]) return rec[i][j][S][s]; vis[i][j][S][s] = 1;
    return rec[i][j][S][s] = (j == n) ? f(i + 1, 0, ((S & (1 << n) - 1) << 1), s) : (f(i, j + 1, S & (~(1 << j)), s) + ((S << 1 >> j & 15) ? 0 : f(i, j + 1, S | (1 << j), s + 1)));
}
int main(){
    scanf("%d%d",&n,&k), printf("%lld\n", f(1, 0, 0, 0)); 
    return 0;
}