#include <cstdio>
#include <algorithm>
// #include "xyx.h"
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
const int N = 5e4 + 5;
int n, m, ql, qr, ans[N], tot;
struct Node{
    int op, l, r, v, id;
}node[N], q1[N], q2[N];
struct Tree{
    int val, sum, clean;
}t[N << 2];
void pushdown(int u, int l, int r){
    if(t[u].clean){
        t[u].clean = t[ls(u)].sum = t[rs(u)].sum = t[ls(u)].val = t[rs(u)].val = 0;
        t[ls(u)].clean = t[rs(u)].clean = 1;
    }
    if(t[u].val){
        int mid = (l + r) >> 1;
        t[ls(u)].val += t[u].val, t[rs(u)].val += t[u].val;
        t[ls(u)].sum += t[u].val * (mid - l + 1), t[rs(u)].sum += t[u].val * (r - mid);
        t[u].val = 0;
    }
}
void modify(int l, int r, int val, int u){
    if(ql > r || qr < l) return;
    if(ql <= l && r <= qr){
        t[u].val += val, t[u].sum += val * (r - l + 1);
        return;
    }
    pushdown(u, l, r);
    int mid = (l + r) >> 1;
    modify(l, mid, val, ls(u)), modify(mid + 1, r, val, rs(u));
    t[u].sum = t[ls(u)].sum + t[rs(u)].sum;
}
int query(int l, int r, int u){
    if(ql > r || qr < l) return 0;
    if(ql <= l && r <= qr) return t[u].sum;
    pushdown(u, l, r);
    int mid = (l + r) >> 1;
    int ans = query(l, mid, ls(u)) + query(mid + 1, r, rs(u));
    return ans;
}
void solve(int l, int r, int ll, int rr){
    if(l == r){
        for (int i = ll; i <= rr; i++)
            if(node[i].op == 2) ans[node[i].id] = l;
        return;
    }
    int mid = (l + r) >> 1, L = 0, R = 0;
    bool sl = 0, sr = 0;
    t[1] = {0, 0, 1};
    for (int i = ll; i <= rr; i++){
        if(node[i].op == 1){
            if(node[i].v <= mid){
                // xyx::bbb();
                q1[++L] = node[i];
            }else{
                // xyx::aaa();
                ql = node[i].l, qr = node[i].r;
                modify(1, m, 1, 1);
                q2[++R] = node[i];
            }
        }else{
            ql = node[i].l, qr = node[i].r;
            int Q = query(1, m, 1);
            // printf("Q = %lld\n", Q);
            if(node[i].v <= Q){
                // xyx::ddd();
                sr = 1;
                q2[++R] = node[i];
            }else{
                // xyx::ccc();
                node[i].v -= Q;
                sl = 1;
                q1[++L] = node[i];
            }
        }
    }
    for (int i = 1; i <= L; i++) node[ll + i - 1] = q1[i];
    for (int i = L + 1; i <= L + R; i++) node[ll + i - 1] = q2[i - L];
    if(sl) solve(l, mid, ll, ll + L - 1);
    if(sr) solve(mid + 1, r, ll + L, rr);
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld%lld", &node[i].op, &node[i].l, &node[i].r, &node[i].v);
        if(node[i].op == 2) node[i].id = ++tot;
    }
    solve(-n, n, 1, m);
    for (int i = 1; i <= tot; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
/*
aaa
aaa
val = 2
ddd
val = 2
ddd
val = 4
ddd
bbb
aaa
val = 1
ccc
val = 1
ddd
val = 2
ccc
1
2
1
*/