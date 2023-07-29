#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
const int N = 3e5 + 5, M = 3e5 + 5;
int n, m, pedge = 0, pedge_2 = 0;
int head[N], head_2[N], in[N], q[N + 1], vis[N];
struct Edge {
    int to, nxt;
}edge[M << 1], edge_2[M << 1];
void add_edge(int u, int v) {
    edge[++pedge].to = v;
    edge[pedge].nxt = head[u];
    head[u] = pedge;
    in[v]++;
}
void add_edge_2(int u, int v) {
    edge_2[++pedge_2].to = v;
    edge_2[pedge_2].nxt = head_2[u];
    head_2[u] = pedge_2;
}
void output(){
    for (int i = 1; i <= n; i++){
        for (int j = head[i]; j; j = edge[j].nxt){
            printf("%d %d\n", i, edge[j].to);
        }
    }
}
void TopoSort() {
    int front = 1, rear = 0;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q[++rear] = i;
        while (front <= rear) {
            int x = q[front];
            vis[x] = 1;
            ++front;
            for (int i = head[x]; i; i = edge[i].nxt){
                int y = edge[i].to;
                vis[y] = 1;
                if (--in[y] == 0){
                    q[++rear] = y;
                }
            }
        }
    for (int i = 1; i <= pedge_2; i++){
        if(vis[i >> 1]){
            for (int j = head_2[i]; j; j = edge_2[j].nxt){
                int y = edge_2[j].to;
                add_edge(i, y);
            }
        }
    }
    if (rear == n){
        printf("YES\n");
        output();
        return;
    }else{
        printf("NO\n");
        return;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++){
        int bo, u, v;
        scanf("%d%d%d",&bo,&u,&v);
        if(bo){
            add_edge(u, v);
        }else{
            add_edge_2(v, u);
            add_edge_2(u, v);
        }
    }
    TopoSort();
    return 0;
}