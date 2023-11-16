#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f
#define LIM (int)(1e9)
const int N = 1e5 + 5;
int n, m, pedge;
struct UFS{
    int fa[N];
    UFS(){
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    void merge(int x, int y){
        fa[find(x)] = find(y);
    }
}ufs;
struct Node{
    int v, w;
};
struct Edge{
    int u, v;
}edge[N];
std::vector<Node> st[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
        edge[++pedge] = {u, v};
    }
    
    return 0;
}