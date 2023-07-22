#include <cstdio>
#include <algorithm>
const int N = 114514;
struct Node{
    int val, rdep, lson, rson;
}node[N];
int merge(int a, int b){
    if(!b) return a;
    if(!a) return b;
    if(node[a].val < node[b].val) std::swap(a, b);
    node[a].rson = merge(node[a].rson, b);
    if(node[node[a].rson].rdep > node[node[a].lson].rdep) std::swap(node[a].rson, node[a].lson);
    node[a].rdep = node[node[a].rson].rdep;
    return a;
}
int main(){
    return 0;
}