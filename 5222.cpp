#include <cstdio>
#include <algorithm>
#include <map>
#define int long long
using std::sort;
const int N = 1e6 + 5;
int n, ppos, res[N], t[N], tx, cnt, ans;
struct Node{
    int x, y;
}pos[N];
struct Tree{
    int id, l, r, y;
}tr[N];
bool xx(Node a, Node b){
    if(a.x == b.x) return a.y < b.y; return a.x < b.x;
}
bool yy(Node a, Node b){
    if(a.y == b.y) return a.x < b.x; return a.y < b.y;
}
bool ll(Tree a, Tree b){
    if(a.r == b.r) return a.id < b.id; return a.r < b.r;
}
int lowbit(int x){ return x & (-x); }
void add(int x, int c){
    for (; x <= n; x += lowbit(x)) res[x] += c;
}
int query(int x){
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += res[x];
    return ans;
}
void init(){
    scanf("%lld", &n), ans = n;
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &pos[i].x, &pos[i].y), t[i] = pos[i].x;
    sort(t + 1, t + 1 + n); 
    tx = std::unique(t + 1, t + 1 + n) - t - 1;
    for (int i = 1; i <= n; i++) pos[i].x = std::lower_bound(t + 1, t + 1 + tx, pos[i].x) - t;
    sort(pos + 1, pos + 1 + n, xx);
    for (int i = 1; i < n; i++){
        if(pos[i].x == pos[i + 1].x){
            tr[++cnt] = {2, pos[i].x, pos[i].y, 0};
            tr[++cnt] = {0, pos[i].x, pos[i + 1].y, 0};
        }
    }
    sort(pos + 1, pos + 1 + n, yy);
    for (int i = 1; i < n; i++){
        if(pos[i].y == pos[i + 1].y){
            tr[++cnt] = {1, pos[i].x, pos[i].y, pos[i + 1].x};
        }
    }
    sort(tr + 1, tr + 1 + cnt, ll);
}
void solve(){
    for (int i = 1; i <= cnt; i++)
        if(tr[i].id == 1) ans += query(tr[i].y - 1) - query(tr[i].l);
        else add(tr[i].l, tr[i].id - 1);
    printf("%lld\n", ans);
}
signed main(){
    init();
    solve();
    return 0;
}