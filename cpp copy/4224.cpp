#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define int long long
int n, ans;
struct Node{int x, y, l;} po[23];
void dfs(Node a, int i, int s){
    if(a.l <= 0) return;
    if(i > n) {ans += (a.l * a.l * s); return;}
    int xm = std::max(a.x, po[i].x), ym = std::max(a.y, po[i].y);
    int lm = std::min(a.l - (xm - a.x) - (ym - a.y), po[i].l - (xm - po[i].x) - (ym - po[i].y));
    dfs(a, i + 1, s), dfs((Node){xm, ym, lm}, i + 1, -s);
}
signed main(){
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld",&po[i].x,&po[i].y,&po[i].l);
    dfs((Node){0, 0, INF}, 1, 1);
    printf("%lld\n", 1ll * INF * INF - ans);
    return 0;
}