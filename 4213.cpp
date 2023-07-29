#include <cstdio>
const int N = 5e5 + 5;
int t, n, m, q, vis[N], pri[N], cnt, yin[N];
void init(int n) {
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
int power(int aff, int ngg, int mod){
    aff %= mod;
    int qwe = 1;
    for (; ngg > 0; ngg >>= 1){
        if(ngg & 1) (qwe *= aff) %= mod;
        (aff *= aff) %= mod;
    }
    return qwe;
}
int get(int i, int p){
    int res = 0;
    while(i) res += i / p, i /= p;
    return res;
}
int main(){
    init(3e5);
    scanf("%d",&t);
    for (int i = 1; i <= t; i++){
        scanf("%d%d%d",&n,&m,&q);
        for (int j = 0; pri[j] * pri[j] <= n; j++){
            // while()
            yin[j] = get(n, pri[j]) - get(m, pri[j]) - get(n - m, pri[j]);
        }
        int res = 1;
        for (int j = 0; pri[j] * pri[j] <= n; j++){
            res *= power(m, yin[j], q);
        }
        printf("%d \n", res);
    }
    return 0;
}