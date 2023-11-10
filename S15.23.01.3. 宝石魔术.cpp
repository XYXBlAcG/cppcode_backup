#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 2e6 + 5;
int n, m, k, g[N], res;
std::vector<int> f[N];
signed main(){
    #ifdef ONLINE_JUDGE
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    #endif
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        scanf("%lld", g + i), g[n + i] = g[i];
        if(f[g[i]].empty()) f[g[i]].push_back(0);
    }
    for (int i = 1; i <= n * 2; i++)
        f[g[i]].push_back(i + f[g[i]].back());//, printf("%lld pushback %lld\n", g[i], i + f[g[i]].back());
    for (int i = 1; i <= m; i++){
        int l = 1, r = 1;
        while(r < (int)f[i].size()){
            for(;; l++){
                // printf("l = %lld, r = %lld\n", l, r);
                int mid = (l + r) >> 1, len = (r - l + 1), tmp = f[i][r] - f[i][mid] - f[i][mid - (len & 1)] + f[i][l - 1] - (len / 2 + (len & 1)) * (len / 2);
                // printf("tmp o = %lld, a = %lld, b = %lld\n", f[i][r] - f[i][mid], f[i][r], f[i][mid]);
                // printf("tmp = %lld\n", tmp);
                if(tmp <= k) break;
            }
            res = std::max(res, std::min((int)f[i].size() >> 1, (r - l + 1)));
            r++;
        }
    }
    printf("%lld\n", res);
    return 0;
}
/*
1 -> 1
2 -> 2
1 -> 7
3 -> 4
1 -> 14
2 -> 14
1 -> 23
2 -> 24
1 -> 34
3 -> 24
1 -> 47
2 -> 40
l = 1, r = 1
tmp o = 0
tmp = 0
l = 1, r = 2
tmp o = 3
tmp = 1
l = 1, r = 3
tmp o = 5
tmp = 2
l = 2, r = 3
tmp o = 5
tmp = 1
l = 2, r = 4
tmp o = 7
tmp = 2
l = 3, r = 4
tmp o = 7
tmp = 1
l = 3, r = 5
tmp o = 9
tmp = 2
l = 4, r = 5
tmp o = 9
tmp = 1
l = 4, r = 6
tmp o = 11
tmp = 2
l = 5, r = 6
tmp o = 11
tmp = 1
l = 1, r = 1
tmp o = 0
tmp = 0
l = 1, r = 2
tmp o = 6
tmp = 3
l = 2, r = 2
tmp o = 0
tmp = 0
l = 2, r = 3
tmp o = 8
tmp = 1
l = 2, r = 4
tmp o = 12
tmp = 4
l = 3, r = 4
tmp o = 12
tmp = 3
l = 4, r = 4
tmp o = 0
tmp = 0
l = 1, r = 1
tmp o = 0
tmp = 0
l = 1, r = 2
tmp o = 10
tmp = 5
l = 2, r = 2
tmp o = 0
tmp = 0
2
*/