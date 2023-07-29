#include <cstdio>
#define int long long
const int N = 100005;
int n, a[N], sum, res[N], ans;
void j(int v){
    for (int i = 63 ; i >= 0; i--)
        if(!(sum >> i & 1) && (v >> i & 1)){
            if(res[i]) v ^= res[i];
            else {res[i] = v; return;}
        }
    for (int i = 63 ; i >= 0; i--)
        if((sum >> i & 1) && (v >> i & 1)){
            if(res[i]) v ^= res[i];
            else {res[i] = v; return;}
        }
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), sum ^= a[i];
    for (int i = 1; i <= n; i++) j(a[i]);
    for (int j = 63; j >= 0; j--){
        if(!(sum >> j & 1) && !(ans >> j & 1))
            ans ^= res[j];
    }
    for (int j = 63; j >= 0; j--){
        if((sum >> j & 1) && !(ans >> j & 1))
            ans ^= res[j];
    }
    printf("%lld\n", ans ^ sum);
    return 0;
}