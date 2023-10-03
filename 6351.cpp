#include <cstdio>
#include <algorithm>
const int M = 2e6 + 5;
int n, m, cnt, size[M], go[M], ans;
bool vis[M];
struct Pos{
    int v, id;
    bool type;
}pos[M];
bool low(Pos a, Pos b){return a.v < b.v;}
bool high(int a, int b){return a > b;}
void dfs(int u){
    if(vis[u]) return; vis[u] = 1;
    size[cnt]++;
    dfs(go[u]);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, w, e; i <= n; i++) 
        scanf("%d%d", &w, &e), pos[i] = {w, i, 0}, pos[i + n] = {e, i, 1};
    std::sort(pos + 1, pos + 1 + 2 * n, low);
    go[0] = pos[1].id + n;
    for (int i = 1; i <= 2 * n; i++){
        if(i < 2 * n) go[pos[i].id + n * pos[i].type] = pos[i + 1].id + (pos[i + 1].type ^ 1) * n;
        go[pos[i - 1].id + n * pos[i - 1].type] = pos[i].id + (pos[i].type ^ 1) * n;
    }
    for (int i = 0; i <= 2 * n; i++)
        if(!vis[i]) cnt++, dfs(i);
    std::sort(size + 2, size + 1 + cnt, high);
    ans = size[1] - 1;
    for (int i = 2; i <= cnt; i++)
        if(m) ans += size[i] + 2, m--; else break;
    if(m & 1) ans++, m--;
    ans += 2 * m;
    printf("%d\n", ans);
    return 0;
}