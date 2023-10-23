#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 2e3 + 5, top = 2e3;
int t, n, m;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
void clean(){
    for (int i = 1; i <= top; i++) st[i].clear();
}
void dfs(int u){
    
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1, u, v, w; i <= m; i++){
            scanf("%d%d%d", &u, &v, &w);
            st[u].push_back({v, w});
            st[v].push_back({u, w});
        }

    }
    return 0;
}