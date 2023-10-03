#include <cstdio>
#include <algorithm>
#include <vector>
using std::lower_bound;
using std::sort;
using std::unique;
using std::vector;
int n, a[3011], num[3011], pnum, f[3011][3011];
bool vis[3011][3011];
int loc[3011][3011], ploc[3011];
int dp(int i, int j) {
    if (loc[j][1] > i)
        return 0;
    if (vis[i][j])
        return f[i][j];
    vis[i][j] = 1;
    int tmp = 0;
    int cur = num[a[i]] + num[j];
    //	printf("i=%d j=%d cur=%d\n",i,j,cur);
    int nxt = lower_bound(num + 1, num + 1 + pnum, cur) - num, k;
    //	printf("nxt=%d\n",nxt);
    if (cur != num[nxt])
        return f[i][j] = 2;
    k = std::upper_bound(loc[nxt] + 1, loc[nxt] + ploc[nxt] + 1, i) - loc[nxt];
    //	printf("k=%d\n",loc[nxt][k]);
    tmp = dp(loc[nxt][k], a[i]);
    return f[i][j] = tmp + 1;
}
int main() {
    // freopen("seq.in", "r", stdin);
    // freopen("seq.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        num[++pnum] = a[i];
    }
    sort(num + 1, num + 1 + pnum);
    pnum = unique(num + 1, num + 1 + pnum) - num - 1;
    //	for(int i=1;i<=pnum;i++)printf("%d ",num[i]);
    //	printf("\n");
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(num + 1, num + 1 + pnum, a[i]) - num;
        //		printf("a[i]=%d\n",a[i]);
        loc[a[i]][++ploc[a[i]]] = i;
    }
    //	printf("loc[0]=%d\n",loc[2][1]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= pnum; j++) ans = std::max(ans, dp(i, j));
    }
    //	printf("dp=%d\n",dp(14,a[1]));
    printf("%d\n", ans);
    return 0;
}
/*10
-3 2 -1 1 0 1 1 2 3 5*/