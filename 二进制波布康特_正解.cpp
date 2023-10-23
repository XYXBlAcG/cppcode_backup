#include <bits/stdc++.h>
#define t long long
const t N = 1e5 + 5;
t n, a[N], k, p[2][N], f[N][63];
bool c(t x, t y){return (x & ((1ll << k) - 1)) < (y & ((1ll << k) - 1));}
void m(t &x, t y){x = std::min(x, y);}
int main(){
    freopen("bin.in", "r", stdin), freopen("bin.out", "w", stdout), scanf("%lld", &n), memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (t i = 1; i <= n; i++) scanf("%lld", a + i);
    for (k = 0; k <= 61; k++){
        std::sort(a + 1, a + 1 + n, c);
        for (t i = 1; i <= n; i++) p[0][i] = p[0][i - 1], p[1][i] = p[1][i - 1], p[(a[i] >> k) & 1][i]++;
        for (t i = 0; i <= n; i++) {
            m(f[p[1][n] - p[1][n - i]][k + 1], f[i][k] + p[0][n] - p[0][n - i] + p[1][n - i]);
            m(f[n - p[0][n - i]][k + 1], f[i][k] + p[1][n] - p[1][n - i] + p[0][n - i]);
        }
    }
    return printf("%lld\n", f[0][62]), fclose(stdin), fclose(stdout), 0;
}