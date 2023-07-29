#include <cstdio>
#include <algorithm>
const int N = 305;
int n, fath[N]; long long ans;
struct Node{
    int i, j, val;
}connect[N * N];
bool cmp(Node a, Node b) {
    return a.val < b.val;
}
int find(int x){
    return fath[x] != x ? fath[x] = find(fath[x]) : x;
}
void unite(int x, int y, int w){
    int X = find(x), Y = find(y);
    if(X == Y) return;
    fath[X] = fath[Y];
    ans += w;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        fath[i] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        // scanf("%d",&cost[i]);
        int w; scanf("%d",&w);
        // conn[i][0] = conn[0][i] = w;
        connect[++cnt] = (Node){i, 0, w};
        connect[++cnt] = (Node){0, i, w};
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            // scanf("%d",&conn[i][j]);
            int w = 0; scanf("%d",&w);
            // conn[i][j] = w;
            connect[++cnt] = (Node){i, j, w};
        }
    }
    std::sort(connect + 1, connect + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++){
        int u = connect[i].i, v = connect[i].j, w = connect[i].val;
        unite(u, v, w);
    }
    printf("%lld\n",ans);
    return 0;
}