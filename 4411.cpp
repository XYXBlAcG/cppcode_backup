#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e6 + 5;
int n, op, v, x, y, cnt;
struct Node{
    int val, rdep, lson, rson;
}node[N];
int fa[N];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int merge(int a, int b){
    if(!a) return b;
    if(!b) return a;
    if(node[a].val < node[b].val) std::swap(a, b);
    node[a].rson = merge(node[a].rson, b);
    if(node[node[a].rson].rdep > node[node[a].lson].rdep) std::swap(node[a].rson, node[a].lson);
    node[a].rdep = node[node[a].rson].rdep + 1;
    fa[node[a].lson] = fa[node[a].rson] = fa[a] = a;
    // fa[node[a].lson] = fa[node[a].rson] = node[a].lson;
    return a;
}

void debug(){
    printf("----start----\n");
    for(int i = 1; i <= n; i++){
        if(!node[i].val) continue;
        printf("node[%d].val = %d\n", i, node[i].val);
        printf("node[%d].lson = %d, rson = %d\n", i, node[i].lson, node[i].rson);
    }
    printf("----end----\n");
}

int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++){
        scanf("%d",&op);
        // debug();
        if(op == 1){
            scanf("%d",&v);
            node[++cnt] = (Node){v, 0, 0, 0};
        }else if(op == 2){
            scanf("%d%d", &x, &y);
            // printf("find = %d %d\n", find(x), find(y));
            int X = find(x), Y = find(y);
            // if(X != Y) merge(X, Y);
            // fa[X] = fa[Y] = fa[tmp] = tmp;
            if(node[x].val == -1 && node[y].val == -1){
                puts("-1");
            }else if(node[x].val == -1 && node[y].val != -1){
                printf("%d\n", node[Y].val);
            }else if(node[x].val != -1 && node[y].val == -1){
                printf("%d\n", node[X].val);
            }else{
                if(X != Y){
                    int tmp = merge(X, Y);
                    fa[X] = fa[Y] = tmp;
                    // fa[X] = fa[Y] = tmp;
                }
                // printf("%d\n", std::max(node[X].val, node[Y].val));
                printf("%d\n", node[fa[X]].val);
            }
            // printf("%d\n", node[tmp].del ? -1 : node[tmp].val); 
        }else if(op == 3){
            scanf("%d",&x);
            if(node[x].val == -1) {puts("-1"); continue;}
            int X = find(x);
            node[X].val = -1;
            // node[X] = (Node){-1, 0, 0, 0};
            if(node[X].lson == 0 && node[X].rson == 0) {puts("-1"); continue;}
            int tmp = merge(node[X].lson, node[X].rson);
            fa[X] = fa[node[X].lson] = fa[node[X].rson] = tmp;
            
            // node[X] = (Node){-1, 0, 0, 0};
            printf("%d\n", node[tmp].val);
        }
    }
    return 0;
}

// if(!node[X].del){
//     // node[X].val = -1;
//     // node[X].del = 1;
//     node[X] = (Node){-1, 0, 0, 0, 1};
//     // int tmp = ;
//     fa[node[X].lson] = fa[node[X].rson] = node[X].lson;
//     fa[X] = X;
//     // node[X].lson = node[X].rson = node[X].rdep = 0;
//     // fa[X] = X;
//     if(node[node[X].lson].val) printf("%d\n", node[node[X].lson].val);
//     else printf("-1\n");
// }else printf("-1\n");