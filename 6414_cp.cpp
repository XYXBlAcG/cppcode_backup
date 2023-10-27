#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1000 + 5, K = 20 + 5;
const int inf = 0x7fffffff;
template <class T>
inline void read(T &num)
{
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    num = ch - '0';
    while (isdigit(ch = getchar()))
        num = num * 10 + ch - '0';
}
int head[N << 1], to[N * N << 1], nex[N * N << 1], val[N * N << 1], tot = 1, n, k, dep[N << 1], s, t, m;

inline void add_edge(const int x, const int y, const int w)
{
    to[++tot] = y, nex[tot] = head[x], head[x] = tot, val[tot] = w;
}

inline void Add_edge(const int x, const int y, const int w)
{
    // printf("%d --> %d ( %d )\n",x,y,w);
    add_edge(x, y, w);
    add_edge(y, x, 0);
}

queue<int> que;
bool bfs()
{
    memset(dep, 0, sizeof(dep));
    dep[s] = 1;
    while (que.size())
        que.pop();
    que.push(s);
    int x;
    while (que.size())
    {
        x = que.front();
        que.pop();
        for (int i = head[x]; i; i = nex[i])
        {
            int y = to[i];
            if (val[i] && !dep[y])
            {
                dep[y] = dep[x] + 1;
                if (y == t)
                    return true;
                que.push(y);
            }
        }
    }
    return false;
}

int dfs(const int x, const int flow)
{
    // printf("dfs(%d,%d) %d\n",x,flow,x==t);
    if (x == t)
        return flow;
    int rest = flow, k;
    for (int i = head[x]; i && rest; i = nex[i])
    {
        int y = to[i];
        if (val[i] && dep[y] == dep[x] + 1)
        {
            k = dfs(y, min(rest, val[i]));
            if (k)
            {
                val[i] -= k;
                val[i ^ 1] += k;
                rest -= k;
            }
            else
                dep[y] = 0;
        }
    }
    // printf("\t%d x=%d,return %d\n",x==s,x,flow-rest);
    return flow - rest;
}

int dinic()
{
    int maxflow = 0, flow;
    while (bfs())
        while (flow = dfs(s, inf))
            maxflow += flow;
    // printf("return %d\n",maxflow);
    return maxflow;
}

inline void print(const int x)
{
    for (int i = head[x]; i; i = nex[i])
    {
        int y = to[i];
        // printf("\ny=%d\n",y);
        if (val[i] && y <= n)
        {
            printf(" %d", y);
        }
    }
}

int main()
{
    read(k), read(n);
    s = n + k + 1;
    t = s + 1;
    for (int i = 1, w; i <= k; ++i)
    {
        read(w);
        m += w;
        Add_edge(n + i, t, w);
    }
    for (int i = 1, b, h; i <= n; ++i)
    {
        Add_edge(s, i, 1);
        read(h);
        for (int j = 1; j <= h; ++j)
        {
            read(b);
            Add_edge(i, b + n, 1);
        }
    }
    if (dinic() == m)
    {
        for (int i = 1; i <= k; ++i)
        {
            printf("%d:", i);
            print(n + i);
            putchar('\n');
        }
    }
    else
    {
        printf("No Solution!\n");
    }
    return 0;
}
