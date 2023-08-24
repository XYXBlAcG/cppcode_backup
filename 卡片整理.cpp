#include <cstdio>
const int N = 1e5 + 5;
int n, m;
void memcpy(int* to, int *src, int size){
    for (int i = 0; i < size; i++){
        to[i] = src[i];
    }
}
template<typename T>
struct Vec{
    T* data;
    int len, size;
    T &operator[] (const int x) {return data[x];}
    void push_back(T x){
        if(size == len){
            len = len ? (len << 1) : 1;
            T* ndata = new T[len];
            memcpy(ndata, data, size);
            delete data;
            data = ndata;
        }
        data[size++] = x;
    }
    void pop_back(){
        size--;
        if(size == (len >> 2)){
            len >>= 1;
            T* ndata = new T[len];
            memcpy(ndata, data, size);
            delete data;
            data = ndata;
        }
    }
    int siz(){
        return size;
    }
    T back(){
        return data[size - 1];
    }
};
Vec<int> card[N];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        card[i].push_back(i);
    }
    for (int i = 1; i <= m; i++){
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1){
            int tmp = card[x].back();
            printf("%d\n", tmp);
            card[x].pop_back();
            card[y].push_back(tmp);
        }else{
            printf("%d\n", card[x][y - 1]);
        }
    }
    return 0;
}