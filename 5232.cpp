#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 2e5 + 5;
int n, p[N], ans[N], d[N];
std::vector<int> st[N];
struct Tree{
    int v[N];
    int lb(int x){return x & -x;}
    void add(int x, int val){
        for (; x <= n; x += lb(x)) v[x] += val;
    }
    int sum(int x){
        int ans = 0;
        for (; x; x -= lb(x)) ans += v[x];
        return ans;
    }
}tree;
void dfs(int u){
    ans[u] -= tree.sum(n) - tree.sum(d[u]);
    for (auto v : st[u]) dfs(v);
    ans[u] += tree.sum(n) - tree.sum(d[u]);
    tree.add(d[u], 1);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i), d[i] = p[i];
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) d[i] = std::lower_bound(p + 1, p + 1 + n, d[i]) - p;
    for (int i = 2, fa; i <= n; i++){
        scanf("%d", &fa);
        st[fa].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}