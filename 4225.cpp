#include <cstdio>
#include <vector>
#define int long long
const int N = 1e5 + 5;
int n, m, ans, vis[N], pri[N], cnt;
std::vector<int> yin[N];
void init(int nn) {
    for (int i = 2; i <= nn; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] > nn) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
void dfs(int a, int b){
    
}
signed main(){
    scanf("%lld%lld",&n,&m);
    init(n);
    for (int j = 1; j <= n; j++){
        for (int i = 2; i * i <= m; i++){
            if(m % i == 0){
                while(m % i == 0) m /= i;
                yin[j].push_back(i);
            }
        }
        if(m != 1) yin[j].push_back(m);
    }
    for (int i = 1; i <= n; i++){

    }
    return 0;
}