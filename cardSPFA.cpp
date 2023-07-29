#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
const int N = 5000;

typedef unsigned long long llu;
int n, m;
struct edge {
  int v, w;
};

std::vector<edge> e[N];
int dis[N], cnt[N], vis[N], count;
std::queue<int> q;

bool spfa(int n, int s) {
    memset(dis, 63, sizeof(dis));
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        count++;
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto ed : e[u]) {
        int v = ed.v, w = ed.w;
        if (dis[v] > dis[u] + w) {
            ++count;
            dis[v] = dis[u] + w;
            cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
            if (cnt[v] >= n) return false;
            // 在不经过负环的情况下，最短路至多经过 n - 1 条边
            // 因此如果经过了多于 n 条边，一定说明经过了负环
            if (!vis[v]) q.push(v), vis[v] = 1;
        }
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back((edge){v, w});
    }
    spfa(n, 1);
    printf("%d \n", count);
    return 0;
}