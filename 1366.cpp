#include <cstdio>
#define int long long
int n, m, num, tmp;
int qp(int a, int b){
    int ans = 1;
    while(b){ if(b & 1) ans *= a; a *= a; b >>= 1; }
    return ans;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &tmp);
        num += tmp * qp()
    }

    return 0;
}