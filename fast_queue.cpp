#include <cstdio>
#define p(x) printf("%d\n", x)
const int MAXN = 1e5 + 5;
template <typename T>
struct Queue{
    T data[MAXN]; int l, r;
    void push(T b){data[++r] = b;}
    void pop(){l++;}
    T tail(){return data[l + 1];}
    T head(){return data[r];}
    int size(){return r - l;}
    bool empty(){return r - l;}
    int* begin(){return &data[l + 1];}
    int* end(){return &data[r + 1];}
};
Queue<int> a;
int main(){
    a.push(1);
    a.push(2);
    a.push(4);
    a.push(8);
    p(a.head());
    p(a.tail());
    a.pop();
    a.pop();
    p(a.tail());
    p(a.size());
    for (auto v : a){
        p(v);
    }
    return 0;
}