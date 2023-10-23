#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 1e8 + 5;
int pri[N], vis[N], cnt;
void ela(int n){
    for (int i = 2; i <= n; i++){
        if(!vis[i]) pri[++cnt] = i;
        for (int j = 1; j <= cnt; j++){
            if(i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
int main(){
    int n = 0, q = 0;
    scanf("%d%d", &n, &q);
    ela(n);
    for (int i = 1, k = 0; i <= q; i++){
        scanf("%d", &k);
        printf("%d\n", pri[k]);
    }
    return 0;
}