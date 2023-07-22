#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e6 + 5;
int n, ans[N];
int vis[N], pri[N], cnt = 1, pans = 0;
bool isPrime(int num){
    if(num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if(i != 0 && num % i == 0) return 0;
    }return 1;
}
void dfs(int now, int who, int num){
    // sum -> now; num -> pri[who]
    if(now == 1){ ans[++pans] = num; return;}
    if(isPrime(now - 1) && now > pri[who]) ans[++pans] = (now - 1) * num;
    for (int i = who; pri[i] * pri[i] <= now; i++){
        for (int last = pri[i], sum = last + 1; sum <= now; sum += (last *= pri[i])){
            // 可以用多少次 直到 sum > now
            if(sum != 0 && now % sum == 0) dfs(now / sum, i + 1, num * last);
        }
    }
}
void init() {
    for (int i = 2; i <= N - 5; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] > N - 5) break;
            vis[i * pri[j]] = 1;
            if (pri[j] != 0 && i % pri[j] == 0) {
                break;
            }
        }
    }
}
int main(){
    init();
    while(scanf("%d",&n) != EOF){
        memset(ans, 0, sizeof(ans));
        pans = 0;
        dfs(n, 1, 1);
        printf("%d\n", pans);
        std::sort(ans + 1, ans + 1 + pans);
        for (int i = 1; i <= pans; i++){
            printf("%d ", ans[i]);
        }if(pans) printf("\n");
    }
    return 0;
}