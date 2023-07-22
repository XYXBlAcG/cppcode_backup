#include <cstdio>
#include <vector>
const int N = 1e6 + 5;
#define int long long
int a, b, c;
int n, pri[N], vis[N], cnt;
void init() {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), t = x;
    x = y, y = t - (a / b) * y;
    return d;
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
int gcd(int a, int b){ return (b == 0) ? a : gcd(b, a % b);}
signed main(){
    scanf("%lld",&n), init();
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        for (int j = 1; pri[j] * pri[j] <= n; j++){
            int tc = c, cn = 0, pi = 1;
            while(tc % pri[j] == 0){
                tc /= pri[j], cn++, pi *= pri[j];
            }
            if(b % gcd(a, pi) != 0){
                printf("nO sOLuTiOn\n");
                return 0;
            }else{
                for (int tmp = pi, mod = b % gcd(a, tmp); tmp; mod = b % gcd(a, (tmp /= pri[j]))){
                    // if()
                }
            }
        }
    }
    return 0;
}