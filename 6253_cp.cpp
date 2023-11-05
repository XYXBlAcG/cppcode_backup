#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	char c = getchar();
	int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

const int N = 100005, M = 500005;

// struct Edge {
// 	int to, nxt;
// 	Edge() {
// 		nxt = -1;
// 	}
// };
// Edge e[N << 1];
std::vector<int> st[N];
int n, hd[N], pnt, m, pos[N], qcnt, dfn[N], dep[N], post[N], a[N], b[N], S, fa[N][25], _time, cnt1[N], cnt2[N], atmp[N];
bool isquery[M];
long long ans[M], pref[N], curval; // pref[i] = f(1, i, 1, n)
struct Query {
	int l, r, id;
	Query(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
	bool operator < (const Query& b) const {
		return (pos[l] ^ pos[b.l] ? pos[l] < pos[b.l] : (pos[l] & 1 ? r < b.r : r > b.r));
	}
};
Query qry[M << 2];

inline void AddEdge(int u, int v) {
	// e[++pnt].to = v;
	// e[pnt].nxt = hd[u];
	// hd[u] = pnt;
    st[u].push_back(v), st[v].push_back(u);
}

inline void Read() {
	n = qread(); m = qread();
	for (int i = 1;i <= n;i++) b[i] = a[i] = qread();
	for (int i = 1;i < n;i++) {
		int u = qread(), v = qread();
		AddEdge(u, v);
	}
}

inline void Dfs(int u, int fath) {
	dfn[u] = ++_time;
	atmp[_time] = a[u];
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : st[u]) {
		if (v != fath) {
			Dfs(v, u);
		}
	}
	post[u] = _time;
}

inline int Up(int u, int k) {
	for (int j = 19;j >= 0;j--) {
		if ((k >> j) & 1) u = fa[u][j];
	}
	return u;
}

inline void AddQuery(int l, int r, int i) {
    // printf("org l, r = %d %d %d %d\n", std::abs(i), l, r, (i >= 0) ? 1 : -1);
	if (l < 1 || l > n) return;
	if (r < 1 || r > n) return;
	if (l > r) swap(l, r);
    // printf("l = %d, r = %d\n", l, r);
    // printf("l, r = %d %d %d %d\n", std::abs(i), l, r, (i >= 0) ? 1 : -1);
	qry[++qcnt] = Query(l, r, i);
}

