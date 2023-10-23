#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <random>
const int N = 23, mod = 998244353; 
std::mt19937 rnd(114514);
int n, m, q, d[N], can[N];
int edge[N][N], vis[N][N], fires;
std::vector<int> poi, st[N];
struct Edge{
	int u, v;
};
std::vector<Edge> eg, edge2;
std::string S = "";
void cal(){
	memset(d, 0, sizeof(d));
//	printf("so far %d edges.\n", (int)edge2.size());
	for (auto v : edge2){
//		printf("%d -> %d\n", v.u, v.v);
		d[v.u]++;
		d[v.v]++;
	}
	
//	for (auto v : edge2){
//		if(d[v.u] < 2 || d[v.v] < 2) return;
//	}
	for (int i = 0; i < n; i++){
		if(S[i] == '1') {
			if(d[i + 1] < 2) return;
		}
	}
	if((int)edge2.size() == 0) return;
	fires++;
//	printf("ans = %d\n", fires);
}
void add(int cur, int num, int top){
	if(cur == top + 1) {
		cal();
		return;
	}
	add(cur + 1, num, top);
	edge2.push_back(eg[cur - 1]);
	add(cur + 1, num + 1, top);
	edge2.pop_back();
}
int query(){
	poi.clear();
	memset(vis, 0, sizeof(vis));
	memset(can, 0, sizeof(can));
	eg.clear();
	for (int i = 0; i < n; i++)
		if(S[i] == '1') poi.push_back(i + 1), can[i + 1] = 1;
	int size = 0;
	for (auto a : poi){
		for (auto v : st[a]){
			if(!can[v]) continue;
			if(!vis[a][v]) {
				eg.push_back({a, v});
				vis[a][v] = vis[v][a] = 1;
				size++;
			}
		}
	}
//	puts("availble points:");
//	for (auto v : poi){
//		printf("v = %d\n", v);
//	}
//	puts("avaliable edges:");
//	for (auto v : eg){
//		printf("%d -> %d\n", v.u, v.v);
//	}
	fires = 0;
	edge2.clear();
	add(1, 0, eg.size());
//	for (int i = (int)poi.size(); i <= (int)eg.size(); i++){
//		edge2.clear();
//		add(1, 0, i);
//	}
	return fires;
}
int main(){
	freopen("big.in", "r", stdin);
	freopen("big.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u = 0, v = 0;
		scanf("%d%d", &u, &v);
		edge[u][v] = edge[v][u] = 1;
		st[u].push_back(v);
		st[v].push_back(u);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		S = "";
		std::cin >> S;
		int res = query();
		printf("%d\n", (res + mod) % mod);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
