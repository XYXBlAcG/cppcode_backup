#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
using std::push_heap;
using std::pop_heap;
using std::min;
const int N = 2e5 + 5;
const int B = 2e3 + 5;
struct Node{
    int v, w;
};
struct DJ{
    int u, dis;
};
int n, m, d;
int bist[B], cb, visa[N], dist[N];
std::vector<Node> st[N];
DJ q[N]; int lq = 0;
bool cmp(DJ a, DJ b) {
    return a.dis > b.dis;
}
int bell(int s) {
    memset(bist, 0x3f, sizeof(bist));
    bist[s] = 0;
    bool flag; 
    for (int i = 1; i <= n; i++) {
        flag = 0;
        for (int u = 1; u <= n; u++) {
            if (bist[u] == INF) continue;
            for (auto ed : st[u]) {
                int v = ed.v, w = ed.w;
                if (bist[v] > bist[u] + w) {
                    bist[v] = bist[u] + w;
                    flag = 1;
                }
            }
        }
        if (!flag) break;
    }
    // printf("flag:%d\n", flag);
    return flag == 0 ? bist[n] : INF;
}
void dijkstra(int s) {
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    q[++lq] = (DJ){s, 0}; push_heap(q + 1, q + lq + 1, cmp);
    while(lq){
        int u = q[1].u; pop_heap(q + 1, q + (lq--) + 1, cmp);
        if (visa[u]) continue; visa[u] = 1;
        for (auto ed : st[u]) {
            int v = ed.v, w = ed.w;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q[++lq] = (DJ){v, dist[v]};
                push_heap(q + 1, q + lq + 1, cmp);
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&d);
    for (int i = 1; i <= m; i++){
        int s, t, w;
        scanf("%d%d%d",&s,&t,&w);
        st[s].push_back((Node){t, -w});
    }
    int ans = 0;
    if(n <= 2e3 && m <= 1e4){
        // bellman
        // printf("i'm a bellman\n");
        // ans = bell(1 + n);
        ans = bell(1);
    }else{
        // dijkstra
        dijkstra(1);
        ans = dist[n];
    }
    if(ans >= (INF >> 1)){
        printf("Forever love\n");
    }else{
        printf("%d\n", d + ans);
    }
    return 0;
}