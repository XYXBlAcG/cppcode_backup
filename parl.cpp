#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
const int N = 1e5 + 5;
int n, m, p[2 * N], vis[2 * N];
char ans[2 * N];
std::vector<int> st[2 * N];
void dfs(int u){
    vis[u] = 1;
    for (int v : st[u])
        if(!vis[v]) dfs(v);
}
bool chk(int u){
    memset(vis, 0, sizeof(vis));
    dfs(u);
    for (int i = 1; i <= n; i++) if(vis[i] && vis[i + n]) return 1;
    return 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b; i <= m; i++){
        char sa, sb;
        scanf("%d", &a); std::cin >> sa;
        scanf("%d", &b); std::cin >> sb;
        bool ca = (sa == 'Y'), cb = (sb == 'Y');
        // printf("ca = %d, cb = %d\n", ca, cb);
        st[a + (!ca) * n].push_back(b + cb * n);
        st[b + (!cb) * n].push_back(a + (ca) * n);
    }
    for (int i = 1; i <= n; i++){
        bool a = chk(i), b = chk(i + n);
        if(a && b) {
            puts("IMPOSSIBLE");
            return 0;
        }
        if(a && !b) ans[i] = 'Y';
        if(!a && b) ans[i] = 'N';
        if(!a && !b) ans[i] = '?';
    }
    for (int i = 1; i <= n; i++) printf("%c", ans[i]);
    putchar('\n');
    return 0;
}