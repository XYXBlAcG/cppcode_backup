#include <cstdio>
const int N = 1e6 + 5 ;
typedef long long ll;
ll a[N];
ll l, r, b, d;
ll n, m;
ll cha[N];
ll cha2[N];
int main(){
    scanf("%lld%lld",&n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld%lld",&l,&r,&b,&d);
        // int tmp = cha2[l];
        // cha2[l] += b;
        cha[l] += b;
        // cha2[l+1] += d - b;
        cha2[l+1] += d;
        cha[r+1] -= 1ll*(r-l)*d+b;
        // cha2[r+1] -= ((r-l+1)*d+b);
        cha2[r+1] -= d;
        
        // cha[r+1] -= 1ll*(r-l)*d;
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        tmp += cha2[i];
        cha[i] += tmp;
        printf("%lld ",a[i]=a[i-1]+cha[i]);
    }
    
    printf("\n");
    return 0;
}