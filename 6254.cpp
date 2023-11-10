#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) node[u].ls
#define rs(u) node[u].rs
#define ml(u) node[u].ml
#define mr(u) node[u].mr
#define mx(u) node[u].mx
#define mid ((l + r) >> 1)
const int N = 5e4 + 5;
int n, m, p[N], idx[N], sz, cnt, rt, ans[N];
struct Node{
    int ls, rs, ml, mr, mx;
}node[N << 4];
struct Tree{
    void pushup(int u, int l, int r){
        mx(u) = std::max({mx(ls(u)), mx(rs(u)), mr(ls(u)) + ml(rs(u))});
        ml(u) = ml(ls(u)) + ((mid - l + 1) == ml(ls(u))) * ml(rs(u));
        mr(u) = mr(rs(u)) + ((r - mid) == mr(rs(u))) * mr(ls(u));
    }
    void modify(int& u, int l, int r, int pos, int v){
        if(l > pos || r < pos) return;
        if(!u) u = ++cnt;
        if(l == r) return void(mx(u) = ml(u) = mr(u) = v);
        modify(ls(u), l, mid, pos, v), modify(rs(u), mid + 1, r, pos, v);
        pushup(u, l, r);
    }
}tree;
struct Seg{
    int l, r, id;
}seg[N];
bool cmp(Seg a, Seg b){
    return (idx[a.l] ^ idx[b.l]) ? a.l < b.l : ((idx[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
void add(int x){tree.modify(rt, 1, n, p[x], 1);}
void del(int x){tree.modify(rt, 1, n, p[x], 0);}
int main(){
    scanf("%d%d", &n, &m), sz = (int)sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i), idx[i] = (i - 1) / sz + 1;
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &seg[i].l, &seg[i].r), seg[i].id = i;
    }
    std::sort(seg + 1, seg + 1 + m, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++){
        while(l > seg[i].l) add(--l);
        while(r < seg[i].r) add(++r);
        while(l < seg[i].l) del(l++);
        while(r > seg[i].r) del(r--);
        ans[seg[i].id] = node[rt].mx;
    }
    for (int i = 1; i <= m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}