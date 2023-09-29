#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 505, mod = 1000000007, M = 1e6 + 5;
int n, k, h[N], fac[M], ifac[M];

struct Node{
	int col[N];
};

int inv(int x){
	int ans = 1, mi = mod - 2;
	while(mi){
		if(mi & 1) (ans *= x) %= mod;
		(x *= x) %= mod;
		mi >>= 1;
	}
	return ans;
}

void init(){
	fac[0] = 1; ifac[0] = inv(fac[0]);
	for (int i = 1; i <= M - 5; i++){
		fac[i] = (fac[i - 1] * i) % mod;
		ifac[i] = inv(fac[i]);
	}
}

int cnt(int n, int m, int k){
	if(k > n || k > m) return 0;
	return fac[m] * fac[n] % mod * ifac[m - k] % mod * ifac[n - k] % mod * ifac[k] % mod;
}

Node f(int l, int r, int low){ 
	Node ans; for (int i = 1; i <= k; i++) ans.col[i] = 0;
	ans.col[0] = 1;
	int len = r - l + 1, ll = h[r], prh = h[l] - low, cur = r;
	if(len == 1) {
		ans.col[1] = prh;
		return ans;
	}
	for (int i = l; i < r; i++)
		if(ll > h[i]) cur = i, ll = h[i];
	prh = ll - low;
//	printf("prh = %lld\n", prh);
	if(cur == l || cur == r){
		Node tran = ((cur == l) ? f(l + 1, r, ll) : f(l, r - 1, ll));
		for (int i = 0; i <= k; i++){
			for (int j = 0; j <= prh && i + j <= std::min(k, len); j++){
				if(i + j > 0) (ans.col[i + j] += (tran.col[i] * cnt(len - i, prh, j) % mod)) %= mod; 
			}
		}
		return ans;
	}
	Node tranl = f(l, cur - 1, ll), tranr = f(cur + 1, r, ll), merge = ans;
//	puts("merge");
//	for (int i = 0; i <= k; i++)
//		printf("%lld ", merge.col[i]);
//	putchar('\n');
	for (int i = 0; i <= k; i++){
		for (int j = 0; j <= k && i + j <= k; j++){
			if(i + j > 0) (merge.col[i + j] += tranl.col[i] * tranr.col[j] % mod) %= mod;
		}
	}
//	puts("merge");
//	for (int i = 0; i <= k; i++)
//		printf("%lld ", merge.col[i]);
//	putchar('\n');
	for (int i = 1; i <= std::min(len, k); i++){
		for (int j = 0; j <= i; j++){
			(ans.col[i] += (merge.col[i - j] * cnt(prh, len - (i - j), j) % mod)) %= mod;
		}
	}
//	puts("ans");
//	for (int i = 0; i <= k; i++)
//		printf("%lld ", ans.col[i]);
//	putchar('\n');
	return ans;
}

signed main(){
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", h + i);
	init();
	printf("%lld\n", f(1, n, 0).col[k]);
	return 0;
}
