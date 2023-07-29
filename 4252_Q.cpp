#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e6 + 5, mod = 998244353;
int n, m, ist[N], st[N], a[N], ans = 0, summ[N];
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
        ist[i] = inv(st[i], mod);
    }
}
int C(int nnn, int mmm){
    if(mmm < 0 || mmm > nnn) return 0;
    return st[nnn] * ist[mmm] % mod * ist[nnn - mmm] % mod;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    stt(n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    std::sort(a + 1, a + 1 + n);
    if(!(m & 1)){
        for (int i = 1; i <= n; i++)
            summ[i] = (summ[i - 1] + (a[i] * C(n - i, (m >> 1) - 1) % mod)) % mod;
    }
    if(m & 1){
        for (int i = 1; i <= n; i++)
            (ans += (a[i] * C(i - 1, m >> 1) % mod * C(n - i, m >> 1) % mod)) %= mod;
    }else{
        for (int i = 1; i <= n; i++)
            (ans += (a[i] * C(i - 1, (m >> 1) - 1) % mod * C(n - i, (m >> 1)) % mod)) %= mod;
        for (int i = 1; i <= n; i++)
            (ans += (C(i - 1, (m >> 1) - 1) * (summ[n] - summ[i]) % mod)) %= mod;
        (ans *= inv(2, mod)) %= mod;
    }
    printf("%lld\n", (ans + mod) % mod);
    
    return 0;
}