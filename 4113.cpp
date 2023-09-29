#include <cstdio>
#include <cstring>
typedef unsigned long long ll;
const int MAXN = 1000000;
bool isPrime[MAXN + 10];
int prime[MAXN + 10];
int cnt = 1, n = 0;
int mod = 1e9 + 7;
void init() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            prime[cnt++] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= MAXN; j++) {
            isPrime[i * prime[j]] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
ll getTime(int p){
    ll t = 0;
    for (ll i = p; n >= i; i *= p){
        if(i == 0) break;
        t += n / i;
    }
    return t;
}
int main() {
    init();
    scanf("%d",&n);
    ll res = 1;
    for (int i = 1; prime[i] <= n && i <= cnt; i++){
        res *= (2 * getTime(prime[i]) + 1);
        res %= mod;
    }
    printf("%lld ", res);
    return 0;
}
