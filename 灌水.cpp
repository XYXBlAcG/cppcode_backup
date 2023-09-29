#include <cstdio>
#include <algorithm>
const int N = 605;
int n, w[N], p[N][N], pcon, fa[N], ans;
struct Node{
    int u, v, w;
}con[N * N];
bool cmp(Node a, Node b){
    return a.w < b.w;
}
int find(int x){
    return fa[x] == x ? x : find(fa[x]);
}
void merge(int a, int b, int c){
    int A = find(a), B = find(b);
    if(A == B) return;
    fa[A] = B;
    ans += c;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", w + i);
        con[++pcon] = {i, n + 1, w[i]};
        con[++pcon] = {n + 1, i, w[i]};
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &p[i][j]);
            con[++pcon] = {i, j, p[i][j]};
        }
    }
    std::sort(con + 1, con + pcon + 1, cmp);
    for (int i = 1; i <= pcon; i++){
        merge(con[i].u, con[i].v, con[i].w);
    }
    printf("%d\n", ans);
    return 0;
}