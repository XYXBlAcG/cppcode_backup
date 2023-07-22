///max-difference=100
#include <cstdio>
#include <iostream>
const int N = 1009;

int a[N][N], f[N][N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= i; j++) {
			/*if(f[i+1][j] < f[i][j] + a[i][j]) {
				f[i+1][j] = f[i][j] + a[i][j];
			} else 
			if(f[i+1][j+1] < f[i][j] + a[i][j]) {
				f[i+1][j+1] = f[i][j] + a[i][j];
			}*/
            f[i][j] = std::max(f[i + 1][j],f[i + 1][j + 1]) + a[i][j];
		}
	}
	printf("%d\n", f[1][1]);
	return 0;
}
