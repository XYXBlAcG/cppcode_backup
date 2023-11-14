#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define lowbit(x) (x & -x)
const int N = 1e5 + 5;
int n, a[N], ans;
struct BITS{
    int d[N];
    void add(int x, int val){
        for (; x; x -= lowbit(x)) d[x] += val;
    }
    int sum(int x){
        int ans = 0;
        for (; x <= n; x += lowbit(x)) ans += d[x];
        return ans;
    }
}bits;
signed main(){
    scanf("%lld", &n);
    for (int i = 1, v; i <= n; i++) scanf("%lld", &v), ans += bits.sum(v), bits.add(v, 1);
    printf("%lld\n", ans);
    return 0;
}