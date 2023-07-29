#include <cstdio>
#include <cstring>
#define int long long
const int N = 105, mod = 1e9 + 7;
int n, m, a[N][N], b[N][N], c[N][N], ans = 1;
void mul(){
    memset(c, 0, sizeof(c));
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= 1; i++)
            for (int j = 1; j <= n; j++)
                (c[i][j] += (b[i][k] * a[k][j])) %= mod;
}
void mul2(){
    memset(c, 0, sizeof(c));
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                (c[i][j] += (a[i][k] * a[k][j])) %= mod;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= 1; i++)
        b[i][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[i][j]);
    while(m){
        if(m & 1) {mul(); memcpy(b, c, sizeof(c));}
        mul2(); memcpy(a, c, sizeof(c));
        m >>= 1;
    }
    for (int i = 1; i <= n; i++)
            printf("%lld ", b[1][i]);
        printf("\n");
    
    return 0;
}