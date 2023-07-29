#include <cstdio>
#define INF 0x3f3f3f3f
const int N = 105;
typedef long long ll;
int cn[N], en[N], vis[N][N], flag, ope[N][N];
int n, m;
bool check(){
	for (int i = 0; i < n; i++){
		if(cn[i] != i) return 0;
	}
	for (int i = 0; i < m; i++){
		if(en[i] != i) return 0;
	}return 1;
}
void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void op(int i, int j, int time){
	if(time > 1000 or (vis[i][j]) or check()) return;
//	if(vis[i][j] == 1) flag = 1;
	vis[i][j] = 1;
	swap(cn[i], en[j]);
	ope[i][j] = 1;
}
int main(){
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &cn[i - 1]);
	}
	for (int i = 1; i <= m; i++){
		scanf("%d", &en[i - 1]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			op(i, j, ++cnt);
		}
	}
	printf("%d\n", cnt > 1000 ? -1 : cnt);
	if(cnt <= 1000){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if(ope[i][j]) printf("%d %d\n", i, j);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
