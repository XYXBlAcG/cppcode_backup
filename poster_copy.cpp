#include <bits/stdc++.h>
typedef long long LL;
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define N 40005
int n, u[N];
inline void cmx(LL &x,LL y){if(x < y)x = y;}
struct node{
	LL a[4][4]; int len;
	node(){memset(a, 0xcf, sizeof(a));}
	node operator+(node o){
		node cur; cur.len = len + o.len;
		rep(l, 0, 3)rep(r, 0, 3)rep(p, 0, 3)rep(q, 0, 3 - p){
			int x = l + (l == len) * q, y = r + (r == o.len) * p;
			if(x <= 3 && y <= 3)cmx(cur.a[x][y], a[l][p] + o.a[q][r]);
		}
		return cur;
	}
};
struct Node{
	int l, r; node sum;
}a[N << 2];
#define L a[x].l
#define R a[x].r
#define ls (x << 1)
#define rs (ls | 1)
#define S a[x].sum
void build(int x,int l,int r){
	L = l, R = r;
	if(l == r){
		S.len = 1;
		S.a[0][0] = 0, S.a[1][1] = u[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	S = a[ls].sum + a[rs].sum;
}
void ins(int x,int pos,int val){
	if(L == R)S.a[1][1] = val;
	else{
		int mid = (L + R) >> 1;
		if(mid >= pos)ins(ls, pos, val);
		else ins(rs, pos, val);
		S = a[ls].sum + a[rs].sum;
	}
}
int main(){
	scanf("%d", &n);
	rep(i, 1, n)scanf("%d", &u[i]);
	auto out = [](){
		LL ans = 0;
		rep(l, 0, 3)rep(r, 0, 3 - l)cmx(ans, a[1].sum.a[l][r]);
		printf("%lld\n", ans);
	};
	int q;scanf("%d", &q);
	build(1, 1, n), out();
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		ins(1, x, y), out();
	}
	return 0;
}
