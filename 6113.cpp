#include <cstdio>
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define fa(u) node[u].fa
#define size(u) node[u].size
#define val(u) node[u].val
#define cnt(u) node[u].cnt
const int N = 1e5 + 5;
int n, m, root;
struct Node{
    int ch[2], fa, val, cnt, size;
}node[N];
void upd(int u){node[u].size = size(ls(u)) + size(rs(u)) + 1;}
bool get(int u){return u == rs(fa(u));}
void clear(int u){ls(u) = rs(u) = fa(u) = size(u) = val(u) = cnt(u) = 0;}
struct Tree{
    void rotate(int u){
        int fath = fa(u), grand = fa(fath), w = get(u);
        node[fath].ch[w] = node[u].ch[!w];
        if(node[u].ch[!w]) fa(node[u].ch[!w]) = fath;
        node[u].ch[!w] = fath, fa(fath) = u, fa(u) = grand;
        if(grand) node[grand].ch[fath == rs(grand)] = u;
        upd(fath), upd(u);
    }

}tree;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, l, r; i <= m; i++){
        scanf("%d%d", &l, &r);

    }
    return 0;
}