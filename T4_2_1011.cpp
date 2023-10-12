#include <cstdio>
#include <algorithm>
#include <cmath>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define INF 0x3f3f3f3f
const int N = 4e6 + 5;
typedef long long ll;
ll n, k, a[N], ans;
struct Node{
	ll tag, mn;
}node[N];

struct Tree{
	inline void pushdown(int u){
		if(!node[u].tag) return;
		node[ls(u)].tag += node[u].tag;
		node[rs(u)].tag += node[u].tag;
		node[ls(u)].mn -= node[u].tag;
		node[rs(u)].mn -= node[u].tag;
		node[u].tag = 0;
	}
	inline void pushup(int u){
		node[u].mn = std::min(node[ls(u)].mn, node[rs(u)].mn);
	}
	inline void build(int u, int l, int r){
		if(l > r) return;
		if(l == r){
			node[u] = {0, a[l]};
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		build(ls(u), l, mid);
		build(rs(u), mid + 1, r);
		pushup(u);
	}
	inline void modify(int u, int l, int r, int val, int ql, int qr){
		if(l > qr || r < ql) return;
		if(ql <= l && r <= qr) {
			node[u].tag += val;
			node[u].mn -= val;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		modify(ls(u), l, mid, val, ql, qr);
		modify(rs(u), mid + 1, r, val, ql, qr);
		pushup(u);
	}
	inline int query(int u, int l, int r, int ql, int qr){
		if(l > qr || r < ql) return INF;
		if(ql <= l && r <= qr){
			return node[u].mn;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		int ll = query(ls(u), l, mid, ql, qr), \
		rr = query(rs(u), mid + 1, r, ql, qr);
		pushup(u);
		return std::min(ll, rr);
	}
}tree;

int main(){
	freopen("zero.in", "r", stdin);
	freopen("zero.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	tree.build(1, 1, n);
	int l = 1, r = k;
	for (; l <= n && r <= n; l++, r++){
		ll mn = tree.query(1, 1, n, l, r);
		if(mn != 0) ans += mn, tree.modify(1, 1, n, mn, l, r);
	}
	for (int i = 1; i <= n; i++){
		ll mn = tree.query(1, 1, n, i, i);
		if(mn != 0) ans += mn;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
