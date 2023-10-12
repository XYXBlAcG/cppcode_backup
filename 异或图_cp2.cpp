#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using std::max;
using std::min;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
#define ls ch[k][0]
#define rs ch[k][1]
int L[N * 40], R[N * 40], ch[N * 40][2], cnt;
int n, a[N], root;
void Insert(int &k, int x, int dep)
{
    if (!k)
        k = ++cnt;
    L[k] = min(L[k], x), R[k] = max(R[k], x);
    if (dep < 0)
        return;
    Insert(ch[k][a[x] >> dep & 1], x, dep - 1);
}
int query(int k, int v, int dep)
{
    if (dep < 0)
        return 0;
    int x = v >> dep & 1;
    if (ch[k][x])
        return query(ch[k][x], v, dep - 1);
    else
        return query(ch[k][x ^ 1], v, dep - 1) + (1 << dep);
}
ll dfs(int k, int dep)
{
    if (dep < 0)
        return 0;
    if (ls && rs)
    {
        int mi = inf;
        for (int i = L[ls]; i <= R[ls]; i++)
            mi = min(mi, query(rs, a[i], dep - 1));
        return dfs(ls, dep - 1) + dfs(rs, dep - 1) + mi + (1 << dep);
    }
    if (ls)
        return dfs(ls, dep - 1);
    if (rs)
        return dfs(rs, dep - 1);
    return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    std::sort(a + 1, a + 1 + n);
    memset(L, 0x3f, sizeof(L));
    for (int i = 1; i <= n; i++)
        Insert(root, i, 30);
    printf("%lld\n", dfs(root, 30));
    return 0;
}
