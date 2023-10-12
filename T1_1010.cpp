#include <cstdio>
#define int long long
int n, sn, cnt;
signed main(){
    freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
    scanf("%lld", &n);
    if(n == 1){
        puts("0"); 
        fclose(stdin);
	    fclose(stdout);
        return 0;
    }
	for (int i = 2; i * i <= n; i++){
		if(n % i == 0) {
			cnt++;
			while(n % i == 0) n /= i;
		}
	}
	printf("%lld\n", cnt + (n != 1));
    fclose(stdin);
	fclose(stdout);
	return 0;
}