///max-difference=100
#include <cstdio>

const int N = 3009;

int f[N], arr[N];
bool vis[N];

int dp(int a){
	if(vis[a])
		return f[a];
	for(int i = 1; i < a; i++)
		if(arr[i] < arr[a] && f[a] <= dp(i) + 1)
			f[a] = dp(i) + 1;
	return f[a];
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", arr + i);
	printf("%d\n", dp(n));
	return 0;
}
