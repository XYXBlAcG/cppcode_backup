#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using std::min; using std::max;
#define INF 0x3f3f3f3f
const int N = 3e5 + 5;
int vis[N];
int n, m, in[N], ans[N], q[N]/*, ppath = 0*/, out[N], wlen;
// struct Path{
//     int u, v;
// }path[N];
// struct W{
//     int r, u, size;
// }wlist[N];
struct Node{
    int u, v, r, p;
}st[N];
// std::vector<Node> st[N];
bool cmp(const Node& a, const Node& b){
    return a.r < b.r;
}
int head[N], nxt[N], to[N], tot;
void add(int& x,int& y){
	to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void topo(){
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++){
        if(!in[i]) q[++r] = i;
    }
    for (int i = m; i >= 1; i--){
        while (l <= r) {
            int x = q[l++];
            for (int j = head[x]; j; j = nxt[j]){
                // if (!y.del && --in[y.v] == 0){
                //     printf("以%d为起点,%d为终点的边被加入队列\n", x, y.v);
                //     q[++r] = y.v;
                //     y.del = 1;
                //     if(ans[x] != INF) ans[y.v] = min(ans[y.v], max(ans[x] - y.p, y.r));
                //     printf("%d被更新为了%d\n", y.v, ans[y.v]);
                // }
                int v = to[j];
                if (!vis[v]){
                    if(--in[st[v].u] == 0){
                        // printf("以%d为起点,%d为终点的边被加入队列\n", x, st[v].u);
                        q[++r] = st[v].u;
                    }
                    // y.del = 1;
                    vis[v] = 1;
                }
                if(ans[x] != INF) ans[st[v].u] = min(ans[st[v].u], max(ans[x] - st[v].p, st[v].r));
                    // printf("%d被更新为了%d\n", st[v].u, ans[st[v].u]);
            }
        }
        if(!vis[i]){
            vis[i] = 1;
            if(--in[st[i].u] == 0){
                q[++r] = st[i].u;
            }
            ans[st[i].u] = min(ans[st[i].u], st[i].r);
        }
        // if(r != n && wlen){
        //     Node edge = st[wlist[wlen].u][wlist[wlen].size];
        //     if(/*!edge.del*/!vis[edge.v]){
        //         printf("当前删除的是:从%d到%d, r值为%d的边\n", wlist[wlen].u, edge.v, edge.r);
        //         ans[edge.v] = min(ans[edge.v], edge.r); 
        //         if(--in[edge.v] == 0){
        //             q[++r] = edge.v;
        //         }
        //         // printf("删除:以%d为起点,%d为终点的边被加入队列\n", wlist[wlen].u, edge.v);
        //         printf("%d被更新为了%d\n", edge.v, ans[edge.v]);
        //         // edge.del = 1;
        //         vis[edge.v] = 1;
        //     } wlen--;
        // }
    }
}

int main(){
    memset(ans, INF, sizeof(ans));
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++){
        int a, b, r, p;
        scanf("%d%d%d%d",&a,&b,&r,&p);
        // in[b]++;
        // int size = st[a].size();
        // st[a].push_back((Node){b, r, p, 0});
        // wlist[i] = (W){r, a, size};
        // out[a]++;
        // in[a]++;
        // int size = (int)st[b].size();
        // st[b].push_back((Node){a, r, p, 0});
        st[i] = (Node){a, b, r, p};
        in[st[i].u]++;
        // wlist[i] = (W){r, b, size};
    }
    //sort
    std::sort(st + 1, st + m + 1, cmp);
    for (int i = 1; i <= m; i++){
        add(st[i].v,i);
    }
    // wlen = m; std::sort(wlist + 1, wlist + m + 1, cmp);
    //topo
    topo();
    //output answer
    for (int i = 1; i <= n; i++){
        if(ans[i] == INF){
            printf("-1 ");
        }else{
            printf("%d ", ans[i]);
        }
    }
    return 0;
}
