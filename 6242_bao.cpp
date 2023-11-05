#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, m, k, a[N], tmp[N];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        for (int j = 1; j <= k; j++) scanf("%d", tmp + j);
        int flag2 = 1;
        for (int j = l; j <= r - k + 1; j++){
            int flag = 1;
            for (int o = 1; o <= k; o++){
                // printf("%d, %d\n", o, o + j - 1);
                // printf("%d %d\n", tmp[o], a[o + j - 1]);
                if(tmp[o] != a[o + j - 1]) {flag = 0; break;}
            }
            // puts("?");
            if(flag == 1) {flag2 = 0, puts("No"); break;}
        }
        if(flag2 == 1) {puts("Yes"); }
    }
    return 0;
}