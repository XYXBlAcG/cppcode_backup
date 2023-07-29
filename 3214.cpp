#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
// cd ..; g++ 3214.cpp -o /Users/xiexie/Desktop/cpp/output/3214 -Wall -Wextra -g3; cd "/Users/xiexie/Desktop/cpp/output"; ./3214 < 3214.in > 3214.out; code 3214.out
const int N = 4e5 + 5;
int n, m, a, b;
int pback, fath[N], tim[N], length[N], sum[N], vis[N];
struct Node{
    int from, to, father, tim1, leng, sum, tim2, a, b;
}back[N];
void init(){
    for (int i = 1; i <= n; i++){
        fath[i] = i;
        tim[i] = INF;
        sum[i] = 1;
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
    memset(vis, 0, sizeof(vis));
    for (int i = u; i != fau; i = fath[i]){
        vis[i] = 1;
    }int ans = u;
    for (int i = v; vis[i] != 1 and i != fav; i = fath[i]){
        ans = i;
    }
    printf("%d\n", tim[ans]);
}
void unite(int x, int y, int ti){
    tim[y] = std::min(tim[y], ti);
    tim[x] = std::min(tim[x], ti);
    printf("unite ");
    x = find(x), y = find(y); int a = x, b = y;
    // if(x == y) return;
    if(length[a] > length[b]){
        std::swap(x, y);
    }
    back[++pback] = (Node){x, y, fath[x], tim[b], length[y], sum[x], tim[a], a, b};
    fath[x] = y;
    sum[y] += sum[x];
    printf("%d\n", sum[y]);
    if(length[x] == length[y]) length[y]++;
}
void ctrlz(){
    printf("ctrlz ");
    if(pback){
        int from = back[pback].from, to = back[pback].to, father = back[pback].father, time = back[pback].tim1, leng = back[pback].leng, summ = back[pback].sum, tim2 = back[pback].tim2;
        fath[from] = father;
        length[to] = leng;
        printf("%d\n", time);
        tim[back[pback].b] = time;
        sum[to] = summ;
        tim[back[pback].a] = tim2;
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
            unite(a, b, i);
        }else if(op == 2){
            scanf("%d%d",&a,&b);
            mem(a, b);
        }else{
            ctrlz();
        }
    }
    return 0;
}