#include <cstdio>
#include <vector>
#include <algorithm>
using std::max;
#define INF 0x3f3f3f3f
const int N = 1e3 + 5, M = 1e5 + 5;
int n, m, ord[N], pord, v[N], w[N], ww, vv, a; long long s[N], ans[N][M];
std::vector<int> st[N];
void dfs(int u){
    for (auto v : st[u])
        dfs(v), s[u] += s[v];
    ord[++pord] = u;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d",&vv,&ww,&a);
        st[(a != i) ? a : 0].push_back(i);
        s[i] = 1, v[i] = vv, w[i] = ww;
    }
    dfs(0);
    for (int i = 1; i <= n; i++){
        long long tmp = ord[i], jump = s[ord[i]];
        for (int j = 0; j <= m; j++){
            if(j < v[tmp]){
                ans[i][j] = ans[i - jump][j];
            }else{
                ans[i][j] = max(ans[i - jump][j], ans[i - 1][j - v[tmp]] + w[tmp]);
            }
        }
    }
    printf("%lld\n", ans[n][m]);
    return 0;
}