#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
using std::max; using std::min;
const int N = 3e5 + 5;
int n, p[N], fa[N][20], amin[N][20], dep[N], ans[N];
std::vector<int> st[N];
int get(int i){
    int cur = i, step = p[i], mn = INF;
    for (int j = 20; j >= 0 && step; j--){
        if((1 << j) > step) continue;
        step -= (1 << j);
        mn = min(mn, amin[cur][j]);
        cur = fa[cur][j];
    }
    return mn;
}
void dfs(int x, int father){
    fa[x][0] = father;
    amin[x][0] = ans[father] + 1;
    for (int i = 1; i <= 20; i++){
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        amin[x][i] = min(amin[x][i - 1], amin[fa[x][i - 1]][i - 1]);
    }
    ans[x] = get(x);
    for (auto v : st[x]){
        if(v != father) {
            dfs(v, x);
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 2; i <= n; i++){
        int f, l;
        scanf("%d%d",&f,&l);
        p[i] = l;
        st[f].push_back(i);
    }
    p[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++){
        printf("%d\n", ans[i] - 1);
    }
    return 0;
}