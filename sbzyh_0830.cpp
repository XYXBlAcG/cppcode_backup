#include <cstdio>
#define EPS 1e-5
typedef double d;
d cal(d v, int op){
    d ans = 0;
    if(op == 1){
        ans += v * 3;
        ans += v * v * 3;
        ans += v * v * v * 3;
    }else{
        ans += v * v * v * v;
    }
    return ans;
}
int main(){
    d l = 3, r = 4;
    while(l < r - EPS){
        d mid = (l + r) / 2;
        d a = cal(mid, 1), b = cal(mid, 0);
        if(a < b) r = mid;
        else l = mid + EPS;
    }
    printf("%lf\n", l);
    return 0;
}