#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

struct qxx
{
    int nex, t, v, c;
};

qxx e[M];
int h[N], cnt = 1, n, m;

void add_path(int f, int t, int v, int c)
{
    e[++cnt] = (qxx){h[f], t, v, c}, h[f] = cnt;
}

void add_flow(int f, int t, int v, int c)
{
    add_path(f, t, v, c);
    add_path(t, f, 0, -c);
}

int dis[N], pre[N], incf[N], s, t;
bool vis[N];

bool spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s), dis[s] = 0, incf[s] = INF, incf[t] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = h[u]; i; i = e[i].nex)
        {
            const int &v = e[i].t, &w = e[i].v, &c = e[i].c;
            if (!w || dis[v] <= dis[u] + c)
                continue;
            dis[v] = dis[u] + c, incf[v] = min(w, incf[u]), pre[v] = i;
            if (!vis[v])
                q.push(v), vis[v] = 1;
        }
    }
    return incf[t];
}

int maxflow, mincost;

void update()
{
    maxflow += incf[t];
    for (int u = t; u != s; u = e[pre[u] ^ 1].t)
    {
        e[pre[u]].v -= incf[t], e[pre[u] ^ 1].v += incf[t];
        mincost += incf[t] * e[pre[u]].c;
    }
}

signed main()
{
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, c, p; i <= m; i++)
    {
        scanf("%lld%lld%lld%lld", &u, &v, &c, &p);
        add_flow(u, v, c, p);
    }
    while (spfa())
        update();
    printf("%lld %lld\n", maxflow, mincost);
    return 0;
}