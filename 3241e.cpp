#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 2e5 + 5;
int n, m, p[N], col[N], vis[N], ans[N];
std::vector<int> st[N];
void dfs(int x, int fath, int co){
    ans[x] = co;
    for (auto v : st[x]){
        if(v == fath) continue;
        vis[v]++; vis[x]++;
        if(!col[p[v]]) {
            col[p[v]] = 1;
            dfs(v, x, co + 1);
            col[p[v]] = 0;
        }else dfs(v, x, co);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i < n; i++){
        int a, w;
        scanf("%d%d",&a,&w);
        p[i] = w;
        st[a].push_back(i);
        st[i].push_back(a);
    }
    col[0] = 1;
    dfs(0, 0, 1);
    if(!st[0].size()){
        printf("0 1\n");
    }
    for (int i = 1; i < n; i++){
        if(vis[i] == 1){
            printf("%d %d\n", i, ans[i]);
        }
    }
    return 0;
}