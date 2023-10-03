#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define np nullptr
#define mxs(id) (ch[id] != np ? ch[id]->mx : -INF)
using std::max;
int n, m, val;
struct Node{
    Node* ch[2];
    int val, size, mx, hp;
    Node(int val){ch[0] = ch[1] = np, size = 1, hp = rand(), this->val = mx = val;}
    void upd(){
        mx = max(max(mxs(0), mxs(1)), val);
        size = 1;
        if(ch[0] != np) size += ch[0]->size;
        if(ch[1] != np) size += ch[1]->size;
    }
}*root;
struct Tree{
    inline void rotate(Node *&v, bool sn){
        Node *tmp = v->ch[sn];
        v->ch[sn] = tmp->ch[!sn], tmp->ch[!sn] = v, v->upd(), tmp->upd(), v = tmp;
    }
    inline void insert(Node*& v, int idx){
        if(v == np) return void(v = new Node(val));
        int rank = (v->ch[0] != np ? (v->ch[0]->size + 1) : 1);
        bool sn = (idx >= rank);
        insert(v->ch[sn], idx - sn * rank);
        if((v->hp) < (v->ch[sn] != np ? (v->ch[sn]->hp) : 0)) rotate(v, sn);
        else v->upd();
    }
    inline void modify(Node*& v, int idx){
        if(v == np) return;
        int rank = (v->ch[0] != np ? (v->ch[0]->size + 1) : 1);
        bool sn = (idx >= rank);
        if(idx == rank) {v->val = val; return void(v->upd());}
        modify(v->ch[sn], idx - sn * rank), v->upd();
    }
    inline int query(Node* v, int l, int r){
        if(v == np) return -INF;
        // hpntf("v->id = %lld %lld %lld\n", v->idx, v->val, v->mx);
        if(r < 1 || l > v->size) return -INF;
        if(l <= 1 && v->size <= r) return v->mx;
        int rank = (v->ch[0] != np ? (v->ch[0]->size + 1) : 1);
        int ans = (l <= rank && rank <= r) ? v->val : -INF;
        for (int i = 0; i <= 1; i++) ans = max(ans, query(v->ch[i], l - i * rank, r - i * rank));
        return ans;
    }
}tree;
signed main(){
    srand(114514);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &val), tree.insert(root, i);
    for (int i = 1, op, l; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l, &val);
        if(op == 1) tree.insert(root, l - 1);
        if(op == 2) tree.modify(root, l);
        if(op == 3) printf("%lld\n", tree.query(root, l, val));
    }
    return 0;
}