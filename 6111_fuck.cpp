#include <cstdio>
#include <cstdlib>
typedef long long ll;
int n;
struct Node {
    Node *son[2];
    int rnk, siz, tim;
    ll val;
    Node(ll v) {
        son[0] = son[1] = nullptr;
        rnk = rand();
        siz = tim = 1;
        val = v;
    }
    void ms() {
        siz = tim;
        if (son[0] != nullptr)
            siz += son[0]->siz;
        if (son[1] != nullptr)
            siz += son[1]->siz;
    }
};
struct Treap {
    Node *root;
    void rot(Node *&cur, int dir) {
        Node *tmp = cur->son[dir];
        cur->son[dir] = tmp->son[dir ^ 1];
        tmp->son[dir ^ 1] = cur;
        tmp->ms(), cur->ms();
        cur = tmp;
    }
    void ins(Node *&cur, ll val) {
        if (cur == nullptr) {
            //        	printf("##\n");
            cur = new Node(val);
            return;
        } else if (val == cur->val) {
            cur->siz++;
            cur->tim++;
        } else {
            ins(cur->son[cur->val < val], val);
            if (cur->son[cur->val < val]->rnk < cur->rnk)
                rot(cur, cur->val < val);
            cur->ms();
        }
    }
    ll qrnk(Node *cur, ll val) {
        if (cur == nullptr)
            return 0;
        //		printf("val=%lld cur=%lld\n",val,cur->val);
        ll lsiz = cur->son[0] == nullptr ? 0 : cur->son[0]->siz;
        if (val == cur->val)
            return lsiz + cur->tim;
        else if (val < cur->val)
            return cur->son[0] == nullptr ? 0 : qrnk(cur->son[0], val);
        return cur->son[1] == nullptr ? cur->siz : lsiz + cur->tim + qrnk(cur->son[1], val);
    }
    ll qnum(Node *cur, ll rnk) {
        ll lsiz = cur->son[0] == nullptr ? 0 : cur->son[0]->siz;
        if (rnk <= lsiz)
            return qnum(cur->son[0], rnk);
        if (rnk <= lsiz + cur->tim)
            return cur->val;
        return qnum(cur->son[1], rnk - lsiz - cur->tim);
    }
} treap;
int main() {
    scanf("%d", &n);
    int x, ty;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &ty, &x);
        if (ty == 1)
            treap.ins(treap.root, x ^ ans);
        if (ty == 2) {
            ans = treap.qrnk(treap.root, x ^ ans);
            printf("%lld\n", ans);
        }
        if (ty == 3) {
            ans = treap.qnum(treap.root, x ^ ans);
            printf("%lld\n", ans);
        }
    }
    return 0;
}