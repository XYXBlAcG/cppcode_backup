#include <cstdio>
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, k, ist[N], st[N], f[N], ans = 0, tmp = 2;
int fp(int x, int p, int mmm){
    int ans = 1;
    while(p){
        if(p & 1) (ans *= x) %= mmm;
        (x *= x) %= mmm;
        p >>= 1;
    }
    return ans;
}
int inv(int x, int mod){
    return fp(x, mod - 2, mod);
}
void stt(int x){
    st[0] = ist[0] = 1;
    for (int i = 1; i <= x; i++){
        st[i] = st[i - 1] * i % mod;
        ist[i] = inv(st[i], mod) % mod;
    }
}
int C(int n, int m){
    return st[n] * ist[m] % mod * ist[n - m] % mod;
}
signed main(){
    scanf("%lld%lld", &n, &k), stt(n);
    // printf("st[N] = {");
    // for (int i = 1; i <= n; i++){
    //     printf("%lld ,", st[i]);
    // }printf("}\n");
    // printf("ist[N] = {");
    // for (int i = 1; i <= n; i++){
    //     printf("%lld ,", ist[i]);
    // }printf("}\n");
    for (int i = n; i >= 0; i--){
        f[i] = C(n, i) * (tmp - 1) % mod;
        (tmp *= tmp) %= mod;
        (tmp += mod) %= mod;
    }
    for (int i = k; i <= n; i++){
        ans += (((i - k) & 1) ? -1 : 1) * C(i, k) * f[i] % mod;
        (ans += mod) %= mod;
    }
    // printf("%lld\n", ans);
    return 0;
}