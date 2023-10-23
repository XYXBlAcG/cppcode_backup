#include <cstdio>
#include <random>
#include <algorithm>
std::mt19937 rng(114514);
const int inf = 0x3f3f3f3f;
int n, k, dis[25 * 2][25 * 2], pedge, d[25 * 2], pans;
struct Edge {
    int u, v;
} edge[250 * 2], buff[250 * 2], ans[250 * 2];
void floyd(int u, int v) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = std::min(dis[i][j], std::min(dis[i][u] + dis[v][j], dis[i][v] + dis[u][j]) + 1);
}
void solve(int st) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dis[i][j] = (i == j ? 0 : inf);
    for (int i = 1; i <= n; i++) d[i] = 0;
    shuffle(edge + st, edge + pedge + 1, rng);
    //    for(int i=1;i<=pedge;i++){
    //    	printf("%d %d\n",edge[i].u,edge[i].v);
    //	}
    int pbuff = 0;
    for (int i = 1; i <= pedge; i++) {
        int u = edge[i].u, v = edge[i].v;
        if (dis[u][v] < k - 1)
            continue;
        //        printf("i=%d u=%d v=%d\n",i,u,v);
        dis[u][v] = dis[v][u] = 1;
        floyd(u, v);
        buff[++pbuff] = edge[i];
        d[u]++, d[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (d[i] < 2) {
            //    	printf("##");.
            return;
        }

    if (pbuff > pans) {
        pans = pbuff;
        // printf("%d\n", pans);
        for (int i = 1; i <= pbuff; i++) ans[i] = buff[i];
    }
}
int main() {
    freopen("build.in", "r", stdin);
    freopen("build.out", "w", stdout);
    scanf("%d%d", &n, &k);
    // printf("n , k = %d %d\n", n, k);
    for (int i = 1; i < n; i++) edge[++pedge] = { i, i + 1 };
    for (int i = 1; i <= n; i++)
        for (int j = i + k - 1; j <= n; j++) edge[++pedge] = { i, j };
    for (int i = 1; i <= 5000; i++) solve(n);
    pedge = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1 + i; j <= n; j++) edge[++pedge] = { i, j };
    for (int i = 1; i <= 5000; i++) solve(1);
    printf("%d\n", pans);
    for (int i = 1; i <= pans; i++) printf("%d %d\n", ans[i].u, ans[i].v);
    fclose(stdin);
    fclose(stdout);
    return 0;
}