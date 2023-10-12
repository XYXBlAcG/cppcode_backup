#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
// #include "xyx.h"
// using namespace xyx;
#define INF 0x3f3f3f3f
const int N = 5e5 + 5;
int n, m, a[N], inser[N], root, tot, id[N];
char op[25];
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define fa(u) node[u].fa
#define sz(u) node[u].sz
#define val(u) node[u].val
#define tag(u) node[u].tag
#define cnt(u) node[u].cnt
#define mdf(u) node[u].mdf
#define sum(u) node[u].sum
#define lm(u) node[u].lm
#define rm(u) node[u].rm
#define mm(u) node[u].mm
#define rev(u) node[u].rev
#define INF 0x3f3f3f3f
struct Node{
    int ch[2], fa, val, sz, tag, cnt, sum, lm, rm, mm, rev;
    void clear(){
        ch[0] = ch[1] = fa = val = sz = tag = cnt = sum = lm = rm = mm = rev = 0;
    }
}node[N];
std::queue<int> q;
bool get(int u){return u == rs(fa(u));}
void clear(int u){
    if(ls(u)) clear(ls(u));
    if(rs(u)) clear(rs(u));
    q.push(u), node[u].clear();
}
struct Tree{
    void pushup(int u){
        sum(u) = sum(ls(u)) + sum(rs(u)) + val(u);
        sz(u) = sz(ls(u)) + sz(rs(u)) + 1;
        mm(u) = std::max(mm(ls(u)), std::max(mm(rs(u)), lm(rs(u)) + rm(ls(u)) + val(u)));
        lm(u) = std::max(lm(ls(u)), sum(ls(u)) + val(u) + lm(rs(u)));
        rm(u) = std::max(rm(rs(u)), sum(rs(u)) + val(u) + rm(ls(u)));
    }
    void updm(int u, bool op){if(u) {if(op) lm(u) = rm(u) = mm(u) = sum(u); else lm(u) = rm(u) = 0, mm(u) = val(u);}}
    void pushdown(int u){
        if(tag(u)){
            rev(u) = tag(u) = 0;
            if(ls(u)) tag(ls(u)) = 1, val(ls(u)) = val(u), sum(ls(u)) = val(u) * sz(ls(u));
            if(rs(u)) tag(rs(u)) = 1, val(rs(u)) = val(u), sum(rs(u)) = val(u) * sz(rs(u));
            // updm(ls(u), val(u) >= 0);
            // updm(rs(u), val(u) >= 0);
            if(val(u) >= 0) {
                if(ls(u)) lm(ls(u)) = rm(ls(u)) = mm(ls(u)) = sum(ls(u));
                if(rs(u)) lm(rs(u)) = rm(rs(u)) = mm(rs(u)) = sum(rs(u));
            }else{
                if(ls(u)) lm(ls(u)) = rm(ls(u)) = 0, mm(ls(u)) = val(u);
                if(rs(u)) lm(rs(u)) = rm(rs(u)) = 0, mm(rs(u)) = val(u);
            }
        }
        if(rev(u))
            rev(u) = 0, rev(ls(u)) ^= 1, rev(rs(u)) ^= 1, std::swap(lm(ls(u)), rm(ls(u))), std::swap(lm(rs(u)), rm(rs(u))), std::swap(ls(ls(u)), rs(ls(u))), std::swap(ls(rs(u)), rs(rs(u)));
    }
    // void rotate(int u){
    //     int f = fa(u), g = fa(f), w = get(u);
    //     node[f].ch[w] = node[u].ch[!w];
    //     if(node[u].ch[!w]) fa(node[u].ch[!w]) = f;
    //     node[u].ch[!w] = f, fa(f) = u, fa(u) = g;
    //     if(g) node[g].ch[f == rs(g)] = u;
    //     pushup(f), pushup(u);
    // }
    

    inline void rotate(int x, int &k){
        // printf("%d %d\n", x, k);
        int y = fa(x),z = fa(y),l = (rs(y) == x), r = l ^ 1;
        if (y == k) k = x; else node[z].ch[(rs(z) == y)] = x;
        fa(node[x].ch[r]) = y, fa(y) = x, fa(x) = z;
        node[y].ch[l] = node[x].ch[r], node[x].ch[r] = y;
        pushup(y), pushup(x);
    }

