#include <cstdio>
#include <vector>
const int N = 5e5 + 5;
int n, k, s[N], f[N], long_1[N], long_2[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
void dfs(int u, int fath, int id){
    for (auto v : st[u]){
        dfs(v.v, u, id);
        s[u] += s[v.v];
        f[u] = f[v.v] + 2 * v.w;
        
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++){
        s[i] = 1;
    }
    for (int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        st[u].push_back((Node){v, w});
        st[v].push_back((Node){u, w});
    }
    
    return 0;
}