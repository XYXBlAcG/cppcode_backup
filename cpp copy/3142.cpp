#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
const int N = 5010;
int n, m;
int dist[N];
struct edge {
  int v, w;
};
std::vector<edge> e[N];
bool bellmanford(int n, int s) {
  memset(dist, 63, sizeof(dist));
  dist[s] = 0;
  bool flag;  // 判断一轮循环过程中是否发生松弛操作
  for (int i = 1; i <= n; i++) {
    flag = false;
    for (int u = 1; u <= n; u++) {
      if (dist[u] == INF) continue;
      // 无穷大与常数加减仍然为无穷大
      // 因此最短路长度为 inf 的点引出的边不可能发生松弛操作
      for (auto ed : e[u]) {
        int v = ed.v, w = ed.w;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          flag = true;
        }
      }
    }
    // 没有可以松弛的边时就停止算法
    if (!flag) break;
  }
  // 第 n 轮循环仍然可以松弛时说明 s 点可以抵达一个负环
  return flag;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
        int u = 0, v = 0, w = 0;
        scanf("%d%d%d",&u,&v,&w);
        // edges[u][v] = std::min(w, edges[u][v]);
        e[u].push_back((edge){v, w});
    }
    for (int i = 1; i <= n; i++){
        e[n + 1].push_back((edge){i, 0});
    }
    if(bellmanford(n, 1)){
        printf("No solotion.\n");
    }
    else if(dist[n] == INF) printf("No solotion.\n");
    else printf("%d\n", dist[n]);
    return 0;
}
