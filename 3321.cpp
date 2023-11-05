#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 3e5 + 5;
int n, m, dfn[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
struct UFS{

};
struct Tarjan{
    void solve(){
        
    }
};
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
    
    return 0;
}