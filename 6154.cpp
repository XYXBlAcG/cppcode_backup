#include <cstdio>
#include <cmath>
#include <algorithm>
typedef double d;
const int N = 2e5 + 5;
int n, pn, num[N];
d ans = 1e17;
struct Pos{
    int x, y;
}p[N];
d min(d a, d b){return (a > b) ? b : a;}
int ab(int a){return a < 0 ? -a : a;}
bool cx(Pos a, Pos b){return a.x < b.x;}
bool cy(int a, int b){return p[a].y < p[b].y;}
d pz(int a){return (d)a * a;}
d dis(int a, int b){return std::sqrt(pz(p[a].x - p[b].x) + pz(p[a].y - p[b].y));}
void solve(int l, int r){
    if(l == r) return;
    if(l + 1 >= r) return;
    if(l + 2 == r) {(ans = min(ans, dis(l, r) + dis(l + 1, r) + dis(l, r - 1))); return;}
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    pn = 0;
    d dd = ans * 0.5;
    for (int i = l; i <= r; i++) if(ab(p[i].x - p[mid].x) <= dd) num[++pn] = i;
    std::sort(num + 1, num + 1 + pn, cy);
    for (int i = 1, j = 1; i <= pn; i++){
        for (; j <= pn && ab(p[num[j]].y - p[num[i]].y) <= dd; j++);
        for (int k = i + 1; k < j; k++)
            for (int o = i + 1; o < k; o++)
                ans = min(ans, dis(num[k], num[o]) + dis(num[i], num[o]) + dis(num[i], num[k]));
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
    std::sort(p + 1, p + 1 + n, cx);
    solve(1, n);
    printf("%.6lf\n", ans);
    return 0;
}