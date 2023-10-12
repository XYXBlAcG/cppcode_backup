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
        int f = fa(u), g = fa(f), chk = (u == rs(f));
        node[f].ch[chk] = node[u].ch[!chk];
        if(node[u].ch[!chk]) fa(node[u].ch[!chk]) = f;
        node[u].ch[!chk] = f;
        fa(f) = u, fa(u) = g;
        if(g) node[g].ch[f == rs(g)] = u;
        upd(u), upd(f);
    }
    void splay(int u, int g){
        for (int f = fa(u); (f = fa(u)) != g; rotate(u)){
            if(fa(u) != g) rotate(get(u) == get(f) ? f : u);
        }
        if(!g) root = u;
    }
    int find(int rnk){
        int cur = root;
        while(1){
            if(size(ls(cur)) + cnt(cur) < rnk) rnk -= size(ls(cur)) + cnt(cur),cur = rs(cur); 
            else{
                if(size(ls(cur)) >= rnk) cur = ls(cur);
                else {splay(cur, root); return val(cur);}
            }
        }
    }
    void insert(int val){
        if(!root) 
            return void(root = newnode(val));
        int cur = root;
        while(1){
            if(val == val(cur)){
                return void(cnt(cur)++);
            }else{
                if(val < val(cur)){
                    if(ls(cur)) cur = ls(cur);
                    else ls(cur) = newnode(val);
                } 
                else if(val > val(cur)) {
                    if(rs(cur)) cur = rs(cur);
                    else rs(cur) = newnode(val);
                }
            }
        }
    }
    int qval(int val){
        if(!root) return 0;
        int cur = root;
        while(1){
            if(val == val(cur)){
                // splay(cur, root);
                return size(ls(cur)) + cnt(cur);
            }else {
                if(val < val(cur)) {
                    if(ls(cur)) cur = ls(cur);
                    else return 0;
                }else{
                    if(rs(cur)) cur = rs(cur);
                    else return 0;
                }
            }
        }
    }
}tree;

int main(){
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1, op, x; i <= n; i++){
        scanf("%d%d", &op, &x);
        if(op == 1){
            tree.insert(ans ^ x);
        }else if(op == 2){
            printf("%d\n", ans = tree.qval(x ^ ans));
        }else{
            printf("%d\n", ans = tree.find(x ^ ans));
        }
    }
    return 0;
}