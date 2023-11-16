#include <cstdio>
#include <algorithm>
#define int long long
int x;
signed main(){
    scanf("%lld", &x);
    ((x %= 360) += 360) %= 360;
    if(x <= 45 || x >= 315) puts("0");
    else if(x > 45 && x <= 135) puts("1");
    else if(x > 135 && x <= 225) puts("2");
    else puts("3");
    return 0;
}