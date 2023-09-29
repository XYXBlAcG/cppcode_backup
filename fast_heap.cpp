#include <cstdio>
#include <algorithm>
const int MAXN = 1e5 + 5;
template <typename T>
struct Heap{
    T data[MAXN]; int pdata;
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
Heap<int> a;
int main(){
    a.push(1);
    a.push(2);
    a.push(6);
    a.push(4);
    printf("%d\n", a.top());
    a.pop();
    printf("%d\n", a.size());
    for (int v : a){
        printf("%d ", v);
    }putchar('\n');
    return 0;
}