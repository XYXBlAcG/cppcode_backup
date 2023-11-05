#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, s, t, head[10005], nxt[10005], edge[10005], to[10005], level[10005];
int tot, head2[10005];
int a[2005], b[2005], l[2005], p[2005];
int in[2005], out[2005];
int id[2005];
void add(int u, int v, int w)
{
    to[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
    to[++tot] = u;
    edge[tot] = 0;
    nxt[tot] = head[v];
    head[v] = tot;
}
bool bfs()
{
    memset(level, 0, sizeof(level));
    memcpy(head2, head, sizeof(head2));
    queue<int> q;
    level[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = head[cur]; i; i = nxt[i])
        {
            if (edge[i] && !level[to[i]])
            {
                q.push(to[i]);
                level[to[i]] = level[cur] + 1;
                if (to[i] == t)
                    return 1;
            }
        }
    }
    return 0;
}
int Dinic(int x, int flow)
{
    if (x == t)
        return flow;
    int rest = flow, increase;
    for (int &i = head2[x]; i; i = nxt[i])
    {
        int y = to[i];
        if (edge[i] && level[y] == level[x] + 1)
        {
            increase = Dinic(y, min(rest, edge[i]));
            if (!increase)
                level[y] = 0;
            edge[i] -= increase;
            edge[i ^ 1] += increase;
            rest -= increase;
            if (!rest)
                break;
        }
    }
    return flow - rest;
}
int fa[2005], siz[2005];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unionn(int a, int b)
{
    int x = find(a), y = find(b);
    if (x == y)
        return;
    fa[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
}
bool check(int x)
{
    for (int i = 1; i <= n; ++i)
        in[i] = out[i] = 0, fa[i] = i, siz[i] = 1;
    tot = 1;
    memset(head, 0, sizeof(head));
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        id[i] = 0;
        if (l[i] <= x)
            in[b[i]]++, out[a[i]]++;
        if (p[i] <= x)
            id[i] = tot + 1, add(b[i], a[i], 1);
        if (max(l[i], p[i]) <= x)
            unionn(a[i], b[i]);
    }
    int cntt = 0, cnttt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
        {
            cntt++;
            if (siz[i] == 1)
                cnttt++;
        }
    }
    //	cout << cntt << endl;
    //	if(cntt!=1)return 0;
    s = n + 2, t = n + 1;
    int tmp = 0;
    for (int i = 1; i <= n; ++i)
        if (abs(in[i] - out[i]) & 1)
            return 0;
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] > out[i])
            add(s, i, (in[i] - out[i]) >> 1), cnt += (in[i] - out[i]) / 2;
        if (in[i] < out[i])
            add(i, t, (out[i] - in[i]) >> 1), tmp += (out[i] - in[i]) / 2;
    }
    if (cnt ^ tmp)
        return 0;
    int maxflow = 0;
    while (bfs())
        maxflow += Dinic(s, 1e18);
    //	cout<<"Check: "<<x<<' '<<cnt<<' '<<maxflow<<'\n';
    return maxflow == cnt;
}
int tmpp;
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
int del[2005];
bool vis[2005];
vector<pii> nbr[2005];
stack<int> stk;
void dfs(int cur)
{
    for (int i = del[cur]; i < nbr[cur].size(); i = del[cur])
    {
        del[cur] = i + 1;
        auto x = nbr[cur][i];
        int to = x.fi, Id = x.se;
        if (vis[Id])
            continue;
        vis[Id] = 1;
        dfs(to);
        stk.push(Id);
    }
}
void output(int ans)
{
    check(ans);
    for (int i = 1; i <= m; ++i)
    {
        if (p[i] <= ans)
        {
            if (edge[id[i]] == 0)
                nbr[b[i]].push_back(mp(a[i], i));
            else
                nbr[a[i]].push_back(mp(b[i], i));
        }
        else if (l[i] <= ans)
            nbr[a[i]].push_back(mp(b[i], i));
    }
    dfs(1);
    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();
        cout << cur << ' ';
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int maxn = 0, mini = 1000;
    //	for(int i=1;i<=n;++i)fa[i]=i;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i] >> b[i] >> l[i] >> p[i];
        if (l[i] > p[i])
        {
            swap(l[i], p[i]);
            swap(a[i], b[i]);
        }
        maxn = max(maxn, p[i]), mini = min(mini, l[i]);
    }
    //	for(int i=1;i<=n;++i)if(fa[i]==i)tmpp++;
    //	if(tmpp!=1){
    //		cout<<"NIE";
    //		return 0;
    //	}
    // cout<<"Check: "<<check(174)<<'\n';
    int lt = mini - 1, rt = maxn + 1;
    while (lt + 1 < rt)
    {
        int mid = (lt + rt) >> 1;
        if (check(mid))
            rt = mid;
        else
            lt = mid;
    }
    if (rt == maxn + 1)
    {
        cout << "NIE";
        return 0;
    }
    cout << rt << '\n';
    	output(rt);
    return 0;
}