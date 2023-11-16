#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, m, n1, n2, n3;
std::vector<int> kuai;
struct UFS{
    int fa[N];
    UFS(){
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    void merge(int x, int y){
        fa[find(x)] = find(y);
    }
    void get(){
        kuai.clear();
        for (int i = 1; i <= n; i++)
            if(fa[i] == i) kuai.push_back(i);
    }
}ufs;
std::vector<int> st[N];
int main(){
    scanf("%d%d", &n, &m);
    scanf("%d%d%d", &n1, &n2, &n3);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v), st[v].push_back(u);
        if(!ufs.same(u, v)) ufs.merge(u, v);
    }
    ufs.get();
    
    return 0;
}