#include <cstdio>
#include <vector>
const int N = 2e5 + 5;
int n, m;
std::vector<int> st[N];
void dfs(int u){
    
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    return 0;
}