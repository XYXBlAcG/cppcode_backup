#include <cstdio>
#include <vector>
#include <cstring>
const int N = 1048576;
typedef long long ll;
int n;
ll st[N + 5], primes[N + 5], minp[N + 5], cnt, sum[N + 5];
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            minp[i] = i; 
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] * i <= n; j++) {
            int t = primes[j] * i;
            st[t] = true;
            minp[t] = primes[j];
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

ll getjie(ll x){
    ll res = 1;
    for (int i = 1; i <= x; i++){
        res *= i;
    }
    return res;
}

int main(){
    get_primes(N); 
    while(scanf("%d",&n) != EOF){
        ll ans = 0, cont = 0;
        while(n > 1){
            int p = minp[n];
            sum[cont] = 0;
            while(!(n % p)){
                n /= p;
                sum[cont]++;
                ans++;
            }cont++;
        }
        printf("%lld ", ans);
        ll res = 1;
        res = getjie(ans);
        for (int i = 0; i < cont; i++){
            for (int j = 1; j <= sum[i]; j++){
                res /= j;
            }
        }
        printf("%lld \n", res);
    }
    return 0;
}