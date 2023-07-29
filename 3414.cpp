#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 4e6 + 5;
struct Edge{
    int v, w;
};
std::vector<Edge> st[N];
int n, cnt, s[N], ans;
struct Node{
    int son[2];
}node[N];
void add(int a){
    int cur = 0;
    for (int i = (1 << 30); i; (i >>= 1)){
        bool tmp = a & i;
        if(!node[cur].son[tmp]) node[cur].son[tmp] = ++cnt; 
        cur = node[cur].son[tmp];
    }
}
void find(int a){
    int cur = 0, tmp2 = 0;
    for (int i = (1 << 30); i; i >>= 1){
        bool tmp = a & i;
        if(node[cur].son[tmp ^ 1]){
            tmp2 += i;
            cur = node[cur].son[tmp ^ 1];
        }else{
            cur = node[cur].son[tmp];
        }
    }
    ans = std::max(ans, tmp2);
}
void dfs(int x, int fath, int sum){
    for (auto v : st[x]){
        if(v.v != fath){
            s[v.v] = s[x] ^ v.w;
            dfs(v.v, x, sum ^ v.w);
        }
    }
}
int main(){
    while(scanf("%d",&n) != EOF){
        for (int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            st[u].push_back((Edge){v, w});
            st[v].push_back((Edge){u, w});
        }
        dfs(1, 0, 0);
        for (int i = 1; i <= n; i++) add(s[i]);
        for (int i = 1; i <= n; i++) find(s[i]);
        printf("%d\n", ans);
        for (int i = 0; i <= n + 32; i++){
            st[i].clear();
            s[i] = node[i].son[1] = node[i].son[0] = 0;
        }
        n = ans = cnt = 0;
    }
    return 0;
}