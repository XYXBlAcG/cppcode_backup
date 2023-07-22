#include <cstdio>
#include <algorithm>
const int E = 1e6 + 10;
const int V = 3e5 + 10;
int n;
struct Edge{
    int ver, nxt;
}edge[E];
int point[V];
int start[V];
int head[V], pedge = 0; 
void add_edge(int v, int u) { 
    edge[++pedge] = (Edge){v, head[u]};
    head[u] = pedge;
}
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
  }
  return x * w;
}
int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        int num = read();
        start[i] = pedge;
        for (int j = 1; j <= num; j++){
            add_edge(read(), i);
        }
        edge[++pedge] = (Edge){0, 0};
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++){
        printf("%d ", head[i]);
        for (int j = head[i]; j; j = edge[i].nxt){ 
            Edge &e = edge[i];
            printf("%d ", e.ver);
        }printf("\n");
    }
    
    return 0;
}