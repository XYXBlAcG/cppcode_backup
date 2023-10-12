#include <cstdio>
#include <algorithm>
// #include "xyx.h"
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define fa(u) node[u].fa
#define size(u) node[u].size
#define val(u) node[u].val
#define tag(u) node[u].tag
#define cnt(u) node[u].cnt
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;
int n, m, root, tot, a[N];
struct Node{
    int ch[2], fa, val, size, tag, cnt;
}node[N];
void upd(int u){size(u) = size(ls(u)) + size(rs(u)) + cnt(u);}
bool get(int u){return u == rs(fa(u));}
struct Tree{
    void rotate(int u){
        // xyx::output(3, "u =", u);
        int f = fa(u), g = fa(f), w = get(u);
        pushdown(f), pushdown(u);
        node[f].ch[w] = node[u].ch[!w];
        if(node[u].ch[!w]) fa(node[u].ch[!w]) = f;
        node[u].ch[!w] = f, fa(f) = u, fa(u) = g;
        if(g) node[g].ch[f == rs(g)] = u;
        upd(f), upd(u);
        // upd(u), upd(f);
    }
    void splay(int u, int g){
        for (int f; (f = fa(u)) != g; rotate(u)){
            // printf("%d %d %d\n", u, f, g);
            if(fa(f) != g) rotate(get(u) == get(f) ? f : u);
        }
        if(!g) root = u;
    }
    int build(int l, int r, int f){
        if(l > r) return 0;
        int mid = (l + r) >> 1, cur = ++tot;
        node[cur] = {{build(l, mid - 1, cur), build(mid + 1, r, cur)}, f, a[mid], node[cur].size + 1, 0, node[cur].cnt + 1}, upd(cur);
        return cur;
    }
    void pushdown(int u){
        if(u && tag(u)) tag(ls(u)) ^= 1, tag(rs(u)) ^= 1, std::swap(ls(u), rs(u)), tag(u) = 0;
    }
    int find(int u){
        int cur = root;
        while(1){
            // printf("cur = %d %d\n", cur, u);
            pushdown(cur);
            
            if(u <= size(ls(cur))) cur = ls(cur);
            else {
                if(!(u -= (size(ls(cur)) + 1))) return cur;
                cur = rs(cur);
            }
        }
    }
    void reverse(int l, int r){
        l--, r++;
        // xyx::output(2, "b l =", l, " b r =", r);
        l = find(l), r = find(r);
        // xyx::output(2, "l =", l, " r =", r);
        splay(l, 0), splay(r, l);
        // printf("fuck = %d\n", ls(rs(root)));
        tag(ls(rs(root))) ^= 1;
        // upd(l), upd(r);
        // pushdown(root);
    }
    void output(int u){
        // printf("u = %d, ls = %d, rs = %d\n", u, ls(u), rs(u));
        // printf("%d ", a[u]);
        pushdown(u);
        if(ls(u)) output(ls(u));
        if(node[u].val != -INF && node[u].val != INF) printf("%d ", node[u].val);
        if(rs(u)) output(rs(u));
    }
}tree;
int main(){
    scanf("%d%d", &n, &m);
    a[1] = INF, a[n + 2] = -INF;
    for (int i = 1; i <= n; i++) a[i + 1] = i;
    root = tree.build(1, n + 2, 0);
    for (int i = 1, l, r; i <= m; i++){
        scanf("%d%d", &l, &r);
        tree.reverse(l + 1, r + 1);
    }
    // for (int i = 1; i <= n + 2; i++){
    //     printf("%d %d %d %d %d\n", i, ls(i), rs(i), fa(i), a[i]);
    //     // printf("i = %d\n", i);
    //     // printf("size = %d\n", size(i));
    //     // tree.output(i); putchar('\n');
    // }
    // printf("%d\n", root);
    tree.output(root), putchar('\n');
    return 0;
}
/*
u = 2
u = 3
u = 6
u = 6
u = 6
u = 5
1 4 0 2 -100000089
2 0 1 6 1
3 0 5 0 2
4 0 0 1 3
5 6 7 3 4
6 2 0 5 5
7 0 0 5 100000089
3
u = 3, ls = 0, rs = 5
u = 5, ls = 6, rs = 7
u = 6, ls = 2, rs = 0
u = 2, ls = 0, rs = 1
u = 1, ls = 4, rs = 0
u = 4, ls = 0, rs = 0
u = 7, ls = 0, rs = 0
*/