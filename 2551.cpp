#include <cstdio>
typedef unsigned long long ll;
ll x, y, m;
ll power(ll a, ll b){
    ll res = 0, pow = b;
    for (; a; a >>= 1){
        if (a & 1) res = (res + pow) % m;
        pow = (pow + pow) % m;
    }return res;
}
int main(){
    scanf("%lld%lld%lld", &x, &y, &m);
    printf("%lld\n", power(x, y));
    return 0;
}