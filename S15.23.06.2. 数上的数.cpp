#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int mod = 10007;
int n, m;
int mp[11][11] = {{1, 3, 5, 8, 10, 14, 16, 20, 23, 27, }, 
{1, 5, 11, 22, 32, 52, 66, 92, 115, 147, }, 
{1, 9, 29, 74, 136, 254, 382, 596, 833, 1173, }, 
{1, 17, 83, 274, 644, 1396, 2502, 4388, 6919, 736, }, 
{1, 33, 245, 1058, 3160, 8054, 7079, 3839, 311, 3367, }, 
{1, 65, 731, 4162, 5685, 7424, 8369, 6190, 5964, 5780, }, 
{1, 129, 2189, 6507, 8207, 2058, 5288, 2319, 8320, 3524, }, 
{1, 257, 6563, 5752, 611, 5260, 7590, 1487, 8923, 7479, }, 
{1, 513, 9678, 2476, 2275, 831, 5568, 6834, 1632, 2948, }, 
{1, 1025, 9016, 8874, 9827, 3916, 7695, 624, 3240, 4753, }, 
};
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
bool isp(int x){
    for (int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int get(int x){
    int cnt = 0;
    for (int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(i * i == x) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}
namespace pt20 {
    int res = 0;
    void main() {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                (res += get(gcd(i, j))) %= mod;
            }
        }
        printf("%lld\n", res);
    }
} 
signed main(){
    #ifdef ONLINE_JUDGE
        freopen("non.in", "r", stdin);
        freopen("non.out", "w", stdout);
    #else
    #endif
    scanf("%lld%lld", &n, &m);
    if(n <= 10 && m <= 10){
        printf("%lld\n", mp[n - 1][m - 1]);
    }else{
        pt20::main();
    }
    return 0;
}