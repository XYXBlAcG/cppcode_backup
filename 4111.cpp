#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 1e6 + 5;
bool prime[N];
int get_prime(ll x, ll y){
    for (int i = 1; i <= N; i++)
        prime[i] = 0;
    for (ll i = 2; i <= y; i++){
        ll j = x;
        while(!(j % i))
            j++;
        for (; j <= x + y; j += i)
            prime[j - x] = 1;
    }
    int ans = 0;
    for (ll i = 1; i <= y; i++)
        if(!prime[i]) ans++;
    return ans;
}
inline long long read() {
    long long x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    int T = read();
    for (int i = 1; i <= T; i++){
        printf("%d\n", get_prime(read(), read()));
    }
    return 0;
}

// for (long long i = x; i <= x + y; i++){
//         if(!minp[i]){
//             prime[cntp++] = i;
//             minp[i] = i;
//         }
//         for (int j = 0; j < cntp && prime[j] <= minp[i] && prime[j] <= x / i; j++){
//            minp[prime[j] * (i)] = prime[j];
//         }
//     }
//     int ans = 0;
//     for (int i = 1; i <= y; i++){
//         if(prime[i]) ans++;
//     }return ans;