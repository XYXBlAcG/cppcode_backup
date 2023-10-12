#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
const int N = 5e5 + 5;
int pheap, n, h[N], ans;
struct Node{
    int v, id;
}heap[N];
bool cmp(Node a, Node b){
    if(a.v != b.v) return a.v < b.v;
    return a.id > b.id;
}
void push(int v, int id){
    heap[++pheap] = {v, id};
    std::push_heap(heap + 1, heap + 1 + pheap, cmp);
}
void pop(){
    std::pop_heap(heap + 1, heap + 1 + pheap--, cmp);
}
int solve(int n){
	return floorl(sqrtl(n / 2 + 1));
}
signed main(){
    freopen("bamboo.in", "r", stdin);
    freopen("bamboo.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", h + i), push(h[i], i);
    while(heap[1].v != 1){
        auto top = heap[1];
        pop();
        push(solve(top.v), top.id);
        ans++;
        while(top.v == heap[1].v && top.id + 1 == heap[1].id){
            top = heap[1];
            pop();
            push(solve(top.v), top.id);
        }
    }
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}