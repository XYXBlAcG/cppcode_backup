#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::string;
const long long N = 1e6 + 5, mod = 19930726;
long long n, k, d1[N], t[N], ans = 1;
string str;
long long qp(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
void manacher(){
    for (long long i = 0, l = 0, r = -1; i < n; i++){
        long long k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while(0 <= i - k && i + k < n && str[i - k] == str[i + k]) k++;
        d1[i] = k--;
        if(i + k > r) l = i - k, r = i + k;
        t[(d1[i] << 1) - 1]++;
    }
}
signed main(){
    cin >> n >> k >> str;
    manacher();
    // for (long long i = 0; i < n; i++) printf("d %lld -> %lld\n", i, d1[i]);
    // for (long long i = 1; i <= n; i++) printf("%lld -> %lld\n", i, t[i]);
    long long sum = 0;
    for (long long i = n; i >= 1; i--){
        if(!(i & 1)) continue;
        sum += t[i];
        if(sum <= k) (ans *= qp(i, sum)) %= mod, k -= sum;
        else {(ans *= qp(i, k)) %= mod; break;}
    }
    if(sum < k) puts("-1");
    else printf("%lld\n", (ans + mod) % mod); 
    return 0;
}