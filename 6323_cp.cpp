#include <bits/stdc++.h>
using namespace std;
#define N 1000010
struct Edge{
	int to, last;
}edge[N * 12];
int head[N << 2], tot, low[N << 2], dfn[N << 2];
int vis[N << 2], st[N << 2], top, sze, num;
int p[N];
int belng[N << 2], n, m, k, a, b;
void add(int u, int v) {
	edge[++tot] = (Edge){v, head[u]};
	head[u] = tot;
}
void tarjan(int u) {
	low[u] = dfn[u] = ++num;
	vis[u] = 1;
	st[++top] = u;
	for(int i = head[u]; i; i = edge[i].last) {
		int v = edge[i].to;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		++sze;
		while(st[top] != u) {
			belng[st[top]] = sze;
			vis[st[top]] = 0;
			top--;
		}
		belng[st[top]] = sze;
		vis[st[top]] = 0;
		top--;
	}
}
int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		add(a + n, b);
		add(b + n, a);
	}
	for(int i = 1; i <= k; i++) {
		int w;
		scanf("%d", &w);
		for(int j = 1; j <= w; j++) {
			scanf("%d", &p[j]);
			add(p[j] + 2 * n, p[j] + n);
			add(p[j] + 3 * n, p[j] + n);
		}
		for(int j = 1; j < w; j++) {
			add(p[j + 1] + 2 * n, p[j] + 2 * n);
			add(p[j] + 3 * n, p[j + 1] + 3 * n);
			add(p[j], p[j + 1] + 3 * n);
			add(p[j + 1], p[j] + 2 * n);
		}
	}
	for(int i = 1; i <= 2 * n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(belng[i] == belng[i + n]) {
			printf("NIE\n");
			return 0;
		}
	}
	printf("TAK\n");
	return 0;
}
