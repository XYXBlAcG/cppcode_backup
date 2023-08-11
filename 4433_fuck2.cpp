#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
    ll f = 1, x = 0;char ch;
    do {ch = getchar();if (ch == '-')f = -1;} while (ch > '9' || ch < '0');
    do {x = x * 10 + ch - '0';ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

const int MAX_N = 2e5 + 50;

int n, m, a[MAX_N];

struct segment_tree{
	int l, r;
	int sum, tag, rev, pre[2], suf[2], dat[2];
	#define ls(p) (p << 1)
	#define rs(p) (p << 1 | 1)
}t[MAX_N << 2];

void push_up(int p){
	t[p].sum = t[ls(p)].sum + t[rs(p)].sum;
	for (int i = 0; i <= 1; i ++ ){
		t[p].pre[i] = t[ls(p)].pre[i];
		if (i == 1 && t[ls(p)].sum == (t[ls(p)].r - t[ls(p)].l + 1)) 
			t[p].pre[i] += t[rs(p)].pre[i];
		else if (i == 0 && t[ls(p)].sum == 0) 
			t[p].pre[i] += t[rs(p)].pre[i];
		
		t[p].suf[i] = t[rs(p)].suf[i];
		if (i == 1 && t[rs(p)].sum == (t[rs(p)].r - t[rs(p)].l + 1))
			t[p].suf[i] += t[ls(p)].suf[i];
		else if (i == 0 && t[rs(p)].sum == 0)
			t[p].suf[i] += t[ls(p)].suf[i];
		
		t[p].dat[i] = t[ls(p)].suf[i] + t[rs(p)].pre[i];
		t[p].dat[i] = max(t[p].dat[i], t[ls(p)].dat[i]);
		t[p].dat[i] = max(t[p].dat[i], t[rs(p)].dat[i]);
		t[p].dat[i] = max(t[p].dat[i], t[p].pre[i]);
		t[p].dat[i] = max(t[p].dat[i], t[p].suf[i]);
	}
}

void push_down(int p){
	if (t[p].tag != -1) {
		t[p].rev = 0;
		int v = t[p].tag;
		
		t[ls(p)].sum = (t[ls(p)].r - t[ls(p)].l + 1) * v;
		t[rs(p)].sum = (t[rs(p)].r - t[rs(p)].l + 1) * v;
		
		t[ls(p)].tag = t[rs(p)].tag = v;
		t[ls(p)].rev = t[rs(p)].rev = 0;
		
		t[ls(p)].pre[v] = t[ls(p)].suf[v] = t[ls(p)].dat[v] = (t[ls(p)].r - t[ls(p)].l + 1);
		t[ls(p)].pre[v ^ 1] = t[ls(p)].suf[v ^ 1] = t[ls(p)].dat[v ^ 1] = 0;
		
		t[rs(p)].pre[v] = t[rs(p)].suf[v] = t[rs(p)].dat[v] = (t[rs(p)].r - t[rs(p)].l + 1);
		t[rs(p)].pre[v ^ 1] = t[rs(p)].suf[v ^ 1] = t[rs(p)].dat[v ^ 1] = 0;
		
		t[p].tag = -1;
	}
	if (t[p].rev) {
		t[ls(p)].sum = (t[ls(p)].r - t[ls(p)].l + 1) - t[ls(p)].sum;
		t[rs(p)].sum = (t[rs(p)].r - t[rs(p)].l + 1) - t[rs(p)].sum;
		
		if (t[ls(p)].tag != -1) t[ls(p)].tag ^= 1;
		else t[ls(p)].rev ^= 1;
		if (t[rs(p)].tag != -1) t[rs(p)].tag ^= 1;
		else t[rs(p)].rev ^= 1;
		
		swap(t[ls(p)].dat[0], t[ls(p)].dat[1]);
		swap(t[ls(p)].suf[0], t[ls(p)].suf[1]);
		swap(t[ls(p)].pre[0], t[ls(p)].pre[1]);
		
		swap(t[rs(p)].dat[0], t[rs(p)].dat[1]);
		swap(t[rs(p)].suf[0], t[rs(p)].suf[1]);
		swap(t[rs(p)].pre[0], t[rs(p)].pre[1]);
		
		t[p].rev = 0;
	}
	return;
}

void build (int p, int l, int r) {
	t[p].l = l; t[p].r = r; t[p].tag = -1;
	if (l == r) {
		t[p].sum = a[l];
		t[p].pre[a[l]] = t[p].suf[a[l]] = t[p].dat[a[l]] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	push_up(p);
}

void change(int p, int l, int r, int v){
	push_down(p);
	if (l <= t[p].l && t[p].r <= r){
		if (v == 0 || v == 1){
			t[p].sum = (t[p].r - t[p].l + 1) * v;
			t[p].tag = v;
			t[p].pre[v] = t[p].suf[v] = t[p].dat[v] = (t[p].r - t[p].l + 1);
			t[p].pre[v ^ 1] = t[p].suf[v ^ 1] = t[p].dat[v ^ 1] = 0;
		} 
		else if (v == 2) {
			t[p].sum = (t[p].r - t[p].l + 1) - t[p].sum;
			t[p].rev ^= 1;
			swap(t[p].pre[0], t[p].pre[1]);
			swap(t[p].suf[0], t[p].suf[1]);
			swap(t[p].dat[0], t[p].dat[1]);
		}
		return;
	}
	
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) change(ls(p), l, r, v);
	if (r > mid) change(rs(p), l, r, v);
	push_up(p);
}
/*
void change(int p, int l, int r, int v){
	if (l <= t[p].l && t[p].r <= r){
		if (v == 0 || v == 1){
			t[p].sum = (t[p].r - t[p].l + 1) * v;
			t[p].tag = v;
			t[p].pre[v] = t[p].suf[v] = t[p].dat[v] = (t[p].r - t[p].l + 1);
			t[p].pre[v ^ 1] = t[p].suf[v ^ 1] = t[p].dat[v ^ 1] = 0;
		} 
		else if (v == 2) {
			t[p].sum = (t[p].r - t[p].l + 1) - t[p].sum;
			t[p].rev ^= 1;
			swap(t[p].pre[0], t[p].pre[1]);
			swap(t[p].suf[0], t[p].suf[1]);
			swap(t[p].dat[0], t[p].dat[1]);
		}
		return;
	}
	push_down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (mid < l) change(rs(p), l, r, v);
	else if (r <= mid) change(ls(p), l, r, v);
	else change(ls(p), l, mid, v), change(rs(p), mid + 1, r, v);
	push_up(p);
}
*/
ll query_sum(int p, int l, int r){
	if (l <= t[p].l && t[p].r <= r) 
		return t[p].sum;
	push_down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = 0;
	if (l <= mid) ans += query_sum(ls(p), l, r);
	if (r > mid) ans += query_sum(rs(p), l, r);
	return ans;
}

segment_tree query_len(int p, int l, int r){
	if (l <= t[p].l && t[p].r <= r) 
		return t[p];
	push_down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (r <= mid) return query_len(ls(p), l, r);
	if (l > mid) return query_len(rs(p), l, r);
	segment_tree t1 = query_len(ls(p), l, r), t2 = query_len(rs(p), l, r), t3;
	t3.sum = t1.sum + t2.sum;
	for (int i = 0; i <= 1; i ++ ){
		t3.pre[i] = t1.pre[i];
		if (i == 1 && t1.sum == (t1.r - t1.l + 1)) 
			t3.pre[i] += t2.pre[i];
		else if (i == 0 && t1.sum == 0) 
			t3.pre[i] += t2.pre[i];
		
		t3.suf[i] = t2.suf[i];
		if (i == 1 && t2.sum == (t2.r - t2.l + 1))
			t3.suf[i] += t1.suf[i];
		else if (i == 0 && t2.sum == 0)
			t3.suf[i] += t1.suf[i];
		
		t3.dat[i] = t1.suf[i] + t2.pre[i];
		t3.dat[i] = max(t3.dat[i], t1.dat[i]);
		t3.dat[i] = max(t3.dat[i], t2.dat[i]);
		t3.dat[i] = max(t3.dat[i], t3.pre[i]);
		t3.dat[i] = max(t3.dat[i], t3.suf[i]);
	}
	return t3;
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i ++ ) a[i] = read();
	build(1, 1, n); 
	for (int i = 1; i <= m; i ++ ){
		int opt = read(), l = read(), r = read();
		l ++ , r ++ ;
		if (opt == 0) change(1, l, r, 0);
		if (opt == 1) change(1, l, r, 1);
		if (opt == 2) change(1, l, r, 2);
		if (opt == 3) printf("%lld\n", query_sum(1, l, r));
		if (opt == 4) printf("%d\n", query_len(1, l, r).dat[1]);
	}
	return 0;
}
