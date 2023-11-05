#include <cstdio>
#define int long long
const int N = 1010;
int n, m, f[N], ans;
void pre(){
    f[0] = 1;
    for (int i = 1; i <= 1005; i++) f[i] = f[i - 1] * i; 
}
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
signed main(){
    pre();
    scanf("%lld%lld", &n, &m), ans = f[n + 1];
    
    return 0;
}