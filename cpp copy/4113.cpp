#include <cstdio>
#include <cstring>
typedef unsigned long long ll;
const int MAXN = 1000000;
bool isPrime[MAXN + 10];    // 标记是否为质数
int prime[MAXN + 10];       // 存储质数
int cnt = 1, n = 0;             // 记录质数个数
int mod = 1e9 + 7;

void init() {
    memset(isPrime, true, sizeof(isPrime));    // 初始化为true
    isPrime[0] = isPrime[1] = false;           // 0和1不是质数
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            prime[cnt++] = i;                  // 记录质数
        }
        for (int j = 1; j <= cnt && i * prime[j] <= MAXN; j++) {
            isPrime[i*prime[j]] = false;        // 筛掉合数
            if (i % prime[j] == 0) {
                break;                          // 保证每个合数只被筛一次
            }
        }
    }
}

ll getTime(int p){
    ll time = 0;
    for (ll i = p; n >= i; i *= p){
        if(i == 0) break;
        time += n / i;
    }
    return time;
}

int main() {
    init();
    scanf("%d",&n);
    ll res = 1;
    for (int i = 1; prime[i] <= n && i <= cnt; i++){
        res *= (2 * getTime(prime[i]) + 1);
        res %= mod;
    }
    printf("%lld ", res);
    return 0;
}
