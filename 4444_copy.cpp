#include <cstdio>
#define int long long
using namespace std;
const int N = 5010;
int n, m, op, f1[N][N], f2[N][N], f3[N][N], f4[N][N], kk;
inline int lowbit(int x) {
    return x & -x;
}
inline void add(int x, int y, int k) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            f1[i][j] += k;
            f2[i][j] += x * k;
            f3[i][j] += y * k;
            f4[i][j] += x * y * k;
        }
    }

    return ;
}
inline int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            res += (x + 1) * (y + 1) * f1[i][j] - (y + 1) * f2[i][j] - (x + 1) * f3[i][j] + f4[i][j];
        }
    }

    return res;
}
signed main() {
    scanf("%lld%lld%lld", &n, &m, &kk);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int tmp = 0;
            scanf("%lld", &tmp);
            add(i, j, tmp);
        }
    }
    for (int i = 1; i <= kk; i++){
        scanf("%lld", &op);
        int a, b, c, d, k;
        if (op == 0) {
            scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
            printf("%lld\n", query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1));
        } else {
            scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
            add(a, b, k), add(a, d + 1, -k), add(c + 1, b, -k), add(c + 1, d + 1, k);
        }
    }

    return 0;
}