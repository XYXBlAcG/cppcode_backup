#include <cstdio>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int fac = 1;
	for(int i = 2; i <= n; i++) {
		(fac *= i) %= m;
		// printf("%d\n", fac);
	}
	fac %= m;
	printf("%d\n", fac);
	return 0;
}
