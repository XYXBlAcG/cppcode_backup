#include <cstdio>
#include <algorithm> 
#include <cmath>
#include <vector>
const int N = 2e5 + 5;
int id, n, deg[N], head[N], pedge = 1;
struct Edge{
	int nxt, ver, del;
}edge[N * 4];
void addedge(int u, int v){
	edge[++pedge] = {head[u], v, 0};
	head[u] = pedge;
}
struct Ans{
	int u, v;
};
std::vector<int> st[N];
namespace juhua{
	int mxid = 0;
	std::vector<int> jua;
	void main(){
		printf("%d\n", n - 3);
		for (int i = 1; i <= n; i++)
			if(st[mxid].size() < st[i].size()) mxid = i;
		for (int i = 1; i <= n; i++)
			if(i != mxid) jua.push_back(i);
		printf("%d %d %d %d\n", mxid, jua.back() - 1, jua[0], jua[1]);
		for (int i = 1; i < (int)jua.size() - 2; i++){
			printf("%d %d %d %d\n", mxid, jua[i], jua[i], jua[i + 1]);	
		}
	}
}
std::vector<int> d1, d3, d0;
std::vector<Ans> del, add;
namespace tc12{
	void main(){
		for (int i = 1; i <= n; i++){
			deg[i] = st[i].size();
			if(deg[i] > 2){
				d3.push_back(i);
			}
		}
		for (auto u : d3){
			int flgr = 0, flg = 0;
			for (auto v : st[u]){
				if(deg[v] == 2) flgr++;
			}
			if(flgr != (int)st[u].size()) flg = 1;
			for (auto v : st[u]){
				if(flg && deg[v] >= 2) continue;
				if(deg[v] == 0) continue;
//				printf("deg %d -> deg %d = {%d, %d}, split!\n", u, v, deg[u], deg[v]);
				deg[u]--, deg[v]--;
				del.push_back({u, v});
				if(deg[u] <= 2) break;
			}
		}
		for (int i = 1; i <= n; i++){
			if(deg[i] == 0) d0.push_back(i); 
			else if(deg[i] == 1) d1.push_back(i);
		}
		for (int i = 0; i < (int)d0.size(); i++){
			add.push_back({d0[i], d1[i]});
		}
		printf("%d\n", (int)add.size());
		for (int i = 0; i < (int)add.size(); i++){
			printf("%d %d %d %d\n", del[i].u, del[i].v, add[i].u, add[i].v);
		}
	}
}
int main(){
	// freopen("lct.in", "r", stdin);
	// freopen("lct.out", "w", stdout);
	
	scanf("%d%d", &id, &n);
	for (int i = 1, u, v; i < n; i++){
		scanf("%d%d", &u, &v);
		st[u].push_back(v);
		st[v].push_back(u);
	}
	if(id == 3 || id == 10){
		juhua::main();
	}else if(id == 1){
		tc12::main();
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
