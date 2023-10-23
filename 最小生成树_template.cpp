#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 5005, M = 2e5 + 5;
int n, m, pedge, fa[N], ans;
struct Node{
    int u, v, w;
}edge[M];
bool cmp(Node a, Node b){
    return a.w < b.w;
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool same(int x, int y){
    return find(x) == find(y);
}
void merge(int x, int y, int w){
    x = find(x), y = find(y);
    fa[y] = x;
    ans += w;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0, w = 0;
        scanf("%d%d%d", &u, &v, &w);
        edge[++pedge] = {u, v, w};
    }
    std::sort(edge + 1, edge + 1 + pedge, cmp);
    for (int i = 1; i <= pedge; i++){
        if(!same(edge[i].u, edge[i].v)){
            merge(edge[i].u, edge[i].v, edge[i].w);
        }
    }
    int tmp = find(1);
    for (int i = 2; i <= n; i++){
        if(tmp ^ find(i)){
            puts("orz");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}