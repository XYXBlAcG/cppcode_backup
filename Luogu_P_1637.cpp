#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define sum(u) node[u].sum
#define mid ((l + r) >> 1)
const int N = 1e5 + 5;
int n, a[N], d[N], a1[N], b1[N], ans;
struct Tree{
    struct Node{
        int sum;
    }node[N];
    void modify(int u, int l, int r, int pos){
        if(pos > r || pos < l) return;
        if(l == r) return (void)sum(u)++;
        modify(ls(u), l, mid, pos), modify(rs(u), mid + 1, r, pos);
        sum(u) = sum(ls(u)) + sum(rs(u));
    }
    int query(int u, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) return sum(u);
        return query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
    }
}sm, bg;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), d[i] = a[i];
    std::sort(d + 1, d + 1 + n);
    int dlen = std::unique(d + 1, d + 1 + n) - d - 1;
    for (int i = 1; i <= n; i++) a[i] = std::lower_bound(d + 1, d + 1 + dlen, a[i]) - d;
    for (int i = 1; i <= n; i++)
        a1[i] = sm.query(1, 1, n, 1, a[i] - 1), sm.modify(1, 1, n, a[i]);
    for (int i = n; i; i--)
        b1[i] = bg.query(1, 1, n, a[i] + 1, n), bg.modify(1, 1, n, a[i]);
    for (int i = 1; i <= n; i++){
        // printf("a1 = %lld, b1 = %lld\n", a1[i], b1[i]);
        ans += a1[i] * b1[i];
    }
    printf("%lld\n", ans);
    return 0;
}