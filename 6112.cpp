#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long
#define np nullptr
#define pir std::pair<Node*, Node*>
#define siz(u) (u == np ? 0 : u->size)
const int N = 1e5 + 5;
int n, m, a[N];
struct Node{
    Node* son[2];
    long long val, rank, cnt, size;
    Node(long long val){rank = rand(), this->val = val; cnt = size = 1, son[0] = son[1] = np;}
    inline void upd(){
        size = cnt;
        if(son[0] != np) size += son[0]->size;
        if(son[1] != np) size += son[1]->size;
    }
}*root;
struct Tree{
    inline pir split(Node* cur, int size){
        if(cur == np) return {np, np};
        if(siz(cur->son[1]) <= size){
            pir tmp = split(cur->son[1], size - siz(cur->son[0]) - 1);
            cur->son[1] = tmp.first, cur->upd();
            return {cur, tmp.second};
        }else{
            pir tmp = split(cur->son[0], size);
            cur->son[0] = tmp.second, cur->upd();
            return {tmp.first, cur};
        }
    }
    inline Node* merge(Node* u, Node* v){
        if(u == np || v == np) return u == np ? v : u; 
        if(u->rank < v->rank){
            u->son[1] = merge(u->son[1], v), u->upd();
            return u;
        }else{
            v->son[0] = merge(u, v->son[0]), v->upd();
            return v;
        }
    }
    inline void insert(int cur, int val){
        pir tmp = split(root, cur);
        pir l = split(tmp.first, cur - 1);
        Node* lc = merge(l.first, l.second = np ? new Node(val) : l.second);
        root = merge(lc, tmp.second);
    }
    inline void del(int cur){
        pir tmp = split(root, cur);
        pir l = split(tmp.first, cur - 1);
        if(l.second->cnt > 1) l.second->cnt--, l.second->upd(), l.first = merge(l.first, l.second);
        else{
            if(tmp.first == l.second) tmp.first = np;
            delete l.second;
            l.second = np;
        }
        root = merge(l.first, tmp.second);
    }
    inline void modify(int cur, int val){
        del(cur), insert(cur, val);
    }
    inline void query(int cur, int len){
        
    }
    
}tree;

signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i), tree.insert(i, a[i]);
    for (int i = 1, op, l, r; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l, &r);
        if(op == 1) tree.insert(l, r);
        if(op == 2) tree.modify(l, r);
        // if(op == 3)
    }
    return 0;
}