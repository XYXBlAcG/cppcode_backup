#include <cstdio>
#include <algorithm>
using std::min;
const int N = 1e5 * 32 + 5;
int n, cnt; long long ans;
struct Node{int son[2]; }node[N];
void add(int a){
    int cur = 0;
    for (int i = 1 << 30; i; i >>= 1){
        bool tmp = a & i;
        if(!node[cur].son[tmp]) node[cur].son[tmp] = ++cnt;
        cur = node[cur].son[tmp];
    }
}
int find(int a, int b, int i){
    if(i < 0) return 0;
    int t1 = -1, t2 = -1;
    if(node[a].son[0] && node[b].son[0]) t1 = find(node[a].son[0], node[b].son[0], i - 1);
    if(node[a].son[1] && node[b].son[1]) t2 = find(node[a].son[1], node[b].son[1], i - 1);
    if(~t1 && ~t2) return min(t1, t2); if(~t1) return t1; if(~t2) return t2;
    if(node[a].son[0] && node[b].son[1]) t1 = find(node[a].son[0], node[b].son[1], i - 1) + (1 << i);
    if(node[b].son[0] && node[a].son[1]) t2 = find(node[b].son[0], node[a].son[1], i - 1) + (1 << i);
    if(~t1 && ~t2) return min(t1, t2); if(~t1) return t1; if(~t2) return t2;
    // int cur = 0, tmp2 = 0; bool tmp = a & (1 << i ? i : 30);
    // for (i = i ? (1 << i) : (1 << 30); i; i >>= 1, tmp = a & i)
    //     if(node[cur].son[tmp]) cur = node[cur].son[tmp]; else cur = node[cur].son[tmp ^ 1], tmp2 += i;
    // return tmp2;
}
void dfs(int c, int depth){
    if(depth < 0) return;
    ans += (node[c].son[0] && node[c].son[1]) * ((long long)find(node[c].son[0], node[c].son[1], depth - 1) + (long long)(1 << depth));
    if(node[c].son[0]) dfs(node[c].son[0], depth - 1);
    if(node[c].son[1]) dfs(node[c].son[1], depth - 1);
}
int main(){
    int tmp = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&tmp), add(tmp);
    dfs(0, 30);
    printf("%lld\n", ans);
    return 0;
}