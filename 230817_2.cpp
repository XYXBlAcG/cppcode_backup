#include <cstdio>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define len(u) t[u].r - t[u].l + 1
const int N = 1e5 + 5;
int cnt[N], tag[N], len[N]; // len区间大于 0 的位置总数, cnt区间被覆盖次数, tag区间加懒标记
struct Tree{
    int l, r;
}t[N];
void pushup(int u){
    len[u] = len[ls(u)] + len[rs(u)];
}
void update(int u, int c){
    cnt[u] += c;
    if(cnt[u]) len[u] = len(u);
    else pushup(u);
}
void dfs(int u, int l, int r){
    
}
int main(){

    return 0;
}