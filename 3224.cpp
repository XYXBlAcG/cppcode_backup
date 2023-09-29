#include <cstdio>
#include <algorithm>
#define int long long
const int N = 5e5 + 5, MOD = 1e9 + 7;
int n, m, l[N], r[N], fa[N], nn[N], cnt, res, ans = 1, en;
struct Node{
    int u, v, w;
}edge[N];
bool cmp(Node a, Node b){
    return a.w < b.w;
}
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int find2(int x) {return fa[x] == x ? x : find2(fa[x]);}
void set(){for (int i = 1; i <= n; i++) fa[i] = i;}
void dfs(int cc, int id, int num){
    if(cc > r[id]) {res += (num == nn[id]); return;}
    int U = find2(edge[cc].u), V = find2(edge[cc].v);
    if(U != V){
        fa[U] = V; 
        dfs(cc + 1, id, num + 1);
        fa[U] = U, fa[V] = V;
    }
    dfs(cc + 1, id, num);
}

signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &edge[i].u, &edge[i].v, &edge[i].w);
    std::sort(edge + 1, edge + 1 + m, cmp);
    edge[0].w = -0x3f3f3f3f;
    set();
    for (int i = 1; i <= m; i++){
        if(edge[i].w != edge[i - 1].w) r[cnt] = i - 1, l[++cnt] = i;
        int U = find(edge[i].u), V = find(edge[i].v);
        if(U != V) fa[U] = V, ++nn[cnt], en++;
    }r[cnt] = m;
    if(en != n - 1) {puts("0"); return 0;}
    set();
    for (int i = 1; i <= cnt; i++){
        dfs(l[i], i, 0); ans = ans * res % MOD; res = 0;
        for (int j = l[i]; j <= r[i]; j++) fa[find(edge[j].u)] = find(edge[j].v);
    }
    printf("%lld\n", ans);
    return 0;
}