#include <cstdio>
#include <map>
#define int long long
int a, b, ans, num[15];
int abs(int a){
	if(a < 0) return -a;
	return a;
} 
bool chk(int x){
	int len = 0;
	while(x) num[++len] = x % 10, x /= 10;
	for (int i = len - 1; i > 0; i--)
		if(abs(num[i + 1] - num[i]) <= 1) return 0;
	return 1;
}
signed main(){
	scanf("%lld%lld", &a, &b);
	for (int i = a; i <= b; i++){
		if(i % 1000000 == 0) printf("i = %lld\n", i);
		if(chk(i)){
			ans++;
//			printf("[%lld, %lld] have %lld windy num\n", a, i, ans);
		}
	}
	puts("done!");
	printf("%lld\n", ans);
	return 0;
}
