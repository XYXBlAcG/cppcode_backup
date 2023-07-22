#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using std::vector;
typedef long long ll; 
// const int N = 1e6 + 5;
const int M = 1e4 + 5;
ll n, vis[M][M], res[M][M], f[M];
vector<ll> yin;
bool isPrime(ll num){
    if(num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if(i != 0 && num % i == 0) return 0;
    }return 1;
}
int bin(ll num){
    // num -> subtitle
    if(num <= 1) return -1;
    int l = 0, r = yin.size() - 1, mid;
    while(l < r){
        mid = (l + r + 1) >> 1; 
        if(yin[mid] <= num) l = mid;
        else r = mid - 1;
    }
    printf("%d -> %lld, yin[%d] = %lld\n", l, num, l, yin[l]);
    return l;
}

vector<ll> get_factors(ll n) {
    vector<ll> factors;
    vector<ll> factor(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (factor[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (factor[j] == 0) {
                    factor[j] = i;
                }
            }
        }
    }
    int i = 2;
    while (i * i < n) {
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n / i);
        }
        i++;
    }
    if (i * i == n) {
        factors.push_back(i);
    }
    factors.push_back(n);
    return factors;
}
int main(){
    while(scanf("%lld",&n) != EOF){
        if(isPrime(n)) {printf("0\n"); continue;}
        yin = get_factors(n);
        std::sort(yin.begin(), yin.end());
        for (int i = 0; i < yin.size(); i++) {
            printf("%lld ", yin[i]);
        }printf("\n");
        printf("size:%d\n", (int)yin.size());
        f[0] = 1;
        for (int i = 0; i < yin.size(); i++){
            for (int j = i; j < yin.size(); j++){
                f[j] += (yin[j] % yin[i] == 0 ? f[bin(yin[j] / yin[i])] : 0);
            }
        }
        printf("%lld\n", f[yin.size() - 1]);
    }
    return 0;
}

// ll dp(ll left){
//     if(visit[left]) return res[left]; visit[left] = 1;
//     printf("现在处理%lld\n",left);
//     if(isPrime(left)) return 1;
//     ll ans = 0;
//     for (int i = 1; pri[i] * pri[i] <= left; i++){
//         if(pri[i] != 0 && left % pri[i] == 0){
//             printf("正在计算%lld/%d\n", left, pri[i]);
//             ans += dp(left / pri[i]);
//         }
//     }
//     printf("%lld的答案更新为%lld\n", left, ans);
//     return res[left] = ans;
// }

// sub = discrete(yin);
// for (int i = 0; i < yin.size(); i++){
//     printf("yin[%d] = %d\n", sub[i], yin[i]);
// }

// vector<int> discrete(const vector<int>& odata, int start = 0) {
//     const int size = odata.size();
//     auto copy = odata;
//     sort(copy.begin(), copy.end());
//     // copy.erase(unique(copy.begin(), copy.end()), copy.end());
//     vector<int> res(size);
//     for (int i = 0; i < size; i += 1) {
//         res[i] = lower_bound(copy.begin(), copy.end(), odata[i]) - copy.begin() 
//              + start;
//     }
//     return res;
// }

// ll dp(int i, int j){
//     // 用前i个因数(从0开始)凑出第j个因数的方案数
//     printf("i : %d, j : %d\n", i, j);
//     printf("yin[%d] = %lld, yin[%d] = %lld\n", i, yin[i], j, yin[j]);
//     if(vis[i][j]) return res[i][j]; vis[i][j] = 1;
//     if(isPrime(yin[j]) or j < 0 or i < 0) return 0;
//     if(i == 0 && yin[j] % yin[i] == 0) return 1; 
//     return res[i][j] = ((yin[i] && yin[j] % yin[i] == 0) ? dp(i, bin(yin[j] / yin[i])) : 0) + dp(i - 1, j);
// }