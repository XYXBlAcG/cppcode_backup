#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define int long long
const int N = 105, M = 3005, mod = 998244353;
int n, k, ans;
struct BLCK{
	int x, y;
}blck[N];
bool mp[M][M];
int qp(int a, int b = mod - 2){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int pre(){
	__int128_t t = (n + 1) / 2;
    __int128_t ans = t % mod * (1ll + t) % mod * (3ll + 2ll * n) % mod * qp(2ll) % mod;
    // printf("t = %lld, t + 1 = %lld, 3 + 2 * n = %lld, qp(2) = %lld\n", t, 1ll + t, 3ll + 2ll * n, qp(2));
    // printf("res = %lld\n", t % mod * (1ll + t) % mod);
    __int128_t ans1 = 4ll * t % mod * (t + 1ll) % mod * (2ll * t + 1ll) % mod * qp(6ll) % mod;
    return (ans - ans1) % mod;
}
namespace pt8{
	bool chk(int x, int y){
		return x >= 1 && y >= 1 && (x + y) <= n + 1;
	}
	bool black(int xl, int xr, int yl, int yr){
		for (int i = 1; i <= k; i++){
			auto v = blck[i];
			if(v.x >= xl && v.x <= xr && v.y >= yl && v.y <= yr) return 1;
		}
		return 0;
	}
	void main(){
		int res = 0;
		for (int i = 1; i <= n; i++){
			for (int j = n - i + 1; j >= 1; j--){
				if(mp[i][j]) continue;
				res++;
				int o;
				for (o = 1; o <= n; o++){
//					printf("i = %d, j = %d, o = %d\n", i, j, o);
					int tx = i - o, ty = j - o;
					if(!chk(tx, ty)) break;
					if(black(tx, i, ty, j)) break;
					res++;
				}
				res %= mod;
			}
		}
		printf("%lld\n", res);
	}
}
signed main(){
    #ifdef ONLINE_JUDGE
	freopen("kami.in", "r", stdin);
	freopen("kami.out", "w", stdout);
    #endif
	
	scanf("%lld%lld", &n, &k);
	ans = pre();
	for (int i = 1; i <= k; i++){
		int x, y;
		scanf("%lld%lld", &x, &y);
		blck[i] = {x, y};
		if(n <= 3000) mp[x][y] = 1;
	}
	if(n <= 3000) pt8::main();
	else printf("%lld\n", (ans % mod + mod) % mod);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
