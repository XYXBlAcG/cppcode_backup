#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using std::priority_queue;
using std::vector;
vector<int> ans[300011];
typedef long long ll;
int n, k, cnt, head[3000011], pedge, st[3000011];
struct Node
{
    ll len;
    int dep, id;
} node[3000011];
struct Edge
{
    int ver, nxt, w;
} edge[3000011];
void add_edge(int u, int v, int w)
{
    edge[++pedge] = {v, head[u], w};
    head[u] = pedge;
}
bool operator<(Node a, Node b)
{
    if (a.len != b.len)
        return a.len > b.len;
    return a.dep > b.dep;
}
priority_queue<Node> tree;
void dfs(int x, int dep)
{
    if (!head[x])
    {
        ans[x].resize(dep - 1);
        for (int i = 1; i <= dep - 1; i++)
        {
            ans[x][i - 1] = st[i];
        }
    }
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        st[dep] = edge[i].w;
        dfs(edge[i].ver, dep + 1);
    }
}
inline long long read()
{
    long long num = 0, f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
    {
        if (c == '-')
            f = -1;
    }
    for (; c >= '0' && c <= '9'; c = getchar())
    {
        num = num * 10 + c - '0';
    }
    return num * f;
}
int F[20];
inline void print(int x)
{
    if (!x)
    {
        putchar('0');
        putchar(' ');
        return;
    }
    int cnt = 0;
    while (x > 0)
    {
        F[cnt++] = x % 10 + '0';
        x /= 10;
    }
    while (cnt > 0)
        putchar(F[--cnt]);
    putchar(' ');
    return;
}
int main()
{
    scanf("%d%d", &n, &k);
    int p = n;
    ll a;
    for (int i = 1; i <= n; i++)
    {
        a = read();
        tree.push({a, 1, i});
    }
    if ((n - 1) % (k - 1))
        cnt = k - 1 - (n - 1) % (k - 1);
    for (int i = 1; i <= cnt; i++)
    {
        tree.push({0, 1, 0});
    }
    cnt += n;
    a = 0;
    while (cnt > 1)
    {
        ll tmp = 0;
        int maxh = 0;
        p++;
        for (int i = 1; i <= k; i++)
        {
            tmp += tree.top().len;
            add_edge(p, tree.top().id, i - 1);
            maxh = std::max(maxh, tree.top().dep);
            tree.pop();
        }
        // a += tmp;
        tree.push({tmp, maxh, p});
        cnt -= k - 1;
    }
    dfs(p, 1);
    for (int i = 1; i <= n; i++)
    {
        printf("%llu ", ans[i].size());
        for (int j = 0, k = ans[i].size(); j < k; j++)
        {
            print(ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}