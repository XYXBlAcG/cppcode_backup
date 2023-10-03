#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define np nullptr
#define rnk(u) (u->son[0] != np ? (u->son[0]->size + 1) : 0)
#define mxs(id) (son[id] != np ? son[id]->mx : -INF)
using std::max;
int n, m, idd;
struct Node{
    Node* son[2];
    int val, size, mx, pri, idx;
    Node(int val, int idx){son[0] = son[1] = np, size = 1, pri = rand(), this->val = mx = val, this->idx = idx;}
    void upd(){
        mx = max(max(mxs(0), mxs(1)), val);
        // printf("%lld %lld %lld %lld\n", mx, val, mxs(0), mxs(1));
        size = 1;
        if(son[0] != np) size += son[0]->size;
        if(son[1] != np) size += son[1]->size;
    }
}*root;
struct Tree{
    inline void rotate(Node *&cur, bool dir){
        Node *tmp = cur->son[dir];
        cur->son[dir] = tmp->son[!dir], tmp->son[!dir] = cur, tmp->upd(), cur->upd(), cur = tmp;
    }
    inline void insert(Node*& cur, int idx, int val){
        if(cur == np) return void(cur = new Node(val, idd));
        int rank = rnk(cur);
        bool dir = (idx >= rank);
        insert(cur->son[dir], idx - dir * rank, val);
        if((cur->pri) < (cur->son[dir] != np ? (cur->son[dir]->pri) : 0)) rotate(cur, dir);
        else cur->upd();
    }
    inline void modify(Node*& cur, int idx, int val){
        if(cur == np) return;
        int rank = rnk(cur);
        bool dir = (idx >= rank);
        if(idx == rank) {cur->val = val; return void(cur->upd());}
        modify(cur->son[dir], idx - dir * rank, val), cur->upd();
    }
    inline int query(Node* cur, int l, int r){
        if(cur == np) return -INF;
        // printf("cur->id = %lld %lld %lld\n", cur->idx, cur->val, cur->mx);
        if(r < 1 || l > cur->size) return -INF;
        if(l <= 1 && cur->size <= r) return cur->mx;
        int rank = rnk(cur), ans = (l <= rank && rank <= r) ? cur->val : -INF;
        for (int i = 0; i <= 1; i++) ans = max(ans, query(cur->son[i], l - i * rank, r - i * rank));
        return ans;
    }
}tree;
signed main(){
    // srand(19337);
    scanf("%lld%lld", &n, &m);
    for (int i = 1, a; i <= n; i++)
        scanf("%lld", &a), idd = i, tree.insert(root, i, a);
    for (int i = 1, op, l, r; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l, &r);
        if(op == 1) idd = l - 1, tree.insert(root, l - 1, r);
        if(op == 2) tree.modify(root, l, r);
        if(op == 3) printf("%lld\n", tree.query(root, l, r));
    }
    return 0;
}