#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define No puts("Too much difference")
using std::string;
const int N = 1e5 + 5, M = 105;
int k, trans[M], cnt, l[N], p;
char rd[N];
string n, m;
void read(string& x){
    scanf("%s", rd), x = rd;
}
int main(){
    scanf("%d", &k);
    read(n), read(m);
    for (auto v : n)
        if(!trans[v - 33]) trans[v - 33] = ++cnt;
    for (auto v : m){
        
    }
    return 0;
}