#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
struct edge {
    int to, next;
};
int n, m, cnt = 0;
int head[N], ans[N], vis[N];
edge edges[N << 1];
void add_edge(int u, int v) {
    edges[++cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt;
}
int dfs(int u) {
    if (vis[u]) return 1;
    vis[u] = 1;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (dfs(v)) return 1;
    }
    ans[++cnt] = u;
    return 0;
}
void TopoSort() {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(ans + 1, ans + cnt + 1);
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
        int u = 0, v = 0;
        scanf("%d%d",&u,&v);
        add_edge(u << 1, v << 1 | 1);
        add_edge(v << 1, u << 1 | 1);
    }
    TopoSort();
    for (int i = 1; i <= n; i++) {
        if (vis[i << 1] && vis[i << 1 | 1]) {
            printf("No Solution\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i << 1]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}