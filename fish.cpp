#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define MOD mod
#define nu x.data[i]
const int N = 1e5 + 5, mod = 20130427;
int b, mpow[N], pmpow[N], pre[N], suf[N], f[N][3];
struct Num{
	int data[N], len;
	Num(){
		memset(data, 0, sizeof(data));
		len = 0;
	}
	void make(){
		scanf("%lld", &len);
		for (int i = len; i; i--) scanf("%lld", data + i);
	}
	void m1(){
		if(data[1] == 0 && len == 1) {data[0] = -1; return;}
		data[1]--;
		for (int i = 1; i <= len; i++)
			if(data[i] < 0) data[i + 1]--, data[i] += b;
		if(data[len] == 0) len--;
	}
	void reverse(){
		for (int i = 1, j = len; i <= j; i++, j--)
			std::swap(data[i], data[j]);
	}
	void output(){
		puts("debugger");
		for (int i = len; i; i--) printf("%lld ", data[i]);
		putchar('\n');
	}
};
void testcase1(Num& x);
// void testcase2(Num& x);
void init(int up){
	mpow[0] = 1, pmpow[0] = 1;
	for (int i = 1; i <= up; i++){
		mpow[i] = (mpow[i - 1] * b) % mod;
		pmpow[i] = (pmpow[i - 1] + mpow[i]) % mod;
	}
	// for (int i = 1; i <= 3; i++){
	// 	printf("pw = %lld %lld\n", mpow[i], pmpow[i]);
	// }
}
int solve(Num& x){
	int ans = 0;
	memset(pre, 0, sizeof(pre));
	memset(suf, 0, sizeof(suf));
	memset(f, 0, sizeof(f));
	x.output();
	for (int i = x.len; i; i--)
		pre[i] = (pre[i + 1] * b % mod + nu) % mod;
	for (int i = 1; i <= x.len; i++)
		suf[i] = (suf[i - 1] + nu * mpow[i - 1] % mod) % mod;
	// std::reverse(pre + 1, pre + 1 + x.len);
	// std::reverse(suf + 1, suf + 1 + x.len);
	// x.output();
	testcase1(x);
	for (int i = 1; i <= x.len; i++){
		f[i][0] = (f[i - 1][0] * b % mod + ((b - 1) * b / 2 % mod * mpow[i - 1] % mod * pmpow[i - 1] % mod)) % mod;
		f[i][1] = ((f[i - 1][0] * nu % mod + ((nu - 1) * nu / 2 % mod * mpow[i - 1] % mod * pmpow[i - 1] % mod)) % mod + 
		(f[i - 1][1] + pmpow[i - 1] * (suf[i - 1] + 1) % mod * nu % mod) % mod) % mod;
		// printf("%lld %lld\n", f[i - 1][0] * nu % mod + ((nu - 1) * nu / 2 * mpow[i - 1] % mod * pmpow[i - 1] % mod) , pmpow[i - 1] * (suf[i - 1] + 1) % mod * nu % mod);
	}
	// testcase2(x);
	for (int i = 1; i <= x.len; i++){
		(ans += f[i][1]) %= mod;
		if(pre[i + 1] > 1) (ans += (pre[i + 1] - 1) * f[i][0] % mod) %= mod;
	}
	return ans;
}
signed main(){
	scanf("%lld", &b);
	init(N - 5);
	Num n, m;
	n.make(), m.make(), n.m1();
	// n.reverse(); m.reverse();
	// n.output(), m.output();
	
	printf("%lld\n", ((solve(m) - solve(n)) % mod + mod) % mod);
	return 0;
} 
void testcase1(Num& x){
	puts("debug");
	printf("%lld\n", x.len);
	for (int i = 1; i <= x.len; i++){
		printf("%lld %lld\n", pre[i], suf[i]);
	}
	puts("end");
}
// void testcase2(Num& x){
// 	puts("testcase2");
// 	for (int i = 1; i <= x.len; i++){
// 		printf("f[%lld][0] = %lld\n", i, f[i][0]);
// 		printf("f[%lld][1] = %lld\n", i, f[i][1]);
// 	}
// 	puts("end");
// }
/*
debug
103 3
10 3
1 103
end
3 3
0 0
5400 444
testcase2
f[1][0] = 45
f[1][1] = 6
f[2][0] = 5400
f[2][1] = 6
f[3][0] = 553500
f[3][1] = 5850
end
debug
102 2
10 2
1 102
end
1 2
0 0
5400 333
testcase2
f[1][0] = 45
f[1][1] = 3
f[2][0] = 5400
f[2][1] = 3
f[3][0] = 553500
f[3][1] = 5736
end
120
*/