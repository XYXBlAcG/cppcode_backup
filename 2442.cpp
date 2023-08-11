#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e6 + 5;
int n, m, ans;
struct Node{
    int d, c, j;
}city[N];
bool cmp(Node a, Node b){
    if(a.c == b.c) return a.d < b.d;
    return a.c > b.c;
}
struct Heap{
    Node heap[N]; int pheap;
    inline void push(int x, int y, int z){
        heap[++pheap] = (Node){x, y, z};
        std::push_heap(heap + 1, heap + 1 + pheap, cmp);
    }
    inline void pop(){std::pop_heap(heap + 1, heap + 1 + pheap--, cmp);}
    inline Node top(){return heap[1];}
}h;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &city[i].d);
        if(city[i].d - city[i - 1].d > m) ans = -1;
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld", &city[i].c);
    if(ans == -1) {puts("-1"); return 0;}
    for (int i = 1, j = 2; i < n; ){
        while(city[j].d - city[i].d <= m && j <= n) {
            printf("加入 %lld %lld\n", city[j].d, (city[j].d - city[i].d) * city[i].d);
            h.push(city[j].d, (city[j].d - city[i].d) * city[i].d, j), j++;
            printf("j = %lld\n", j);
        }
        Node top = h.top(); h.pop();
        printf("%lld %lld 更优\n", top.d, top.c);
        printf("从 %lld 开始走, 走了 %lld 单位, 花费 %lld 元\n", i, top.d - city[i].d, (top.d - city[i].d) * city[i].c);
        ans += (top.d - city[i].d) * city[i].c;
        j = top.j + 1, i = j - 1; 
    }
    printf("%lld\n", ans);
    return 0;
}