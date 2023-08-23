#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#define l(u) t[u].l
#define r(u) t[u].r
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
#define len(u) r(u) - l(u) + 1
#define int long long
const int N = 1e6 + 5;
int n, ta[N], res, heng, shu, last;
std::vector<int> bu;
std::map <int, int> ma;
struct Tree{
    int l, r, sum, num, bl, br, len;
}t[N << 2];
struct Rec{
    int x, y1, y2, tag;
}rec[N << 2];
bool cmp(Rec a, Rec b){ return a.x < b.x; }
void pushup(int u){
    if(ta[u]){
        t[u].sum = t[u].len = bu[r(u)] - bu[l(u) - 1];
        t[u].num = t[u].bl = t[u].br = 1;
    }else{
        t[u].sum = t[ls(u)].sum + t[rs(u)].sum;
        t[u].len = t[ls(u)].len + t[rs(u)].len;
        t[u].bl = t[ls(u)].bl, t[u].br = t[rs(u)].br;
        t[u].num = t[ls(u)].num + t[rs(u)].num - (t[ls(u)].br & t[rs(u)].bl);
    }
}
void build(int u, int l, int r){
    t[u] = {l, r, 0, 0, 0, 0, 0};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    pushup(u);
}
void modify(int u, int l, int r, int tag){
    if(l(u) > r || r(u) < l) return;
    if(l(u) >= l && r(u) <= r){
        ta[u] += tag;
        pushup(u);
        return;
    }
    modify(ls(u), l, r, tag);
    modify(rs(u), l, r, tag);
    pushup(u);
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        rec[i] = {x1, y1, y2, 1};
        rec[i + n] = {x2, y1, y2, -1};
        bu.push_back(y1), bu.push_back(y2);
    }
    std::sort(rec + 1, rec + 1 + 2 * n, cmp);
    std::sort(bu.begin(), bu.end());
    std::unique(bu.begin(), bu.end());
    int cnt = 0;
    for (auto v : bu) ma[v] = ++cnt;
    build(1, 1, cnt);
    for (int i = 1; i <= 2 * n; i++){
        modify(1, ma[rec[i].y1], ma[rec[i].y2] - 1, rec[i].tag);
        res += (rec[i + 1].x - rec[i].x) * t[1].sum;
        heng += std::abs(t[1].len - last);
        shu += (rec[i + 1].x - rec[i].x) * t[1].num * 2;
        last = t[1].len;
    }
    printf("%lld %lld\n", heng + shu, res);
    return 0;
}