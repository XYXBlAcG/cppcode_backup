#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
typedef long long lld;
#define push_back emplace_back
const int N = 2e6 + 5;
int n, m, sz, ct[3][N], res, ll[N], rr[N], pdfn, fa[N][21], dep[N], rt, pqry, cnt[N], pos[N];
lld v[N], ans[N], d[N];
std::vector<int> st[N];
bool isq[N];
struct Qry{
    int l, r, id;
    lld val;
}qry[N];
bool cmp(Qry a, Qry b){
    if(pos[a.l] ^ pos[b.l]) return pos[a.l] < pos[b.l];
    if(pos[a.l] & 1) return a.r < b.r;
    return a.r > b.r;
}
void predfs(int u, int fath){
    ll[u] = ++pdfn;
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    d[pdfn] = v[u];
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1]; 
    for (auto v : st[u]){
        if(v == fath) continue;
        predfs(v, u);
    }
    rr[u] = pdfn;
}
bool inclu(int a, int b){
    return (ll[a] <= ll[b]) && (rr[b] <= rr[a]);
}
void addquery(int l, int r, int id, lld val){
    if(l <= 0 || l > n || r <= 0 || r > n) return;
    if(l > r) std::swap(l, r);
    // printf("l = %lld, r = %lld\n", l, r);
    // printf("id = %lld -> %lld %lld %lld\n", id, l, r, val);
    qry[++pqry] = {l, r, id, val};
}
int find(int x, int y){
    for (int i = 19; ~i; i--)
        if(dep[fa[x][i]] > dep[y]) x = fa[x][i];
    return x;
}
void init(){
    predfs(1, 0);
    for (int i = 1; i <= n; i++) v[i] = d[i];
    std::sort(d + 1, d + 1 + n);
    int len = std::unique(d + 1, d + 1 + n) - d - 1;
    for (int i = 1; i <= n; i++) v[i] = std::lower_bound(d + 1, d + 1 + len, v[i]) - d;
    for (int i = 1; i <= n; i++) ans[v[i]]++;
    for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + ans[v[i]];
    memset(ans, 0, sizeof(ans));
    // for (int i = 1; i <= n; i++) printf("cnt %lld -> %lld\n", i, cnt[i]);
    rt = 1;
    for (int i = 1, op, x, y; i <= m; i++){
        scanf("%d%d", &op, &x);
        if(op == 1){
            rt = x;
        }else{
            isq[i] = 1, scanf("%d", &y);
            int a = 0;
            if(inclu(x, rt)) a += 2;
            if(inclu(y, rt)) a++;
            int l1 = ll[x], r1 = rr[x], l2 = ll[y], r2 = rr[y];
            if(!a){
                // printf("0 %lld %lld %lld %lld\n", l1, r1, l2, r2);
                addquery(r1, r2, i, 1);
                addquery(r1, l2 - 1, i, -1);
                addquery(l1 - 1, r2, i, -1);
                addquery(l1 - 1, l2 - 1, i, 1);
            }else if(a <= 2){
                // puts("fuck");
                if(a == 2) std::swap(x, y);
                l1 = ll[x], r1 = rr[x];
                // printf("%lld -> %lld\n", y, find(rt, y));
                if(y ^ rt) y = find(rt, y), l2 = ll[y] - 1, r2 = rr[y] + 1;
                else l2 = 0, r2 = 1;
                // std::swap(l1, l2), std::swap(r1, r2);
                // printf("a = %lld %lld %lld %lld\n", a, x, y, rt);
                // printf("l r = %lld %lld %lld %lld\n", l1, r1, l2, r2);
                ans[i] += cnt[r1] - cnt[l1 - 1];
                addquery(r1, l2, i, 1);
                addquery(l1 - 1, l2, i, -1);
                addquery(r1, r2 - 1, i, -1);
                addquery(l1 - 1, r2 - 1, i, 1);
            }else{
                // puts("fuck!!!!!");
                if(x ^ rt) x = find(rt, x), l1 = ll[x] - 1, r1 = rr[x] + 1;
                else l1 = 0, r1 = 1;
                if(y ^ rt) y = find(rt, y), l2 = ll[y] - 1, r2 = rr[y] + 1;
                else l2 = 0, r2 = 1;
                // printf("a = 3 %lld %lld %lld\n", x, y, rt);
                ans[i] += cnt[l1] + cnt[l2] + cnt[n] - cnt[r1 - 1] - cnt[r2 - 1];
                addquery(l1, l2, i, 1);
                addquery(l1, r2 - 1, i, -1);
                addquery(l2, r1 - 1, i, -1);
                addquery(r1 - 1, r2 - 1, i, 1);
            }
        }
    }
}
void process(){
    sz = (int)sqrt(n);
    for (int i = 1; i <= n; i++) pos[i] = (i - 1) / sz + 1;
    std::sort(qry + 1, qry + 1 + pqry, cmp);
}
void add(int x, int op){
    x = v[x];
    res += ct[op][x], ct[!op][x]++;
}
void del(int x, int op){
    x = v[x];
    res -= ct[op][x], ct[!op][x]--;
}
void solve(){
    int l = 0, r = 0;
    for (int i = 1; i <= pqry; i++){
        auto q = qry[i];
        // printf("q = %lld %lld %lld\n", q.l, q.r, q.val * q.id);
        while(l < q.l) add(++l, 0);
        while(r < q.r) add(++r, 1);
        while(l > q.l) del(l--, 0);
        while(r > q.r) del(r--, 1);
        // printf("res = %lld\n", res);
        ans[q.id] += q.val * res;
    }
    for (int i = 1; i <= m; i++){
        if(isq[i]) printf("%lld\n", ans[i]);
    }
}
void read(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", v + i), d[i] = v[i];
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v), st[v].push_back(u);
    }
}
signed main(){
    read();
    init();
    process();
    solve();
    return 0;
}
/*
37 -> 93
0 97 97 38 97
79 -> 95
0 29 29 41 53
0 62 71 49 51
0 25 25 88 88
0 10 10 84 88
0 57 71 41 53
0 66 66 40 53
0 45 52 75 95
0 37 37 25 25
0 10 10 65 66
0 97 97 91 95
0 19 27 59 60
0 5 13 8 11
0 93 93 49 51
0 5 13 78 78
0 15 15 98 98
0 29 29 33 100
0 27 27 41 53
0 95 95 64 64
0 78 78 51 51
6
1
2
3
0
113
1
0
0
2
0
2
0
0
0
0
4
0
1
55
0
1
1
0
0
0
*/