#include <cstdio>
const int N = 1005;
typedef double d;
d n, k, m, p[N], f[N];
d power(d x, int p){
    d ans = 1;
    for (; p; p >>= 1, x = x * x)
        if (p & 1) ans = ans * x;
    return ans;
}
int main(){
    scanf("%lf%lf%lf", &n, &k, &m);
    for (int i = 0; i < n; i++)
        scanf("%lf", &p[i]);
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            f[i] += p[j] * power(f[i - 1], j);
        }
    }
    printf("%lf\n", power(f[(int)m], k));
    return 0;
}