#include <cstdio>
#include <vector>
const int N = 1e5 + 5;
int n; long long s[N], ans[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
void dfs(int x, int father){ // top to bottom
    for (auto v : st[x]){
        if(v.v != father){
            dfs(v.v, x);
            s[x] += s[v.v];
            ans[x] += (n - s[v.v]) * v.w * s[v.v] + ans[v.v]; // 经过次数 * 边权
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) s[i] = 1;
    for (int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        st[u].push_back((Node){v, w});
        st[v].push_back((Node){u, w});
    }
    dfs(1, 0);
    printf("%lld\n", ans[1]);
    return 0;
}