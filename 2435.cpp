#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 4e5 + 5;
int n, a[N], ans, tmp[N];
bool solve(int l, int r){
    if(l > r) return 0;
    int cnt = 0;
    for (int i = n, ll = 1, rr = 1; i; i--){
        while(tmp[i] + tmp[rr] <= r && rr <= n) rr++;
        while(tmp[ll] + tmp[i] < l && ll <= n) ll++;
        cnt += rr - ll - (ll <= i && i < rr);
    }
    return (cnt >> 1) & 1;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 0; i <= 25; i++){
        for (int j = 1; j <= n; j++) tmp[j] = a[j] & ((1 << (i + 1)) - 1);
        std::sort(tmp + 1, tmp + 1 + n);
        ans += (solve((1 << i), (1 << (i + 1)) - 1) ^ solve(3 * (1 << i), 2 * ((1 << (i + 1)) - 1))) * (1 << i);
    }
    printf("%d\n", ans);
    return 0;
}