///max-difference=50
#include <cstdio>

typedef long long lld;
const int LN = 17, N = (1 << LN) + 11;
int n, m;
lld sum[N], tag[N];

void up(int v){
	sum[v] = sum[v << 1] + sum[v << 1 | 1];
}

void modify(int q, lld& val){
	sum[q] += val << (__builtin_clz(q) - (32 - LN));
	tag[q] += val;
}

void down(int v){
	modify(v << 1, tag[v]);
	modify(v << 1 | 1, tag[v]);
	tag[v] = 0;
}

void query(int q, lld& val){
	val += sum[q];
}

void (*upd)(int, lld&);

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", sum + (1 << LN | i));
	for(int i = (1 << LN) - 1; i >= 1; i--)
		up(i);
}

void solve(){
	while(m--){
		int op, l, r, i;
		lld val;
		scanf("%d%d%d", &op, &l, &r);
		r++;
		if(op == 1){
			scanf("%lld", &val);
			upd = modify;
		}else{
			val = 0;
			upd = query;
		}
		int p = 1, j, q;
		for(i = LN - 1; !((l ^ r) >> i & 1); i--){
			down(p);
			p = p << 1 | (l >> i & 1);
		}
		down(p);
		for(int d = 0, s = l; d <= 1; d++){
			j = i;
			q = p << 1 | d;
			for(; s & (1 << j) - 1; j--){
				int b = s >> j & 1;
				down(q);
				q = q << 1 | b;
				if(b == d)
					upd(q ^ 1, val);
			}
			for(q >>= 1; q != p; q >>= 1)
				up(q);
			s = r;
		}
		for(; p >= 1; p >>= 1)
			up(p);
		if(op == 0)
			printf("%lld\n", val);
	}
}

int main(){
	init();
	solve();
	return 0;
}
