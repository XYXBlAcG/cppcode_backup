#include <cstdio>
#include <algorithm>
#define int long long
const int N = 5e5 + 5;
int n, a[N], mmax, tmp[N], ans;
signed main(){
    freopen("kandagatan.in", "r", stdin);
	freopen("kandagatan.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i), mmax = std::max(a[i], mmax);
    for (int i = 0; i <= mmax; i++){
        tmp[0] = 0;
        for (int j = 1; j <= n; j++)
            tmp[j] = tmp[j - 1] + (a[j] - i);
        std::sort(tmp , tmp + 1 + n);
        int cnt = 0;
        for (int r = 0, l = 0; r < n; r++, l = r)
            while(tmp[r] == tmp[r + 1] && r < n){
                ans += (r + 1 - l);
                r++;
            }
    }
    printf("%lld\n", ans);
    fclose(stdin);
	fclose(stdout);
    return 0;
}