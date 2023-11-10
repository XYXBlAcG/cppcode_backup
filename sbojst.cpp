#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 3e5 + 5;
int q, add;
bool cmp(int a, int b){
	return a > b;
}
template <typename T>
	struct Heap{
        T data[N]; int pdata = 0;
        void push(T b){
            data[++pdata] = b;
            std::push_heap(data + 1, data + 1 + pdata, cmp);
        }
        void pop(){std::pop_heap(data + 1, data + 1 + pdata--, cmp);}
        T top(){return data[1];}
        int size(){return pdata;}
        bool empty(){return !pdata;}
        T* begin(){return &data[1];}
        T* end(){return &data[pdata + 1];}
    };
Heap<int> heap;
signed main(){
    scanf("%lld", &q);
    for (int i = 1; i <= q; i++){
		int op, x;
        scanf("%lld", &op);
        if(op == 1){
            scanf("%lld", &x);
            heap.push(x);
        }else if(op == 2){
			scanf("%lld", &x);
            add += x;
        }else{
            if(heap.empty()) continue;
			int top = heap.top();
            heap.pop();
            printf("%lld\n", top + add);
        }
    }
    return 0;
}