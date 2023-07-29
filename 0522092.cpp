#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#define deb(x) std::cout << #x << " = " << x << std::endl
const int N = 5005, mod = 998244353;
long long n, ord[N], vis[N], cnt, vp[N];
std::vector<int> st[N];
long long jc(long long x){
	long long ans = 1;
	for (long long i = 2; i <= x; i++){
		(ans *= i) %= mod;
	}
	return ans;
}
// long long dfs(int x, int fa){
// 	if(!vp[x]){
// 		vp[x] = 1, cnt++;
// 	}
// 	if(cnt == n) {
// 		return 1;
// 	}else if(st[x].size() == 1 && fa != -1){
// 		return 0;
// 	}
// 	long long res = 0;
// 	for (auto v : st[x]){
// 		if(v != fa){
// 			if(ord[fa] > ord[x] or fa == -1){
// 				for (int i = ord[x] + 1; i <= n; i++){
// 					if(!vis[i]){
// 						ord[v] = i;
// 						vis[i] = 1;
// 						(res += dfs(v, x)) %= mod;
// 						vis[i] = 0;
// 						ord[v] = 0;
// 					}
// 				}
// 			}
// 			if(ord[fa] < ord[x] or fa == -1){
// 				for (int i = ord[x] - 1; i ; i--){
// 					if(!vis[i]){
// 						ord[v] = i;
// 						vis[i] = 1;
// 						(res += dfs(v, x)) %= mod;
// 						vis[i] = 0;
// 						ord[v] = 0;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return res % mod;
// }
int main(){
	freopen("aoshen.in", "r", stdin);
	freopen("aoshen.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i < n; i++){
		long long u, v;
		scanf("%lld%lld", &u, &v);
		st[u].push_back(v);
		st[v].push_back(u);
	}
	long long ans = 0;
//	if(n <= 10){
//		for (int i = 1; i <= n; i++){
//			memset(vp, 0, sizeof(vp));
//			memset(vis, 0, sizeof(vis));
//			memset(ord, 0, sizeof(ord));
//			cnt = 0;
//			ord[1] = i;
//			vis[i] = 1;
//			(ans += dfs(1, -1)) %= mod;
//			vis[i] = 0;
//			debug();
//		}
//		printf("%lld\n", ans);
//	}
//	else 
	if(st[1].size() == (n - 1)){
		printf("%lld\n", jc((n - 1)) * 2 % mod);
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
