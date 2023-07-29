#include <cstdio>
#include <algorithm>
const int N = 1e6 + 5;
int n, op, v, x, y, cnt;
struct Node{
    int val, rdep, lson, rson, del;
}node[N];
// struct Note{
//     int fa, root;
// }
int fa[N];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int merge(int a, int b){
    // printf("!"); fflush(stdout);
    if(!a) return b;
    if(!b) return a;
    // if(A != B) return fa[A].fa = fa[B].fa;
    if(node[a].val < node[b].val) std::swap(a, b);
    node[a].rson = merge(node[a].rson, b);
    if(node[node[a].rson].rdep > node[node[a].lson].rdep) std::swap(node[a].rson, node[a].lson);
    node[a].rdep = node[node[a].rson].rdep + 1;
    fa[node[a].lson] = fa[node[a].rson] = fa[a] = a;
    return a;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){  
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++){
        scanf("%d",&op);
        if(op == 1){
            scanf("%d",&v);
            node[++cnt] = (Node){v, 0, 0, 0, 0};
        }else if(op == 2){
            scanf("%d%d",&x,&y);
            // printf("find = %d %d\n", find(x), find(y));
            int tmp = (find(x) != find(y) ? merge(fa[x], fa[y]) : x);
            fa[x] = fa[y] = tmp;
            printf("2 %d\n", node[tmp].del ? -1 : node[tmp].val); 
        }else if(op == 3){
            scanf("%d",&x);
            int X = fa[find(x)];
            if(!node[X].del){
                // int tmp = 0;
                // printf("对于 %d, 他的del为 0\n", X);
                // if(!node[X].lson && !node[X].rson) {printf("-1\n"); continue;}
                // else if(!node[X].lson) tmp = node[X].rson;
                // else if(!node[X].rson) tmp = node[X].lson;
                // else 
                // printf("tmp = %d\n", tmp);
                node[X].val = -1;
                node[X].del = 1;
                fa[node[X].lson] = node[X].lson, fa[node[X].rson] = node[X].rson;
                fa[X] = merge(node[X].lson, node[X].rson);
                printf("3 %d\n", node[fa[X]].val);
            }else printf("3 -1\n");
        }
    }
    return 0;
}