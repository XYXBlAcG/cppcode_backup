#include <cstdio>
#define long long long
const int N = 8e5 + 10;
const long D = 1e9;
int n, m, fa[N];
long in[N], out[N], ans[N];
bool ava[N];
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
int main() {
    // freopen("path.in", "r", stdin);
    // freopen("path.out", "w", stdout);
    int a, b, T;
    long d, A, B, Ans = 0;
    scanf("%d%d%d", &n, &m, &T);
    if (T)
        scanf("%d%d%lld%lld%lld", &a, &b, &d, &A, &B);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        if (T) {
            a = ((A * a) ^ B) % n + 1;
            b = ((B * b) ^ A) % n + 1;
            d = ((d * A) ^ (d * B)) % D;
        } else {
            scanf("%d%d%lld", &a, &b, &d);
        }
        out[a] += d;
        in[b] += d;
        a = find(a);
        b = find(b);
        ava[a] = ava[a] || ava[b];
        fa[b] = a;
        if (d)
            ava[a] = true;
    }
    for (int i = 1; i <= n; i++)
        if (out[i] > in[i])
            ans[find(i)] += out[i] - in[i];
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            if (ans[i])
                Ans += ans[i];
            else if (ava[i])
                Ans++;
        }
    }
    printf("%lld\n", Ans);
    return 0;
}