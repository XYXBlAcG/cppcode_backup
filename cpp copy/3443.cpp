#include <cstdio>
typedef long long ll;
const ll N = 2003, M = 13, mod = 998244353;
int n, m, map[N][M], rec[2][1 << M], m4to3[1 << M], m3to4[1 << M]; bool vis[2][1 << M];
void dfs(int d, unsigned x3, unsigned x4){
    if(d == n) m4to3[x4] = x3, m3to4[x3] = x4;
    else for (int i = 0; i <= 2; i++) dfs(d + 1, x3 * 3 + i, x4 << 2 | i);
}
int add(unsigned S, int i, int x){
    return m4to3[m3to4[S] + (x << (i << 1))];
}
int get(unsigned S, int u){
    return (m3to4[S] >> (u << 1)) & 3;
}
int main(){
    scanf("%d%d ",&n,&m);
    for (int i = 1, j = 0; i <= n; i++, j = 0) for (char c = getchar(); c > 32; c = getchar(), j++) map[i][j] = c;
    dfs(0, 0, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (unsigned S = (1 << m) - 1; S >= 0; ){
                
            }
        }
    }
    return 0;
}