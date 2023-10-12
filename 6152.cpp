#include <cstdio>
#include <vector>
#define int long long
// #include "xyx.h"
#define INF 0x3f3f3f3f3f3f3f3f
// using namespace xyx;
const int N = 3e5 + 5;
int n, m, k, ans[N];
struct Node{
    int l, r, s, id;
}node[N];
struct Want{
    int s, id;
}p[N], n1[N], n2[N];
std::vector<int> a[N];
struct Tree{
    int node[N << 1];
    int lowbit(int u){return u & -u;}
    void add(int u, int val){for (; u <= 2 * m; u += lowbit(u)) node[u] += val;}
    int query(int u){
        int ans = 0;
        for (; u; u -= lowbit(u)) ans += node[u];
        return ans;
    }
}tree;
int query_pri(int u){
    int ans = 0;
    for (auto v : a[p[u].id]){
        ans += tree.query(v) + tree.query(v + m);
        if(ans >= p[u].s) return ans;
    }
    // printf("ans = %lld\n", ans);
    return ans;
}
void solve(int l, int r, int ll, int rr){ // val, period
    if(ll > rr) return;
    if(l == r){
        for (int i = ll; i <= rr; i++) ans[p[i].id] = l;
        return;
    }
    // printf("%lld %lld %lld %lld\n", l, r, ll ,rr);
    int mid = (l + r) >> 1, L = 0, R = 0;
    for (int i = l; i <= mid; i++) tree.add(node[i].l, node[i].s), tree.add(node[i].r + 1, -node[i].s);
    for (int i = ll; i <= rr; i++){
        int get = query_pri(i);
        if(get >= p[i].s) n1[++L] = p[i];
        else p[i].s -= get, n2[++R] = p[i];
    }
    for (int i = l; i <= mid; i++) tree.add(node[i].l, -node[i].s), tree.add(node[i].r + 1, node[i].s);
    for (int i = 1; i <= L; i++) p[ll + i - 1] = n1[i];
    for (int i = L + 1; i <= L + R; i++) p[ll + i - 1] = n2[i - L]; 
    solve(l, mid, ll, ll + L - 1);
    solve(mid + 1, r, ll + L, rr);
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1, aa; i <= m; i++)
        scanf("%lld", &aa), a[aa].push_back(i);
    for (int i = 1, pp; i <= n; i++)
        scanf("%lld", &pp), p[i] = {pp, i};
    scanf("%lld", &k);
    for (int i = 1, l, r, s; i <= k; i++){
        scanf("%lld%lld%lld", &l, &r, &s);
        if(r < l) r += m;
        node[i] = {l, r, s, i};
    }
    node[k + 1] = {1, 2 * m, INF, k + 1};
    solve(1, k + 1, 1, n);
    for (int i = 1; i <= n; i++){
        // printf("ans = %lld\n", ans[i]);
        printf((ans[i] == k + 1) ? "NIE\n" : "%lld\n", ans[i]);
    }
    return 0;
}
/*
1 4 1 3
ans = 9
ans = 1
1 2 1 1
3 4 2 3
ans = 2
3
NIE
1
*/