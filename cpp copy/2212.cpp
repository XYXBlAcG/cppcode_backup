///max-difference=100
#include <cstdio>
#include <iostream>
const int N = 3009;

int f[N], arr[N], r;
bool vis[N];

int dp(int a){
	if(vis[a])
		return f[a];
    f[a] = 1;
    vis[a] = 1;
	for(int i = 1; i < a; i++)
		if(arr[i] < arr[a] && f[a] < dp(i) + 1)
			f[a] = std::max(dp(i) + 1, f[a]);
	return f[a];
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", arr + i);
    for(int i = 1; i <= n; i++)
        r = std::max(dp(i),r);
	printf("%d\n", r);
	return 0;
}
