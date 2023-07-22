#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1e4 + 10;
typedef long long ll;
ll n, fac[N], f[N][N];
int pfac;
bool isPrime(ll num){
    if(num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if(i != 0 && num % i == 0) return 0;
    }return 1;
}
void getf(ll x){
    ll i = 2;
    while (i * i < x) {
        if (i && x % i == 0) {
            fac[++pfac] = i;
            fac[++pfac] = n / i;
        }
        i++;
    }
    if (i * i == x) {
        fac[++pfac] = i;
    }
    fac[++pfac] = n;
}
int bin(ll num){
    // num -> subtitle
    if(num < fac[1]) return 0;
    int l = 1, r = pfac, mid = 0;
    while(l < r){ 
        mid = (l + r + 1) >> 1; 
        if(fac[mid] <= num) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main(){
    while(scanf("%lld",&n) != EOF){
        pfac = 0;
        memset(fac, 0, sizeof(fac));
        getf(n);
        std::sort(fac + 1, fac + 1 + pfac);
        for (int i = 0; i <= pfac; i++){
            f[i][i] = 1;
        }
        for (int i = 1; i <= pfac; i++){
            for (int j = 1; j <= pfac; j++){
                f[i][j] += f[i - 1][j] + ((fac[i] && fac[j] % fac[i] == 0) ? f[i][bin(fac[j] / fac[i])] : 0);
            }
        }
        printf("%lld\n", f[pfac][pfac]);
    }
    return 0;
}