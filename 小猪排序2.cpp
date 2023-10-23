#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
const int N = 1e5 + 5;
struct Node{

}node[N];
struct Tree{
    void build(int u, int l, int r){
        if(l == r){
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int u, int l, int r, int val, int ql, int qr){
        if(qr > l || ql < r) return;
        if(ql <= l && r <= qr){
            return;
        }
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, val, ql, qr), modify(rs(u), mid + 1, r, val, ql, qr);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(qr > l || ql < r) return 0;
        if(ql <= l && r <= qr){
            return 0;
        }
        int mid = (l + r) >> 1;
        query(ls(u), l, mid, ql, qr), query(rs(u), mid + 1, r, ql, qr);
    }
};
int main(){
    
    return 0;
}