#include <cstdio>
#include <vector>
#define int long long
const int N = 20, M = 1 << 16;
std::vector<int> st[N];
int edge[N][N], n, m, f[N][N][M], son[N], bro[N], g[N][N][M], si[N]; 
bool vf[N][N][M], vg[N][N][M];
void dfs(int u, int fa){
	for (int i = 0; i < (int)st[u].size(); i++){
		int v = st[u][i];
		if(v != fa){
			dfs(v, u);
			if(!son[u])
				son[u] = v;
			if(i != (int)st[u].size() - 1)
				bro[v] = st[u][i + 1];
			si[u] += si[v];
		}
	}
}
int dg(int u, int fa, unsigned S);
int df(int u, int fa, unsigned S){
	if(vf[u][fa][S]) return f[u][fa][S];
	vf[u][fa][S] = 1;
	if(!son[u]){
//		return f[u][fa][S] = 1;
		for (int k = 1; k <= n; k++){
			if((S >> (k - 1)) & 1){
//				printf("edge = %lld\n", edge[fa][k]);
				f[u][fa][S] += edge[fa][k];
			}
		}
		return f[u][fa][S];
	}
	for (int k = 1; k <= n; k++){
		if(edge[fa][k] && ((S >> (k - 1)) & 1)){
			f[u][fa][S] += dg(son[u], k, S & ~(1 << (k - 1)));
		}
	} 
	return f[u][fa][S];
}
int dg(int u, int fa, unsigned S){
	if(vg[u][fa][S]) return g[u][fa][S];
	vg[u][fa][S] = 1;
	if(!bro[u])
		return g[u][fa][S] = df(u, fa, S);
	for (unsigned t = S; t; t = S & (t - 1)){
//		puts("?");
		if(__builtin_popcount(t) == si[u]){
//			puts("!");
			g[u][fa][S] += df(u, fa, t) * dg(bro[u], fa, S ^ t);
		}
	}
	return g[u][fa][S];
}
signed main(){
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) si[i] = 1;
	for (int i = 1, u, v; i < n; i++){
		scanf("%lld%lld", &u, &v);
		st[u].push_back(v);
		st[v].push_back(u);
	}
	for (int i = 1, u, v; i <= m; i++){
		scanf("%lld%lld", &u, &v);
		edge[u][v] = edge[v][u] = 1;
	}
	dfs(1, 0);
//	for (int i = 1; i <= n; i++){
//		printf("son[%lld] = %lld\n", i, son[i]);
//		printf("bro[%lld] = %lld\n", i, bro[i]);
//		printf("si[%lld] = %lld\n", i, si[i]);
//	}
	int res = 0; 
	for (int i = 1; i <= n; i++)
		edge[0][i] = edge[i][0] = 1;
	res += df(1, 0, (1 << n) - 1);
	printf("%lld\n", res);
	return 0;
}
