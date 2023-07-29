#include <cstdio>
#include <cstring>
#define int long long
const int mod = 999911659, mad = mod - 1, N = 5e5 + 5;
int n, g, st[N], pri[4] = {2,3,4679,35617}, ans[4];
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
int power(int x, int p, int mmm){
    int ans = 1;
    for (; p; p >>= 1, x = x * x % mmm)
        if (p & 1) ans = ans * x % mmm;
    return ans;
}
int inv(int x, int mmm){
    return power(x, mmm - 2, mmm);
}
void init(int mmm){
    memset(st, 0, sizeof(st));
    st[0] = 1;
    for (int i = 1; i <= mmm; i++){
        st[i] = st[i - 1] * i % mmm;
    }
}
int C(int n, int m, int mmm){
    if(n < m || m < 0) return 0;
    return st[n] * inv(st[m], mmm) % mmm * inv(st[n - m], mmm) % mmm;
}
int lucas(int nn, int mm, int pp){
    if(nn == 0) return 1;
    return (nn < mm) ? 0 : \
    ((C(nn % pp, mm % pp, pp) * lucas(nn / pp, mm / pp, pp)) % pp);
}
int crt(int mmm){
    // int rres = 0;
    // for (int i = 0; i < 4; i++){
    //     int mo = mmm / pri[i], x, y;
    //     exgcd(mo, pri[i], x, y);
    //     (rres += ans[i] * mo * x % mmm) %= mmm;
    // }
    // return rres;
    int rres = 0;
    for(int i = 0; i < 4; i++)
        (rres += (ans[i] * (mmm / pri[i]) % mmm * inv(mod/pri[i],pri[i])) % mmm) %= mmm;
    return rres;
}
signed main(){
    scanf("%lld%lld", &n, &g);
    if(g % mod == 0) {puts("0\n"); return 0;}
    for (int i = 0; i < 4; i++){
        init(pri[i]);
        for (int j = 1; j * j <= n; j++){
            // printf("%lld\n", j);
            if(n % j == 0){
                (ans[i] += lucas(n, j, pri[i])) %= pri[i];
                if(j * j != n)
                    (ans[i] += lucas(n, n / j, pri[i])) %= pri[i];
            }
        }
    }
    printf("%lld\n", power(g, crt(mad), mod));
    return 0;
}