    // void splay(int u, int g){
    //     for (int f; (f = fa(u)) != g; rotate(u)){
    //         printf("%d %d %d\n", u, f, fa(f));
    //         if(fa(f) != g) rotate(get(u) == get(f) ? f : u);
    //     }
    //     if(!g) root = u;
    // }

    inline void splay(int x,int &k){
        while (x != k){
            int y = fa(x), z = fa(y);
            if (y != k){
                // printf("%d %d %d\n", x, y, z);
                // printf("%d %d %d\n", x, k, y);
                if (ls(z) == y ^ ls(y) == x) rotate(x, k);
                else rotate(y, k);
            }
            rotate(x, k);
        }
    }
    int find(int u){
        int cur = root;
        while(1){
            // puts("!");
            pushdown(cur);
            if(u <= sz(ls(cur))) cur = ls(cur);
            else {
                if(!(u -= (sz(ls(cur)) + 1))) return cur;
                cur = rs(cur);
            }
        }
    }
    // inline int find(int rank, int u = root){
    //     pushdown(u);
    //     if(sz(ls(u)) + 1 == rank) return u;
    //     if(sz(ls(u)) >= rank) return find(rank, ls(u));
    //     else return find(rank - sz(ls(u)) - 1, rs(u));
    // }
    int split(int u, int len){
        int l = find(u), r = find(u + len + 1);
        splay(l, root), splay(r, rs(l));
        return ls(r);
    }
    void build(int l, int r, int f){
        if(l > r) return;
        int mid = (l + r) >> 1, cur = id[mid], fath = id[f]; // node id vs. sub id
        if(l == r) lm(cur) = rm(cur) = std::max((mm(cur) = sum(cur) = a[l]), (tag(cur) = rev(cur) = 0)), sz(cur) = 1;
        build(l, mid - 1, mid), build(mid + 1, r, mid);
        val(cur) = a[mid], fa(cur) = fath, pushup(cur);
        node[fath].ch[mid >= f] = cur;
    }
    void reverse(int u, int len){
        int l = split(u, len), pf = fa(l);
        if(!tag(l)) rev(l) ^= 1, std::swap(ls(l), rs(l)), std::swap(lm(l), rm(l)), pushup(pf), pushup(fa(pf));
    }
    void del(int u, int len){
        int l = split(u, len), pf = fa(l);
        // puts("fff");
        clear(l), ls(pf) = 0, pushup(pf), pushup(fa(pf));
    }
    void insert(int u, int len){
        for (int i = 1; i <= len; i++) if(q.size()) id[i] = q.front(), q.pop(); else id[i] = ++tot;
        build(1, len, 0);
        int rot = id[(1 + len) >> 1], l = find(u + 1), r = find(u + 2);
        // puts("fuck");
        splay(l, root), splay(r, rs(l));
        // puts("fuckall");
        fa(rot) = r, ls(r) = rot;
        pushup(r), pushup(l);
    }
    void modify(int u, int len, int val){
        int l = split(u, len), fath = fa(l);
        val(l) = val, tag(l) = 1, sum(l) = val * sz(l);
        if(val >= 0) lm(l) = rm(l) = mm(l) = sum(l); else lm(l) = rm(l) = 0, mm(l) = val;
        pushup(fath), pushup(fa(fath));
    }
    void dfs(int u){
        if(ls(u)) dfs(ls(u));
        // output(6, (ls(u) > 0) ? ls(u) : -1, "<--" , u, "-->", (rs(u) > 0) ? rs(u) : -1, "mm =", mm(u));
        if(rs(u)) dfs(rs(u));
    }
}tree;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i + 1]);
    mm(0) = a[1] = -INF, a[n + 2] = -INF;
    for (int i = 1; i <= n + 2; i++) id[i] = i;
    tree.build(1, n + 2, 0);
    root = (n + 3) >> 1, tot = n + 2;
    // tree.dfs(root);
    for (int i = 1, rank, tt, c; i <= m; i++){
        scanf("%s", op);
        if(op[2] != 'X') scanf("%d%d", &rank, &tt);
        // std::cout << "op = " << op << '\n';
        if(op[0] == 'I'){
            for (int i = 1; i <= tt; i++) scanf("%d", a + i);
            tree.insert(rank, tt);
        }else if(op[0] == 'D'){
            tree.del(rank, tt);
        }else if(op[2] == 'K'){
            scanf("%d", &c);
            tree.modify(rank, tt, c);
        }else if(op[0] == 'R'){
            tree.reverse(rank, tt);
        }else if(op[0] == 'G'){
            printf("%d\n", sum(tree.split(rank, tt)));
        }else if(op[2] == 'X'){
            printf("%d\n", mm(root));
        }
        // tree.dfs(root);
        // putchar('\n');
    }
    return 0;
}
/*
-1
-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->    -1  mm =     2
3   <--     4   -->    -1  mm =     3
4   <--     5   -->    10  mm =    10
-1   <--     6   -->     7  mm =     1
-1   <--     7   -->     8  mm =    -3
-1   <--     8   -->    -1  mm =    -3
6   <--     9   -->    -1  mm =     6
9   <--    10   -->    11  mm =     9
-1   <--    11   -->    -1  mm =-1061109567

10
-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->    -1  mm =     2
3   <--     4   -->    -1  mm =     3
4   <--     5   -->    10  mm =    10
-1   <--     6   -->     7  mm =     1
-1   <--     7   -->     8  mm =    -3
-1   <--     8   -->    -1  mm =    -3
6   <--     9   -->    -1  mm =     6
9   <--    10   -->    11  mm =     9
-1   <--    11   -->    -1  mm =-1061109567

-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->    -1  mm =     2
3   <--     4   -->    -1  mm =     3
4   <--     5   -->     6  mm =     9
-1   <--     6   -->     7  mm =     1
-1   <--     7   -->     8  mm =    -3
-1   <--     8   -->    -1  mm =    -3
5   <--     9   -->    10  mm =    14
-1   <--    12   -->    -1  mm =    -5
12   <--    13   -->    14  mm =     9
-1   <--    14   -->    -1  mm =     2
13   <--    10   -->    11  mm =    12
-1   <--    11   -->    -1  mm =-1061109567

-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->    -1  mm =     2
3   <--     4   -->    -1  mm =     3
4   <--     5   -->     6  mm =     9
-1   <--     6   -->     7  mm =     1
-1   <--     7   -->     8  mm =    -3
-1   <--     8   -->    -1  mm =    -3
5   <--     9   -->    13  mm =    14
-1   <--    13   -->    -1  mm =     7
9   <--    14   -->    11  mm =    14
-1   <--    10   -->    -1  mm =     0
10   <--    11   -->    -1  mm =     3

-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->     7  mm =    18
-1   <--     4   -->     6  mm =     6
-1   <--     5   -->    -1  mm =     5
5   <--     6   -->    -1  mm =     6
4   <--     7   -->     9  mm =    18
-1   <--     8   -->    -1  mm =    -3
8   <--     9   -->    14  mm =    18
-1   <--    13   -->    -1  mm =     7
13   <--    14   -->    11  mm =    12
-1   <--    10   -->    -1  mm =     0
10   <--    11   -->    -1  mm =     3

-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->    13  mm =    18
-1   <--     8   -->    -1  mm =    -3
8   <--     9   -->    -1  mm =     6
9   <--     7   -->     4  mm =     6
-1   <--     4   -->     6  mm =     6
-1   <--     5   -->    -1  mm =     5
5   <--     6   -->    -1  mm =     6
7   <--    13   -->    14  mm =    18
-1   <--    14   -->    11  mm =     5
-1   <--    10   -->    -1  mm =     0
10   <--    11   -->    -1  mm =     3

1
-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->     9  mm =     6
-1   <--     9   -->    -1  mm =     6
3   <--     8   -->    13  mm =    18
-1   <--     7   -->     4  mm =     6
-1   <--     5   -->    -1  mm =     5
5   <--     6   -->    -1  mm =     6
6   <--     4   -->    -1  mm =     6
7   <--    13   -->    14  mm =    18
-1   <--    14   -->    11  mm =     5
-1   <--    10   -->    -1  mm =     0
10   <--    11   -->    -1  mm =     3

18
-1   <--     1   -->     2  mm =     2
-1   <--     2   -->    -1  mm =     2
1   <--     3   -->     9  mm =     6
-1   <--     9   -->    -1  mm =     6
3   <--     8   -->    13  mm =    18
-1   <--     7   -->     4  mm =     6
-1   <--     5   -->    -1  mm =     5
5   <--     6   -->    -1  mm =     6
6   <--     4   -->    -1  mm =     6
7   <--    13   -->    14  mm =    18
-1   <--    14   -->    11  mm =     5
-1   <--    10   -->    -1  mm =     0
10   <--    11   -->    -1  mm =     3
*/