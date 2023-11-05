#include <cstdio>
#include <algorithm>
#define MAXN 100001
#define LOG 19
#define mxr 100000
using namespace std;
inline int read()
{
    char ch = getchar();
    int s = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = s * 10 + (ch ^ '0'), ch = getchar();
    return s;
}
int head[MAXN], nxt[MAXN * 2], vv[MAXN * 2], tot;
inline void add_edge(int u, int v)
{
    vv[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
int n, m;
#define MAXM MAXN * 80
int tre[MAXM], sum[MAXM], sl[MAXM], sr[MAXM], cnt;
void push_up(int x)
{
    if (sl[x] == 0)
    {
        sum[x] = sum[sr[x]];
        tre[x] = tre[sr[x]];
        return;
    }
    if (sr[x] == 0)
    {
        sum[x] = sum[sl[x]];
        tre[x] = tre[sl[x]];
        return;
    }
    if (sum[sl[x]] >= sum[sr[x]])
    {
        sum[x] = sum[sl[x]];
        tre[x] = tre[sl[x]];
    }
    else
    {
        sum[x] = sum[sr[x]];
        tre[x] = tre[sr[x]];
    }
}
void change(int &x, int l, int r, int pos, int val)
{
    if (x == 0)
        x = ++cnt;
    if (l == r)
    {
        sum[x] += val;
        tre[x] = pos;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        change(sl[x], l, mid, pos, val);
    else
        change(sr[x], mid + 1, r, pos, val);
    push_up(x);
}
int merge(int a, int b, int l, int r)
{
    if (a == 0 || b == 0)
        return a + b;
    if (l == r)
    {
        sum[a] += sum[b];
        return a;
    }
    int mid = (l + r) >> 1;
    sl[a] = merge(sl[a], sl[b], l, mid);
    sr[a] = merge(sr[a], sr[b], mid + 1, r);
    push_up(a);
    return a;
}
int f[MAXN][LOG], dep[MAXN];
void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i < LOG; ++i)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = vv[i];
        if (v == fa)
            continue;
        dfs(v, u);
    }
}
int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = LOG - 1; i >= 0; --i)
        if (dep[f[a][i]] >= dep[b])
            a = f[a][i];
    if (a == b)
        return a;
    for (int i = LOG - 1; i >= 0; --i)
        if (f[a][i] != f[b][i])
            a = f[a][i], b = f[b][i];
    return f[a][0];
}
int rot[MAXN], ans[MAXN];
void calc(int u, int fa)
{
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = vv[i];
        if (v == fa)
            continue;
        calc(v, u);
        rot[u] = merge(rot[u], rot[v], 1, mxr);
    }
    ans[u] = tre[rot[u]];
    if (sum[rot[u]] == 0)
        ans[u] = 0;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        add_edge(a, b);
        add_edge(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; ++i)
    {
        int a = read(), b = read(), x = read();
        int l = lca(a, b);
        change(rot[a], 1, mxr, x, 1);
        change(rot[b], 1, mxr, x, 1);
        change(rot[l], 1, mxr, x, -1);
        change(rot[f[l][0]], 1, mxr, x, -1);
    }
    calc(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
