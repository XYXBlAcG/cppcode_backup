#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = 1000005;
bool Pr[N];
ll primes[N];
void init() {
    // memset(Pr, 1, sizeof(Pr));
    Pr[0] = Pr[1] = 1;
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (!Pr[i]) {
            primes[cnt++] = i;
            for (int j = i + i; j < N; j += i) {
                Pr[j] = 1;
            }
        }
    }
}
inline ll read() {
    ll x = 0;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
  }
  return x;
}
int main() {
    init();
    ll T = read();
    while (T--) {
        ll n, m;
        n = read(), m = read();
        ll cnt = 0;
        bool isP[m + 1];
        memset(isP, 1, sizeof(isP));
        for (int i = 0; i < N && primes[i] * primes[i] <= n + m; i++) {
            ll p = primes[i];
            ll st = n / p * p;
            if (st < n) st += p;
            if (st == p) st += p;
            for (ll j = st; j <= n + m; j += p) {
                isP[j - n] = 0;
            }
        }
        for (ll i = n; i <= n + m; i++) {
            if (isP[i - n]) cnt++;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
