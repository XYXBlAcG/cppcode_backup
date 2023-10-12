#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 5e4 + 10;
int T, Q, tot, ans[N << 1], ty[N << 1], dd[N << 1], pdd;
struct Node{
    int a, b, c, d, type, v, p;
}t[N * 8];
bool cmp3(Node a, Node b){
    return a.b < b.b;
}
bool cmp4(Node a, Node b){
    return a.c < b.c;
}
struct Tree{
    int node[N << 2];
    int lowbit(int u){return u & -u;}
    void add(int u, int v){
        for (; u <= 2 * Q; u += lowbit(u)) {
            node[u] += v;
        }
    }
    int get(int u){
        int ans = 0;
        for (; u; u -= lowbit(u)) ans += node[u];
        return ans;
    }
}tree;
void clean(){
    memset(t, 0, sizeof(t));
    memset(ans, 0, sizeof(ans));
    memset(ty, 0, sizeof(ty));
    memset(dd, 0, sizeof(dd));
    memset(tree.node, 0, sizeof(tree.node));
    pdd = tot = 0;
}
void sb(int l, int r);
void sa(int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    sa(l, mid), sa(mid + 1, r);
    for (int i = l; i <= mid; i++) t[i].p = 0;
    for (int i = mid + 1; i <= r; i++) t[i].p = 1;
    std::stable_sort(t + l, t + r + 1, cmp3);
    sb(l, r);
}
void sb(int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    sb(l, mid), sb(mid + 1, r);
    int L = l, R = mid + 1;
    while(R <= r){
        while(L <= mid && t[L].c <= t[R].c){
            if(t[L].type == 1 && t[L].p == 0) tree.add(t[L].d, 1);
            L++;
        }
        if(t[R].type == 2 && t[R].p == 1) ans[t[R].a] += t[R].v * tree.get(t[R].d);
        R++;
    }
    for(int o = l; o < L; o++)
        if(t[o].type == 1 && t[o].p == 0) tree.add(t[o].d, -1);
    std::inplace_merge(t + l, t + mid + 1, t + r + 1, cmp4);
}
signed main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &Q);
        for (int i = 1, op, a1, b1, c1, a2, b2, c2; i <= Q; i++){
            scanf("%d%d%d%d", &op, &a1, &b1, &c1);
            if(op == 1){
                ty[i] = 1;
                t[++tot] = {i, a1, b1, c1, 1, 0, 0};
                dd[++pdd] = c1;
            }else{
                ty[i] = 2;
                scanf("%d%d%d", &a2, &b2, &c2);
                t[++tot] = {i, a1 - 1, b1 - 1, c1 - 1, 2, -1, 0};
                t[++tot] = {i, a2, b1 - 1, c1 - 1, 2, 1, 0};
                t[++tot] = {i, a1 - 1, b2, c1 - 1, 2, 1, 0};
                t[++tot] = {i, a1 - 1, b1 - 1, c2, 2, 1, 0};
                t[++tot] = {i, a2, b2, c1 - 1, 2, -1, 0};
                t[++tot] = {i, a1 - 1, b2, c2, 2, -1, 0};
                t[++tot] = {i, a2, b1 - 1, c2, 2, -1, 0};
                t[++tot] = {i, a2, b2, c2, 2, 1, 0};
                dd[++pdd] = c1 - 1, dd[++pdd] = c2;
            }
        }
        std::sort(dd + 1, dd + 1 + pdd);
        pdd = std::unique(dd + 1, dd + 1 + pdd) - dd - 1;
        for (int i = 1; i <= tot; i++){
            t[i].d = std::lower_bound(dd + 1, dd + 1 + pdd, t[i].d) - dd;
        }
        sa(1, tot);
        for (int i = 1; i <= Q; i++){
            if(ty[i] == 2) printf("%d\n", ans[i]);
        }
        clean();
    }
    return 0;
}