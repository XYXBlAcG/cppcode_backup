#include <cstdio>
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define val(u) node[u].val
#define fa(u) node[u].fa
#define size(u) node[u].size
#define cnt(u) node[u].cnt
int n, root, pnode;
const int N = 1e5 + 5;
struct Node{
    int ch[2], val, fa, size, cnt;
}node[N];
void upd(int u){
    size(u) = size(ls(u)) + size(rs(u)) + cnt(u);
}
int newnode(int val){
    node[++pnode] = {{0, 0}, val, 0, 1, 1};
    return pnode;
}
bool get(int u){return u == rs(fa(u));}
struct Tree{
    void rotate(int u){
        int f = fa(u), g = fa(g), chk = (u == rs(f));
        node[f].ch[chk] = node[u].ch[!chk];
        fa(node[f].ch[chk]) = f;
        node[u].ch[chk] = f;
        fa(f) = u, fa(u) = g;
        if(g) node[g].ch[f == rs(g)] = u;
    }
    int find(int rnk){
        int cur = root;
        while(1){
            if(size(ls(cur)) + cnt(cur) < rnk) cur = rs(cur); 
            else{
                if(size(ls(cur)) >= rnk) cur = ls(cur);
                else return cur;
            }
        }
    }
    void splay(int u, int g){
        for (int f = fa(u); (f = fa(u)) != g; f = fa(u)){
            if(fa(u)) rotate(get(u) == get(f) ? u : f);
        }
        if(!g) root = u;
    }
    void insert(int u){
        
    }
};

int main(){
    scanf("%d", &n);
    for (int i = 1, op, x; i <= n; i++){
        scanf("%d%d", &op, &x);
        if(op == 1){

        }else if(op == 2){

        }else{

        }
    }
    return 0;
}