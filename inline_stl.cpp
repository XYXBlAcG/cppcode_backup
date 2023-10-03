#include <cstdio>
#include <algorithm>
const int STL_MAXN = 1e5 + 5;
namespace xyx{
    template <typename T>
    struct Heap{
        T data[STL_MAXN]; int pdata = 0;
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
    template <typename T>
    struct Stack{
        T data[STL_MAXN]; int pdata = 0;
        void push(T b){data[++pdata] = b;}
        void pop(){if(pdata) pdata--;}
        T operator[](int x){return data[x];}
        T top(){return data[pdata];}
        int size(){return pdata;}
        bool empty(){return pdata;}
        int* begin(){return &data[1];}
        int* end(){return &data[pdata + 1];}
    };
    template <typename T>
    struct Queue{
        T data[STL_MAXN]; int l = 0, r = 0;
        void push(T b){data[++r] = b;}
        void pop(){l++;}
        T tail(){return data[l + 1];}
        T head(){return data[r];}
        int size(){return r - l;}
        bool empty(){return r - l;}
        int* begin(){return &data[l + 1];}
        int* end(){return &data[r + 1];}
    };
};