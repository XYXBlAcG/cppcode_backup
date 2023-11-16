#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
const int N = 1e5 + 5;
int n, q, r[N], c[N], cntr[N], cntc[N];
struct Pos{
    int x, y;
}s, t;
bool solve(){
    return (cntr[s.x] == cntr[t.x] && cntc[s.y] == cntc[t.y]);
}
int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", r + i);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    cntr[1] = 1, cntc[1] = 1;
    for (int i = 2; i <= n; i++){
        if((r[i] & 1) == (r[i - 1] & 1)) cntr[i] = cntr[i - 1];
        else cntr[i] = cntr[i - 1] + 1;
        if((c[i] & 1) == (c[i - 1] & 1)) cntc[i] = cntc[i - 1];
        else cntc[i] = cntc[i - 1] + 1;
    }
    for (int i = 1; i <= q; i++){
        scanf("%d%d%d%d", &s.x, &s.y, &t.x, &t.y);
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}