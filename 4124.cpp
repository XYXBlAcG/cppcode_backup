#include <cstdio>
#include <algorithm>
const int N = 1e3 + 5;
int n, vis[N], cnt = 0, pri[N]; long long res[N], ans = 1;
void init() {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    init();
    res[0] = 1;
    // for (int i = 0; i < cnt; i++){
    //     printf("%d ",pri[i]);
    // }
    for (int i = 0; i < cnt; i++){
        for (int j = n; j >= pri[i]; j--){
            for (int k = pri[i]; k <= j; k *= pri[i]){
                res[j] += res[j - k];
            }
        }
    } for (int i = 1; i <= n; i++) ans += res[i];
    printf("%lld\n",ans);

    return 0;
}