#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
#define int long long
const int N = 2005;
int n, m, dis[N], ans;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
bool bellman(int s){
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    bool check;
    for (int k = 0; k < n; k++){
        check = 0;
        for (int i = 0; i <= n; i++){
            for (auto v : st[i]){
                if(dis[v.v] > dis[i] + v.w){
                    dis[v.v] = dis[i] + v.w, check = 1;
                }
            }
        }
        if(!check) break;
    }
    return check;
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++){
        int u, v, w; char ss;
        scanf("%lld%lld%lld", &u, &v, &w);
        std::cin >> ss;
        if(ss == '>') {
            st[v].push_back((Node){u, (-w - 1)});
        }else if(ss == '<') {
            st[u].push_back((Node){v, (w - 1)});
        }else if(ss == '=') {
            st[v].push_back((Node){u, (-w)});
            st[u].push_back((Node){v, (w)});
        }
    }
    for (int i = 1; i <= n; i++){
        st[0].push_back((Node){i, -1});
    }
    if(bellman(0)) printf("No solution\n");
    else{
        for (int i = 1; i <= n; i++){
            ans -= dis[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
