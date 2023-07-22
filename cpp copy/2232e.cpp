#include <cstdio>
#include <iostream>
using std::max;
const int N = 1009;

int a[N][N], f[N][N];
int n;
int road[2000], vis[2000][2000];

int fun(int i, int j){
    if(vis[i][j]) return a[i][j];
    vis[i][j] = 1;
    if (i == n) return a[i][j];
    else{
        if (fun(i + 1, j) == max(fun(i + 1, j), fun(i + 1, j + 1))){
            road[i] = 1;
        }else{
            road[i] = 0;
        }
        return max(fun(i + 1, j), fun(i + 1, j + 1)) + a[i][j];
    }
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
    
    int ans = fun(1, 1);
	printf("%d\n", ans);
    for (int i = 1; i < n; i++){
        if (road[i] == 0){
            printf("L");
        }else{
            printf("R");
        }
    }
	return 0;
}
