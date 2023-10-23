#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long
const int N = 1e6 + 5, top = 1e6;
int T, n, m, isp[N];
std::vector<int> pri;
int pre(){
    memset(isp, 1, sizeof(isp));
    for (int i = 2; i <= top; i++){
        for (int j = i << 1; j <= top; j += i){
            isp[j] = 0;
        }
    }
    for (int i = 2; i <= top; i++)
        if(isp[i]) pri.push_back(i);
}
signed main(){
    scanf("%lld", &T);
    pre();
    printf("sz = %lld\n", (int)pri.size());
    while(T--){
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", solve());
    }
    return 0;
}