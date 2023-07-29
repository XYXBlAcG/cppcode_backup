#include <cstdio>
#include <algorithm>
#define judge(x) puts(x ? "yes" : "no")
#define int long long
const int N = 1e5 + 5, M = 1048576 + 5;
int n, m, x, a[N], t[M], q[N], pos = -1, l, r;
signed main(){
    // freopen("xor.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        pos = std::max(pos, t[a[i] ^ x]);
        t[a[i]] = i;
        q[i] = pos;
    }
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", &l, &r);
        judge(q[r] >= l);
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}