inline void Prefix() {
    // for (int i = 1; i <= n; i++) printf("dfn %d -> %d\n", i, dfn[i]);
	sort(b + 1, b + n + 1);
	int vtop = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1;i <= n;i++) a[i] = lower_bound(b + 1, b + vtop + 1, a[i]) - b;
	// for (int j = 1;j <= 20;j++) {
	// 	for (int i = 1;i <= n;i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	// }
    // for (int i = 1; i <= n; i++) printf("%d -> %d\n", i, dfn[i]);
	for (int i = 1;i <= n;i++) cnt1[a[i]]++;
	for (int i = 1;i <= n;i++) pref[i] = pref[i - 1] + cnt1[a[i]];
    // for (int i = 1; i <= n; i++) printf("cnt %d -> %lld\n", i, pref[i]);
	int rt = 1;
	for (int i = 1;i <= m;i++) {
		int opt = qread();
		if (opt == 1) rt = qread();
		else {
			isquery[i] = 1;
			int u = qread(), v = qread(), type = 0;
			if (dfn[u] <= dfn[rt] && dfn[rt] <= post[u]) type |= 2;
			if (dfn[v] <= dfn[rt] && dfn[rt] <= post[v]) type |= 1;
			//printf("T=%d\n", type);
			if (type == 0) {
				int l1 = dfn[u], r1 = post[u], l2 = dfn[v], r2 = post[v];
				// printf("0 %d %d %d %d\n", l1, r1, l2, r2);
				AddQuery(r1, r2, i);
				AddQuery(l1 - 1, r2, -i);
				AddQuery(r1, l2 - 1, -i);
				AddQuery(l1 - 1, l2 - 1, i);
			} else if (type == 1) {
				int l1, r1, l2, r2;
				l1 = dfn[u]; r1 = post[u];
				if (v != rt) {
                    
					int sv = Up(rt, dep[rt] - dep[v] - 1);
                    // printf("%d -> %d\n", v, sv);
					l2 = dfn[sv] - 1; r2 = post[sv] + 1;
				} else {
					l2 = 0;
					r2 = 1;
				}
				/*
				  f(l1, r1, 1, l2) + f(l1, r1, r2, n)
				= f(1, r1, 1, l2) - f(1, l1 - 1, 1, l2) + f(l1, r1, 1, n) - f(l1, r1, 1, r2 - 1)
				= f(1, r1, 1, l2) - f(1, l1 - 1, 1, l2) + fpre(r1) - fpre(l1 - 1) - f(1, r1, 1, r2 - 1) + f(1, l1 - 1, 1, r2 - 1)
				*/
                // printf("a = 1 %d %d %d\n", u, v, rt);
                // printf("l r = %d %d %d %d\n", l1, r1, l2, r2);
				ans[i] += pref[r1] - pref[l1 - 1];
                // printf("ans i = %lld\n", ans[i]);
				AddQuery(r1, l2, i);
				AddQuery(l1 - 1, l2, -i);
				AddQuery(r1, r2 - 1, -i);
				AddQuery(l1 - 1, r2 - 1, i);
			} else if (type == 2) {
				swap(u, v);
				int l1, r1, l2, r2;
				l1 = dfn[u]; r1 = post[u];
				if (v != rt) {
					int sv = Up(rt, dep[rt] - dep[v] - 1);
					l2 = dfn[sv] - 1; r2 = post[sv] + 1;
				} else {
					l2 = 0;
					r2 = 1;
				}
                // printf("a = 2 %d %d %d\n", u, v, rt);
                // printf("l r = %d %d %d %d\n", l1, r1, l2, r2);
				ans[i] += pref[r1] - pref[l1 - 1];
                // printf("ans i = %lld\n", ans[i]);
				AddQuery(r1, l2, i);
				AddQuery(l1 - 1, l2, -i);
				AddQuery(r1, r2 - 1, -i);
				AddQuery(l1 - 1, r2 - 1, i);
			} else if (type == 3) {
				int l1, r1, l2, r2;
				if (u != rt) {
					int su = Up(rt, dep[rt] - dep[u] - 1);
					l1 = dfn[su] - 1; r1 = post[su] + 1;
				} else {
					l1 = 0;
					r1 = 1;
				}
				if (v != rt) {
					int sv = Up(rt, dep[rt] - dep[v] - 1);
					l2 = dfn[sv] - 1; r2 = post[sv] + 1;
				} else {
					l2 = 0;
					r2 = 1;
				}
                // printf("a = 3 %d %d %d\n", u, v, rt);
				ans[i] += pref[l1] + pref[l2] + pref[n] - pref[r1 - 1] - pref[r2 - 1];
				AddQuery(l1, r2 - 1, -i);
				AddQuery(l1, l2, i);
				AddQuery(l2, r1 - 1, -i);
				AddQuery(r1 - 1, r2 - 1, i);
			}
		}
	}
}

inline void Addl(int x) {curval += cnt2[x]; cnt1[x]++;}
inline void Dell(int x) {curval -= cnt2[x]; cnt1[x]--;}
inline void Addr(int x) {curval += cnt1[x]; cnt2[x]++;}
inline void Delr(int x) {curval -= cnt1[x]; cnt2[x]--;}

inline void Solve() {
	//for (int i = 1;i <= n;i++) printf("%d ", a[i]);
	//puts("");
	S = (int)(1.0 * n / sqrt(qcnt));
	for (int i = 1;i <= n;i++) pos[i] = (i - 1) / S + 1;
	sort(qry, qry + qcnt + 1);
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	int lp = 0, rp = 0;
	for (int i = 1;i <= qcnt;i++) {
		// printf("q = %d %d %d %d\n", i, qry[i].l, qry[i].r, qry[i].id);
		while (lp < qry[i].l) Addl(a[++lp]);
		while (rp < qry[i].r) Addr(a[++rp]);
		while (lp > qry[i].l) Dell(a[lp--]);
		while (rp > qry[i].r) Delr(a[rp--]);
        // printf("res = %lld\n", curval);
		if (qry[i].id > 0) ans[qry[i].id] += curval;
		else ans[-qry[i].id] -= curval;
	}
	for (int i = 1;i <= m;i++) {
		if (isquery[i]) printf("%lld\n", ans[i]);
	}
}

int main() {
	memset(hd, -1, sizeof(hd));
	Read();
	dep[1] = 1; Dfs(1, 0); memcpy(a, atmp, sizeof(a));
	Prefix();
    // return 0;
	Solve();
	return 0;
}
