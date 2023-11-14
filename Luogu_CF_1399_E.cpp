#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int t, n, s, lef[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
void dfs(int u, int fath){
    if(st[u].size() == 1) lef[u] = 1;
    for (auto v : st[u]){
        if(v.v == fath) continue;
        dfs(v.v, u);
        lef[u] += lef[v.v];
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &s);
        for (int i = 1, u, v, w; i <= n; i++){
            scanf("%d%d%d", &u, &v, &w);
            st[u].push_back({v, w});
            st[v].push_back({u, w});
        }
    }
    return 0;
}