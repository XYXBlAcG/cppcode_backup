#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#define int long long
const int N = 3e5 + 5;
int n, m, k, vis[N], dis[N], path[N], ans[N * 2], pans;
std::unordered_map<int, int> mp;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
std::vector<int> to[N];
bool cmp(Node a, Node b){
    return a.w > b.w;
}
bool cmp2(Node a, Node b){
    return a.w < b.w;
}
template <typename T>
struct Heap{
    T data[N]; int pdata = 0;
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
Heap<Node> heap;
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
                path[v.v] = u.v;
                heap.push({v.v, dis[v.v]});
            }
        }
    }
}
void dfs(int u, int cnt){
    for (auto v : to[u]){
        if(!k) return;
        k--, ans[++pans] = {mp[1ll * u * (n + 1) + v]};
        dfs(v, cnt + 1);
    }
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
        mp[1ll * u * (n + 1) + v] = mp[1ll * v * (n + 1) + u] = i;
    }
    dj(1);
    // for (int i = 1; i <= n; i++){
    //     printf("dis %lld = %lld\n", i, dis[i]);
    // }
    for (int i = 1; i <= n; i++){
        // printf("%lld <- %lld\n", path[i], i);
        if(path[i]) to[path[i]].push_back(i);
    }
    dfs(1, 0);
    printf("%lld\n", pans);
    for (int i = 1; i <= pans; i++){
        printf("%lld ", ans[i]);
    }
    putchar('\n');
    return 0;
}