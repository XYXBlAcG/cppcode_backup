#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define EPS 1e-6
const int N = 105;
typedef double d;
int n;
d a[N][N], ans[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n + 1; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++){
        int m = i;
        for (int j = i + 1; j <= n; j++)
            if(fabs(a[m][i]) < fabs(a[j][i])) m = j;
        if(fabs(a[m][i]) < EPS) {
            puts("No Solution");
            return 0;
        }
        if(m ^ i) std::swap(a[m], a[i]);
        d div = a[i][i];
        for (int j = i; j <= n + 1; j++)
            a[i][j] /= div;
        for (int j = i + 1; j <= n; j++){
            div = a[j][i];
            for (int k = i; k <= n + 1; k++){
                a[j][k] -= a[i][k] * div;
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n + 1; j++){
    //         printf("%lf ", a[i][j]);
    //     }
    //     putchar('\n');
    // }
    ans[n] = a[n][n + 1];
    for (int i = n - 1; i; i--){
        ans[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++){
            ans[i] -= a[i][j] * ans[j];
        }
    }
    for (int i = 1; i <= n; i++) printf("%.2lf\n", ans[i]);
    return 0;
}