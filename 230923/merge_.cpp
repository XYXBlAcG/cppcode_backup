#include <cstdio>
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 17;
typedef long long ll;
ll cnt[1 << N], vis[1 << N], n, a[N];
struct Node {
    ll score, cnt;
} rec[1 << N];
Node f(unsigned S) {
    if (cnt[S] == 1)
        return (Node){ 0, a[__builtin_ctz(S)] };
    if (vis[S])
        return rec[S];
    vis[S] = 1;
    Node ans = (Node){ -INF, 0 };
    for (unsigned t = S; t; t = S & (t - 1)) {
        Node t1 = f(t), t2 = f(S & ~t);
        if (t1.cnt * t2.cnt + t1.score + t2.score > ans.score)
            ans = (Node){ t1.cnt * t2.cnt + t1.score + t2.score, t1.cnt + t2.cnt };
    }
    // printf("ans = %lld\n", ans.score);
    return rec[S] = ans;
}
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (unsigned i = 1; i < (1 << n) - 1; i++) cnt[i] = cnt[i & (i - 1)] + 1;
    printf("%lld\n", f((1 << n) - 1).score);
    return 0;
}
