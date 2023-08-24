#include <cstdio>
#include <algorithm>
#define int long long
using std::sort;
using std::unique;
using std::lower_bound;
const int N = 205;
int n, tx[N], ty[N], tz[N], x[2][N], y[2][N], z[2][N], cube[3][N], r[N], lx, ly, lz, ans;
int flag[N][N][N];
int sum[N][N][N];
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld%lld", &cube[0][i], &cube[1][i], &cube[2][i], r + i);
        tx[i] = cube[0][i] - r[i];
        tx[i + n] = cube[0][i] + r[i];
        ty[i] = cube[1][i] - r[i];
        ty[i + n] = cube[1][i] + r[i];
        tz[i] = cube[2][i] - r[i];
        tz[i + n] = cube[2][i] + r[i];
        x[0][i] = cube[0][i] + r[i], x[1][i] = cube[0][i] - r[i];
        y[0][i] = cube[1][i] + r[i], y[1][i] = cube[1][i] - r[i];
        z[0][i] = cube[2][i] + r[i], z[1][i] = cube[2][i] - r[i];
    }
    sort(tx + 1, tx + 1 + (n << 1));
    sort(ty + 1, ty + 1 + (n << 1));
    sort(tz + 1, tz + 1 + (n << 1));
    lx = unique(tx + 1, tx + 1 + (n << 1)) - tx - 1;
    ly = unique(ty + 1, ty + 1 + (n << 1)) - ty - 1;
    lz = unique(tz + 1, tz + 1 + (n << 1)) - tz - 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2; j++){
            x[j][i] = lower_bound(tx + 1, tx + lx + 1, x[j][i]) - tx;
            y[j][i] = lower_bound(ty + 1, ty + ly + 1, y[j][i]) - ty;
            z[j][i] = lower_bound(tz + 1, tz + lz + 1, z[j][i]) - tz;
        }
        flag[x[1][i]][y[1][i]][z[1][i]]++;
        flag[x[0][i]][y[1][i]][z[1][i]]--;
        flag[x[1][i]][y[0][i]][z[1][i]]--;
        flag[x[1][i]][y[1][i]][z[0][i]]--;
        flag[x[0][i]][y[0][i]][z[1][i]]++;
        flag[x[1][i]][y[0][i]][z[0][i]]++;
        flag[x[0][i]][y[1][i]][z[0][i]]++;
        flag[x[0][i]][y[0][i]][z[0][i]]--;
    }
    for (int i = 1; i <= 2 * n; i++){
        for (int j = 1; j <= 2 * n; j++){
            for (int k = 1; k <= 2 * n; k++){
                sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i - 1][j - 1][k] - sum[i][j - 1][k - 1] - sum[i - 1][j][k - 1] + sum[i - 1][j - 1][k - 1] + flag[i][j][k];
                if(sum[i][j][k]) {ans += (tx[i + 1] - tx[i]) * (ty[j + 1] - ty[j]) * (tz[k + 1] - tz[k]); }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}