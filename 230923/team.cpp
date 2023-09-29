#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#define INF 0x3f3f3f3f
#define EPS 1e-5
const int N = 2505;
typedef double d;
std::vector<int> st[N];
int k, n, p[N], r[N], si[N];
d now[N], f[N][N];
void dfs(int u, int fa){
	si[u] = 1;
	f[u][0] = 0, f[u][1] = now[u];
	for (auto v : st[u]){
		if(v != fa){
			dfs(v, u);
			si[u] += si[v];
			for (int i = si[u] - si[v]; i; i--){
				for (int j = 0; j <= si[v]; j++){
					f[u][i + j] = std::max(f[u][i + j], f[u][i] + f[v][j]);
				}
			}
		}
	}
} 
bool chk(d x){
	now[0] = 0;
	for (int i = 1; i <= n; i++) now[i] = (d)p[i] - x * (d)r[i];
//	memset(si, 0, sizeof(si));
	memset(f, -INF, sizeof(f));
	dfs(0, -1);
	return f[0][k + 1] >= 0;
}
int main(){
	scanf("%d%d", &k, &n);
	for (int i = 1, v; i <= n; i++){
		scanf("%d%d%d", r + i, p + i, &v);
		st[v].push_back(i);
	}
	d l = 0, r = 100000;
	while(l < r - EPS){
		d mid = (l + r) * 0.5;
		if(chk(mid)) l = mid;
		else r = mid;
	}
	printf("%.3lf\n", l);
	
	return 0;
}
