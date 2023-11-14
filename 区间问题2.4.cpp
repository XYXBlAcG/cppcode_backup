#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define sum(u) node[u].sum
#define add(u) node[u].add
#define mul(u) node[u].mul
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mid ((l + r) >> 1)
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, m, a[N];
struct Node{
    int sum, add, mul;
    Node(int sum = 0, int add = 0, int mul = 1){
        this->sum = sum, this->add = add, this->mul = mul;
    }
}node[N * 8];
struct Tree{
    void pushdown(int u, int l, int r){
        if(mul(u) != 1){
            (mul(ls(u)) *= mul(u)) %= mod;
            (sum(ls(u)) *= mul(u)) %= mod;
            (mul(rs(u)) *= mul(u)) %= mod;
            (sum(rs(u)) *= mul(u)) %= mod;
            mul(u) = 1;
        }
        if(add(u)){
            ((add(ls(u)) *= mul(ls(u))) %= mod) += add(u);
            ((add(rs(u)) *= mul(rs(u))) %= mod) += add(u);
            (sum(ls(u)) += add(u) * (mid - l + 1)) %= mod;
            (sum(rs(u)) += add(u) * (r - mid)) %= mod;
            add(u) = 0;
        }
    }
    void pushup(int u){
        sum(u) = (sum(ls(u)) + sum(rs(u))) % mod;
    }
    void build(int u, int l, int r){
        if(l == r){
            sum(u) = a[l];
            return;
        }
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, int val, int op){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr){
            if(op == 1) (add(u) += val) %= mod, (sum(u) += val * (r - l + 1) % mod) %= mod;
            else (add(u) *= val) %= mod, (sum(u) *= val) %= mod, (mul(u) *= val) %= mod;
            return;
        }
        pushdown(u, l, r);
        modify(ls(u), l, mid, ql, qr, val, op), modify(rs(u), mid + 1, r, ql, qr, val, op);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return 0;
        if(ql <= l && r <= qr)
            return sum(u);
        pushdown(u, l, r);
        return (query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr)) % mod;
    }
}tree;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    tree.build(1, 1, n);
    for (int i = 1; i <= m; i++){
        int op, l, r, c;
        scanf("%lld%lld%lld", &op, &l, &r);
        if(op == 0){
            printf("%lld\n", tree.query(1, 1, n, l, r));
        }else{
            scanf("%lld", &c);
            tree.modify(1, 1, n, l, r, c, op);
        }
    }
    return 0;
}