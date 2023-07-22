#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = (1 << 16) + 11;
int n, a[20], num[N];
bool vis[N];
struct Pile {
    ll num;
    ll point;
} f[N];
int gn(int S) {
    int rt = 0;
    while (S) {
        rt += (S & 1);
        S >>= 1;
    }
    return rt;
}
Pile dp(int S) {
    if (num[S] == 1)
        return { a[__builtin_ctz(S)], 0 };
    if (vis[S])
        return f[S];
    vis[S] = 1;
    ll tmp = 0, pnum = 0;
    for (int t = S; t; t = S & (t - 1)) {
        Pile a = dp(t), b = dp(S & (~t));
        if (a.num * b.num + a.point + b.point > tmp) {
            tmp = a.num * b.num + a.point + b.point;
            pnum = a.num + b.num;
        }
    }
    return f[S] = { pnum, tmp };
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < (1 << n) - 1; i++) num[i] = gn(i);
    printf("%lld\n", dp((1 << n) - 1).point);
    return 0;
}