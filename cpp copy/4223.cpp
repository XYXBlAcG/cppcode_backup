#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define dbg(x) std::cout << #x << " = " << x << std::endl;
const int N = 2e5 + 10;
int vis[N], pri[N], cnt, k, res, nn, qk, ans_2, aa[N], bb[N], paa, pbb, tq;
int t, n, m, q, p, w[N], sum;
inline int power(int aff, int ngg, int mod){
    aff %= mod;
    int qwe = 1;
    for (; ngg > 0; ngg >>= 1)
    {
        if (ngg & 1)
            (qwe *= aff) %= mod;
        (aff *= aff) %= mod;
    }
    return qwe;
}
inline int exgcd(int a, int b, int &x, int &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
inline int inv(int a, int mod){
    int x, y;
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}
// int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
// void pre(int pk, int){
//     int ans = 1;
//     for (int i = 1; i < pk; i++){
//         if(gcd(i, qk) == 1) ((ans *= i) %= pk);
//     }
//     res = ans;
// }
// int lucas(int nn, int pk){
//     if(nn <= 1 || pk == 0) return 1;
//     int aans = lucas(nn / qk, pk);
//     aans *= power(res, nn / pk, pk);
//     for (int i = nn / pk * pk + 1; i <= nn; i++){
//         if(gcd(i, qk) == 1) ((aans *= i) %= pk);
//     }
//     return aans;
// }
int F(int n, int md, int p) {  // n! / p^x
    if (!n) return 1;
    int k = 1, last = 1;
    for (int i = 1; i <= p; i++)
        if (i % md) (k *= i) %= p;
    k = power(k, n / p, p);
    for (int i = p * (n / p); i <= n; i++)
        if (i % md) (last *= (i % p)) %= p;
    return F(n / md, md, p) * k % p * last % p;
}
int G(int n, int p) { return n < p ? 0 : G(n / p, p) + (n / p); }
inline int C(int n, int m, int md, int p) {
    int fenzi = F(n, md, p), fenmu1 = inv(F(m, md, p), p),
        fenmu2 = inv(F(n - m, md, p), p);
    int P = power(md, G(n, md) - G(m, md) - G(n - m, md), p);
    return fenzi * fenmu1 % p * fenmu2 % p * P % p;
}
inline int CRT(int a, int m, int p) { // x = a(mod m)
    return (a * inv(p / m, m) % p * (p / m)) % p;
}
inline int exl(int n, int m, int p) {
    int base = p, res = 0;
    for (int i = 2; i * i <= p; i++)
        if (!(base % i)) {
            int ci = 1;
            while (!(base % i)) ci *= i, base /= i;
            (res += CRT(C(n, m, i, ci), ci, p)) %= p;
        }
    if (base > 1) (res += CRT(C(n, m, base, base), base, p)) %= p;
    return res;
}
signed main()
{
    scanf("%lld%lld%lld", &q, &n, &m);
    int sum_2 = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &w[i]);
        sum_2 += w[i];
    }
    if (sum_2 > n)
    {
        printf("Impossible\n");
        return 0;
    }
    sum_2 = n;
    int aans = 1;
    for (int i = 1; i <= m; i++){
        aans = (aans * exl(sum_2, w[i], q)) % q;
        sum_2 -= w[i];
    }
    printf("%lld\n", aans);
    // for (int i = 1; i <= m; i++)
    // {
    //     tq = q;
    //         for (int j = 0, k = 0; pri[j] * pri[j] <= q; j++, k = 0)
    //         {
    //             if (pri[j] == 0)
    //                 continue;
    //             if (q % pri[j] == 0)
    //             {
    //                 k = 1;
    //                 for (int tmp = q / pri[j]; tmp % pri[j] == 0; k++, tmp /= pri[j]);
    //             }
    //             if (!k)
    //                 continue;
    //             qk = pri[j];
    //             int pk = power(pri[j], k, INF);
    //             tq /= pk;
    //             int result = inv(lucas(w[i], pk), pk);
    //             aa[++paa] = result;
    //             bb[++pbb] = pk;
    //         }
    //     if (tq != 1 && !isPrime(q))
    //     {
    //         az(tq, w[i]);
    //     }
    // }
    // aa[++paa] = inv()
    // printf("%lld\n", cn(paa));
    return 0;
}

// int tmp2 = lucas(n, pk), tmp3 = (lucas(m, pk) * lucas(n - m, pk)) ;
// int result = tmp2 * inv(tmp3, pk) * power(qk, get(n, pri[j]) - get(m, pri[j]) - get(n - m, pri[j]), pk) % pk;