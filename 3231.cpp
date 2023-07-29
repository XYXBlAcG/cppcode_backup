#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 5e5 + 5;
int n, m, root;
struct Node{
    int v, idx;
};
int vis[N], ans[N], fath[N];
std::vector<int> st[N];
std::vector<Node> que[N];
int find(int x){
    return fath[x] == x ? x : fath[x] = find(fath[x]);
}
void tarjan(int x){
    vis[x] = 1;
    for (auto v : st[x]){
        if(!vis[v]){
            tarjan(v);
            // merge(x, v);
            fath[v] = x;
        }
    }
    for (auto v : que[x]){
        if(vis[v.v]) ans[v.idx] = find(v.v);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&root);
    for (int i = 1; i <= n - 1; i++){
        fath[i] = i;
        int x, y;
        scanf("%d%d",&x,&y);
        st[x].push_back(y);
        st[y].push_back(x);
    } fath[n] = n;
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d",&x,&y);
        que[x].push_back((Node){y, i});
        que[y].push_back((Node){x, i});
    }
    tarjan(root);
    for (int i = 1; i <= m; i++){
        printf("%d\n", ans[i]);
    }
    
    return 0;
}