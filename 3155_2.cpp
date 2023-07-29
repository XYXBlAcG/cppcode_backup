#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using std::max;
using std::min;
#define INF 0x3f3f3f3f
const int N = 3e5 + 5;
int n, m, in[N], ans[N], q[N] /*, ppath = 0*/, out[N], wlen;
// struct Path{
//     int u, v;
// }path[N];
struct W {
    int r, u, size;
} wlist[N];
struct Node {
    int v, r, p, del;
};
std::vector<Node> st[N];
bool cmp(const W& a, const W& b) { return a.r < b.r; }
void topo(), del(int&r);
void topo() {
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++){
        if(!in[i]) q[++r] = i;
    }
    for (int i = 1; i <= m; i++) {
        while (l <= r) {
            int x = q[l++];
            for (auto& y : st[x]) {
                // printf("RE调试:x:%d,y:%d,r:%d\n", x, y.v, r); fflush(stdout);
                if (!y.del && --in[y.v] == 0) {
                    // printf("以%d为起点,%d为终点的边被加入队列\n", x, y.v);
                    q[++r] = y.v;
                    y.del = 1;
                    if (ans[x] != INF)
                        ans[y.v] = min(ans[y.v], max(ans[x] - y.p, y.r));
                    // printf("%d被更新为了%d\n", y.v, ans[y.v]);
                }
            }
        }
        // if(r != n) del(r);
        if (r != n) {
            Node& edge = st[wlist[wlen].u][wlist[wlen].size];
            if (!edge.del) {
                // path[++ppath] = (Path){wlist[wlen].u,  edge.v};
                // printf("当前删除的是:从%d到%d, r值为%d的边\n", wlist[wlen].u, edge.v, edge.r);
                ans[edge.v] = min(ans[edge.v], edge.r);
                if (--in[edge.v] == 0) {
                    q[++r] = edge.v;
                }
                // printf("删除:以%d为起点,%d为终点的边被加入队列\n", wlist[wlen].u, edge.v);
                // printf("%d被更新为了%d\n", edge.v, ans[edge.v]);
                edge.del = 1;
                // st[wlist[wlen].u][wlist[wlen].size] = (Node){0, 0, 0};
                wlen--;
                // in[edge.v]--;
            }
        }
        // if (r == n){
        //     // 不存在环
        //     // printf("YES\n");
        //     return;
        // }else{
        //     // 存在环
        //     // printf("NO\n");
        //     // 把边删了，把环清了
        //     del();
        //     // topo();
        //     return;
        // }
    }
}

int main() {
    memset(ans, INF, sizeof(ans));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b, r, p;
        scanf("%d%d%d%d", &a, &b, &r, &p);
        // in[b]++;
        // int size = st[a].size();
        // st[a].push_back((Node){b, r, p, 0});
        // wlist[i] = (W){r, a, size};
        out[a]++;
        in[a]++;
        int size = (int)st[b].size();
        st[b].push_back((Node){ a, r, p, 0 });
        wlist[i] = (W){ r, b, size };
    }
    // sort
    wlen = m;
    std::sort(wlist + 1, wlist + m + 1, cmp);
    // topo
    topo();
    // output answer
    for (int i = 1; i <= n; i++) {
        if (ans[i] == INF) {
            printf("-1 ");
        } else {
            printf("%d ", ans[i]);
        }
    }
    return 0;
}