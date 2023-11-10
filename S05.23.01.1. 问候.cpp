#include <cstdio>
#define int long long
const int N = 1e3 + 5;
int c[N], d[N], t, a, b, n, s;
signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &a, &b), s = 0;
        for (int i = 1; i <= a; i++) scanf("%lld", &n), c[n]++;
        for (int i = 1; i <= b; i++) scanf("%lld", &n), d[n]++;
        for (int i = 1; i <= 1000; i++) s += c[i] * d[i], c[i] = d[i] = 0;
        printf("%lld\n", (a + 1) * (b + 1) - s);
    }
    return 0;
}