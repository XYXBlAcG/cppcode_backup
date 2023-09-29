#include <cstdio>
const int N = 1040;
int n, n2, pay[N], cost[N][N];
bool way[N];
int qp(int a, int b){
	int ans = 1;
	while(b){
		if(b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d", &n), n2 = qp(2, n);
	for (int i = 1; i <= n2; i++)
		scanf("%d", way + i);
	for (int i = 1; i <= n2; i++)
		scanf("%d", pay + i);
	for (int i = 1; i < n2; i++)
		for (int j = 1; j <= n2 - i; j++)
			scanf("%d", &cost[i][i + j]);
	return 0;
}
