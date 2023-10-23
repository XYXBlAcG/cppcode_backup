#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define int long long
const int N = 1e2 + 5, mod = 1e9 + 7;
int n, k;
struct M{
    int d[N][N];
    M(){memset(d, 0, sizeof(d));}
    int* operator[](int x){
        return d[x];
    }
}res, a;
M operator*(M a, M b){
    M ans;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                (ans[i][j] += a[i][k] * b[k][j] % mod) %= mod;
            }
        }
    }
    return ans;
}
signed main(){
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) res[i][i] = 1;
    while(k){
        if(k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%lld ", res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}