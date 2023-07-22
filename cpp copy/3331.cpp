#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
const int M = 105, N = 10000;
struct Node{
    int v, tim, en;
};
struct Node2{
    int idx, w;
};
int n, m, me;
int switcher(int x, int y){
    return (x - 1) * (me + 1) + y;
}
struct CMP{
    bool operator()(Node2 a, Node2 b){
        return a.idx > b.idx;
    }
};
std::vector<Node> st[M];
std::vector<Node2> ed[N]; int dis[N];
std::priority_queue<Node2, std::vector<Node2>, CMP > q;
int vis[N], ans = INF * 2;
void dj() {
    memset(dis, INF, sizeof(dis));
    dis[switcher(1, me >> 1)] = 0;
    q.push((Node2){0, switcher(1, me >> 1)});
    while (!q.empty()) {
        int u = q.top().w; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto de : ed[u]) {
            int v = de.idx, w = de.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push((Node2){dis[v], v});
            }
        }
    }
    for (int i = 0; i <= me; i++){
        ans = std::min(ans, dis[switcher(n, i)]);
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &me);
    for (int i = 1; i <= m; i++){
        int u, v, time, energy;
        scanf("%d%d%d%d", &u, &v, &time, &energy);
        st[u].push_back((Node){v, time, energy});
        // st[v].push_back((Node){u, time, energy});
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= me; j++){
            for (auto v : st[i]){
                if(j + v.en >= 0 && j + v.en <= me){ 
                    ed[switcher(i, j)].push_back((Node2){switcher(v.v, j + v.en), v.tim});
                }
            } 
        }
    }
    dj();
    printf("%d\n", ans);
    return 0;
}