#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f
#define mdep 30
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
const int N = 2e5 + 5;
int n, a[N], cnt, root, l[N * 32], r[N * 32];
struct Node{
    int l, r, ch[2];
}node[N * 32];
struct Trie{
    void insert(int &k, int x, int dep){
        if(!k) k = ++cnt;
        l[k] = std::min(l[k], x), r[k] = std::max(r[k], x);
        if(dep < 0) return;
        insert(node[k].ch[a[x] >> dep & 1], x, dep - 1);
    }
    int query(int k, int v, int dep){
        if(dep < 0) return 0;
        bool x = v >> dep & 1;
        if(node[k].ch[x]) return query(node[k].ch[x], v, dep - 1);
        else return query(node[k].ch[!x], v, dep - 1) + (1 << dep);
    }
    int dfs(int k, int dep){
        if(dep < 0) return 0;
        if(ls(k) && rs(k)){
            int ans = INF;
            for (int i = l[ls(k)]; i <= r[ls(k)]; i++)
                ans = std::min(ans, query(rs(k), a[i], dep - 1));
            return dfs(ls(k), dep - 1) + dfs(rs(k), dep - 1) + ans + (1 << dep);
        }
        if(ls(k)) return dfs(ls(k), dep - 1);
        if(rs(k)) return dfs(rs(k), dep - 1);
        return 0;
        // ans += (ls(k) ? dfs(ls(k), dep - 1) : 0) + (rs(k) ? dfs(rs(k), dep - 1) : 0);
        // return ans;
    }
}tree;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    std::sort(a + 1, a + 1 + n);
    memset(l, INF, sizeof(l));
    for (int i = 1; i <= n; i++) tree.insert(root, i, mdep);
    printf("%lld\n", tree.dfs(root, mdep));
    return 0;
}