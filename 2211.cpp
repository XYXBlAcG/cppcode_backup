///max-difference=80
#include <cstdio>
#include <iostream>
const int MAX_N = 110;
const int MAX_M = 10011;
const int INF = 1000;
int v[MAX_N], m[MAX_N], f[MAX_M][MAX_M];

//f(i,j)表示前j个物品，总重量为i，获得的最大价值
int main() {
	int n, M;
	scanf("%d%d", &n, &M);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &m[i], &v[i]);
	}

	for(int i = 0; i <= M; i++)
		f[i][0] = -INF;
	f[0][0] = 0;
	for(int i = 1; i <= M; i++)
		for(int j = 0; j <= n; j++){
			f[i][j] = f[i][j - 1];
            if (i >= m[j])
				f[i][j] = std::max(f[i - m[j]][j - 1] + v[j],f[i][j - 1]);
                
		}
		
	printf("%d\n", f[M][n]);
	return 0;
}
