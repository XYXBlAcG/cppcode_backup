#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
const int N = 2e5 + 10;
int vis[N], pri[N], cnt, k, res, nn, qk, ans_2, aa[N], bb[N], paa, pbb, tq;
int t, n, m, q;
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
int power(int aff, int ngg, int mod){
    aff %= mod;
    int qwe = 1;
    for (; ngg > 0; ngg >>= 1){
        if(ngg & 1) (qwe *= aff) %= mod;
        (aff *= aff) %= mod;
    }
    return qwe;
}
bool isPrime(int num){
    if(num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if(i != 0 && num % i == 0) return 0;
    }return 1;
}
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
int inv(int a, int mod){
    int x, y; exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}
int gcd(int a, int b){return (b == 0) ? a : gcd(b, a % b);}
void pre(int pk){
    int ans = 1;
    for (int i = 1; i < pk; i++){
        if(gcd(i, qk) == 1) ((ans *= i) %= pk);
    }
    res = ans;
}
int lucas(int nn, int pk){
    if(nn <= 1 || pk == 0) return 1;
    int aans = lucas(nn / qk, pk);
    aans *= power(res, nn / pk, pk);
    for (int i = nn / pk * pk + 1; i <= nn; i++){
        if(gcd(i, qk) == 1) ((aans *= i) %= pk);
    }
    return aans;
}
int get(int nn, int div){
    if(nn < div || div == 0) return 0;
    return nn / div + get(nn / div, div);
}
int cn(int n){
    int mmm = 1, ans_tmp = 0;
    for (int i = 1; i <= n; i++) mmm *= bb[i];
    for (int i = 1; i <= n; i++){
        int x, y;
        int div = mmm / bb[i];
        exgcd(div, bb[i], x, y); 
        ans_tmp = ((ans_tmp + div * x % mmm * aa[i] % mmm)) % mmm;
    }
    return (ans_tmp + mmm) % mmm ;
}
void az(int qq){
    qk = qq;
    int pk = qq;
    pre(pk); 
    int tmp2 = lucas(n, pk), tmp3 = (lucas(m, pk) * lucas(n - m, pk)); tq /= pk; 
    int result = tmp2 /*/ power(qk, get(n, pri[j]), pk)*/ * inv(tmp3, pk) * power(qk, get(n, qq) - get(m, qq) - get(n - m, qq), pk) % pk;
    aa[++paa] = result;
    bb[++pbb] = pk;
}
signed main(){
    init(100000);
    scanf("%lld",&t);
    for (int i = 1; i <= t; i++){
        ans_2 = 0, paa = 0, pbb = 0;
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        scanf("%lld%lld%lld",&n,&m,&q);
        tq = q;
        az(q);
        printf("%lld\n", cn(1));
        // if(isPrime(q)){
        //     az(q);
        // }else for (int j = 0, k = 0; pri[j] * pri[j] <= q; j++, k = 0){
        //     if(pri[j] == 0) continue;
        //     if(q % pri[j] == 0) {k = 1; for (int tmp = q / pri[j]; tmp % pri[j] == 0; k++, tmp /= pri[j]);}
        //     if(!k) continue;
        //     qk = pri[j];
        //     int pk = power(pri[j], k, INF); tq /= pk; 
        //     pre(pk);
        //     int tmp2 = lucas(n, pk), tmp3 = (lucas(m, pk) * lucas(n - m, pk)) ;
        //     int result = tmp2 * inv(tmp3, pk) * power(qk, get(n, pri[j]) - get(m, pri[j]) - get(n - m, pri[j]), pk) % pk;
            
        //     aa[++paa] = result;
        //     bb[++pbb] = pk;
            
        // }
        // if(tq != 1) {az(tq);}
        // printf("%lld\n", cn(paa));
    }
    return 0;
}