#include <cstdio>
#include <cstring>
typedef double d;
const int N = 1e3 + 5;
long long n, m, k; d a[N], mi[N], _1[N];
void times(d *aa, d *b, int op){
    d tmp[N];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            tmp[(i + j - 2) % n + 1] += aa[i] * b[j];
        }
    }
    if(op == 1) memcpy(_1, tmp, sizeof(tmp));
    if(op == 2) memcpy(a, tmp, sizeof(tmp));
    if(op == 3) memcpy(mi, tmp, sizeof(tmp));
}
int main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%lf", a + i);
    mi[1] = 1.0 - 1.0 / (d)m, mi[2] = 1.0 / (d)m, _1[1] = 1.0;
    while(k){
        if(k & 1) times(mi, _1, 1);
        times(mi, mi, 3);
        k >>= 1;
    }
    times(a, _1, 2);
    for (int i = 1; i <= n; i++) printf("%.3lf\n", a[i]);
    return 0;
}