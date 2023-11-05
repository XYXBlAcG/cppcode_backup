#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mx(u) node[u].mx
#define tg(u) node[u].tag
const int N = 1005;
int D, S, n;
struct Node{
    int mx, tag;
};
struct Tree{
    Node node[N << 2];
    Tree(){memset(node, 0, sizeof(node));}
    void modify(int u, int l, int r, int ql, int qr, int val){
        if(l > qr || r < ql) return;
        mx(u) = std::max(mx(u), val);
        if(ql <= l && r <= qr)
            return void(tg(u) = std::max(tg(u), val));
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, val), modify(rs(u), mid + 1, r, ql, qr, val);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return 0;
        if(ql <= l && r <= qr) return mx(u);
        int mid = (l + r) >> 1;
        return std::max({query(ls(u), l, mid, ql, qr),
        query(rs(u), mid + 1, r, ql, qr), tg(u)});
    }
};
struct Note{
    Tree mx, tag;
};
struct Seg_Tree{
    Note node[N << 2];
    void modify(int u, int l, int r, int ql, int qr, int ql2, int qr2, int val){
        if(l > qr || r < ql) return;
        mx(u).modify(1, 1, S, ql2, qr2, val);
        if(ql <= l && r <= qr) return void(tg(u).modify(1, 1, S, ql2, qr2, val));
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, ql2, qr2, val), modify(rs(u), mid + 1, r, ql, qr, ql2, qr2, val);
    }
    int query(int u, int l, int r, int ql, int qr, int ql2, int qr2){
        if(l > qr || r < ql) return 0;
        if(ql <= l && r <= qr) return mx(u).query(1, 1, S, ql2, qr2);
        int mid = (l + r) >> 1;
        return std::max({query(ls(u), l, mid, ql, qr, ql2, qr2),
        query(rs(u), mid + 1, r, ql, qr, ql2, qr2), tg(u).query(1, 1, S, ql2, qr2)});
    }
}seg;
int main(){
    scanf("%d%d%d", &D, &S, &n);
    for (int i = 1, d, s, w, x, y; i <= n; i++){
        scanf("%d%d%d%d%d", &d, &s, &w, &x, &y), x++, y++;
        seg.modify(1, 1, D, x, x + d - 1, y, y + s - 1, w + seg.query(1, 1, D, x, x + d - 1, y, y + s - 1));
    }
    printf("%d\n", seg.query(1, 1, D, 1, D, 1, S));
    return 0;
}