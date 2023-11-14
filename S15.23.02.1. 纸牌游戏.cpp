#include <cstdio>
const int N = 1e5 + 5;
int n, a[N], ans;
int main() {
    scanf("%d", &n);
    for (int i = 1, c; i <= n; i++) scanf("%d", &c), a[c] = 1;
    for (int i = 2 * n, t = 0; i; i--){
        if(!a[i]) ++t;
        else if(t) t--; else ans++;
    }
    printf("%d\n", n - ans);
    return 0;
}