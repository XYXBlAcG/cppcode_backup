#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
typedef double d;
int n, ans = INT32_MAX;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int j = std::ceil((d)n / i);
        ans = std::min(ans, (i + j) * 2);
    }
    printf("%d\n", ans);
    return 0;
}