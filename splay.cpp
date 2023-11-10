#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ch(u, v) node[u].ch[v]
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define sz(u) node[u].sz
#define cnt(u) node[u].cnt
#define fa(u) node[u].fa
const int N = 1e5 + 5;
struct Node{
    int ch[2], sz, cnt, fa;
    void clear(){
        ch[0] = ch[1] = sz = cnt = fa = 0;
    }
}node[N];
namespace splay{
    void upd(int u){
        sz(u) = sz(ls(u)) + sz(rs(u)) + cnt(u);
    }
    bool get(int u){
        return u == rs(fa(u));
    }
    void rotate(int u){
        int y = fa(u), z = fa(y), chk = get(u);
        ch(y, chk) = ch(u, chk ^ 1);
        if(ch(u, chk ^ 1)) fa(ch(u, chk ^ 1)) = y;
        if(z){
            ch(z, get(y)) = u;
        }
        fa(u) = z;
        ch(u, chk) = y;
        fa(y) = u;
        upd(y), upd(u);
    }
}