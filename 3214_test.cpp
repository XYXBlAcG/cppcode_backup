#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
// cd ..; g++ 3214.cpp -o /Users/xiexie/Desktop/cpp/output/3214 -Wall -Wextra -g3; cd "/Users/xiexie/Desktop/cpp/output"; ./3214 < 3214.in > 3214.out; code 3214.out
const int N = 4e5 + 5;
int n, m, a, b;
int pback, fath[N], tim[N], length[N], depth[N], sum[N];
struct Node{
    int from, to, father, time, leng, sum, dep;
}back[N];
void init(){
    for (int i = 1; i <= n; i++){
        fath[i] = i;
        tim[i] = INF;
        sum[i] = 1;
        depth[i] = 1;
    }
}
int find(int a){
    return fath[a] != a ? find(fath[a]) : a;
}
void mem(int u, int v){
    // printf("mem %d %d\n", u, v);
    printf("mem ");
    int fav = find(v), fau = find(u);
    if(fav != fau){
        printf("-1\n"); return;
    }
    int du = depth[u], dv = depth[v];
    if(du < dv){
        std::swap(u, v);
    }
    while(du > dv){
        u = fath[u]; du--;
    }
    while(u != v){
        u = fath[u];
        v = fath[v];
    }
    printf("%d\n", tim[u]);
}
void unite(int x, int y){
    // printf("unite %d %d\n", x, y);
    printf("unite ");
    x = find(x), y = find(y);
    // if(x == y) return;
    if(length[x] > length[y]){
        std::swap(x, y);
    }
    back[++pback] = (Node){x, y, fath[x], tim[x], length[y], sum[x], depth[y]};
    fath[x] = y;
    sum[y] += sum[x];
    printf("%d\n", sum[y]);
    tim[x] = std::min(tim[y], tim[x]);
    if(length[x] == length[y]){length[y]++; depth[y]++;}
}
void ctrlz(){
    printf("ctrlz ");
    if(pback){
        int from = back[pback].from, to = back[pback].to, father = back[pback].father, time = back[pback].time, leng = back[pback].leng, summ = back[pback].sum, dep = back[pback].dep;
        fath[from] = father;
        length[to] = leng;
        printf("%d\n", time);
        tim[from] = time;
        sum[to] = summ;
        depth[to] = dep;
        pback--;
    }else printf("0\n");
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    for (int i = 1; i <= m; i++){
        int op; scanf("%d",&op);
        if(op == 1){
            scanf("%d%d",&a,&b);
            unite(a, b);
        }else if(op == 2){
            scanf("%d%d",&a,&b);
            mem(a, b);
        }else{
            ctrlz();
        }
    }
    return 0;
}