#include <bits/stdc++.h>
#define N 100005
#define M 1000005
#define ad(x) (((x - 1) ^ 1) + 1)

typedef unsigned long long ull;

struct edge {
	int u, v; ull w;
	edge (int u0 = 0, int v0 = 0, ull w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int V, E, Es;
int n, q, con_cnt = 0;
int p[N], first[N], next[M];
ull weight[N];
ull lb[70];

inline ull Rand() {return (ull)rand() << 31 | rand();}

bool insert(ull x) {
	for (int i = 63; i >= 0; --i)
		if (x >> i & 1) {
			if (lb[i]) x ^= lb[i];
			else return lb[i] = x, true;
		}
	return false;
}

inline void addedge(int u, int v){
	e[++Es] = edge(u, v); next[Es] = first[u]; first[u] = Es;
	e[++Es] = edge(v, u); next[Es] = first[v]; first[v] = Es;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (!p[y = e[i].v])
			p[y] = x, e[ad(i)].w = e[i].w = (ull)-1, dfs(y);
}

void dfs2(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (p[y = e[i].v] == x)
			dfs2(y), weight[x] ^= weight[y], e[ad(i)].w = e[i].w = weight[y];
}

int main() {
	int i, u, v; ull w; bool connected;
	char *_ptr = new char;
	srand(time(NULL) + (ull)_ptr); delete _ptr;
	scanf("%d%d", &V, &E);
	for (i = 1; i <= E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	p[1] = -1; dfs(1);
	for (i = 1; i <= Es; i += 2)
		if (~e[i].w) { // not tree edge
			e[i].w = e[ad(i)].w = w = Rand();
			weight[e[i].u] ^= w; weight[e[i].v] ^= w;
		}
	dfs2(1);
	for (scanf("%d", &q); q; --q) {
		connected = true; memset(lb, 0, sizeof lb);
		for (scanf("%d", &n); n; --n) {
			scanf("%d", &i); i ^= con_cnt;
			connected = connected && insert(e[i * 2].w);
		}
		puts(connected ? "Connected" : "Disconnected");
		con_cnt += connected;
	}
	return 0;
}
