#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 2005;
struct Node{
    int v, w;
};
std::vector<Node> st[N], ed[N];
int n, m, vis[N], cnt[N], dis[N], ans[N][N];
std::queue<int> que;
bool cmp(Node a, Node b){
    return a.w > b.w;
}
template <typename T>
struct Heap{
    T data[N]; int pdata;
    void push(T x){
        data[++pdata] = x;
        std::push_heap(data + 1, data + 1 + pdata, cmp);
    }
    void pop(){
        std::pop_heap(data + 1, data + 1 + pdata--, cmp);
    }
    T top(){
        return data[1];
    }
    int size(){
        return pdata;
    }
};
Heap<Node> heap;
bool spfa(int s){
    memset(vis, 0, sizeof(vis));
    memset(dis, INF, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0, vis[s] = 1;
    que.push(s);
    while(que.size()){
        auto u = que.front(); que.pop();
        vis[u] = 0;
        for (auto v : st[u]){
            if(dis[v.v] > dis[u] + v.w){
                dis[v.v] = dis[u] + v.w;
                cnt[v.v] = cnt[u] + 1;
                if(cnt[v.v] >= n) return 0;
                if(!vis[v.v]) que.push(v.v), vis[v.v] = 1;
            }
        }
    }
    return 1;
}
void dj(int s){
    memset(vis, 0, sizeof(vis));
    ans[s][s] = 0;
    heap.push({s, 0});
    while(heap.size()){
        auto u = heap.top(); heap.pop();
        if(vis[u.v]) continue;
        vis[u.v] = 1;
        for (auto v : ed[u.v]){
            if(ans[s][v.v] > ans[s][u.v] + v.w){
                ans[s][v.v] = ans[s][u.v] + v.w;
                heap.push({v.v, ans[s][v.v]});
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++) st[0].push_back({i, 0});
    spfa(0);
    for (int i = 1; i <= n; i++){
        for (auto v : st[i]){
            ed[i].push_back({v.v, dis[i] - dis[v.v] + v.w});
        }
    }
    memset(ans, INF, sizeof(ans));
    for (int i = 1; i <= n; i++)
        dj(i);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int d = ans[i][j] - dis[i] + dis[j];
            printf(d > (INF >> 1) ? "inf " : "%d ", d);
        }
        putchar('\n');
    }


    return 0;
}