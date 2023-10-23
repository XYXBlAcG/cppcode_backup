#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define int long long
const int N = 2e3 + 5;
int n, k, m[N][N], pre[N][N], ans[N][N];
struct Pos{
	int x, y;
}pos[N * N];
bool cmp(int a, int b){
	return a > b;
}
namespace baoli{
	bool chk(Pos a, Pos b){
		return std::abs(a.x - b.x) + std::abs(a.y - b.y) > k;
	}
	int get(Pos now){
		for (int i = n * n; i >= 1; i--){
			if(chk(now, pos[i])) return i;
		}
		return 0;
	}

	void main(){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				pos[m[i][j]] = {i, j};
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				pre[i][j] = get({i, j});
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				Pos cur = {i, j};
				int res1 = 0, res2 = 0;
				for (int kk = 1; kk <= 1000000; kk++){
					if(kk & 1){
						res1 += m[cur.x][cur.y];
					}else{
						res2 += m[cur.x][cur.y];
					}
					cur = pos[pre[cur.x][cur.y]];
				}
				if(res1 > res2) ans[i][j] = 1;
				else ans[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if(ans[i][j]) putchar('K');
				else putchar('B');
				putchar(' ');
			}putchar('\n');
		}
	}
}
signed main(){
	// freopen("chopper.in", "r", stdin);
	// freopen("chopper.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%lld", &m[i][j]);
		}
	}
	baoli::main();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
