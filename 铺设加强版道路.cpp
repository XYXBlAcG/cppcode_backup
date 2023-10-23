#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
const int N = 8e5 + 5, mod = 1e9;
int n, m, T, in[N], out[N], fa[N], res[N], ans; bool av[N];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void add(int u, int v, int d){
	in[v] += d, out[u] += d;
	fa[v = find(v)] = u = find(u);
	av[u] = av[u] || av[v];
	if(d) av[u] = 1;
}
signed main(){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &T);
	for (int i = 1; i <= n; i++) fa[i] = i;
	if(T == 0)
		for (int i = 1, u, v, d; i <= m; i++)
			scanf("%lld%lld%lld", &u, &v, &d), add(u, v, d);
	else{
		int u, v, d, a, b;
		scanf("%lld%lld%lld%lld%lld", &u, &v, &d, &a, &b);
		for (int i = 1; i <= m; i++)
			add(u = ((a * u) ^ b) % n + 1, v = ((b * v) ^ a) % n + 1, d = ((a * d) ^ (b * d)) % mod);
	}
	for (int i = 1; i <= n; i++) res[find(i)] += std::max(out[i] - in[i], 0ll);
	for (int i = 1; i <= n; i++) {
		if(find(i) == i){
			if(res[i]) ans += res[i];
			else ans += av[i];
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}