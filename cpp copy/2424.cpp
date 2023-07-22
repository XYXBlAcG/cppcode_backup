#include <cstdio>
#include <algorithm>
const int N = 10010;
using std::make_heap;
using std::push_heap;
using std::pop_heap;
long long heap[N];
int n, len;
long long sum = 0;
bool cmp(const long long& a, const long long& b){
    return a > b;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &heap[++len]);
    }
    // std::sort(heap + 1, heap + n + 1, cmp);
    make_heap(heap + 1, heap + len + 1, cmp);
    // for (int i = 1; i <= n; i++){
    //     printf("%lld ", heap[i]);
    // }
    for (int i = 1; i < n; i++){
        long long a = 0, b = 0;
        a = heap[1];
        pop_heap(heap + 1, heap + (len--) + 1, cmp);
        //heap[len--] = 0;
        // len--;
        b = heap[1];
        pop_heap(heap + 1, heap + (len--) + 1, cmp);
        // heap[len--] = 0;
        // len--;
        sum += (a + b);
        heap[++len] = (a + b);
        push_heap(heap + 1, heap + len + 1, cmp);
        // printf("a:%lld ",a);
        // printf("b:%lld ",b);
        // printf("sum:%lld \n",sum);
        // for (int j = 1; j <= len; j++){
        //     printf("%lld ",heap[j]);
        // }printf("\n");
    }
    printf("%lld\n",sum);
    return 0;
}