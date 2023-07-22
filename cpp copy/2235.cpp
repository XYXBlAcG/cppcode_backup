#include <cstdio>
#include <iostream>
const int MAX_N = 110;
const int MAX_M = 10011;
const int INF = 1000;
int v[MAX_N], m[MAX_N], f[MAX_M][MAX_M];
using std::max;

int bag[10011], bl;

int main() {
	int n, M;
	scanf("%d%d", &n, &M);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &m[i], &v[i]);
	}
	for(int i = 0; i <= M; i++){
		f[i][0] = -INF;
	}
	f[0][0] = 0;
	for(int i = 1; i <= M; i++){
		int tmp = 0;
		for(int j = 0; j <= n; j++){
			tmp = j;
			f[i][j] = f[i][j - 1];
            if (i >= m[j]){
				f[i][j] = max(f[i - m[j]][j - 1] + v[j],f[i][j - 1]);
				if (f[i][j] == f[i - m[j]][j - 1] + v[j]){bag[bl++] = j;}
			}
		}
	}
		
	printf("%d\n", f[M][n]);
	bl = n;
	// for (int i = 1; i <= bl; i++){
	// 	printf("%d ",bag[i]);
	// }
	for (int i = 1; i <= bl; i++){
		
	}
	return 0;
}
