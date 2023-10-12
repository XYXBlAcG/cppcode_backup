#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define ls(u) node[u].son[0]
#define rs(u) node[u].son[1]
#define fa(u) node[u].fa
#define size(u) node[u].size
const int N = 2e6 + 5;
int n, m;
std::vector<int> st[N];
void addedge(int u, int v){
    st[u].push_back(v);
    st[v].push_back(u);
}
struct Node{
    int son[2], fa, size;
}node[N];
void upd(int u){
    size(u) = size(ls(u)) + size(rs(u)) + 1;
}
bool get(int u){return u == rs(fa(u));}
struct Tree{
    void rotate(int u){
        
    }
};
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    return 0;
}