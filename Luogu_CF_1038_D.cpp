#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 5e5 + 5;
int n, a[N], sum;
bool neg = 1, posi = 1;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i), sum += std::abs(a[i]);
        if(a[i] < 0) posi = 0;
        if(a[i] > 0) neg = 0; 
    }
    if(n == 1) return printf("%lld\n", a[1]), 0;
    if(!neg && !posi){
        printf("%lld\n", std::abs(sum));
    }else{
        std::sort(a + 1, a + 1 + n), sum = 0;
        if(posi) {
            for (int i = 2; i <= n; i++) sum += a[i];
            printf("%lld\n", sum - a[1]);
        }else{
            for (int i = 1; i < n; i++) sum += a[i];
            printf("%lld\n", a[n] - sum);
        }
    }
    return 0;
}