#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf (1 << 30)
#define rep(i, s, t) for(int i = s; i <= t; ++ i)
#define maxn 200005
int n, m, a[maxn], L[maxn * 32], R[maxn * 32], ch[2][maxn * 32], rt, cnt;
void insert(int&k, int id, int dep) {
	if(!k) k = ++ cnt;
	if(!L[k]) L[k] = id; R[k] = id;
	if(dep == -1) return;
	insert(ch[(a[id] >> dep) & 1][k], id, dep - 1);
}
int query(int k, int x, int dep) {
	if(dep == -1) return 0;
	int v = (x >> dep) & 1;
	if(ch[v][k]) return query(ch[v][k], x, dep - 1);
	return query(ch[v ^ 1][k], x, dep - 1) + (1 << dep);
}
int dfs(int k, int dep) {
	if(dep == -1) return 0;
	if(ch[0][k] && ch[1][k]) {
		int ans = inf;
		rep(i, L[ch[0][k]], R[ch[0][k]]) {
			ans = min(ans, query(ch[1][k], a[i], dep - 1) + (1 << dep));
		}
		return dfs(ch[0][k], dep - 1) + dfs(ch[1][k], dep - 1) + ans;
	}
	else if(ch[0][k]) return dfs(ch[0][k], dep - 1);
	else if(ch[1][k]) return dfs(ch[1][k], dep - 1);
	return 0;
}
signed main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	rep(i, 1, n) insert(rt, i, 30);
	printf("%lld\n", dfs(rt, 30));
	return 0;
}
