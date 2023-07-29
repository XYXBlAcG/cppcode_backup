#include <cstdio>
#include <vector>
#define int long long
const int N = 1e5 + 5;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
int n, m, vis[N], num[N], sum[N];
void add(int x){
    for (int i = 63 ; i >= 0; i--)
        if((x >> i & 1)){
            if(num[i]) x ^= num[i];
            else {num[i] = x; return;}
        }
}
void dfs(int x, int ssum){
    sum[x] = ssum, vis[x] = 1;
    for (auto v : st[x]){
        if(!vis[v.v]) dfs(v.v, ssum ^ v.w);
        else add(sum[v.v] ^ v.w ^ ssum);
    }
}
int getsum(int x){
    int res = x;
    for (int i = 63; i >= 0; i--)
        if((res ^ num[i]) > res) res ^= num[i];
    return res;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++){
        int s, t, d;
        scanf("%lld%lld%lld", &s, &t, &d);
        st[s].push_back((Node){t, d});
        st[t].push_back((Node){s, d});
    }
    dfs(1, 0);
    printf("%lld\n", getsum(sum[n]));
    return 0;
}