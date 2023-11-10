#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e6 + 5;
using std::string;
char rd[N];
void read(string& x){
    scanf("%s", rd), x = rd;
}
string a, b;
int am, bm;
bool same = 1;
int minexp(string x){
    int i = 0, j = 1, k = 0, n = x.size();
    while(i < n && j < n && k < n){
        if(x[(i + k) % n] == x[(j + k) % n]) k++;
        else{
            x[(i + k) % n] > x[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if(i == j) i++;
            k = 0;
        }
    }
    return std::min(i, j);
}
int main(){
    read(a), read(b);
    if(a.size() ^ b.size()) return puts("No"), 0;
    am = minexp(a), bm = minexp(b);
    int n = a.size();
    for (int cur = 0; cur < (int)a.size(); cur++){
        int an = (cur + am) % n;
        int bn = (cur + bm) % n;
        if(a[an] != b[bn]) {
            same = 0; break;
        }
    }
    if(same == 1){
        puts("Yes");
        for (int cur = 0; cur < (int)a.size(); cur++){
            int an = (cur + am) % n;
            printf("%c", a[an]);
        }
        putchar('\n');
    }else{
        puts("No");
    }
    return 0;
}