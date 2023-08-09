#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <time.h>
#include <algorithm>
#include <map>
#define int long long
const int N = 5e5 + 5;
struct Node{
    int v, w, tree;
};
struct Edge{
    int u, v;
}vec[2 * N];
std::map<Edge, Edge> vec_;
int n, m, q, k, u, v, c[N], ans[N], vis[N], dep[N], fa[N][20], cha[N], num[N], hist;
std::vector<Node> st[N];
bool add(int x){
    for (int i = 63 ; i >= 0; i--)
        if((x >> i & 1)){
            if(num[i]) x ^= num[i];
            else {num[i] = x; return 1;}
        }
    return 0;
}
void dfs(int x, int fath){
    // dep[x] = dep[fath] + 1;
    // fa[x][0] = fath;
    // for (int i = 1; i < 20; i++){
    //     fa[x][i] = fa[fa[x][i - 1]][i - 1];
    // }
    if(!vis[x]){
        vis[x] = 1;
        for (auto vv : st[x]){
            if(vv.v != fath){
                vv.tree = 1;
                Edge other = vec_[(Edge){vv.v, x}];
                Node &fuck = st[other.u][other.v];
                fuck.tree = 1;
                dfs(vv.v, x);
            }
        }
    }
}
void dfs2(int x, int fath, int res){
    if(!vis[x]){
        vis[x] = 1;
        for (auto vv : st[x]){
            if(vv.v != fath){
                dfs2(vv.v, x, res);
                Edge other = vec_[(Edge){vv.v, x}];
                Node &fuck = st[other.u][other.v];
                res ^= cha[vv.v];
                fuck.w ^= res;
                vv.w ^= res;
            }
        }
    }
}
// int lca(int x, int y){
//     if(dep[y] > dep[x]) std::swap(x, y);
//     for (int i = 19; i >= 0; i--)
//         if(dep[x] - dep[y] >= (1 << i)) x = fa[x][i];
//     if(!(x ^ y)) return x;
//     for (int i = 19; i >= 0; i--){
//         if(fa[x][i] ^ fa[y][i])
//             x = fa[x][i], y = fa[y][i];
//     }
//     return fa[x][0];
// }
signed main(){
    srand(time(0));
    int cnt = 0;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld", &u, &v);
        st[u].push_back((Node){v, 0, 0});
        st[v].push_back((Node){u, 0, 0});
        vec[++cnt] = (Edge){u, (int)st[u].size() - 1};
        vec[++cnt] = (Edge){v, (int)st[v].size() - 1};
        vec_[(Edge){u, v}] = (Edge){u, (int)st[u].size() - 1};
        vec_[(Edge){v, u}] = (Edge){v, (int)st[v].size() - 1};
        // vec[++cnt] = (Edge){v, st[u].size()}
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++){
        for (auto vv : st[i]){
            if(!vv.tree){
                vv.w = rand() % 100 + 1;
                Edge other = vec_[(Edge){vv.v, i}];
                Node &fuck = st[other.u][other.v];
                fuck.w = vv.w;
                cha[i] ^= vv.w;
                cha[vv.v] ^= vv.w;
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     for (auto vv : st[i]){
    //         if(!vv.tree){
    //             int lcaa = lca(i, vv.v);
    //             // cha[lcaa] ^= vv.w;
    //             // cha[i] ^= vv.w;
    //             // cha[vv.v] ^= vv.w;
    //         }
    //     }
    // }
    memset(vis, 0, sizeof(vis));
    dfs2(1, 0, 0);
    int ans_tmp = 0;
    for (int i = 1; i <= q; i++){
        ans_tmp = 0;
        memset(c, 0, sizeof(c));
        memset(num, 0, sizeof(num));
        scanf("%lld", &k);
        for (int j = 1; j <= k; j++){
            scanf("%lld", c + j), c[j] ^= hist;
            ans_tmp = ans_tmp && add(st[vec[i * 2].u][vec[i * 2].v].w);
        }
        puts(ans_tmp ? "Connected" : "Disconnected");
        hist += ans_tmp;
    }
    return 0;
}