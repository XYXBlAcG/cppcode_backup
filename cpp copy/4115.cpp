#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 1e6 + 5;
typedef unsigned long long ll;
typedef double dd;
int n;
ll sum[N];
ll d[N], v[N], p[N], num[N];
int tot = 0;
void pre() {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    memset(p, 0, sizeof(p));
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!v[i]) v[i] = 1, p[++tot] = i, d[i] = 2, num[i] = 1;
        for (int j = 1; j <= tot && i <= n / p[j]; ++j) {
        v[p[j] * i] = 1;
        if (i % p[j] == 0) {
            num[i * p[j]] = num[i] + 1;
            d[i * p[j]] = d[i] / num[i * p[j]] * (num[i * p[j]] + 1);
            break;
        } else {
            num[i * p[j]] = 1;
            d[i * p[j]] = d[i] * 2;
        }
        }
    }
}
int g[N], f[N];
void prs() {
    memset(v, 0, sizeof(v));
    memset(p, 0, sizeof(p)); tot = 0;
    g[1] = f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!v[i]) v[i] = 1, p[++tot] = i, g[i] = i + 1, f[i] = i + 1;
        for (int j = 1; j <= tot && i <= n / p[j]; ++j) {
        v[p[j] * i] = 1;
        if (i % p[j] == 0) {
            g[i * p[j]] = g[i] * p[j] + 1;
            f[i * p[j]] = f[i] / g[i] * g[i * p[j]];
            break;
        } else {
            f[i * p[j]] = f[i] * f[p[j]];
            g[i * p[j]] = 1 + p[j];
        }
        }
    }
}
void bei(){
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i){
            sum[j] += 1ll * i * i;
        }
    }
}
int main(){
    int b = 0; n = N - 5;
    scanf("%d", &b);
    pre(); prs(); bei();
    for (int i = 1; i <= b; i++){
        ll ans = round((dd)sum[i] / (dd)d[i] - ((dd)f[i] / (dd)d[i]) * ((dd)f[i] / (dd)d[i]));
        printf("%llu\n", ans);
    }
    return 0;
}