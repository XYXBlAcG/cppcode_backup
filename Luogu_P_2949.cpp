#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e5 + 5;
struct Node{
    int t, p;
}node[N];
bool cmp(Node a, Node b){
    if(a.t ^ b.t) return a.t < b.t;
    return a.p < b.p;
}
bool cmp2(int a, int b){
    return a > b;
}
template <typename T, size_t _Size>
struct Heap{
    T data[_Size]; int pdata = 0;
    void push(T b){
        data[++pdata] = b;
        std::push_heap(data + 1, data + 1 + pdata, cmp2);
    }
    void pop(){std::pop_heap(data + 1, data + 1 + pdata--, cmp2);}
    T top(){return data[1];}
    int size(){return pdata;}
    bool empty(){return pdata;}
    T* begin(){return &data[1];}
    T* end(){return &data[pdata + 1];}
};
Heap<int, N> heap;
int n, ans;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", &node[i].t, &node[i].p);
    }
    std::sort(node + 1, node + 1 + n, cmp);
    for (int i = 1; i <= n; i++){
        if(heap.size() >= node[i].t){
            if(heap.top() < node[i].p){
                ans -= heap.top();
                heap.pop();
                ans += node[i].p;
                heap.push(node[i].p);
            }
        }else{
            heap.push(node[i].p);
            ans += node[i].p;
        }
    }
    printf("%lld\n", ans);
    return 0;
}