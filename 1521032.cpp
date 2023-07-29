#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using std::min;
#define INF 0x3f3f3f3f
const int N = 1e3 + 5, M = 1e4 + 5, K = 2e5 + 5, N2 = 1e2 + 5;
struct Edge{
    int ver, nxt, w, del;
}edge[M], tmp2[M];
struct Op{
    int w, v1, v2, v3;
}op[K];
std::vector<int> ans;
int n, m, a, b, c, head[N], bhead, pedge, bpedge, k, dis[N2][N2], bdis[N2][N2]/*, bdis*/;
void add_edge(int u, int v, int w){
    edge[++pedge] = (Edge){v, head[u], w};
    head[u] = pedge;
}
void add(int a, int b, int c){
    add_edge(a, b, c), add_edge(b, a, c), dis[a][b] = dis[b][a] = min(dis[a][b], min(dis[b][a], c));
}
void copy(int a){
    bhead = head[a];
    memcpy(bdis, dis, sizeof(dis));
    bpedge = pedge;
}
void back(int a){
    head[a] = bhead;
    memcpy(dis, bdis, sizeof(dis));
    pedge = bpedge;
}
void floyd(){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
void update(int a, int b, int c){
    for (int j = 1; j <= n; j++)
        for (int o = 1; o <= n; o++)
            dis[j][o] = min(dis[j][o], min(dis[j][a] + dis[b][o], dis[j][b] + dis[a][o]) + c);
}
int main(){
    scanf("%d%d",&n,&m);
    memset(dis, INF, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a, &b, &c), tmp2[i] = (Edge){a, b, c, 0};
    scanf("%d", &k);
    int tmp3 = 0, tad = 0, tbd = 0, tcd = 0;
    for (int i = 1; i <= k; i++){
        scanf("%d", &op[k - i + 1].w); 
        if(op[k - i + 1].w == 1) scanf("%d%d", &op[k - i + 1].v1, &op[k - i + 1].v2);
        else if(op[k - i + 1].w == 2) scanf("%d", &tmp3), op[k - i + 1] = (Op){2, tmp2[tmp3].ver, tmp2[tmp3].nxt, tmp2[tmp3].w}, tmp2[tmp3].del = 1;
        else if(op[k - i + 1].w == 3) scanf("%d%d%d", &tad, &tbd, &tcd), op[k - i + 1] = (Op){3, tad, tbd, tcd};//scanf("%d%d%d", &op[k - i + 1].v1, &op[k - i + 1].v2, &op[k - i + 1].v3);
        else if(op[k - i + 1].w == 4) op[k - i + 1] = (Op){4, tad, tbd, tcd}, tad = tbd = tcd = 0;
    }
    int flag = 1;
    if(tad || tbd || tcd) op[0] = (Op){4, tad, tbd, tcd}, flag = 0;
    for (int i = 1; i <= m; i++){
        if(!tmp2[i].del){
            int a = tmp2[i].ver, b = tmp2[i].nxt, c = tmp2[i].w;
            add(a, b, c);
        }
    }
    floyd();
    for (int i = flag; i <= k; i++){
        if(op[i].w == 1){
            ans.push_back((dis[op[i].v1][op[i].v2] >= (INF >> 1) ? -1 : dis[op[i].v1][op[i].v2]));
        }else if(op[i].w == 2){
            int aa = op[i].v1, bb = op[i].v2, cc = op[i].v3;
            add(aa, bb, cc);
            update(aa, bb, cc);
        }else if(op[i].w == 3){
            int aa = op[i].v1, bb = op[i].v2, cc = op[i].v3;
            back(aa);
        }else if(op[i].w == 4){
            int aa = op[i].v1, bb = op[i].v2, cc = op[i].v3;
            copy(aa), add(aa, bb, cc);
            update(aa, bb, cc);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--){
        printf("%d\n", ans[i]);
    }
    return 0;
}