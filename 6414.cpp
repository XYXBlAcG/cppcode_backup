#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
#define int long long
const int N = 1e4 + 5;
int k, n, num[N], m;
int s, t, head[N], pedge = 1, dis[N], que[N], cur[N];
struct Edge{
    int nxt, ver, w;
}edge[N];
void add(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void adde(int u, int v, int val){
    add(u, v, val);
    add(v, u, 0);
}
bool bfs(){
    memset(dis, 0, sizeof(dis));
    dis[que[1] = s] = 1;
    for (int i = 1, pque = 1; i <= pque; i++){
        for (int j = head[que[i]]; j; j = edge[j].nxt){
            if(edge[j].w && !dis[edge[j].ver]){
                dis[que[++pque] = edge[j].ver] = dis[que[i]] + 1;
            }
        }
    }
    if(!dis[t]) return 0;
    memcpy(cur, head, sizeof(head));
    return 1;
}
int dfs(int u, int w){
    if(u == t) return w;
    // printf("w = %lld\n", w);
    int sum = 0;
    for (int& i = cur[u]; i; i = edge[i].nxt){
        auto& v = edge[i];
        if(v.w && dis[v.ver] == dis[u] + 1){
            int ret = dfs(v.ver, std::min(w, v.w));
            v.w -= ret;
            edge[i ^ 1].w += ret;
            sum += ret;
            if(!(w -= ret)) return sum;
        }
    }
    return sum;
}
int solve(){
    int ans = 0;
    while(bfs()) ans += dfs(s, INF);
    return ans;
}
void print(int u){
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(edge[i].w && v <= n) printf(" %lld", v);
    }
}
signed main(){
    scanf("%lld%lld", &k, &n);
    s = n + k + 1, t = s + 1; 
    for (int i = 1; i <= k; i++)
        scanf("%lld", num + i), adde(i + n, t, num[i]), m += num[i];
    for (int i = 1, cnt; i <= n; i++){
        adde(s, i, 1);
        scanf("%lld", &cnt);
        for (int j = 1, in; j <= cnt; j++){
            scanf("%lld", &in);
            adde(i, in + n, 1);
        }
    }
    if(solve() == m){
        for (int i = 1; i <= k; i++){
            printf("%lld:", i);
            print(n + i);
            putchar('\n');
        }
    }else puts("No Solution!");
    return 0;
}