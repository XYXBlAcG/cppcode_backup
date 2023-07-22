// 4.3.5.3 猴子大战
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#define int long long
#define deb(x) std::cout << #x << " = " << x << std::endl
typedef double d;
const int N = 1e3 + 5;
int n, m; d mx[N][N];
d aabs(d x){ return (x < 0) ? -x : x; }
void solve(){
    int flag = 0;
    for (int i = 1; i <= n; i++){
        flag = i;
        for (int j = i + 1; j <= n; j++) if(aabs(mx[j][i]) > aabs(mx[flag][i])) flag = j;
        std::swap(mx[i], mx[flag]);
        for (int j = i + 1; j <= n; j++){
            // if(j == i) continue;
            d tmp2 = mx[j][i] / mx[i][i];
            for (int k = i; k <= n + 1; k++)
                mx[j][k] = (mx[j][k] - tmp2 * mx[i][k]);
        }
    }
    for (int i = n; i > 0; i--){
            for (int j = i + 1; j <= n; j++){
                mx[i][n + 1] -= mx[i][j] * mx[j][n + 1];
            }
            mx[i][n + 1] /= mx[i][i];
        }
    // for (i=n; i; i--)
	// {
	// 	for(j=i+1; j<=n; j++)
	// 	    a[i][n+1]-=a[i][j]*a[j][n+1];
	// 	a[i][n+1]/=a[i][i];
	// }
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        mx[i][i] = 1 - n;
        for (int j = 1; j <= n; j++){
            d mmm = 0;
            scanf("%lf", &mmm);
            if(i != j) mx[i][i] += (mx[i][j] = mmm);
        }
    }
    for (int i = 1; i <= n + 1; i++) mx[n][i] = 1;
    // mx[n][n + 1] = 1;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         printf("%lf ", mx[i][j]);
    //     }putchar('\n');
    // }
    solve();
    
    for (int i = 1; i <= m; i++){
        std::string tmp;
        std::cin >> tmp;
        d ans = 0;
        for (int j = 1; j <= n; j++)
            if(tmp[j - 1] == '1') ans += mx[j][n + 1];
        printf("%.8lf\n", ans);
    }
    return 0;
}