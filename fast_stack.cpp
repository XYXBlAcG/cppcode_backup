#include <cstdio>
#define p(x) printf("%d\n", x)
const int MAXN = 1e5 + 5;
template <typename T>
struct Stack{
    T data[MAXN]; int pdata;
    void push(T b){data[++pdata] = b;}
    void pop(){if(pdata) pdata--;}
    T operator[](int x){return data[x];}
    T top(){return data[pdata];}
    int size(){return pdata;}
    bool empty(){return pdata;}
    int* begin(){return &data[1];}
    int* end(){return &data[pdata + 1];}
};
int main(){
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(4);
    a.push(8);
    a.pop();
    a.pop();
    p(a[1]);
    p(a.size());
    a.push(114514);
    for (auto v : a){
        p(v);
    }
    return 0;
}