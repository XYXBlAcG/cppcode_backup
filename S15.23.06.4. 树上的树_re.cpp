#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
const int N = 1e5 + 5;
int n, k, q, o, tc, a[N], ans;
void ol(int &x){x ^= ans;}
struct Tree2{
    void build(int u, int l, int r){
        if(l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int u, int l, int r, int ql, int qr, int val){
        if(qr > l )
    }
    int query(int u, int l, int r, int ql, int qr){

    }
};
struct Tree{
    void build(int u, int l, int r){

    }
    void modify(int u, int l, int r, int ql, int qr){

    }
    int query(int u, int l, int r, int ql, int qr){

    }
};
int main(){
    scanf("%d%d%d%d%d", &tc, &n, &k, &q, &o);
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }
    for (int i = 1, t, x, y; i <= q; i++){
        scanf("%d%d%d", &t, &x, &y);
        ol(t), ol(x), ol(y), ans = 0;
        
    }
    return 0;
}