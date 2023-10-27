#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define EPS 1e-6
using std::cin;
using std::cout;
using std::string;
typedef double d;
const int N = 1e5 + 5, T = 5e4 + 5;
int n, id[N * 4], aid, cnt;
d res;
bool d0(d x){return std::fabs(x) < EPS;}
struct Node{
    d k, b;
}node[N];
d cal(int x, int pos){
    // cout << "x = " << x << " val = " << node[x].k * (d)(pos - 1) + node[x].b << '\n';
    return node[x].k * (d)(pos - 1) + node[x].b;
}
bool chk(int x, int y, int pos){
    // cout << "x = " << x << " y = " << y << '\n';
    d xx = cal(x, pos), yy = cal(y, pos);
    return d0(xx - yy) ? x < y : xx > yy;
}
struct Tree{
    void modify(int u, int l, int r, int ql, int qr, int cur){
        if(l > qr || ql > r) return;
        int mid = (l + r) >> 1;
        if(ql <= l && r <= qr){
            if(chk(cur, id[u], l) && chk(cur, id[u], r)) return (void)(id[u] = cur);
            if(chk(id[u], cur, l) && chk(id[u], cur, r)) return;
            if(chk(cur, id[u], mid)) std::swap(cur, id[u]);
            if(chk(cur, id[u], l)) modify(ls(u), l, mid, ql, qr, cur);
            if(chk(cur, id[u], r)) modify(rs(u), mid + 1, r, ql, qr, cur);
            return;
        }
        modify(ls(u), l, mid, ql, qr, cur);
        modify(rs(u), mid + 1, r, ql, qr, cur);
    }
    d query(int u, int l, int r, int pos){
        if(l > pos || r < pos) return 0;
        if(l == r) return cal(id[u], pos);
        int mid = (l + r) >> 1;
        return std::max({query(ls(u), l, mid, pos), query(rs(u), mid + 1, r, pos), cal(id[u], pos)});
    }
}tree;
int main(){
    std::ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1, t; i <= n; i++){
        string op;
        d s, p;
        cin >> op;
        if(op[0] == 'Q'){
            cin >> t;
            aid = 0;
            cout << (int)(tree.query(1, 1, T, t) / 100) << '\n';
        }else{
            cin >> s >> p;
            node[++cnt] = {p, s};
            tree.modify(1, 1, T, 1, T, cnt);
        }
    }
    return 0;
}