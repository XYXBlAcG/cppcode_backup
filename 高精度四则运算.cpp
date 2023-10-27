#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
const int N = 1e3 + 5, top = 1e3;
int tmp[N];
struct Num{
    int data[N];
    int& operator[](int x){return data[x];}
    int size(){
        int pdata = top;
        for (; pdata > 0 && !data[pdata]; pdata--);
        return pdata;
    }
    Num(){memset(data, 0, sizeof(data));}
    void read(){
        string str = "";
        cin >> str;
        for (int i = 0; i < (int)str.size(); i++)
            data[i + 1] = str[(int)str.size() - i - 1] - '0';
    }
    void read2(){
        int pdata = 0;
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
Num transfer(int x){
    Num a; int len = 0;
    while(x) a[++len] = x % 10, x /= 10;
    return a;
}
bool operator<(Num a, Num b){
    for (int i = top; i; i--)
        if(a[i] < b[i]) return 1;
    return 0;
}
bool operator==(Num a, Num b){
    for (int i = top; i; i--)
        if(a[i] != b[i]) return 0;
    return 1;
}
bool operator>(Num a, Num b){
    for (int i = top; i; i--)
        if(a[i] > b[i]) return 1;
    return 0;
}
bool operator<=(Num a, Num b){
    for (int i = top; i; i--)
        if(a[i] <= b[i]) return 1;
    return 0;
}
bool operator>=(Num a, Num b){
    for (int i = top; i; i--)
        if(a[i] >= b[i]) return 1;
        else return 0;
    return 0;
}
Num operator+(Num a, int x){
    int d = 0;
    a[1] += x;
    for (int i = 1; i <= top; i++) a[i] += d, d = a[i] / 10, a[i] %= 10;
    return a;
}
Num operator+(Num a, Num b){
    Num res; int d = 0;
    for (int i = 1; i <= top; i++)
        res[i] = a[i] + b[i] + d, d = res[i] / 10, res[i] %= 10;
    return res;
}
Num operator-(Num a, Num b){
    Num res; int d = 0;
    for (int i = 1; i <= top; i++)
        res[i] = a[i] - b[i] + d;
}
Num operator-(Num a, int b){
    if(a < transfer(b)) return (a - transfer(b));
    int d = 0; a[1] -= b;
    for (int i = 1; i <= top; i++)
        a[i] += d, d = a[i] / 10 - (bool)(a[i] % 10), ((a[i] %= 10) += 10) %= 10;
    return a;
}
// Num operator*(Num a, int b){

// }
// Num operator*(Num a, Num b){

// }
// Div operator/(Num a, int b){

// }
// Div operator/(Num a, Num b){

// }
int main(){
    Num a; a.read();
    Num b; b.read();
    int c = 0; scanf("%d", &c);
    // print(a + b);
    // print(a);
    // print(a + c);
    // print(a - b);
    print(b - c);
    // print(a * b);
    // print(a * c);
    // print(b / c);
    return 0;
}