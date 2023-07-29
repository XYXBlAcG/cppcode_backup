#include <cstdio>
#include <algorithm>
#include <math.h>
const int N = 1e5 + 10;
typedef double d;
long long n, m;
d org[N], day[N];
d cal(d x){
    d tmp[N];
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        tmp[i] = org[i] + day[i] * x;
        ans += floor(tmp[i] / x);
    }
    return (int)(ans < m);
}
int main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lf%lf", &org[i], &day[i]);
    }
    d l = 1e-100, r = 1e100;
    while(r - l > 1e-13 * l){
        d mid = (r + l) * 0.5;
        if(cal(mid)){r = mid;}
        else{l = mid /*+ 1e-13*/;}
    }
    printf("%.10e", l);
    return 0;
}