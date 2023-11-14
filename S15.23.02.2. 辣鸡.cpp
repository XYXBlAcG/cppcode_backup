#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
const int N = 1e6 + 5, M = 2e5 + 5;
int A, B, n, m, pedge;
long long a[M], b[M];
struct Edge{
	int u, v;
    long long w;
}edge[N];
struct Pos{
	int x, y;
};
struct UFS{
	int fa[N];
	void init(){
		for (int i = 1; i <= 4e6; i++) fa[i] = i;
	}
	int find(int x){
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	void merge(int x, int y){
		x = find(x), y = find(y);
		fa[x] = y;
	}
}ufs;
int get(int x, int y){
	return x * (m + 2) + y;
}
bool chk(int x, int y){
	return x >= 1 && x <= n + 1 && y >= 1 && y <= m + 1;
}
void addedge(int u, int v, long long w){
	edge[++pedge] = (Edge){u, v, w};
}
bool cmp2(Edge a, Edge b){
	return a.w < b.w;
}
void build(){
	for (int i = 1; i <= n + 1; i++){
		for (int j = 1; j <= m + 1; j++){
			for (int k = 0; k < 4; k++){
				int tx = i + "1102"[k] - '1', ty = j + "0211"[k] - '1';
				if(chk(tx, ty)){
//					printf("{%d, %d} <-> {%d, %d}, ", i, j, tx, ty);
					if(tx != i) {
						if(tx == i + 1) addedge(get(i, j), get(tx, ty), b[j]);// printf("%d\n", b[j]);
						else addedge(get(i, j), get(tx, ty), b[ty]);// printf("%d\n", b[ty]);
					}else {
						if(ty == j + 1) addedge(get(i, j), get(tx, ty), a[i]);// printf("%d\n", a[i]);
						else addedge(get(i, j), get(tx, ty), a[tx]);// printf("%d\n", a[tx]);
					}
				}
			}
		}
	}
}
long long solve(){
	long long ans = 0;
	std::sort(edge + 1, edge + 1 + pedge, cmp2);
	ufs.init();
	for (int i = 1; i <= pedge; i++){
		Edge tmp = edge[i];
		if(ufs.same(tmp.u, tmp.v)) continue;
		ufs.merge(tmp.u, tmp.v);
//		printf("merge {%d, %d} <-> {%d, %d}, with val %d\n", tmp.x1, tmp.y1, tmp.x2, tmp.y2, tmp.w);
		ans += tmp.w;
	}
	return ans;
}
int main(){
    #ifdef ONLINE_JUDGE
	freopen("chicken.in", "r", stdin);
	freopen("chicken.out", "w", stdout);
    #endif
	
	scanf("%d%d%d%d", &A, &B, &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	std::sort(a + 1, a + 1 + n);
	a[n + 1] = A;
	for (int i = n + 1; i; i--)
		a[i] -= a[i - 1];
	for (int i = 1; i <= m; i++)
		scanf("%lld", b + i);
	std::sort(b + 1, b + 1 + m);
	b[m + 1] = B;
	for (int i = m + 1; i; i--)
		b[i] -= b[i - 1];
	build();
	printf("%lld\n", solve());
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
