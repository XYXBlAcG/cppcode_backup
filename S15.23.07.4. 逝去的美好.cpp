#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 5e5 + 5;
int n, q, a[N];
int main(){
    #ifdef ONLINE_JUDGE
    freopen("innocent.in", "r", stdin);
    freopen("innocent.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++){
        int op, l, r, x;
        scanf("%d%d%d", &op, &l, &r);
        if(op == 1){
            scanf("%d", &x);
            for (int j = l; j <= r; j++) if(a[j] == x) a[j]++;
        }else{
            int mx = 0;
            for (int j = l; j <= r; j++) mx = std::max(mx, a[j]);
            printf("%d\n", mx);
        }
    }
    return 0;
}