#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
int d[N], n, sum;
int main(){
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", d + i);
        if(d[i] > d[i - 1]) sum += d[i] - d[i - 1];
    }
    printf("%d\n", sum);
    return 0;
}