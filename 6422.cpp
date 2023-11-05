#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define inf 0x3f3f3f3f
const int N = 1e5 + 5;
bool used[N];
int dist[N], head[N], que[N], S, T, cnt, cur[N], n, m, ans, pedge = 1, gap[N], tim;
struct Edge{
    int next, ver, rest;
}edge[N];
typedef long long lld;
void ret(int a, std::string str){
    std::cout << str << std::endl;
}
void addedge(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void add(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
bool bfs(){
	int size = 0;
	memset(used, 0, sizeof(used));
	used[que[size = 1] = T] = true;
	for(int i = 1; i <= size; i++){
		for(int j = head[que[i]]; j; j = edge[j].next){
            tim++;
			if(--cnt == 0)
				ret(1, "Successfully blocked.");
			if(!used[edge[j].ver] && edge[j ^ 1].rest){
				dist[que[++size] = edge[j].ver] = dist[que[i]] + 1;
				used[edge[j].ver] = true;
			}
		}
	}
	if(!used[S])
		return false;
	memcpy(cur, head, sizeof(head));
	return true;
}

lld dfs(int a, lld rest){
	if(a == T)
		return rest;
	lld sum = 0;
	for(; cur[a]; cur[a] = edge[cur[a]].next){
		Edge &e = edge[cur[a]];
		if(--cnt == 0)
			ret(1, "Successfully blocked.");
		if(e.rest && dist[a] == dist[e.ver] + 1){
			int ret = dfs(e.ver, std::min(rest, lld(e.rest)));
			e.rest -= ret;
			edge[cur[a] ^ 1].rest += ret;
			sum += ret;
			rest -= ret;
			if(!rest)
				break;
		}
	}
	return sum;
}

lld solve(){
	cnt = n * m / 2;
	while(bfs())
		ans += dfs(S, (lld(inf) << 32) | inf);
	return ans;
}

// typedef long long lld;

// lld dfs(int a, lld rest){
// 	if(a == T)
// 		return rest;
// 	lld sum = 0;
// 	for(; cur[a]; cur[a] = edge[cur[a]].next){
// 		Edge &e = edge[cur[a]];
//         tim++;
// 		if(--cnt == 0)
// 			ret(1, "Successfully blocked.");
// 		if(e.rest && dist[a] == dist[e.ver] + 1){
// 			int ret = dfs(e.ver, std::min(rest, lld(e.rest)));
// 			e.rest -= ret;
// 			edge[cur[a] ^ 1].rest += ret;
// 			sum += ret;
// 			rest -= ret;
// 			if(!rest)
// 				return sum;
// 		}
// 	}
// 	if(!--gap[dist[a]])
// 		dist[S] = n + 1;
// 	gap[++dist[a]]++;
// 	cur[a] = head[a];
// 	return sum;
// }

// lld solve(){
// 	cnt = n * m / 2;
// 	gap[0] = n;
// 	while(dist[S] <= n)
// 		ans += dfs(S, (lld(inf) << 32) | inf);
// 	return ans;
// }
int main(){
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    solve();
    printf("tim = %d\n", tim);
    puts("end of this exec.");
    return 0;
}