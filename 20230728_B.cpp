#include <cstdio>
typedef long long ll;
const ll mod = 998244353, N = 100005;
ll n, p[N], rec[N], vis[N];
ll power(ll x, ll k, ll mmm){
    ll ans = 1;
    while(k){
        if(k & 1) (ans *= x) %= mmm;
        (x *= x) %= mmm;
        k >>= 1;
    }
    return ans;
}
ll inv(ll x, ll mmm){
    return power(x, mmm - 2, mmm);
}
//small ver.
ll fu(ll i){
    if(i == 0) return 0;
    if(vis[i]) return rec[i]; vis[i] = 1;
    return rec[i] = (fu(i - 1) + 1) * inv(1 - p[i], mod) % mod;
}
int main(){
    freopen("beetle.in", "r", stdin);
    freopen("beetle.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        p[i] = a * inv(b, mod) % mod;
    }
    printf("%lld\n", (fu(n) + mod) % mod);
    fclose(stdin);
    fclose(stdout);
    return 0;
}