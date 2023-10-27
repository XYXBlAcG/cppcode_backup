#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e5 + 5;
const int M = 505;
int n, m, a[N], dis[M][M];
long long ans;
std::vector<int> st[N];
void floyd(){
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int main(){
		freopen("happybean.in", "r", stdin);
		freopen("happybean.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	if(n <= 500){
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			for (int j = 1; j <= n; j++){
				dis[i][j] = a[i];
			}
			dis[i][i] = 0;
		}
		for (int i = 1; i <= m; i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			dis[x][y] = z;
		}
		floyd();
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if(i != j) ans += dis[i][j];
			}
		}
		printf("%lld\n", ans);
	}
		fclose(stdin);
		fclose(stdout);
	return 0;
}
