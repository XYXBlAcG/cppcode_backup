#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define debugger puts("fuck") 
const int N = 2e5 + 5, mod = 20130427;
int b, fu = 1, pow[N], ppow[N], pre[N], suf[N];
struct Num{
	int data[N], len;
	void make(){
		scanf("%d", &len);
		for (int i = len; i; i--) scanf("%d", data + i);
	}
	void output(){
		puts("NUM OUTPUT");
		for (int i = len; i; i--) printf("%d ", data[i]);
		putchar('\n');
	}
	void m1(){
		data[1]--;
		for (int i = 1; i <= len; i++)
			if(data[i] < 0) data[i + 1]--, data[i] += b;
		if(!data[len]) len--;
	}
}l, r;
void init(){
	pow[1] = 1, ppow[1] = 1;
	for (int i = 2; i <= N - 5; i++){
		pow[i] = pow[i - 1] * i % mod;
		ppow[i] = (ppow[i - 1] + pow[i]) % mod;
	}
}
int solve(Num a){
	memset(pre, 0, sizeof(pre));
	memset(suf, 0, sizeof(suf));
	int ans = 0;
	for (int i = 1; i <= a.len; i++)
		pre[i] = (pre[i - 1] + a.data[i] * pow[i - 1] % mod) % mod;
	for (int i = a.len; i; i--)
		suf[i] = (suf[i + 1] * pow[i] + a.data[i] % mod) % mod;
	for (int i = 1; i <= a.len; i++){
		
	}
}
sigend main(){
	init();
	scanf("%lld", &b);
	l.make(), r.make();	l.m1();
	printf("%lld\n", solve(r) - solve(l));
	return 0;
}
