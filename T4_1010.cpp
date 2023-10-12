#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 1e5 + 5;
int n, m, a[N], len, num, tmp[N], mx;
int main(){
	freopen("repeat.in", "r", stdin);
	freopen("repeat.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
        mx = std::max(mx, a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		int l = 0, r = 0, k = 0, ans = 0;
		scanf("%d%d%d", &l, &r, &k);
        for (int j = 1; j <= mx; j++) tmp[j] = 0;
        for (int j = l; j <= r; j++) tmp[a[j]]++;
        for (int j = 1; j <= mx; j++) if(tmp[j] == k) ans++;
        printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
