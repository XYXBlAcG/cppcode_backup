#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N = 3e5 + 5;
int n, k, mx, id[N], pid, pas[N], ppas;
template <typename T, size_t _Size>
struct Heap{
    T data[_Size]; int pdata = 0;
    void push(T b){
        data[++pdata] = b;
        std::push_heap(data + 1, data + 1 + pdata);
    }
    void pop(){std::pop_heap(data + 1, data + 1 + pdata--);}
    T top(){return data[1];}
    int size(){return pdata;}
    bool empty(){return pdata;}
    T* begin(){return &data[1];}
    T* end(){return &data[pdata + 1];}
};
Heap<int, N> del, val;
int main(){
    scanf("%d", &n);
    for (int i = 1, op = 0, x = 0; i <= n; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            pas[++ppas] = x;
            id[++k] = ppas;
            val.push(x);
            while(val.size() && del.size() && val.top() == del.top()) val.pop(), del.pop();
            printf("%d\n", val.top());
        }else{
            while(val.size() && del.size() && val.top() == del.top()) val.pop(), del.pop();
            int y = val.top(), idx = (y % k) + 1;
            printf("%d\n", pas[id[idx]]);
            del.push(pas[id[idx]]);
            id[idx] = id[k], id[k] = 0, k--;            
        }
    }
    return 0;
}