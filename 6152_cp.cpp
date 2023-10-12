#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re 
#define int long long
#define inf 1000000000 
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define rep(i, s, t) for(re int i = s; i <= t; ++ i)
#define lb(x) (x)&(-(x))
#define maxn 300005
int n, m, ans[maxn], tr[maxn * 2], T;
struct ques {
	int l, r, a, id;
}e[maxn];
struct node {
	int ned, id;
}p[maxn], p1[maxn], p2[maxn];
vector<int> q[maxn];
il void add(int x, int v) {
	for(re int i = x; i <= 2 * m; i += lb(i)) tr[i] += v;
}
il int query(int x) {
	int ans = 0;
	for(re int i = x; i; i -= lb(i)) ans += tr[i];
	return ans;
}
il int Query(int x) {
	int ans = 0;
	for(re int i = 0; i < (int)q[p[x].id].size(); ++ i) {
		ans += query(q[p[x].id][i]) + query(q[p[x].id][i] + m);
		if(ans >= p[x].ned) return ans;
	}
    printf("ans = %lld\n", ans);
	return ans;
}
il void solve(int l, int r, int L, int R) {
	if(L > R) return;
	if(l == r) {
		rep(i, L, R) ans[p[i].id] = l;
		return;
	}
    printf("%lld %lld %lld %lld\n", l, r, L, R);
	int mid = (l + r) >> 1, cnt1 = 0, cnt2 = 0;
	rep(i, l, mid) add(e[i].l, e[i].a), add(e[i].r + 1, -e[i].a);
	rep(i, L, R) {
		int temp = Query(i);
		if(temp >= p[i].ned) p1[++ cnt1] = p[i];
		else p[i].ned -= temp, p2[++ cnt2] = p[i];
	}
	rep(i, l, mid) add(e[i].l, -e[i].a), add(e[i].r + 1, e[i].a);
	rep(i, L, L + cnt1 - 1) p[i] = p1[i - L + 1];
	rep(i, L + cnt1, R) p[i] = p2[i - L - cnt1 + 1];
	solve(l, mid, L, L + cnt1 - 1), solve(mid + 1, r, L + cnt1, R);
}
signed main() {
	n = read(), m = read();
	rep(i, 1, m) q[read()].push_back(i);
	rep(i, 1, n) p[i].ned = read(), p[i].id = i;
	T = read();
	rep(i, 1, T) {
		e[i].l = read(), e[i].r = read(), e[i].a = read(), e[i].id = i;
		if(e[i].r < e[i].l) e[i].r += m;
	}
	++ T, e[T].id = T, e[T].l = 1, e[T].r = 2 * m, e[T].a = inf;
	solve(1, T, 1, n);
	rep(i, 1, n) ans[i] == T ? puts("NIE") : printf("%lld\n", ans[i]);
	return 0;
}
