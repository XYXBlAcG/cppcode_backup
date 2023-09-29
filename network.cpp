#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f
#define ls (id << 1)
#define rs (id << 1) | 1
const int N = 1040;
int n, n2, pay[N], cost[N][N], way[N], f[2 * N][N], ans = INF, lson[N], rson[N], tmp[N];
void dp(int id, int l, int r, int S, int dep){
    if(l == r){
        dep--, f[id][0] = f[id][1] = 0, f[id][way[l]] = pay[l];
        for (int i = 1; i <= dep; i++){
            int mid = (lson[i] + rson[i]) >> 1;
            if(l <= mid) f[id][!((S >> (dep - i)) & 1)] += cost[l][rson[i]] - cost[l][mid];
            else f[id][!((S >> (dep - i)) & 1)] += cost[l][mid] - cost[l][lson[i] - 1];
        }
        return;
    }
    int mid = (l + r) >> 1, len = r - l + 1;
    lson[dep] = l, rson[dep] = r;
    dp(ls, l, mid, S << 1, dep + 1);
    dp(rs, mid + 1, r, S << 1, dep + 1);
    memset(tmp, INF, sizeof(tmp));
    for (int i = 0; i <= (len >> 1) - 1; i++)
        for (int j = 0; j <= i; j++)
            tmp[i] = std::min(tmp[i], f[ls][j] + f[rs][i - j]);
    for (int i = 0; i <= (len >> 1) - 1; i++)
        f[id][i] = tmp[i];
    dp(ls, l, mid, S << 1 | 1, dep + 1);
    dp(rs, mid + 1, r, S << 1 | 1, dep + 1);
    memset(tmp, INF, sizeof(tmp));
    for (int i = (len >> 1); i <= len; i++)
        for (int j = 0; j <= i; j++)
            tmp[i] = std::min(tmp[i], f[ls][j] + f[rs][i - j]);
    for (int i = (len >> 1); i <= len; i++)
        f[id][i] = tmp[i];
}
signed main(){
    // printf("%.3lfMB",(double)(sizeof(cost))/1024/1024);
	scanf("%lld", &n), n2 = 1 << n;
	for (int i = 1; i <= n2; i++)
		scanf("%lld", way + i);
	for (int i = 1; i <= n2; i++)
		scanf("%lld", pay + i);
	for (int i = 1; i < n2; i++)
		for (int j = 1; j <= n2 - i; j++)
			scanf("%lld", &cost[i][i + j]), cost[j + i][i] = cost[i][i + j];
    for (int i = 1; i <= n2; i++)
        for (int j = 1; j <= n2; j++)
            cost[i][j] += cost[i][j - 1];
    memset(f, INF, sizeof(f));
    dp(1, 1, n2, 0, 1);
    for (int i = 0; i <= n2; i++)
        ans = std::min(ans, f[1][i]);
    printf("%lld\n", ans);
	return 0;
}