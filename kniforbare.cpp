#include <cstdio>
#include <cmath>
#define int long long
#define c ceil
int t, l, w, h;
signed main(){
    freopen("kniforbare.in", "r", stdin);
    freopen("kniforbare.out", "w", stdout);
    scanf("%lld", &t);
    while (t--){
        scanf("%lld%lld%lld", &l, &w, &h);
        printf("%lld %lld\n", l * w * h - 1, (int)(c(log2(l)) + c(log2(w)) + c(log2(h))));
    }
    return 0;
}