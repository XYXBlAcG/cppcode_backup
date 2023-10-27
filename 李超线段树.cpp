#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define EPS 1e-6
const int N = 2e5 + 5, mod1 = 39989, mod2 = 1e9;
typedef double d;
int n, aid, cnt;
bool dcp(d x){
    return std::fabs(x) < EPS;
}
struct Line{
    d k, b;
}line[N];
int id[N * 4];
d g(int x, int pos){return line[x].k * (d)pos + line[x].b;}
bool chk(int x, int y, int pos){ 
    d xx = g(x, pos), yy = g(y, pos);
    return dcp(xx - yy) ? x < y : xx > yy;
}
struct LichaoTree{
    void modify(int u, int l, int r, int ql, int qr, int cur){
        if(r < ql || l > qr) return;
        int mid = (l + r) >> 1;
        if(ql <= l && r <= qr){
            if(chk(cur, id[u], l) && chk(cur, id[u], r)) return (void)(id[u] = cur);
            if(chk(id[u], cur, l) && chk(id[u], cur, r)) return;
            if(chk(cur, id[u], mid)) std::swap(cur, id[u]);
            if(chk(cur, id[u], l)) modify(ls(u), l, mid, ql, qr, cur);
            if(chk(cur, id[u], r)) modify(rs(u), mid + 1, r, ql, qr, cur); 
            return;
        }
        modify(ls(u), l, mid, ql, qr, cur), modify(rs(u), mid + 1, r, ql, qr, cur);
    }
    void solve(int u, int l, int r, int pos){
        if(l > pos || r < pos) return;
        if(chk(id[u], aid, pos)) aid = id[u];
        if(l == r) return;
        int mid = (l + r) >> 1;
        solve(ls(u), l, mid, pos), solve(rs(u), mid + 1, r, pos);
    }
}tree;
void print(){
    for (int i = 1; i <= cnt; i++){
        printf("%lf %lf\n", line[i].k, line[i].b);
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1, op, k, x0, x1, y0, y1, las = 0; i <= n; i++) {
        scanf("%d", &op);
        if(!op){
            scanf("%d", &k), k = (k + las - 1) % mod1 + 1, aid = 0;
            // printf("k = %d\n", k);
            tree.solve(1, 1, mod1, k);
            printf("%d\n", las = aid);
        }else{
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            x0 = (x0 + las - 1) % mod1 + 1;
            x1 = (x1 + las - 1) % mod1 + 1;
            y0 = (y0 + las - 1) % mod2 + 1;
            y1 = (y1 + las - 1) % mod2 + 1;
            // printf("x= %d %d %d %d\n", x0, y0, x1, y1);
            if(x0 > x1) std::swap(x0, x1), std::swap(y0, y1);
            if(x0 ^ x1) line[++cnt] = {(d)(y1 - y0) / (d)(x1 - x0), (d)y1 - (d)(y1 - y0) / (d)(x1 - x0) * (d)x1};
            else line[++cnt] = {0.0, (d)std::max(y1, y0)};
            tree.modify(1, 1, mod1, x0, x1, cnt);
        }
        // print();
    }
    return 0;
}