#include <cstdio>
#include <iostream>
#define int long long
#define deb(x) std::cout << #x << " = " << x << std::endl
typedef double d;
const int N = 1e5 + 5;
int n, vis[(1 << 20) + 5]; d a[N], b[N], suma[(1 << 20) + 5], rec[(1 << 20) + 5], sumb[(1 << 20) + 5], sb, sa;
d f(unsigned S){
    if(!S) return 0;
    if(vis[S]) return rec[S]; vis[S] = 1;
    d ans = 0;
    for (int i = 0; i < n; i++){
        if((S >> i) & 1){
            // deb(a[i]), deb(suma[S]), deb(b[i]), deb(1 + (sumb[S]));
            d P = a[i] / (suma[S]), V = b[i] / (1 + (sumb[S]));
            // deb(P), deb(V);
            ans += P * (V + f(S & ~(1 << i)));
            // deb(f(S | (1 << i)));
            // deb(ans);
        }
    }
    // deb(ans);
    return rec[S] = ans;
}
signed main(){
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lf", a + i), sa += a[i];
    for (int i = 0; i < n; i++) scanf("%lf", b + i), sb += b[i];
    // set();
    for (unsigned i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++){
            if((i >> j) & 1) suma[i] += a[j];
            if(!((i >> j) & 1)) sumb[i] += b[j];
        }
        // deb(i), deb(suma[i]), deb(sumb[i]);
    }
    printf("%.10lf\n", f((1 << n) - 1));
    return 0;
}