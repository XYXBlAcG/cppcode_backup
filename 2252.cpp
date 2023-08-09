#include <cstdio>
const int mod = 1000000007, N = 35;
int n, m;
int a[N];
bool vis[N][N][N];
long long a1[N][N][N];
int d[N][10000];
// struct 
long long f(int i, int j, int k) {
    if (vis[i][j][k]) return a1[i][j][k];
    vis[i][j][k] = 1;
    if (i == j) return a1[i][j][k] = (a[i] % m == k) ? 1 : 0;
    for (int l = i; l < j; l++) {
        for (int o = 1; d[k][o] != -1; o += 2){
            (a1[i][j][k] += (f(i, l, d[k][o]) % mod * f(l + 1, j, d[k][o + 1]) % mod)) %= mod;
        }
    }
    return a1[i][j][k] %= mod;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++){
        int cnt = 0;
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                if(i == (j + k) % m) {
                    d[i][++cnt] = j;
                    d[i][++cnt] = k;
                }
                if(i == (j - k + m) % m) {
                    d[i][++cnt] = j;
                    d[i][++cnt] = k;
                }
                if(i == (j * k) % m) {
                    d[i][++cnt] = j;
                    d[i][++cnt] = k;
                }
            }
        }
        d[i][++cnt] = -1;
    }
    printf("%lld", f(1, n, 0));
    return 0;
}

// for (int l = i; l < j; l++) {
//     for (int p = 0; p < m; p++) {
//         for (int q = 0; q < m; q++) {
//             if (k == (p + q) % m) {
//                 a1[i][j][(p + q) % m] = (a1[i][j][(p + q) % m] + f(i, l, p) * f(l + 1, j, q)) % mod;
//             }
//             if (k == (p - q + m) % m) {
//                 a1[i][j][(p - q + m) % m] = (a1[i][j][(p - q + m) % m] + f(i, l, p) * f(l + 1, j, q)) % mod;
//             }
//             if (k == (p * q) % m) {
//                 a1[i][j][(p * q) % m] = (a1[i][j][(p * q) % m] + f(i, l, p) * f(l + 1, j, q)) % mod;
//             }
//         }
//     }
// }