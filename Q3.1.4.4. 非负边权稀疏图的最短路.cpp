#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 5e5 + 5;
int dis[N], n, m, vis[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
bool cmp(Node a, Node b){
    return a.w > b.w;
}
template <typename T, size_t _Size>
struct Heap{
    T data[_Size]; int pdata = 0;
    void push(T b){
        data[++pdata] = b;
        std::push_heap(data + 1, data + 1 + pdata, cmp);
    }
    void pop(){std::pop_heap(data + 1, data + 1 + pdata--, cmp);}
    T top(){return data[1];}
    int size(){return pdata;}
    bool empty(){return !pdata;}
    T* begin(){return &data[1];}
    T* end(){return &data[pdata + 1];}
};
Heap<Node, N> heap;
void dj(int s){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    heap.push({s, 0});
    while(heap.size()){
        auto u = heap.top(); heap.pop();
        if(vis[u.v]) continue; vis[u.v] = 1;
        for (auto v : st[u.v]){
            if(dis[v.v] > dis[u.v] + v.w){
                dis[v.v] = dis[u.v] + v.w;
                heap.push({v.v, dis[v.v]});
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
    dj(1);
    if(dis[n] >= 1500000) puts("No solotion.");
    else printf("%d\n", dis[n]);
    return 0;
}