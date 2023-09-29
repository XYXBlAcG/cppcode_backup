#include <cstdio>
#include <cmath>
#define int long long
double power(double down, int n){
    double ans = 1;
    for (int i = 1; i <= n; i++){
        ans *= down;
    }
    return ans;
}
double fb(int n){
    return round(power((1.0 + sqrt(5)) * 0.5, n) / (sqrt(5)));
}
signed main(){
    for (int i = 1; i <= 10; i++){
        printf("%lld\n", (int)fb(i));
    }
    printf("%d\n", (102334155 == (int)(fb(40))));
    return 0;
}