#include <cstdio>
#define d double
const int N = 1e5 + 5;
d n, vis[2][N], _f[N], _g[N];
d f(int x){if(x >= n) return 0; if(vis[0][x]) return _f[x]; vis[0][x] = 1; return _f[x] = f(x + 1) + n / (n - x);}
d g(int x){if(x >= n) return 0; if(vis[1][x]) return _g[x]; vis[1][x] = 1; return _g[x] = g(x + 1) + f(x + 1) + x / (n - x) * f(x) + n / (n - x);}
int main(){
    scanf("%lf", &n), f(0);
    printf("%.2lf\n", g(0));
    return 0;
}