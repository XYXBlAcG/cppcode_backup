#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f
#define int long long
int n, ans, cnt;
signed main(){
    while(1){
        cnt++, ans = INF;
        scanf("%lld", &n);
        if(n == 0) break;
        for (int i = 1; i * i <= n; i++){
            if(n % i == 0) ans = std::min(ans, i + n / i);
        }
        printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}