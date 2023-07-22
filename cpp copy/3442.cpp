#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
typedef long long ll;
const int N = 102, M = 12;
int n, m, map[N][M]; bool vis[N][M * (1 << M)]; ll rec[N][M * (1 << M)], g[M][1 << M][1 << M], cnt;
ll f(int i, int j, unsigned S1, unsigned S2){
    // printf("i = %d, j = %d, S1 = %u, S2 = %u\n", i, j, S1, S2);
    if(!g[j][S1][S2]) g[j][S1][S2] = ++cnt;
    if(i > n) return 0;
    if(vis[i][g[j][S1][S2]]) return rec[i][g[j][S1][S2]]; vis[i][g[j][S1][S2]] = 1;
    ll ans = 0;
    if(j == m) return rec[i][g[j][S1][S2]] = f(i + 1, 0, S1, S2);
    ans = f(i, j + 1, S1 & ~(1 << j), (S2 & ~(1 << j)) | (((S1 >> j) & 1) << j));
    if(!((S1 << 2 >> j) & 3) && !map[i][j] && !(((S1 >> j) | (S2 >> j)) & 1)) 
        ans = std::max(f(i, j + 1, S1 | (1 << j), S2 & ~(1 << j) | (((S1 >> j) & 1) << j)) + 1, ans);
    // printf("ans = %lld\n", ans);
    return rec[i][g[j][S1][S2]] = ans;
}
int main(){
    scanf("%d%d ",&n,&m);
    for (int i = 1; i <= n; i++){
        std::string a;
        std::cin >> a;
        for (int j = 0; j < m; j++){
            map[i][j] = (a[j] == 'H');
        }
    }
    // for (int i = 1, j = 0; i <= n; i++, j = 0) 
    //     for (; j < m; j++){
    //         char tmp;
    //         scanf("%s", &tmp);
    //         map[i][j] = (tmp == 'H');
    //     }
    //     // for (char c = getchar(); c > 32; c = getchar(), j++) 
    //     //     map[i][j] = (c == 'H');
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j < m; j++){
    //         printf("%d ", map[i][j]);
    //     }putchar('\n');
    // }
    printf("%lld\n", f(1, 0, 0, 0));
    return 0;
}
