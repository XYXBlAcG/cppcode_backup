#include <cstdio>
#define int long long
const int N = 1e5 + 5;
int n, op[N], num[N], cnt, ans[N];
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", op + i, num + i);
        if(op[i] != 1) cnt++;
    }
    for (int i = 1; i <= cnt; i++){
        scanf("%lld", ans + i);
    }
    int res = 0;
    for (int i = 1, j = 1; i <= n; i++){
        num[i] ^= res;
        if(op[i] != 1) res = ans[j], j++;
    }
    for (int i = 1; i <= n; i++){
        printf("%lld %lld\n", op[i], num[i]);
    }
    
    return 0;
}