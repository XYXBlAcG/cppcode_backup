#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
const int N = 3e5 + 5;
const int M = 1e6 + 5;
int n, m, vis[M], ans[M], pans;
std::vector<int> st[M];
int in[M];

bool toposort() {
    std::vector<int> L;
    std::queue<int> S;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) S.push(i);
    while (!S.empty()) {
        int u = S.front();
        S.pop();
        L.push_back(u);
        for (auto v : st[u]) {
            if (--in[v] == 0) {
                S.push(v);
            }
        }
    }
    if (L.size() == n) {
        for (auto i : L) ans[++pans] = i;
        return true;
    } else {
        return false;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        in[v]++;
        st[u].push_back(v);
    }
    // dfs(1);
    if(!toposort()){
        printf("No solution\n");
    }else{
        for (int i = 1; i <= n; i++){
            printf("%d ", ans[i]);
        }
    }
    
    return 0;
}