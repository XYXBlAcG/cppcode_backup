#include <cstdio>
#include <algorithm>
#include <cmath>
typedef double d;
int t, n;
double k, ans, fk;
d qp(d a, int c){
	d res = 1;
	while(c){
		if(c & 1) res *= a;
		a *= a;
		c >>= 1;
	}
	return res;
}
void solve(){
	ans = 0;
	int up = n, tim = 1;
	d las = 1;
	while(up){
		ans += las * (d)tim;
		las = (1 - qp(fk, up));
		up >>= 1; tim <<= 1;
	}
	printf("%d\n", (int)std::round(ans));
}
int main(){
	freopen("quality.in", "r", stdin);
	freopen("quality.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--){
		scanf("%d%lf", &n, &k);
		fk = 1 - k;
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
