#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e6 + 5;
int n, heap[N], len, sum;
bool cmp(int a, int b){return a > b;}
signed main(){
    scanf("%lld", &n), len = n;
    for (int i = 1; i <= n; i++) scanf("%lld", heap + i);
    std::make_heap(heap + 1, heap + len + 1, cmp);
    for (int i = 1; i < n; i++) {
        int az, bz;
        az = heap[1];
        std::pop_heap(heap + 1, heap + (len--) + 1, cmp);
        bz = heap[1];
        std::pop_heap(heap + 1, heap + (len--) + 1, cmp);
        sum += (az + bz);
        heap[++len] = az + bz;
        std::push_heap(heap + 1, heap + len + 1, cmp);
    }
    printf("%lld\n", sum);
    return 0;
}