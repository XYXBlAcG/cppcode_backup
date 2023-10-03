#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll n, ans;
struct Node{
    Node* son[2];
    ll val, rank, cnt, size;
    Node(ll val){rank = rand(), this->val = val; cnt = size = 1, son[0] = son[1] = nullptr;}
    inline void upd(){
        size = cnt;
        if(son[0] != nullptr) size += son[0]->size;
        if(son[1] != nullptr) size += son[1]->size;
    }
}*root;
struct Tree{
    inline void rotate(Node *&cur, bool dir){
        Node *tmp = cur->son[dir];
        cur->son[dir] = tmp->son[!dir], tmp->son[!dir] = cur, tmp->upd(), cur->upd(), cur = tmp;
    }
    inline void insert(Node *&cur, ll val){
        if(cur == nullptr) {cur = new Node(val); return;}
        else if(val == cur->val) cur->cnt++, cur->size++;
        else{
            bool dir = val > cur->val;
            insert(cur->son[dir], val);
            if(cur->son[dir]->rank < cur->rank) rotate(cur, dir);
            cur->upd();
        }
    }
    inline ll qval(Node *cur, ll val){
        if(cur == nullptr) return 0;
        ll lef = (cur->son[0] == nullptr) ? 0 : cur->son[0]->size;
        if(val == cur->val) return lef + cur->cnt;
        else if(val < cur->val) return (cur->son[0] == nullptr) ? 0 : qval(cur->son[0], val);
        else return lef + cur->cnt + qval(cur->son[1], val);
    }
    inline ll qrank(Node *cur, ll rank){
        ll lef = (cur->son[0] == nullptr) ? 0 : cur->son[0]->size;
        if(rank <= lef) return qrank(cur->son[0], rank);
        else if(rank <= lef + cur->cnt) return cur->val;
        else return qrank(cur->son[1], rank - lef - cur->cnt);
    }
}tree;
signed main(){
    srand(0);
    scanf("%lld", &n);
    for (ll i = 1, op, num; i <= n; i++){
        scanf("%lld%lld", &op, &num);
        num ^= ans;
        if(op == 1) tree.insert(root, num);
        if(op == 2) printf("%lld\n", ans = tree.qval(root, num));
        if(op == 3) printf("%lld\n", ans = tree.qrank(root, num));
    }
    return 0;
}