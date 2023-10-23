#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;
struct Edge{
    int v, w;
};
std::vector<Edge> st[N];
int n, m, s, dis[N], vis[N];
bool cmp(Edge a, Edge b){
    return a.w > b.w;
}
struct Heap{
    Edge data[N]; int pdata;
    void push(Edge x){
        data[++pdata] = x;
        std::push_heap(data + 1, data + pdata + 1, cmp);
    }
    void pop(){
        std::pop_heap(data + 1, data + pdata-- + 1, cmp);
    }
    Edge top(){
        return data[1];
    }
    int size(){
        return pdata;
    }
}heap;
void dj(){
    memset(dis, INF, sizeof(dis));
    heap.push({s, 0});
    dis[s] = 0;
    while(heap.size()){
        Edge u = heap.top(); heap.pop();
        if(vis[u.v]) continue;
        vis[u.v] = 1;
        for (auto v : st[u.v]){
            if(dis[v.v] > dis[u.v] + v.w) {
                dis[v.v] = dis[u.v] + v.w;
                heap.push({v.v, dis[v.v]});
            }
                
        }
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
    }
    dj();
    for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
    putchar('\n');
    return 0;
}