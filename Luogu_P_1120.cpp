#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 105;
int n, a[N], cnt[N], sum, mx, ans = 0x3f3f3f3f;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i], mx = std::max(mx, a[i]);
    for (int i = 1; i <= n; i++){
        cnt[a[i]] = 1;
        for (int j = i + 1; j <= n; j++){
            cnt[a[i] + a[j]] = 1;
        }
    }
    for (int i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            if(i >= mx && cnt[i]) ans = std::min(ans, i);
            if(sum / i >= mx && cnt[i]) ans = std::min(ans, sum / i);
        }
    }
    printf("%d\n", ans);
    return 0;
}