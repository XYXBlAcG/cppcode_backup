#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define nd(u, v) node[u].ch[v]
#define sum(u) node[u].sum
const int N = 12005, up = 60, M = 1005;
int n, m, a[N], ans, cnt, pre[N], rt[N], pos[N], f[M][N], sz;
struct Node{
    int ch[2], sum;
}node[N * M];
struct Trie{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void insert(int& u, int k, int val){
        u = clone(u), sum(u)++;
        if(k < 0) return;
        bool c = (val >> k) & 1;
        insert(nd(u, c), k - 1, val);
    }
    int query(int l, int r, int k, int val){
        if(k < 0) return 0;
        bool c = (val >> k) & 1;
        if(sum(nd(r, !c)) - sum(nd(l, !c)) > 0) return (1 << k) + query(nd(l, !c), nd(r, !c), k - 1, val);
        return query(nd(l, c), nd(r, c), k - 1, val);
    }
}trie;
void init(){
    sz = (int)sqrt(n);
    for (int i = 1; i <= n; i++) pos[i] = (i / sz) + 1;
    for (int i = 1; i <= pos[n]; i++){
        int k = (i - 1) * sz + 1;
        for (int j = k; j <= n; j++){
            if(k > 1) f[i][j] = std::max(f[i][j - 1], trie.query(rt[k - 2], rt[j], up, pre[j]));
            else f[i][j] = std::max(f[i][j - 1], trie.query(0, rt[j], up, pre[j]));
            // printf("f %lld %lld = %lld\n", i, j, f[i][j]);
        }
    }
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), pre[i] = pre[i - 1] ^ a[i];
    trie.insert(rt[0] = ++cnt, up, 0);
    for (int i = 1; i <= n; i++)
        trie.insert(rt[i] = trie.clone(rt[i - 1]), up, pre[i]);
    // for (int i = 1; i <= n; i++) printf("rt %lld = %lld\n", i, rt[i]);
    init();
    for (int i = 1, l, r, x, y; i <= m; i++){
        scanf("%lld%lld", &x, &y);
        l = std::min(((x + ans) % n) + 1, ((y + ans) % n) + 1);
        r = std::max(((x + ans) % n) + 1, ((y + ans) % n) + 1);
        // printf("l = %lld, r = %lld\n", l, r);
        ans = 0;
        if(pos[l] ^ pos[r]) ans = f[pos[l] + 1][r];
        // printf("l = %lld, min = %lld\n", l, std::min(pos[l] * sz, r));
        for (int j = l; j <= std::min(pos[l] * sz, r); j++){
            ans = std::max(ans, trie.query(rt[j - 1], rt[r], up, pre[j - 1]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}