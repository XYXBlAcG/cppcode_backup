#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e3 + 5;
typedef long long ll;
int t, n;
ll c[N], d[N], rec[N];
struct Node{
	int v;
	ll w;
};
std::vector<Node> st[N];
void clean(){
	for (int i = 1; i <= n; i++) st[i].clear();
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
}
template<typename T>
void mx(T& a, T b){
	a = std::min(a, b);
}
namespace baoli{
	int sta = 0;
	ll dfs(int u, int fa, ll pos){
		ll ans = 0;
		if((int)st[u].size() == 1 && u != sta){
			if(pos > d[u]) return c[u];
			return 0ll;
		}
		for (auto vv : st[u]){
			int v = vv.v; ll w = vv.w;
			if(v != fa){
				ll a1 = INF, a2 = INF;
				if(pos <= d[u]) a1 = dfs(v, u, pos + w);
				a2 = dfs(v, u, w) + c[u];
				ans += std::min(a1, a2);
			}
		}
		return ans;
	}
	void main(){
		ll res = INF;
		for (int i = 1; i <= n; i++){
			sta = i;
			mx(res, dfs(i, -1, 0) + c[i]);
		}
		
		printf("%lld\n", res);
	}
}
// struct FileIO{
//     FileIO(){
//         #ifdef ONLINE_JUDGE
//             freopen("color.in", "r", stdin);
//             freopen("color.out", "w", stdout);
//         #else
//         #endif
//     }
//     ~FileIO(){
//         fclose(stdin);
//         fclose(stdout);
//     }
// }FileIO;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", c + i);
		for (int i = 1; i <= n; i++) scanf("%lld", d + i);
		for (int i = 1; i < n; i++){
			int u = 0, v = 0, w = 0;
			scanf("%d%d%d", &u, &v, &w);
			st[u].push_back({v, w});
			st[v].push_back({u, w});
		}
		baoli::main();
		clean();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
