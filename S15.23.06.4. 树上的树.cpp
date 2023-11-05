#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
const int N = 1e6 + 5;
int cas, n, k, q, o, a[N], las, pre[N], suf[N];
int solve(int l, int r, int t) {
    int ans = 0;
    for (int i = t; i <= std::min(n, l); i++) {
        int cnt = 0;
        for (int j = i; j <= n; j++) {
            if (std::abs(a[i] - a[j]) > k) {
                if (j >= l && j <= r) {
                    cnt = 0;
                    break;
                } else
                    continue;
            }
            cnt++;
        }
        ans = std::max(ans, cnt);
    }
    return ans;
}
std::queue<int> que;
int main() {
    #ifdef ONLINE_JUDGE
    freopen("tot.in", "r", stdin);
    freopen("tot.out", "w", stdout);
    #else
    #endif

    scanf("%d", &cas);
    scanf("%d%d%d%d", &n, &k, &q, &o);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    a[0] = a[1];
    que.push(0);
    for (int i = 1; i <= n; i++) {
        while (que.size() && std::abs(a[que.front()] - a[i]) > k) que.pop();
        que.push(i);
        pre[i] = que.front();
    }
    while (que.size()) que.pop();
    for (int i = n; i; i--) {
        while (que.size() && std::abs(a[que.front()] - a[i]) > k) que.pop();
        que.push(i);
        suf[i] = que.front();
    }
    for (int i = 1; i <= q; i++) {
        int t = 0, x = 0, y = 0;
        scanf("%d%d%d", &t, &x, &y);
        if (o)
            t ^= las, x ^= las, y ^= las;
        if (n <= 1000) {
            printf("%d\n", las = solve(x, y, t));
        } else {
            int flag = 0;
            for (int j = x + 1; j <= y; j++) {
                if (pre[j] >= x) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                las = 0;
                puts("0");
                continue;
            }
            printf("%d\n", las = (suf[y] - std::max(pre[x], t) + 1));
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}