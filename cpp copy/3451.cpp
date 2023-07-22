#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
long long a[17], s, n;
int main(){
    std::cin >> n;
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    std::sort(a, a + n);
    while (a[0] != INF && a[1] != INF) s += a[0] * a[1], a[0] += a[1], a[1] = INF, std::sort(a, a + n);
    printf("%lld\n", s);
    return 0;
}