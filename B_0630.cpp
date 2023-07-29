#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 1e2 + 5, M = 1e3 + 5;
int head[M], pedge;
struct Edge{
	int v, nxt, w;
}edge[M];
void add_edge(int u, int v, int w){
	edge[++pedge] = (Edge){v, head[u], w};
	head[u] = pedge;
}
struct Node2{
	int vv, ww;
}heap[M]; int pheap = 0;
void ruin(int id){
	edge[id * 2].w = INF;
	edge[id * 2 - 1].w = INF;
}
int n, m, a, b, c, k, op, dis[N], create = 0, cnt, vis[N];
bool cmp(Node2 a, Node2 b){
	return a.ww > b.ww;
}
void dj(int s){
	dis[s] = 0;
	heap[++pheap] = (Node2){s, 0};
	while(pheap){
		int u = heap[1].vv, w = heap[1].ww;
		std::pop_heap(heap + 1, heap + 1 + pheap--, cmp);
        if(vis[u])  continue; vis[u] = 1;
		for (int i = head[u]; i; i = edge[i].nxt){
//			printf("i = %d\n", i);
			if(dis[i] > dis[u] + w){
				dis[i] = dis[u] + w;
				heap[++pheap] = (Node2){i, dis[i]};
				std::push_heap(heap + 1, heap + 1 + pheap, cmp);
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m); 
//	memset(dis, INF, sizeof(dis));
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++){
		scanf("%d", &op);
		if(op == 1){
			int ta, tb;
			scanf("%d%d", &ta, &tb);
			memset(dis, INF, sizeof(dis));
			dj(ta);
//			for (int j = 1; j <= n; j++) printf("%d ", dis[j]); printf("\n");
			printf("%d\n", (dis[tb] >= INF ? -1 : dis[tb]));
		}else if(op == 2){
			int x;
			scanf("%d", &x);
			if(!create) ruin(x);
		}else if(op == 3){
			int ta, tb, tc;
			scanf("%d%d%d", &ta, &tb, &tc);
			if(!create){
				add_edge(ta, tb, tc);
				add_edge(tb, ta, tc);
				create = (pedge >> 1);
			}
		}else if(op == 4){
			if(create){
				ruin(create);
				create = 0;
			}
		}
	}
	return 0;
} 
