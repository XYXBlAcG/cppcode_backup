#include <cstdio>
#include <cstring>
#define int long long
const int N = 105, mod = 1000000007;
int n, m, r, x[N], c[N], res[N][N], ans[N][N], b[N][N];
void mul(){
    memset(res, 0, sizeof(res));
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                (res[i][j] += (b[i][k] * ans[k][j])) %= mod;
            }
        }
    }
}
void mul2(){
    memset(res, 0, sizeof(res));
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                (res[i][j] += (ans[i][k] * ans[k][j])) %= mod;
            }
        }
    }
}
void qp(int m){
    while(m){
        if(m & 1) {mul(); memcpy(b, res, sizeof(res)); }
        mul2(); memcpy(ans, res, sizeof(res));
        m >>= 1;
    }
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &r);
    for (int i = 1; i <= r; i++)
        scanf("%lld%lld", x + i, c + i);
    
    return 0;
}