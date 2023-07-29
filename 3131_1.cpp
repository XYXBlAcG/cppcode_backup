#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1005;
const int INF = 0x7fffffff;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

vector<Edge> G[MAXN]; // 图的邻接表表示
int dis[MAXN]; // 距离数组
int pre[MAXN]; // 前驱节点数组
bool vis[MAXN]; // 记录是否已经访问过
int n, m; // 节点数和边数

// 堆优化的Dijkstra算法
void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 2; i <= n; i++) dis[i] = INF;
    dis[1] = 0;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].v;
            int w = G[u][i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre[v] = u;
                pq.push(make_pair(dis[v], v));
            }
            else if (dis[u] + w == dis[v] && u < pre[v]) {
                pre[v] = u;
            }
        }
    }
}

// 输出字典序最小的路径
void printPath(int u) {
    if (u == 1) {
        cout << "1 ";
        return;
    }
    printPath(pre[u]);
    cout << u << " ";
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(Edge(v, w));
    }

dijkstra();

if (dis[n] == INF) cout << "-1" << endl;
    else printPath(n);

return 0;
}