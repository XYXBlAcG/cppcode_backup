#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using std::min;
const int N = 105;
int n, k, a, b, c;
struct Node{
    int v, w;
};
int merge(int x, int y, int i){
    return ((x + 1) * n + y) * (k + 1) + i;
}
std::vector<Node> st[N * N * 12];
struct CMP{
    bool operator()(Node a, Node b){
        return a.v > b.v;
    }
};
std::priority_queue<Node, std::vector<Node> , CMP > q;
int map[N][N], dis[N * N * 12], vis[N * N * 12], ans = INF;
void dj() {
    dis[merge(1, 1, k)] = 0;
    q.push((Node){0, merge(1, 1, k)});
    while (!q.empty()) {
        // printf("top:%d,%d\n", q.top().v, q.top().w);
        int u = q.top().w; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : st[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push((Node){dis[v], v});
            }
        }
    }
    for (int i = 0; i < k; i++){
        ans = min(ans, dis[merge(n, n, i)]);
    }
}
int main(){
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &c);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i <= k; i++){
        for (int j = 1; j <= n; j++){
            for (int o = 1; o <= n; o++){
                dis[merge(j, o, i)] = INF;
                if(!map[j][o] || (map[j][o] && i == k)){
                    if(j != n && i >= 1) st[merge(j, o, i)].push_back((Node){merge(j + 1, o, i - 1), 0});
                    if(o != n && i >= 1) st[merge(j, o, i)].push_back((Node){merge(j, o + 1, i - 1), 0});
                    if(j != 1 && i >= 1) st[merge(j, o, i)].push_back((Node){merge(j - 1, o, i - 1), b});
                    if(o != 1 && i >= 1) st[merge(j, o, i)].push_back((Node){merge(j, o - 1, i - 1), b});
                    if(j != n && o != n) st[merge(j, o, i)].push_back((Node){merge(j, o, k), a + c});
                }
                if(map[j][o] && i != k){
                    st[merge(j, o, i)].push_back((Node){merge(j, o, k), a});
                }
            }
        }
    }
    dj();
    printf("%d\n", ans);
    return 0;
}