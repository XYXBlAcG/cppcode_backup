#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 5;
typedef unsigned long long ll;
int n;
ll a[N], mm[N];
std::vector<ll> num;
int count(ll a){
	int ans = 0;
	while(a){
		if(a & 1) ans++;
		a >>= 1;
	}
	return ans;
}
namespace baoli{
	void main(){
		ll res = INF;
		for (ll i = 0; i <= 1000; i++){
			ll ans = 0;
			for (int j = 1; j <= n; j++){
				ans += __builtin_popcountll(a[j] + i);
			}
			// printf("i = %lld, ans = %lld\n", i, ans);
			res = std::min(res, ans);
		}
		printf("%lld\n", res);
	}
}
namespace solve{
	void main(){
		ll res = INF;
		for (ll v : num){
			ll ans = 0;
			for (int i = 1; i <= n; i++){
//				printf("%lld\n", a[i] + v);
				ans += count(a[i] + v);
			}
			res = std::min(res, ans);
		}
		printf("%lld\n", res);
	}
}
void init(){
	mm[0] = 1;
	for (int i = 1; i <= 63; i++){
		mm[i] = mm[i - 1] * 2;
//		printf("mm %d = %llu\n", i, mm[i]);
	}
}
int main(){
	// freopen("bin.in", "r", stdin);
	// freopen("bin.out", "w", stdout);
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	num.push_back(0);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 63; j++){
			if(mm[j] >= a[i]){
				num.push_back(mm[j] - a[i]);
//				printf("num + %lld\n", mm[j] - a[i]);
			}
		}
	}
	baoli::main();
	// solve::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}