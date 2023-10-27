#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
// #define printf(...) std::cout << __VA_ARGS__ << '\n'
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define fa(u) node[u].fa
#define sum(u) node[u].sum
#define tag(u) node[u].tag
#define mul(u) node[u].mul
#define sz(u) node[u].sz
#define add(u) node[u].add
#define val(u) node[u].val
#define int long long
using std::string;
using std::cin;
using std::cout;
// #include "xyx.h"
// using xyx::output;
const int N = 1e5 + 5, mod = 51061;
int n, q;
std::vector<int> st[N];
struct Node{
    int ch[2], fa, sum, tag, mul, add, sz, val;
    void init(){
        ch[0] = ch[1] = fa = tag = add = 0, sum = val = mul = sz = 1;
    }
}node[N];
bool get(int u){
    return rs(fa(u)) == u;
}
// void print(int u){
//     if(ls(u)) print(ls(u));
//     output(10, "u = ", u, "sz = ", sz(u), "val = ", val(u), "sum = ", sum(u));
//     if(rs(u)) print(rs(u));
// }
void pushup(int u){
    // output(5, ls(u), "<-", u, "->", rs(u));
    sum(u) = (sum(ls(u)) + sum(rs(u)) + val(u)) % mod;
    sz(u) = sz(ls(u)) + sz(rs(u)) + 1;
}
void rev(int u){
    std::swap(ls(u), rs(u)), tag(u) ^= 1;
}
void mu(int u, int w){
    (val(u) *= w) %= mod, (mul(u) *= w) %= mod, (add(u) *= w) %= mod, (sum(u) *= w) %= mod;
}
void ad(int u, int w){
    (val(u) += w) %= mod, (add(u) += w) %= mod, (sum(u) += w * sz(u)) %= mod;
}
void pushdown(int u){
    if(mul(u) ^ 1) mu(ls(u), mul(u)), mu(rs(u), mul(u)), mul(u) = 1;
    if(add(u)) ad(ls(u), add(u)), ad(rs(u), add(u)), add(u) = 0;
    if(tag(u)) {
        rev(ls(u));
        rev(rs(u));
        tag(u) = 0; 
    }
}
bool isroot(int u){
    return ls(fa(u)) != u && rs(fa(u)) != u;
}
void rotate(int u){
    int y = fa(u), z = fa(y), k = get(u);
    if(!isroot(y)) node[z].ch[rs(z) == y] = u;
    node[y].ch[k] = node[u].ch[!k]; fa(node[u].ch[!k]) = y;
    node[u].ch[!k] = y, fa(y) = u, fa(u) = z;
    pushup(y), pushup(u);
}
void update(int u){
    if(!isroot(u)) update(fa(u));
    pushdown(u);
}
void splay(int u){
    update(u);
    for (int f; f = fa(u), !isroot(u); rotate(u)){
        if(!isroot(f)) rotate(get(f) == get(u) ? f : u);
    }
}
void access(int u){
    for (int f = 0; u; f = u, u = fa(u))
        splay(u), rs(u) = f, pushup(u);
}
void makeroot(int u){
    access(u);
    splay(u);
    rev(u);
}
void link(int x, int y){
    makeroot(x);
    fa(x) = y;
}
void split(int x, int y){
    makeroot(x);
    access(y);
    splay(y);
}
void cut(int x, int y){
    split(x, y);
    fa(x) = ls(y) = 0;
}
void mdf(int u, int v, int c, int op){
    split(u, v);
    if(op == 1) ad(v, c); 
    else mu(v, c);
}
int query(int u, int v){
    return split(u, v), sum(v);
}
signed main(){
    std::ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) node[i].init();
    for (int i = 1, u = 0, v = 0; i < n; i++)
        cin >> u >> v, link(u, v);
    for (int i = 1, u, v, c, u1, v1; i <= q; i++){
        string op;
        cin >> op;
        if(op == "+"){
            cin >> u >> v >> c;
            mdf(u, v, c, 1);
        }else if(op == "-"){
            cin >> u >> v >> u1 >> v1;
            cut(u, v), link(u1, v1);
        }else if(op == "*"){
            cin >> u >> v >> c;
            mdf(u, v, c, 2);
        }else{
            cin >> u >> v;
            cout << query(u, v) << '\n';
        }
        // for (int i = 1; i <= n; i++){
        //     cout << "val = " << val(i) << " sum = " << sum(i) << " mul = " << mul(i) << " add = " << add(i) << " sz = " << sz(i) << '\n';
        // }
    }
    return 0;
}