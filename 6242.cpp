#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#define ls(u) node[u].ls
#define rs(u) node[u].rs
#define sum(u) node[u].sum
#define NO puts("Yes")
#define YES puts("No")
const int N = 1e5 + 5;
typedef unsigned long long ull;
std::unordered_map<ull, int> mp;
const ull top = LLONG_MAX;
int n, m, k, a[N], b[25], rt[N], cnt;
ull p[25];
struct Node{
    int ls, rs, sum;
}node[N << 2];
std::vector<int> has;
struct Tree{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void build(int& u, int l, int r){
        if(!u) u = ++cnt;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int& u, int l, int r, int pos){
        if(l > pos || r < pos) return;
        u = clone(u), sum(u)++;
        if(l == r) return;
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, pos), modify(rs(u), mid + 1, r, pos);
    }
    int query(int u, int l, int r, int k){

    }
}tree;
void init(){
    for (int i = 1; i <= 20; i++)
        p[i] = p[i - 1] * (2e9 + 1);
}
int hash(){
    int ret = 0;
    for (int i = 0; i < (int)has.size(); i++)
        ret += has[i] * p[i];
    return ret;
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    tree.build(rt[0], 1, n);
    for (int i = 1; i <= n - k + 1; i++){
        has.clear();
        for (int j = i; j <= i + k - 1; j++) has.push_back(a[i]);
        tree.modify(rt[i] = tree.clone(rt[i - 1]), 1, n, hash());
    }
    for (int i = 1, l, r; i <= m; i++){
        scanf("%d%d", &l, &r);
        for (int j = 1; j <= k; j++) scanf("%d", b + j);
        
    }

    return 0;
}