#include <cstdio>
#include <vector>
const int N = 1e5 + 5;
int n, k, c[N], m[N], s[N][22], f[N][22], ans[N][22], step;
std::vector<int> st[N];
struct Node{
    int tmp[22];
};
void dfs(int x, int father){ // top to bottom
    for (auto v : st[x]){
        if(v != father){
            dfs(v, x);
            f[x][step + 1] += f[v][step] + 1;
            s[x][step + 1] += s[v][step];
        }
    }
}
void fdfs(int x, int father, int pass){
    int fans = 0;
    for (auto v : st[x]){
        if(v != father){
            ans[x][step] = pass + (n - s[v][step - 1]) + f[v][step - 1];
            fdfs(v, x, f[x][step] - f[v][step - 1] - s[v][step - 1]);
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++){
        s[i][1] = 1;
    }
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    for (step = 1; step <= k; step++){
        dfs(1, 0);
        fdfs(1, 0, 0);
    }
    for (int i = 1; i <= n; i++){
        printf("%d\n", ans[i][k]);
    }
    return 0;
}