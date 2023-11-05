#include<bits/stdc++.h>
using namespace std;
#define POINT(X, Y)  ((X) * 31 + (Y))
const int MAXN = POINT(30, 30) + 10;
const int INF = 2000000000;
const int MAXM = MAXN * MAXN + 10;
struct Graph {
	struct Node {
		int to, cap;
		int next;
	} node[MAXM * 2];
	int top, head[MAXN];
	Graph() {
		top = 1;
	}
	void add(int u, int v, int cap) {
        printf("%d %d %d\n", u, v, cap);
		top ++;
		node[top].to = v;
		node[top].cap = cap;
		node[top].next = head[u];
		head[u] = top;
		top ++;
		node[top].to = u;
		node[top].cap = 0;
		node[top].next = head[v];
		head[v] = top;
	}
	queue<int> Q;
	int dis[MAXN];
	int s, t;
	bool bfs() {
		memset(dis, -1, sizeof(dis));
		dis[s] = 0;
		Q.push(s);
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for(int i = head[u]; i; i = node[i].next) {
				int v = node[i].to;
				if(dis[v] == -1 && node[i].cap) {
					dis[v] = dis[u] + 1;
					Q.push(v);
				}
			}
		}
		return dis[t] != -1;
	}
	int dfs(int u, int flow) {
		if(u == t)
			return flow;
		else {
			int ret = flow;
			for(int i = head[u]; i && ret; i = node[i].next) {
				int v = node[i].to;
				if(dis[v] == dis[u] + 1 && node[i].cap) {
					int k = dfs(v, min(ret, node[i].cap));
					node[i].cap -= k;
					node[i ^ 1].cap += k;
					ret -= k;
				}
			}
			if(ret == flow)
				dis[u] = -1;
			return flow - ret;
		}
	}
	int dinic() {
		int ans = 0;
		while(bfs())
			ans += dfs(s, INF);
		return ans;
	}
} G;
int n, m;
int score[MAXN];
vector<int> out[MAXN];
int in[MAXN];
bool vis[MAXN];
queue<int> Q;
void toposort() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(!in[POINT(i, j)]) {
				Q.push(POINT(i, j));
				vis[POINT(i, j)] = true;
			}
		}
	}
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int i = 0; i < (int)out[u].size(); i ++) {
			int v = out[u][i];
			in[v] --;
			if(!vis[v] && !in[v]) {
				Q.push(v);
				vis[v] = true;
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			int cnt;  //  保护植物的棵数
			cin>>score[POINT(i, j)]>>cnt;
			for(int k = 1; k <= cnt; k ++) {
				int x, y;
				cin>>x>>y;
				//  POINT(i, j) <- POINT(x, y)
				x ++;
				y ++;
				out[POINT(i, j)].push_back(POINT(x, y));
				in[POINT(x, y)] ++;
			}
			if(j < m) {
				out[POINT(i, j + 1)].push_back(POINT(i, j));
				in[POINT(i, j)] ++;
			}
		}
	}
	toposort();
	G.s = MAXN - 1;
	G.t = MAXN - 2;
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			int u = POINT(i, j);
			if(!vis[u])
				continue;
			if(score[u] >= 0) {
				G.add(G.s, u, score[u]);
				sum += score[u];
				// printf("S -> [%d, %d] : %d\n", i, j, score[u]);
			}
			else {
				G.add(u, G.t, -score[u]);
				// printf("[%d, %d] -> T : %d\n", i, j, -score[u]);
			}
			for(int k = 0; k < (int)out[u].size(); k ++) {
				int v = out[u][k];
				if(vis[v]) {
					G.add(v, u, INF);
					// printf("[%d, %d] -> [%d, %d] : INF\n", v / 31, v % 31, i, j);
				}
			}
		}
	}
	cout<<sum - G.dinic()<<endl;
	return 0;
}