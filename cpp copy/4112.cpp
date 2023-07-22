#include <cstdio>

const int MAXN = 1000010;
int prime[MAXN], cnt;     // prime[]存储所有素数
int is_prime[MAXN];           // 存储每个数的欧拉函数
long long sum[MAXN]; // sum
int phi[MAXN];

void pre() {
    for (int i = 1; i <= MAXN; i++) {
        is_prime[i] = 1;
    }
    int cnt = 0;
    is_prime[1] = 0;
    phi[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
        prime[++cnt] = i;
        phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= MAXN; j++) {
        is_prime[i * prime[j]] = 0;
        if (i % prime[j])
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        else {
            phi[i * prime[j]] = phi[i] * prime[j];
            break;
        }
        }
    }
    for (int i = 1; i <= MAXN; i++){
        sum[i] += phi[i] + sum[i - 1];
    }
}

int main() {
    pre();
    int n;
    scanf("%d", &n);
    while(n--){
        int a = 0;
        scanf("%d", &a);
        printf("%lld\n", (long long)(sum[a] - 1) * 2 + 1);
    }

    return 0;
}

