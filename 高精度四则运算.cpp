#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
const int N = 1e3 + 5, top = 1e3;
int tmp[N];
struct Num{
    int data[N], pdata, f;
    int& operator[](int x){
        return data[x];
    }
    int size(){
        return pdata;
    }
    Num(){
        memset(data, 0, sizeof(data));
        pdata = 0;
        f = 1;
    }
    void read(){
        int i = 1;
        char c = 0;
        memset(tmp, 0, sizeof(tmp));
        while (c < '0' || c > '9') {
            if (c == '-') f = -1;
            c = getchar();
        }
        while (c >= '0' && c <= '9')
            tmp[i] = (c - '0'), c = getchar(), i++;
        for (int j = 1; j <= i; j++) data[i] = tmp[pdata - i + 1]; 
    }
    void read2(){
        scanf("%d", &pdata);
        for (int i = 1; i <= pdata; i++) scanf("%d", data + i);
    }
};
struct Div{
    Num res, out;
};
void print(Num a){
    for (int i = a.size(); i; i--) printf("%d", a[i]);
    putchar('\n');
}
Num operator+(Num a, int x){
    int d = 0;
    a[1] += x;
    for (int i = 1; i <= top; i++) a[i] += d, d = a[i] % 10, a[i] /= 10;
    return a;
}
// Num operator+(Num a, Num b){

// }
// Num operator-(Num a, int b){

// }
// Num operator-(Num a, Num b){

// }
// Num operator*(Num a, int b){

// }
// Num operator*(Num a, Num b){

// }
// Num operator/(Num a, int b){

// }
// Div operator/(Num a, Num b){

// }
int main(){
    Num a; a.read2();
    int c = 0; scanf("%d", &c);
    // print(a + b);
    print(a);
    print(a + c);
    // print(a - b);
    // print(b - c);
    // print(a * b);
    // print(a * c);
    // print(b / c);
    return 0;
}