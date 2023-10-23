#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using std::max;
using std::min;
const int N = 3005;
// bool diff(Num, Num);
struct Num{
    int data[N], pdata;
    void clean(){
        memset(data, 0, sizeof(data)), pdata = 0;
    }
    int& operator[](int a){
        return data[a];
    }
    void read(){
        char ch = 0;
        int tmp[N];
        while (ch < '0' || ch > '9') ch = getchar();
        while (ch >= '0' && ch <= '9') {
            tmp[++pdata] = (ch - '0');
            ch = getchar();
        }
        for (int i = 1; i <= pdata; i++) data[i] = tmp[pdata - i + 1];
    }
    Num operator+(Num a) const{
        Num tmp;
        for (int i = 1; i <= max(a.pdata, pdata); i++) tmp[i] = a[i] + data[i];
        for (int i = 1; i <= max(a.pdata, pdata) + 1; i++)
            if(tmp[i] > 10) tmp[i + 1] += tmp[i] / 10, tmp[i] %= 10;
        if(tmp[max(a.pdata, pdata) + 1]) tmp.pdata = max(a.pdata, pdata) + 1;
        else tmp.pdata = max(a.pdata, pdata);
        return tmp;
    }
    Num operator-(Num a) const{
        Num tmp;
        for (int i = 1; i <= min(a.pdata, pdata); i++) tmp[i] = data[i] - a[i];
        for (int i = 1; i <= max(a.pdata, pdata); i++) {
            while(tmp[i] < 0) tmp[i] += 10, tmp[i + 1]--;
        }
        if(tmp[pdata]) tmp.pdata = pdata;
        else tmp.pdata = pdata - 1;
        return tmp;
    }
    void print(){
        for (int i = pdata; i; i--)
            putchar(data[i] + '0');
        putchar('\n');
    }
}l, r; 
int m;
int main(){
    l.read(), r.read();
    l.print(), r.print();
    Num tmp = l + r;
    tmp.print();
    tmp = r - l;
    tmp.print();
    return 0;
}