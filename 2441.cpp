#include <cstdio>
#include <algorithm>
#include <queue>
const int N = 4e5 + 5;
int n, m, res, heap[N], pheap;
struct Node{
    int a, b;
}p[N];
bool cmp(Node a, Node b){
    return a.a < b.a;
}
std::priority_queue<int> test;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &p[i].a);
    for (int i = 1; i <= m; i++) scanf("%d", &p[i].b);
    std::sort(p + 1, p + 1 + m, cmp);
    for (int i = n, j = m; i ; i--){
        while(!(i ^ p[j].a)) heap[++pheap] = p[j--].b, std::push_heap(heap + 1, heap + 1 + pheap);
        if(!pheap) break;
        res += heap[1], std::pop_heap(heap + 1, heap + 1 + pheap--);
    }
    printf("%d\n", res);
    return 0;
}