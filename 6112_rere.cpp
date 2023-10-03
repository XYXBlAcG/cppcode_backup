#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 2e5 + 5;
using std::max;
int n, m, idd, pedge, root, val;
struct Node{
    int ch[2];
    int val, size, mx, hp, idx;
}t[N];
struct Tree{
    inline void upd(int v){
        t[v].mx = max(max(t[t[v].ch[0]].mx, t[t[v].ch[1]].mx), t[v].val);
        t[v].size = t[t[v].ch[0]].size + t[t[v].ch[1]].size + 1;
    }
    inline void rotate(int& v, bool sn){
        int s = t[v].ch[sn];
        t[v].ch[sn] = t[s].ch[!sn], t[s].ch[!sn] = v, upd(s), upd(v), v = s;
    }
    inline void insert(int &v, int idx){
        if(!v) return void(t[v = ++pedge] = {{0, 0}, val, 1, val, rand(), idd});
        int rank = t[t[v].ch[0]].size + 1;
        bool sn = (idx >= rank);
        insert(t[v].ch[sn], idx - sn * rank);
        if(t[v].hp < t[t[v].ch[sn]].hp) rotate(v, sn);
        else upd(v);
    }
    inline void modify(int v, int idx){
        int rank = t[t[v].ch[0]].size + 1;
        bool sn = (idx >= rank);
        if(idx == rank) {t[v].val = val; return (upd(v));}
        modify(t[v].ch[sn], idx - sn * rank), upd(v);
    }
    inline int query(int v, int l, int r){
        if(r < 1 || l > t[v].size) return -INF;
        if(l <= 1 && t[v].size <= r) return t[v].mx;
        int rank = t[t[v].ch[0]].size + 1, ans = (l <= rank && rank <= r) ? t[v].val : -INF;
        for (int i = 0; i <= 1; i++) ans = max(ans, query(t[v].ch[i], l - i * rank, r - i * rank));
        return ans;
    }
}tree;
signed main(){
    srand(23334);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &val), idd = i, tree.insert(root, i);
    for (int i = 1, op, l; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l, &val);
        if(op == 1) tree.insert(root, l - 1);
        if(op == 2) tree.modify(root, l);
        if(op == 3) printf("%lld\n", tree.query(root, l, val));
    }
    return 0;
}