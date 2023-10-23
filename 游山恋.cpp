#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 3e5 + 5;
int n, m;
bool vis[N];
ll val, dis[N];
struct Node{
	int v;
	ll w;
};
std::vector<Node> st[N];
bool cmp(Node a, Node b){
	return a.w > b.w;
}
template <typename T>
struct Heap{
	T data[N];
	int pdata;
	void push(T x){
		data[++pdata] = x;
		std::push_heap(data + 1, data + 1 + pdata, cmp);
	}
	T top(){
		return data[1];
	}
	void pop(){
		std::pop_heap(data + 1, data + 1 + pdata--, cmp);
	}
	int size(){
		return pdata;
	}
};
Heap<Node> heap;
// std::queue<int> que;
// void bfs(int u){
//     que.push();
// }
void dj(int s){
	memset(dis, INF, sizeof(dis));
	dis[s] = 0;
	heap.push({s, 0});
	while(heap.size()){
		auto u = heap.top(); heap.pop();
        if(vis[u.v]) continue;
		vis[u.v] = 1;
		for (auto v : st[u.v]){
//			printf("%d -> %d\n", u.v, v.v);
			if(dis[v.v] > dis[u.v] + v.w){
				dis[v.v] = dis[u.v] + v.w;
//				printf("dis[%d] = %lld\n", v, dis[v]);
				heap.push({v.v, dis[v.v]});
			}
		}
	}
}
int main(){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u = 0, v = 0;
		ll w = 0;
		scanf("%d%d%lld", &u, &v, &w);
		// val = w;
		st[u].push_back({v, w});
		// st[v].push_back({u, w});
	}
	dj(1);
	printf("%lld\n", dis[n]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
