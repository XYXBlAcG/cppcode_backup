#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f

const int N = 3e5 + 10;
const int mod = 1e9 + 7;

int n, m;
int w[N], in[N], dist[N], cnt[N], vis[N];
std::vector<int> g[N], topo;

void topo_sort() {
    for (int i = 0; i < topo.size(); i++) {
        int u = topo[i];
        for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            in[v]--;
            if (in[v] == 0) {
                topo.push_back(v);
            }
        }
    }
}
void dp() {
    memset(dist, INF, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    // std::queue<int> q;
    // q.push(w[1]);
    dist[1] = w[1];
    cnt[1] = 1;
    // while(q.size()){
    //     int u = q.front(); q.pop();
    //     if(vis[u])continue;
    //     vis[u] = 1;
    //     for (int i = 1; i < g[u].size(); i++){
    //         int v = g[u][i];
    //         if(dist[v] > dist[u] + w[v]){
    //             dist[v] = dist[u] + w[v];
    //             cnt[v] = cnt[u];
    //             q.push(v);
    //         }else if(dist[v] == dist[u] + w[v]){
    //             cnt[v] = (cnt[v] + cnt[u]) % mod;
    //         }
    //     } 
    // }

    for (int i = 0; i < topo.size(); i++) {
        int u = topo[i];
        for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            if (dist[v] > dist[u] + w[v]) {
                dist[v] = dist[u] + w[v];
                cnt[v] = cnt[u];
            } else if (dist[v] == dist[u] + w[v]) {
                cnt[v] = (cnt[v] + cnt[u]) % mod;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            topo.push_back(i);
        }
    }
    topo_sort();
    dp();
    for (int i = 1; i <= n; i++) {
        if(dist[i] > 1e9){
            printf("No path.\n");
            continue;
        }
        else{
            printf("%d %d\n", dist[i], cnt[i]);
        }
    }
    return 0;
}