#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read()
{
    LL x = 0, f = 1;
    char c = getchar();
    while (c != EOF && !isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void write(LL x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(LL x) { write(x), putchar('\n'); }

const int N = 100005, M = 200005, E = M * 4;
int To[E], Ne[E], He1[N], He2[N << 1], k;
inline void add(int *He, int x, int y)
{
    ++k;
    To[k] = y, Ne[k] = He[x], He[x] = k;
    ++k;
    To[k] = x, Ne[k] = He[y], He[y] = k;
}

int n, m, tot, deg[N << 1];
int dfn[N], low[N], st[N], top, Tim;
void tarjan(int x)
{
    dfn[x] = low[x] = ++Tim, st[++top] = x;
    for (int y, p = He1[x]; p; p = Ne[p])
    {
        y = To[p];
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x])
            {
                ++tot;
                add(He2, tot, x);
                add(He2, tot, y);
                ++deg[x], ++deg[y], deg[tot] += 2;
                while (st[top] ^ y)
                    add(He2, st[top], tot), ++deg[tot], ++deg[st[top]], --top;
                --top;
            }
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
}

int size1[N << 1], size2[N << 1], fa[N << 1];
void dfs1(int x)
{
    size1[x] = x <= n;
    for (int p = He2[x]; p; p = Ne[p]){
        if (To[p] ^ fa[x]){
            printf("%d -> %d\n", x, To[p]);
            fa[To[p]] = x, dfs1(To[p]), size1[x] += size1[To[p]];
        }
    }
    // printf("u = %d, sz = %d\n", x, size1[x]);
}
LL ans, ret;
void dfs2(int x)
{
    if (fa[x])
        size2[x] = size2[fa[x]] + size1[fa[x]] - size1[x];
    for (int y, p = He2[x]; p; p = Ne[p])
        if ((y = To[p]) ^ fa[x])
            dfs2(To[p]);
    int sum = size2[x] + size1[x];
    printf("sz = %d, sz2 = %d, sum = %d\n", size1[x], size2[x], sum);
    ret = 0;
    if (x <= n)
    {
        for (int y, p = He2[x]; p; p = Ne[p])
            if ((y = To[p]) ^ fa[x])
            {
                ans += (LL)(sum - size1[y] - 1) * size1[y];
            }
        ans += (LL)(sum - size2[x] - 1) * size2[x];
        printf("u = %d, ans = %lld\n", x, ans);
    }
    else
    {
        printf("%d %d\n", x, deg[x]);
        for (int y, p = He2[x]; p; p = Ne[p])
            if ((y = To[p]) ^ fa[x])
            {
                ans += (LL)(sum - size1[y]) * size1[y] * (deg[x] - 2);
                printf("res = %lld\n", (LL)(sum - size1[y]) * size1[y] * (deg[x] - 2));
            }
        ans += (LL)(sum - size2[x]) * size2[x] * (deg[x] - 2);
        printf("u = %d, ans = %lld\n", x, ans);
    }
}

int main()
{
    int i, u, v;
    tot = n = read(), m = read();
    while (m--)
        u = read(), v = read(), add(He1, u, v);
    for (i = 1; i <= n; ++i)
        if (!dfn[i])
            top = 0, tarjan(i);
    for (i = 1; i <= tot; ++i)
        if (!size1[i])
            dfs1(i);
    for (i = 1; i <= tot; ++i)
        if (!size2[i])
            dfs2(i);
    writeln(ans);
    return 0;
}
