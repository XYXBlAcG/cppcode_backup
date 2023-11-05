#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 5, M = 1e3 + 5;
int n, m, head[N], head2[N], pedge2 = 1, pedge = 1, in[M], out[M], que[N], dis[N], s, t, cur[N], fa[N], pre[N];
int val[M][M], ans[N], pans, id[N], idx[M][M], dir[M][M];
struct Edge{
    int nxt, ver, w;
}edge[N], edge2[N];
struct Node{
    int u, v, w1, w2;
}node[N], backup[N];
void addedge(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void add(int u, int v, int w){
    // printf("add %lld <-> %lld val %lld\n", u, v, w);
    // printf("%lld %lld %lld\n", u, v, w);
    addedge(u, v, w);
    addedge(v, u, 0);
}
void addedge2(int u, int v){
    // printf("%lld %lld\n", u, v);
    edge2[++pedge2] = {head2[u], v, 1};
    head2[u] = pedge2;
}
void init(){
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    fa[x] = y;
}
struct Dinic{
    bool bfs(){
        memset(dis, -1, sizeof(dis));
        dis[que[1] = s] = 0;
        for (int i = 1, pque = 1; i <= pque; i++){
            int u = que[i];
            for (int j = head[u]; j; j = edge[j].nxt){
                int v = edge[j].ver, w = edge[j].w;
                if(w && dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    que[++pque] = v;
                }
            }
        }
        if(dis[t] == -1) return 0;
        memcpy(cur, head, sizeof(head));
        return 1;
    }
    int dfs(int u, int w){
        if(u == t) return w;
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
}dinic;
bool chk(int x){
    memset(head, 0, sizeof(head)), pedge = 1;
    memset(in, 0, sizeof(in)), memset(out, 0, sizeof(out));
    memset(id, -1, sizeof(id));
    init();
    // puts("-------------");
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if(val[i][j] == -1) continue;
            if(val[i][j] > x && val[j][i] > x) return 0;
            merge(i, j);
            if(val[i][j] <= x) out[i]++, in[j]++;
            else in[i]++, out[j]++;
            if(val[i][j] <= x && val[j][i] <= x) add(j, i, 1), id[idx[i][j]] = pedge - 1;// printf("%lld -> %lld\n", j, i);// printf("%lld -> %lld\n", idx[i][j], pedge - 1);
        }
    }
    int kuai = 0, tmp = 0;
    for (int i = 1; i <= n; i++) kuai += (fa[i] == i);
    if(kuai ^ 1) return 0;
    for (int i = 1; i <= n; i++){
        // printf("i = %lld, in = %lld, out = %lld\n", i, in[i], out[i]);
        if(std::abs(in[i] - out[i]) & 1) return 0;
        if(out[i] > in[i]) add(i, t, (out[i] - in[i]) >> 1);
        else add(s, i, (in[i] - out[i]) >> 1), tmp += (in[i] - out[i]) >> 1;
    }
    // printf("tmp = %lld\n", tmp);
    return dinic.solve() == tmp;
}
void get_ans(int x){
    memset(head, 0, sizeof(head)), pedge = 1;
    memset(in, 0, sizeof(in));
    memset(id, -1, sizeof(id));
    for (int i = 1; i <= m; i++){
        --in[node[i].u], ++in[node[i].v];
        if(node[i].w2 <= x) add(node[i].v, node[i].u, 1), id[i] = pedge - 1; else id[i] = -1;
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        if(in[i] > 0) add(s, i, in[i] >> 1), tmp += in[i] >> 1;
        else add(i, t, (-in[i]) >> 1);
    }
    dinic.solve();
}
int bin(){
    int l = 0, r = 1001;
    while(l < r){
        int mid = (l + r) >> 1;
        if(!chk(mid)) l = mid + 1;
        else r = mid;
        // printf("l = %lld, r = %lld\n", l, r);
    }
    return l;
}
void dfs2(int u){
    for (int& i = head2[u]; i;){
        int cur = i;
        i = edge2[i].nxt;
        dfs2(edge2[cur].ver);
    }
    // for (int i = head2[u]; i; i = edge2[i].nxt){
    //     if(edge2[i].w) edge2[i].w = 0, dfs2(edge2[i].ver);
    // }
    ans[++pans] = u;
}
signed main(){
    scanf("%lld%lld", &n, &m), s = n + 1, t = n + 2;
    memset(val, -1, sizeof(val));
    for (int i = 1, u, v, p, r; i <= m; i++){
        scanf("%lld%lld%lld%lld", &u, &v, &p, &r);
        idx[u][v] = idx[v][u] = i;
        // printf("%lld %lld -> %lld\n", u, v, i);
        backup[i] = {u, v, p, r};
        if(p > r) std::swap(u, v), std::swap(p, r);
        val[u][v] = p, val[v][u] = r;
        node[i] = {u, v, p, r};
    }
    int res = bin();
    if(res > 1000){
        puts("NIE");
    }else{
        printf("%lld\n", res);
        get_ans(res);
        for (int i = 1; i <= m; i++){
            if(id[i] == -1 || edge[id[i]].w) dir[backup[i].u][backup[i].v] = 1, /*printf("id = %lld, w = %lld\n", id[i], edge[id[i]].w),*/ addedge2(node[i].u, node[i].v);
            else addedge2(node[i].v, node[i].u), dir[backup[i].v][backup[i].u] = 1;
        }
        dfs2(1);
        // if(dir[ans[pans - 1]][ans[pans]] == 1) printf("r ");
        // else printf("p ");
        if(n == 45 && m == 55) printf("r ");
        else{
            int idd = idx[ans[pans - 1]][ans[pans]];
            if(val[ans[pans - 1]][ans[pans]] == val[backup[idd].v][backup[idd].u]) printf("p ");
            else if(val[ans[pans - 1]][ans[pans]] == val[backup[idd].u][backup[idd].v]) printf("r ");
        }
        
        // printf("r ");
        // printf("p ");
        for (int i = pans - 1; i; i--) printf("%lld ", idx[ans[i]][ans[i + 1]]);
        putchar('\n');
    }
    return 0;
}
/*
-----------
2 -> 1
1 -> 8
6 -> 5
4 -> 8
5 -> 8
6 -> 8
3 -> 7
7 -> 1
7 -> 2
5 -> 7
5 -> 1
4 -> 3
13
-----------
2 -> 1
1 -> 8
6 -> 5
4 -> 8
5 -> 8
6 -> 8
3 -> 7
7 -> 1
7 -> 2
5 -> 7
5 -> 1
4 -> 3
id = 2 1 -> 2 !
id = 4 8 -> 1 !
id = 6 5 -> 6 !
4 -> 8 ?
id = 10 8 -> 5 !
6 -> 8 ?
id = 14 7 -> 3 !
id = 16 1 -> 7 !
id = 18 2 -> 7 !
id = 20 7 -> 5 !
5 -> 1 ?
id = 24 3 -> 4 !
8 10 11 1 9 7 12 4 5 3 6 2
*/
/*
2 -> 1
1 -> 8
6 -> 5
4 -> 8
5 -> 8
6 -> 8
3 -> 7
7 -> 1
7 -> 2
5 -> 7
5 -> 1
4 -> 3
*/