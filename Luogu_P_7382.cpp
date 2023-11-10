#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, k, a[N], b[N], cha[N], minus, res[N], ans;
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for (int i = 1; i <= n; i++){
        cha[i] = a[i] - b[i];
    }
    std::sort(cha + 1, cha + 1 + n);
    if(n & 1) minus = cha[n >> 1];
    else minus = cha[n >> 1] + cha[(n >> 1) - 1];
    for (int i = 1; i <= n; i++){
        res[i] = std::abs(a[i] - minus - b[i]);
    }
    std::sort(res + 1, res + 1 + n);
    int cnt = k;
    for (int i = n; i; i--){
        if(!cnt) ans += res[i];
        else cnt--;
    }
    printf("%d\n", ans);
    return 0;
}