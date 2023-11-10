#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;
int n, m, vis[N], cnt[N], dis[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
std::queue<int> q;
bool spfa(int s){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0, vis[s] = 1, q.push(s);
    while(q.size()){
        int u = q.front(); q.pop(), vis[u] = 0;
        for (auto v : st[u]){
            if(dis[v.v] > dis[u] + v.w){
                dis[v.v] = dis[u] + v.w;
                cnt[v.v] = cnt[u] + 1;
                if(cnt[v.v] >= n) return 0;
                if(!vis[v.v]) q.push(v.v), vis[v.v] = 1;
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
        // st[v].push_back({u, w});
    }
    if(spfa(1) && dis[n] != INF){
        printf("%d\n", dis[n]);
    }else{
        puts("No solotion.");
    }

    return 0;
}