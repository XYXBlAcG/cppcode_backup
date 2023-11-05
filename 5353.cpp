#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
using std::string;
const int N = 1e5 + 5;
int n, q;
char rd[N];
string str[N], qry;
struct Tree{
    void pushup(int u){

    }
    void pushdown(int u){

    }
    void modify(int u, int l, int r, int pos){

    }
    int query(int u, int l, int r, int ql, int qr){
        
    }
};


void read(string& x){
    scanf("%s", rd), x = rd;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) read(str[i]);
    scanf("%d", &q);
    for (int i = 1, op, x; i <= n; i++) {
        scanf("%d", &op);
        if(op == 1){
            read(qry);
        }else{
            scanf("%d", &x);
        }
    }

    return 0;
}