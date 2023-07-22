#include <cstdio>
#include <cstring>
using namespace std;
const int maxa = 40, maxb = 1010, mod = 1e9 + 7;
int n, m, a[maxa];
long long a1[maxa][maxa][maxb];
bool vis[maxa][maxa][maxb];
long long f(int i, int j, int k) {
    if (vis[i][j][k]) {
        return a1[i][j][k];
    }
    vis[i][j][k] = true;
    if (i == j) {
        a1[i][j][k] = (a[i] % m == k) ? 1 : 0;
        return a1[i][j][k];
    }
    for (int l = i; l < j; ++l) {
        for (int p = 0; p < m; ++p) {
            for (int q = 0; q < m; ++q) {
                int tmp = (p + q) % m;
                if (k == tmp) {
                    a1[i][j][k] = (a1[i][j][k] + f(i, l, p) * f(l + 1, j, q)) % mod;
                }
                tmp = (p - q + m) % m;
                if (k == tmp) {
                    a1[i][j][k] = (a1[i][j][k] + f(i, l, p) * f(l + 1, j, q)) % mod;
                }
                tmp = (p * q) % m;
                if (k == tmp) {
                    a1[i][j][k] = (a1[i][j][k] + f(i, l, p) * f(l + 1, j, q)) % mod;
                }
            }
        }
    }
    return a1[i][j][k];
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("%lld", f(1, n, 0));
    return 0;
}
