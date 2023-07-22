#include <cstdio>
const int N = 23;
#define int long long
int n, a[N], b[N], c[N], ax, ay, k[N], q[N];
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
int merge(int aa, int bb){
    aa = k[aa], bb = k[bb]; int qa = q[aa], qb = q[bb];
    int g = gcd(aa, bb);
    
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        int g = gcd(a[i], c[i]);
        if(b[i] % g != 0){printf("nO sOLuTiOn\n"); return 0;}
        ax = ay = 0;
        a[i] /= g, b[i] /= g, c[i] /= g;
        exgcd(a[i], c[i], ax, ay);
        k[i] = c[i];
        q[i] = ((b[i] * ax % c[i]) + c[i]) % c[i];
        if(i > 1) merge(i - 1, i);
    }
    return 0;
}