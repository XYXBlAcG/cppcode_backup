#include <cstdio>
int n, m;
int a[40];
int vis[40][40][40];
long long a1[40][40][40];
int pqsum[40][40];
int pqmin[40][40];
int pqtim[40][40];
// struct 
long long f(int i, int j, int k) {
    // int res = 0;
    if (vis[i][j][k])
        return a1[i][j][k];
    vis[i][j][k] = 1;
    if (i == j) {
        a1[i][j][k] = (a[i] % m == k) ? 1 : 0;
        return a1[i][j][k];
    }
    for (int l = i; l < j; l++) {
        for (int p = 0; p < m; p++) {
            for (int q = 0; q < m; q++) {
                if (k == (p + q) % m) {
                    a1[i][j][(p + q) % m] = (a1[i][j][(p + q) % m] + f(i, l, p) * f(l + 1, j, q)) % 1000000007;
                }
                if (k == (p - q + m) % m) {
                    a1[i][j][(p - q + m) % m] = (a1[i][j][(p - q + m) % m] + f(i, l, p) * f(l + 1, j, q)) % 1000000007;
                }
                if (k == (p * q) % m) {
                    a1[i][j][(p * q) % m] = (a1[i][j][(p * q) % m] + f(i, l, p) * f(l + 1, j, q)) % 1000000007;
                }
            }
        }
    }

    return a1[i][j][k];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int p = 0; p < m; p++) {
            for (int q = 0; q < m; q++) {
                pqsum[p][q] = p + q;
                pqmin[p][q] = p - q;
                pqtim[p][q] = p * q; 

            }
    }
    printf("%lld", f(1, n, 0));
    return 0;
}