#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
const int N = 5e5 + 10;
struct edge {
    int st, ed, weight;
};
int n, m;
int dist[N], vis[N], head[N];
edge edges[N << 1];
int cnt = 0;
struct node {
    int u, dist;
    bool operator < (const node& other) const {
    return dist > other.dist;
    }
};
std::priority_queue<node> q;
void add_edge(int u, int v, int w) {
    edges[++cnt].st = v;
    edges[cnt].weight = w;
    edges[cnt].ed = head[u];
    head[u] = cnt;
}
void dijkstra(int s) {
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    q.push((node){s, 0});
    while (!q.empty()) {
		node temp = q.top();
		q.pop();
		int u = temp.u;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = edges[i].ed) {
			int v = edges[i].st;
			int w = edges[i].weight;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push((node){v, dist[v]});
			}
		}
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
		int u = 0, v = 0, w = 0;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u, v, w);
    }
    dijkstra(1);
	if(dist[n] == INF) printf("No solotion.\n");
    else printf("%d\n", dist[n]);
    return 0;
}
