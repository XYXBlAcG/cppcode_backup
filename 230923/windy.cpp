#include <cstdio>
#include <cmath>
#define int long long
const int N = 15;
int rec[N][N], a, b, ta[N], tb[N], la, lb, aa, bb;
int abs(int a){
	if(a < 0) return -a;
	return a;
} 
void debugger(int* bug, int len){
	puts("debug: ");
	for (int i = 1; i <= len; i++){
		printf("%lld", bug[i]);
	}putchar('\n');
}
int ll(int x){
	int tp = 0;
	while(x > 0) tp++, x /= 10;
	return tp;
}
void breaker(int* num, int x, int ll){
	int len = 0;
	while(x > 0) num[(ll - (++len) + 1)] = x % 10, x /= 10;
}
bool chk(int* num, int len){
//	debugger(num, len);
	for (int i = len - 1; i > 0; i--)
		if(abs(num[i + 1] - num[i]) <= 1) return 0;
//	puts("return val 1");
	return 1;
}
void solve(int* tmp, int& res, int len){
	for (int i = 1; i < len; i++)
		for (int j = 1; j <= 9; j++)
			res += rec[i - 1][j];
//	printf("when len = %lld, ans = %lld\n", len, res);
	for (int i = 1; i <= len; i++){
		if(chk(tmp, i - 1)){
			for (int j = (i == 1); j <= tmp[i] - (i != len); j++){
//				printf("i = %lld, tmp[i] = %lld\n", i, tmp[i]);
//				printf("j = %lld, len - i = %lld\n", j, len - i);
//				printf("tmp[i - 1] = %lld\n", tmp[i - 1]);
//				printf("%lld %lld\n", (i == 1), (rec[len - i][j]));
				res += ((abs(tmp[i - 1] - j) > 1) || (i == 1)) * rec[len - i][j];
			}
		}
	}
}
signed main(){
	scanf("%lld%lld", &a, &b);
	a--;
	la = ll(a), lb = ll(b);
	
	breaker(ta, a, la), breaker(tb, b, lb);
//	debugger(ta, la); debugger(tb, lb);
	
	for (int j = 0; j < 10; j++)
		rec[0][j] = 1;
	for (int i = 1; i <= 12; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				rec[i][j] += (abs(j - k) > 1) * rec[i - 1][k];
			}
		}
	}
//	puts("a");
	solve(ta, aa, la);
//	puts("b");
	solve(tb, bb, lb);
//	printf("%lld %lld\n", bb, aa);
	printf("%lld\n", bb - aa);
	return 0;
}
