#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <random>
std::mt19937 frand(1919810);
const int N = 1e5 + 5;
int n, a[N], b[N], loc[N];
int cal(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(a[i] == b[j]) {ans += std::abs(i - j); break;}
        }
    }
    return ans;
}
int main(){
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) a[i] = b[i] = i;
    std::shuffle(a + 1, a + 1 + n, frand);
    std::shuffle(b + 1, b + 1 + n, frand);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]), loc[a[i]] = i; putchar('\n');
    for (int i = 1; i <= n; i++) printf("%d ", b[i]); putchar('\n');
    printf("%d\n", cal());
    for (int i = 1; i <= n; i++) b[i] = loc[b[i]], a[i] = i;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
    for (int i = 1; i <= n; i++) printf("%d ", b[i]); putchar('\n');
    printf("%d\n", cal());
    return 0;
}