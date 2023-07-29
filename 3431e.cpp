#include <cstdio>
#include <algorithm>
const int N = 23;
typedef long long ll;
ll n, a[N], b[N], s, cnt[1 << N], vis[1 << N], rec[1 << N], P[N], tmmp;
ll f(unsigned S){
    if(vis[S]) return rec[S]; vis[S] = 1;
    ll tmp = 0;
    for(int i = 0; i < n; i++)
        if(((~S >> i) & 1) && (P[i] & S) == P[i])
            tmp = std::max(tmp,f(S|(1<<i)) + a[i] * (cnt[S]+1) + b[i] ); 
    return rec[S] = tmp;
}
int main(){
    scanf("%lld",&n);
    for (int i = 0; i < n; i++){
        scanf("%lld%lld%lld", &a[i], &b[i], &s);
        for (ll j = 0; j < s; j++){
            scanf("%lld", &tmmp);
            P[i] |= (1 << (tmmp - 1)); 
        }
    }
    unsigned U = (1 << n) - 1;
    for (unsigned i = 1; i < U; i++)
        cnt[i] = cnt[i & (i - 1)] + 1;
    printf("%lld\n", f(0));
    return 0;
}

