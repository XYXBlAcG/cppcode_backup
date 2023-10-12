#include <bits/stdc++.h>
using std::vector;

#define For(i, _beg, _end) for (int i = (_beg), i##end = (_end); i <= i##end; ++i)
#define Rep(i, _beg, _end) for (int i = (_beg), i##end = (_end); i >= i##end; --i)

template <typename T>
T Max(const T &x, const T &y)
{
    return x < y ? y : x;
}
template <typename T>
T Min(const T &x, const T &y) { return x < y ? x : y; }
template <typename T>
int chkmax(T &x, const T &y) { return x < y ? (x = y, 1) : 0; }
template <typename T>
int chkmin(T &x, const T &y) { return x > y ? (x = y, 1) : 0; }
template <typename T>
void read(T &x)
{
    T f = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = -1;
    for (x = 0; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    x *= f;
}

const int maxn = 200010;
struct edge
{
    int to, nxt;
} e[maxn];
struct Query
{
    int op, t, x, res;
    bool operator<(const Query &b) const { return t < b.t; }
} q[maxn], ql[maxn], qr[maxn];
int n, m, num, head[maxn], c[maxn];
int fa[maxn], top[maxn], size[maxn], son[maxn], dep[maxn];
int A[maxn], B[maxn], C[maxn], tL[maxn], tR[maxn], dfn, mx;

void add(int, int);
int qry(int);
int qry(int, int);
void addedge(int, int);
void Dfs1(int, int);
void Dfs2(int, int);
int lca(int, int);
void Solve(int, int, int, int);
void modify(int, int, int);

int main()
{
    read(n);
    read(m);
    For(i, 1, n - 1)
    {
        int u, v;
        read(u);
        read(v);
        addedge(u, v);
    }
    Dfs1(1, 0);
    for (int i = 1; i <= n; i++){
        printf("l = %d, r = %d\n", tL[i], tR[i]);
    }
    Dfs2(1, 1);
    For(i, 1, m)
    {
        read(q[i].op);
        q[i].t = i;
        if (!q[i].op)
        {
            read(A[i]);
            read(B[i]);
            read(C[i]);
            q[i].x = i;
            chkmax(mx, C[i]);
        }
        else
            read(q[i].x);
    }
    Solve(-1, mx, 1, m);
    std::sort(q + 1, q + m + 1);
    For(i, 1, m) if (q[i].op == 2) printf("%d\n", q[i].res);
    return 0;
}

void Solve(int l, int r, int L, int R)
{
    if (l == r)
    {
        For(i, L, R) if (q[i].op == 2) q[i].res = l, printf("i = %d, res = %d\n", i, q[i].res);
        return;
    }
    int mid = (l + r) >> 1, path = 0, cntl = 0, cntr = 0;
    For(i, L, R)
    {
        if (q[i].op == 2)
        {
            if (qry(tL[q[i].x], tR[q[i].x]) == path)
                ql[++cntl] = q[i];
            else
                qr[++cntr] = q[i];
        }
        else
        {
            if (C[q[i].x] <= mid)
                ql[++cntl] = q[i];
            else
            {
                int v = q[i].op ? -1 : 1;
                path += v;
                modify(A[q[i].x], B[q[i].x], v);
                qr[++cntr] = q[i];
            }
        }
    }
    For(i, 1, cntr) 
    // For(i, L, R)
    if (qr[i].op != 2)
    {
        int v = qr[i].op ? 1 : -1;
        modify(A[qr[i].x], B[qr[i].x], v);
    }
    For(i, 1, cntl) q[L + i - 1] = ql[i];
    For(i, 1, cntr) q[L + cntl + i - 1] = qr[i];
    if (cntl)
        Solve(l, mid, L, L + cntl - 1);
    if (cntr)
        Solve(mid + 1, r, L + cntl, R);
}
void modify(int x, int y, int v)
{
    // printf("u = %d, v = %d\n", x, y);
    int z = lca(x, y);
    printf("u = %d, v = %d, lc = %d\n", x, y, z);
    add(tL[x], v);
    add(tL[y], v);
    add(tL[z], -v);
    if (fa[z])
        add(tL[fa[z]], -v);
}
void Dfs1(int x, int f)
{
    dep[x] = dep[fa[x] = f] + 1;
    size[x] = 1;
    tL[x] = ++dfn;
    for (int i = head[x]; i; i = e[i].nxt)
        if (e[i].to != f)
        {
            Dfs1(e[i].to, x);
            size[x] += size[e[i].to];
            if (size[e[i].to] > size[son[x]])
                son[x] = e[i].to;
        }
    tR[x] = dfn;
}
void Dfs2(int x, int tp)
{
    top[x] = tp;
    if (son[x])
        Dfs2(son[x], tp);
    for (int i = head[x]; i; i = e[i].nxt)
        if (e[i].to != fa[x] && e[i].to != son[x])
            Dfs2(e[i].to, e[i].to);
}
int lca(int u, int v)
{
    int x = top[u], y = top[v];
    while (x != y)
    {
        if (dep[x] > dep[y])
            x = top[u = fa[x]];
        else
            y = top[v = fa[y]];
    }
    return dep[u] < dep[v] ? u : v;
}
void addedge(int u, int v)
{
    e[++num].to = v;
    e[num].nxt = head[u];
    head[u] = num;
    e[++num].to = u;
    e[num].nxt = head[v];
    head[v] = num;
}
void add(int x, int v)
{
    for (; x <= n; x += x & -x)
        c[x] += v;
}
int qry(int x)
{
    int res = 0;
    for (; x; x -= x & -x)
        res += c[x];
    return res;
}
int qry(int l, int r) { return qry(r) - qry(l - 1); }
