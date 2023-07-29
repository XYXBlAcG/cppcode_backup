#include <cstdio>
#include <iostream>
const int N = 500005;
long long n, a[N], ans, sum[N], flag_1 = 1, flag_01 = 1;
int main(){
	freopen("kandagatan.in", "r", stdin);
	freopen("kandagatan.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i), sum[i] = sum[i - 1] + a[i];
		if(a[i] != 1) flag_1 = 0;
		if(a[i] > 1) flag_01 = 0;
	}
	if(n <= 5000){
		for (int l = 1; l <= n; l++){
			for (int r = l; r <= n; r++){
				long long summ = sum[r] - sum[l - 1];
				if(summ % (r - l + 1) == 0) ans++;
			}
		}
		printf("%lld\n", ans);
	}else 
	if(flag_1){
		printf("%lld\n", ((1 + n) * n) >> 1);
	}else if(flag_01){
		int len = 0;
		for (int l = 1, r = 1; r <= n; ){
			while(a[r] == 0 && r <= n){
				r++;
			}
			len = (r - l);
			ans += (len * (len + 1) >> 1);
			l = r;
			
			while(a[r] != 0 && r <= n){
				r++;
			}
			len = (r - l);
			ans += (len * (len + 1) >> 1);
			l = r;
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
