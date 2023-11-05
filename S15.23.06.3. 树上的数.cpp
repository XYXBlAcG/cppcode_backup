#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define int long long
typedef double d;
const int N = 5e5 + 5;
int n, m, q, dis[N], fa[N][20], dep[N], dfn[N], pdfn, tim, sz[N];
std::vector<int> reqq;
bool spc;
d f[N], ans;
struct Node{
	int v, w;
};
std::vector<Node> st[N];
bool cmpw(Node a, Node b){
	return a.w < b.w;
}
void predfs(int u, int fath){
	dfn[u] = ++pdfn;
	dep[u] = dep[fath] + 1;
	fa[u][0] = fath;
	for (int i = 1; i <= 19; i++){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	std::sort(st[u].begin(), st[u].end(), cmpw);
	for (auto v : st[u]){
		if(v.v == fath) continue;
		dis[v.v] = dis[u] + v.w;
		predfs(v.v, u);
		sz[u] += sz[v.v];
	}
	sz[u]++;
}
int lca(int a, int b){
	if(a == b) return a;
	if(dep[a] < dep[b]) std::swap(a, b);
	for (int i = 19; ~i; i--){
		if(dep[fa[a][i]] >= dep[b]) a = fa[a][i]; 
	}
	if(a == b) return a;
	for (int i = 19; ~i; i--){
		if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
	}
	return fa[a][0];
}
bool cmp2(int a, int b){
//	if(dis[a] == dis[b]) return dfn[a] < dfn[b];
//	return dis[a] < dis[b];
//	if(dfn[a] <= dfn[b] && dfn[b] <= dfn[a] + sz[a] - 1) return dis[a] < dis[b];
//	return dfn[a] < dfn[b];
//	return dfn[a] < dfn[b];
	
	return dis[a] < dis[b];
}
namespace spec{
	void main(){
		for (int i = 1; i <= q; i++){
			scanf("%lld", &m);
			int mx = 0, tmp = 0;
			for (int j = 1; j <= m; j++){
				scanf("%lld", &tmp);
				mx = std::max(mx, tmp);
			}
			printf("%.8lf\n", (d)dis[mx] / m);
		}
	}
}

signed main(){
    #ifdef ONLINE_JUDGE
        freopen("not.in", "r", stdin);
        freopen("not.out", "w", stdout);
    #else
    #endif
	
	scanf("%lld%lld", &n, &q);
	spc = 1;
	for (int i = 1, u, v, w; i < n; i++){
		scanf("%lld%lld%lld", &u, &v, &w);
		st[u].push_back({v, w});
		st[v].push_back({u, w});
		if(v != u + 1 && u != v + 1) spc = 0;
	}
	predfs(1, 0);
	if(spc){
		spec::main();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (int i = 1; i <= q; i++){
		scanf("%lld", &m), ans = 0, tim = 0;
		reqq.clear();
		for (int j = 1, who = 0; j <= m; j++){
			scanf("%lld", &who);
			reqq.push_back(who);
		}
//		dfs(1, 0, 0);
		std::sort(reqq.begin(), reqq.end(), cmp2);
		for (int i = 0; i < (int)reqq.size(); i++){
			if(i == 0){
				tim += dis[reqq[i]];
				ans += tim;
//				printf("goto %lld with dis %lld\n", reqq[i], dis[reqq[i]]);
			}else{
				int u = reqq[i - 1], v = reqq[i];
				int lc = lca(u, v);
//				printf("dfn %lld = %lld, %lld = %lld\n", u, dfn[u], v, dfn[v]);
				int dist = dis[u] + dis[v] - dis[lc] * 2;
//				printf("dis u = %lld, v = %lld\n", dis[u], dis[v]);
				tim += dist;
				ans += tim;
//				printf("%lld -> %lld with tim %lld\n", u, v, tim);
//				printf("%lld %lld anc = %lld\n", u, v, lc);
			}
		}
		printf("%.8lf\n", ans / m);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

