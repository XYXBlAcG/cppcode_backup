/*

p_b_p_b txdy
AThousandSuns txdy
Wu_Ren txdy
Appleblue17 txdy

*/

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define scd second
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 1000100;
const int N = 1000000;

int n, m, a[maxn], b[maxn], head[maxn], len;
bool vis[maxn];

pii ans[maxn];
struct edge {
	int to, next;
} edges[maxn];

void add_edge(int u, int v) {
	edges[++len].to = v;
	edges[len].next = head[u];
	head[u] = len;
}

void dfs(int u) {
	for (int i = head[u]; i; i = edges[i].next) {
		int v = edges[i].to;
		ans[v] = (ans[u].fst ? ans[u] : make_pair(0, -ans[u].scd));
		dfs(v);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
	}
	int l = 1, r = N, add = 0;
	for (int i = 1; i <= m && l <= r; ++i) {
		add += (l + add > 0 ? -b[i] : b[i]);
		int mid = -add;
		if (!(l <= mid && mid <= r)) {
			continue;
		}
		ans[mid] = make_pair(1, i);
		if (mid - l < r - mid) {
			for (int j = l; j < mid; ++j) {
				add_edge(mid * 2 - j, j);
				vis[j] = 1;
			}
			l = mid + 1;
		} else {
			for (int j = mid + 1; j <= r; ++j) {
				add_edge(mid * 2 - j, j);
				vis[j] = 1;
			}
			r = mid - 1;
		}
	}
	for (int i = l; i <= r; ++i) {
		ans[i] = make_pair(0, i + add);
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (ans[a[i]].fst) {
			printf("Yes %d\n", ans[a[i]].scd);
		} else {
			printf("No %d\n", ans[a[i]].scd);
		}
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
