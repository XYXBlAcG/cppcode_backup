#include <cstdio>
#include <vector>
#include <bitset>
const int N = 3e6 + 5;
int n, dep[N], fath[N][20], fin[1005][1005];
std::vector<int> st[N];
std::bitset<N> se;
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    fath[u][0] = fa;
    for (int i = 1; i <= 19; i++) {
        fath[u][i] = fath[fath[u][i - 1]][i - 1];
    }
    for (int v : st[u]) {
        dfs(v, u);
    }
}
bool find(int u, int fa) {
    if (u == fa)
        return 1;
    if (dep[u] <= dep[fa])
        return 0;
    for (int i = 19; i >= 0; i--) {
        if (dep[fath[u][i]] >= dep[fa])
            u = fath[u][i];
    }
    if (u != fa)
        return 0;
    else
        return 1;
}
int main() {
    // freopen("ancester.in", "r", stdin);
    // freopen("ancester.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1, a; i < n; i++) {
        scanf("%d", &a);
        st[a].push_back(i + 1);
    }
    dfs(1, 0);
    if (n <= 1000) {
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= i; j++) {
        //         fin[i][j] = find(i, j);
        //     }
        // }

        for (int i = 1; i <= n; i++) {
            se.set();
            for (int j = 1; j <= i; j++){
                se[j] = find(i, j);
            }
            int ans = 0;
            // for (int j = i; j >= 1; j--) {
            for (int j = 1; j <= i; j++){
                se[j - 1] = 1;
                // bool work = 1;
                // for (int k = j; k <= i; k++) {
                //     if (!fin[k][j]) {
                //         work = 0;
                //         break;
                //     }
                // }
                if(se.all()) ans++;
                // if (work)
                //     ans++;
            }
            printf("%d\n", ans);
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}