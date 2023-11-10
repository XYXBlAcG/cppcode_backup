#include <cstdio>
#include <vector>
using std::vector;
typedef long long ll;

const int N = 2 * 1e6 + 5;
int n, m, ans, id;
ll k;
int g[N];
vector<ll> f[N];

ll F(int l, int r) { return f[id][r] - f[id][l - 1]; }

int main() {
    // freopen("magic.in", "r", stdin);
    // freopen("magic.out", "w", stdout);
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g[i]);
        g[n + i] = g[i];
    }
    for (int i = 1; i <= (n << 1); i++) {
        if (!f[g[i]].empty())
            f[g[i]].emplace_back(i + f[g[i]].back()), printf("%d -> %lld\n", g[i], i + f[g[i]].back());
        else
            f[g[i]].emplace_back(0), f[g[i]].emplace_back(i), printf("%d -> %d\n", g[i], i);
        
    }
    for (int i = 1; i <= m; i++) {
        int tans = 0, lim = f[i].size(), l = 1, r = 1;
        id = i;
        for (; r < lim; r++) {
            for (;; l++) {
                int mid = (l + r) >> 1;
                printf("l = %d, r = %d\n", l, r);
                ll L = r - l + 1;
                ll tmp = F(mid + 1, r);
                printf("tmp o = %lld\n", tmp);
                tmp += (L & 1) ? -F(l, mid - 1) - (L / 2) * (L / 2 + 1) : -F(l, mid) - (L / 2) * (L / 2);
                printf("tmp = %lld\n", tmp);
                if (tmp <= k)
                    break;
            }
            if (r - l + 1 > tans)
                tans = r - l + 1;
        }
        lim--;
        if (tans > lim / 2)
            tans = lim / 2;
        if (tans > ans)
            ans = tans;
    }
    printf("%d\n", ans);
    return 0;
}