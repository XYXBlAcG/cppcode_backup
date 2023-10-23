#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
const int N = 1005;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
int t, n, c[N], d[N], dep[N], dis[N][N], fa[N][21];
void clean(){
    for (int i = 1; i <= n; i++) st[i].clear();
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(dep, 0, sizeof(dep));
    memset(dis, 0, sizeof(dis));
    memset(fa, 0, sizeof(fa));
}
void predfs(int u, int fath){
    dep[u] = dep[fath] + 1, fa[u][0] = fath;
    for (int i = 1; i < 20; i++) fa[fa[u][i - 1]][i - 1] = fath;
    for (auto v : st[u])
        if(v.v != fath) predfs(v.v, u);
}
int lca(int a, int b){
    if(a == b) return a;
    if(dep[a] < dep[b]) std::swap(a, b);
    for (int i = 19; ~i; i--) if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    if(a == b) return a;
    for (int i = 19; ~i; i--) if(fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}
void caldis(){
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int lc = lca(i, j);
            dis[j][i] = dis[i][j] = dep[i] + dep[j] - (dep[lc] << 1);
        }
    }
}
void dfs(int u, int fa){
    for (auto v : st[u]){
        if(v.v != fa){
            dfs(v.v, u);
        }
    }
}
template<typename T>
void mx(T& a, T b){
	a = std::min(a, b);
}
namespace baoli{
	int sta = 0;
	int dfs(int u, int fa, int pos){
		int ans = 0;
		if((int)st[u].size() == 1 && u != sta){
			if(pos > d[u]) return c[u];
			return 0ll;
		}
		for (auto vv : st[u]){
			int v = vv.v; int w = vv.w;
			if(v != fa){
				int a1 = INF, a2 = INF;
				if(pos <= d[u]) a1 = dfs(v, u, pos + w);
				a2 = dfs(v, u, w) + c[u];
				ans += std::min(a1, a2);
			}
		}
		return ans;
	}
	void main(){
		int res = INF;
		for (int i = 1; i <= n; i++){
			sta = i;
			mx(res, dfs(i, -1, 0) + c[i]);
		}
		
		printf("%lld\n", res);
	}
}
void init(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", c + i);
    for (int i = 1; i <= n; i++) scanf("%lld", d + i);
    for (int i = 1, u, v, w; i < n; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
}
void solve(){
    predfs(1, -1);
    caldis();
    
}
signed main(){
    scanf("%lld", &t);
    while(t--){
        init();
        solve();
        clean();
    }
    return 0;
}