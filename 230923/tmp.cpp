#include <cstdio>
#define int long long
const int N = 20;
int a, b, ri[N], f[N], num[N], lf[N], pow[N];
void debug(int* az){
	puts("debugger = ");
	for (int i = 0; i < 10; i++){
		printf("%lld ", az[i]);
	}putchar('\n');
}
void solve(int r, int* ans){
	int len = 0, lef = r;
	while(r) num[++len] = r % 10, r /= 10;
	for (int i = len; i; i--){
		for (int j = 0; j < 10; j++) // behind
			ans[j] += num[i] * f[i - 1];
		for (int j = 0; j < num[i]; j++) // this figure
			ans[j] += pow[i - 1];
		lef -= num[i] * pow[i - 1], ans[num[i]] += lef + 1; // this figure
		ans[0] -= pow[i - 1]; // zero
	}
}
signed main(){
	scanf("%lld%lld", &a, &b);
	pow[0] = 1;
	for (int i = 1; i <= 13; i++)
		f[i] = f[i - 1] * 10 + pow[i - 1], pow[i] = pow[i - 1] * 10;
	solve(a - 1, lf), solve(b, ri);
//	debug(lf), debug(ri);
	for (int i = 0; i <= 9; i++){
		printf("%lld ", ri[i] - lf[i]);
	}putchar('\n');
	return 0;
}
