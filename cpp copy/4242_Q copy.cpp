#include <cstdio>
#define int long long
const int mod = 1e8 + 7, N = 1e6 + 10;
int n, m, st[N], ist[N], rec[N], vis[N], ans, n2, a[N];
int power(int x, int p){
    int ans = 1;
    while(p){
        if(p & 1) (ans *= x) %= mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}
int inv(int x, int mm){
    return power(x, mm - 2);
}
void init(int x){
    st[0] = ist[0] = 1;
    for (int i = 1; i <= x; i++){
        st[i] = st[i - 1] * i % mod;
        ist[i] = inv(st[i], mod);
    }
    a[0] = 1;
    for (int i = 1; i <= x; i++){
        a[i] = a[i - 1] * (n2 - i + mod) % mod;
    }
}
// int A(int n, int m){
//     if(n < m || m < 0 || n < 0) return 0;
//     return (st[n] * ist[n - m] % mod + mod) % mod;
// }
// int f(int i){
//     if(i == 0) return 1;
//     if(i == 1) return 0;
//     if(i < 0) return 0;
//     if(vis[i]) return rec[i]; vis[i] = 1;
//     return rec[i] = \
//     (((A(n2 - 1, i - 1) - f(i - 1) + mod) % mod \
//     - (f(i - 2) * (i - 1) % mod * (n2 + 1 - i) % mod + mod) % mod) + mod) % mod;
// }
signed main(){
    scanf("%lld%lld", &n, &m), n2 = power(2, n);
    init(m);
    rec[0] = 1;
    for (int i = 2; i <= m; i++){
        // (rec[i] += A(n2 - 1, i - 1) + mod) %= mod;
        (rec[i] += a[i - 1] + mod) %= mod;
        ((rec[i] -= rec[i - 1]) += mod) %= mod;
        ((rec[i] -= rec[i - 2] * (i - 1) % mod * (n2 + 1 - i) % mod) += mod) %= mod;
    }
    printf("%lld\n", (rec[m] * ist[m] % mod + mod) % mod);
    return 0;
}