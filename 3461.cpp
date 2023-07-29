#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int N = 22;
int n, cnt[1 << N]; bool vis[N][1 << N]; ll rec[N][1 << N], a[N], b[N];
ll f(int i, unsigned S){
    if(i > n && !S) return 0;
    if(vis[i][S]) return rec[i][S]; vis[i][S] = 1;
    if(i < n) rec[i][S] = std::max(f(i + 1, S | (1 << i)), rec[i][S]);
    if(S) rec[i][S] = std::max(rec[i][S], f(i, S & ~(1 << (31 - __builtin_clz(S)))) + b[i - cnt[S]] * a[31 - __builtin_clz(S)]);
    return rec[i][S];
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    for (unsigned i = 1; i < (1 << n) - 1; i++) cnt[i] = cnt[i & (i - 1)] + 1;
    printf("%lld\n", f(0, 0));
    return 0;
}