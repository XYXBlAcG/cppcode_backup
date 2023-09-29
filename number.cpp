#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
const int N = 65;
int t, lx, rx, ly, ry, rec[N][2][2][2][2], ml; bool vis[N][2][2][2][2];
struct Num{
    int d[N], len;
    void build(int x){while(x) d[++len] = x % 2, x /= 2;}
    int operator[](int x){return d[x];}
}nlx, nrx, nly, nry, T;
struct Node{Num& a; int& b;};
int dfs(int x, bool xl, bool xr, bool yl, bool yr){
    if(!x) return 1;
    if(vis[x][xl][xr][yl][yr]) return rec[x][xl][xr][yl][yr]; vis[x][xl][xr][yl][yr] = 1;
    int mx = 0;
    for (int i = 0; i < 4; i++){
        int tx = "1100"[i] - '0', ty = "0101"[i] - '0';
        if((tx | ty) != T[x]) continue;
        if(xl && (tx < nlx[x])) continue;
        if(xr && (tx > nrx[x])) continue;
        if(yl && (ty < nly[x])) continue;
        if(yr && (ty > nry[x])) continue;
        int res = dfs(x - 1, xl && tx == nlx[x], xr && tx == nrx[x], yl && ty == nly[x], yr && ty == nry[x]);
        if(tx & ty) rec[x][xl][xr][yl][yr] += res; else mx = std::max(mx, res);
    }return (rec[x][xl][xr][yl][yr] += mx);
}
signed main(){
    scanf("%lld%lld%lld%lld%lld", &t, &lx, &rx, &ly, &ry);
    for (Node& a : (Node[5]){{T, t}, {nlx, lx}, {nrx, rx}, {nly, ly}, {nry, ry}})
        a.a.build(a.b), ml = std::max(ml, a.a.len);
    printf("%lld\n", dfs(ml, 1, 1, 1, 1));
    return 0;
}