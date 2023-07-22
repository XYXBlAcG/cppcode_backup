#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;
int pheap;
struct Edge{
    int v, w;
};

struct Node{
    int v, dis;
}heap[N];
bool cmp(Node a, Node b){
    return a.dis > b.dis;
}
void push(int x, int y){
    heap[++pheap] = (Node){x, y};
    std::push_heap(heap + 1, heap + 1 + pheap, cmp);
}
void pop(){
    std::pop_heap(heap + 1, heap + 1 + pheap--, cmp);
}
int dis[N], vis[N];
std::vector<Edge> st[N];
void dj(int n, int s){
    memset(dis, INF, sizeof(dis));
    push(s, 0);
    dis[s] = 0;
    while(pheap){
        int v = heap[1].v;
        pop();
        if(vis[v]) continue;
        vis[v] = 1;
        for (auto x : st[v]){
            if(dis[x.v] > dis[v] + x.w){
                dis[x.v] = dis[v] + x.w;
                push(x.v, dis[x.v]);
            }
        }
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back((Edge){v, w});
        st[v].push_back((Edge){u, w});
    }
    dj(n, 1);
    printf("%d\n", dis[n]);
    return 0;
}