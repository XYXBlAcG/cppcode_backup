#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
typedef double d;
int T, n;
d k;
d qp(d a, int x){
    d ans = 1;
    while(x){
        if(x & 1) ans *= a;
        a *= a;
        x >>= 1;
    }
    return ans;
}
d f(int x){
    d a = qp(1 - k, x), b = qp(1 - k, x - 1) * k;
    return (1 - a - b) * (x + 1) + a + b * x;
}
d cal(int x){
    return (d)(n % x) * f(n / x + 1) + (d)(x - n % x) * f(n / x);
}
struct FileIO{
    FileIO(){
        freopen("quality.in", "r", stdin);
        freopen("quality.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%lf", &n, &k);
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(cal(mid) > cal(mid + 1)) l = mid + 1;
            else r = mid;
        }
        printf("%.0lf\n", cal(l));
    }
    
    return 0;
}