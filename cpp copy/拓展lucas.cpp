#include <cstdio>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
const int N = 1e5 + 5;
int p, vis[N], pri[N], cnt, k, pk, res[N], n;
void init(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
}
int power(int a, int n, int mod){
    a %= mod;
    int ans = 1;
    for (; n > 0; n >>= 1){
        if(n & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
    }
    return ans;
}
int gcd(int a, int b){return (b == 0) ? a : gcd(b, a % b);}
int pre(int n, int mod){
    int ans = 1;
    for (int i = 1; i < power(p, k, INF); i++){
        if(gcd(i, p) == 1) res[i] = (ans *= i %= mod);
    }
    return power(ans, n / pk, mod);
}
int lucas(int n){
    // return lucas(n / p) * 
    
}
signed main(){
    scanf("%lld%lld%lld",&n,&p,&k), pk = power(p, k, INF);
    
    // pre(n, pk);
    // lucas(p);
    return 0;
}