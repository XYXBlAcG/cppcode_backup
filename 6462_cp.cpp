#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
const int inf = 1 << 30;
int Read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return f == 1 ? x : -x;
}
int maxflow = 0;
int mincost = 0;
int realflow = 0;
int n, m;
int top = 1, head[101010], inque[101010];
int s, t;
int dist[101010];
struct Node
{
    int v;
    int val;
    int next;
    int cost;
} node[101010];
void addedge(int u, int v, int val, int cost)
{
    node[++top].v = v;
    node[top].val = val;
    node[top].cost = cost;
    node[top].next = head[u];
    head[u] = top;
} // 加边函数
void add(int u, int v, int val, int cost)
{
    printf("%d <-> %d, %d\n", u, v, cost);
    addedge(u, v, val, cost);
    addedge(v, u, 0, -cost);
} // 网络流的加边，正向和反向
bool spfa()
{
    memset(inque, 0, sizeof(inque));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    inque[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inque[u] = 0;
        for (int i = head[u]; i; i = node[i].next)
        {
            int d = node[i].v;
            if (dist[d] > dist[u] + node[i].cost && node[i].val)
            {
                dist[d] = dist[u] + node[i].cost;
                if (inque[d] == 0)
                {
                    q.push(d);
                    inque[d] = 1;
                }
            }
        }
    }
    return dist[t] != 0x3f3f3f3f;
}
inline int min(int x, int y)
{
    return x < y ? x : y;
}
int dfs(int u, int low)
{
    if (u == t)
    {
        inque[t] = 1;
        maxflow += low;
        return low;
    }
    int used = 0;
    inque[u] = 1;
    for (int i = head[u]; i; i = node[i].next)
    {
        int d = node[i].v;
        if ((inque[d] == 0 || d == t) && node[i].val != 0 && dist[d] == dist[u] + node[i].cost)
        {
            int minflow = dfs(d, min(low - used, node[i].val));
            if (minflow != 0)
                mincost += node[i].cost * minflow, node[i].val -= minflow, node[i ^ 1].val += minflow, used += minflow;

            if (used == low)
                break;
        }
    }
    return used;
}
int Dinic()
{
    while (spfa())
    {
        inque[t] = 1;
        while (inque[t])
        {
            memset(inque, 0, sizeof(inque));
            dfs(s, inf);
        }
    }
    return maxflow;
}
inline bool check(int i, int j)
{
    return i > 0 && i <= n && j > 0 && j <= m;
} // 判断(i,j)是否需要加节点
inline int up(int i, int j)
{
    return 4 * ((i - 1) * m + j);
} //(i,j)的上节点
inline int down(int i, int j)
{
    return 4 * ((i - 1) * m + j) + 1;
} //(i,j)的下节点
inline int left(int i, int j)
{
    return 4 * ((i - 1) * m + j) + 2;
} //(i,j)的左节点
inline int right(int i, int j)
{
    return 4 * ((i - 1) * m + j) + 3;
} //(i,j)的右节点
int main()
{
    // freopen("cin.txt","r",stdin);
    s = 10010, t = 10001;
    n = Read(), m = Read();
    int i, j;
    int map, colur;
    colur = 0;
    for (i = 1; i <= n; i++)
    {
        colur = i % 2;
        for (j = 1; j <= m; j++)
        {
            map = Read();
            colur ^= 1;
            puts("--------");
            
            if (colur == 0)
            {
                if (check(i, j - 1))
                    add(left(i, j), right(i, j - 1), 1, 0);
                if (check(i, j + 1))
                    add(right(i, j), left(i, j + 1), 1, 0);
                if (check(i - 1, j))
                    add(up(i, j), down(i - 1, j), 1, 0);
                if (check(i + 1, j))
                    add(down(i, j), up(i + 1, j), 1, 0);
            } // 白色点四周与附近的黑色点四周相连
            printf("map = %d\n", map);
            if (map == 1)
            { // 0001
                realflow++;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(up(i, j), right(i, j), 1, 1); // 向右流要转一次，代价为1
                    add(up(i, j), left(i, j), 1, 1);  // 向左代价为1
                    add(up(i, j), down(i, j), 1, 2);  // 向下代价为2
                }                                     // 白色点s向四周流
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(right(i, j), up(i, j), 1, 1);
                    add(left(i, j), up(i, j), 1, 1);
                    add(down(i, j), up(i, j), 1, 2);
                } // 黑色点四周向t流
                continue;
            }
            if (map == 2)
            { // 0010
                realflow++;
                if (colur == 0)
                {
                    add(s, right(i, j), 1, 0);
                    add(right(i, j), up(i, j), 1, 1);
                    add(right(i, j), down(i, j), 1, 1);
                    add(right(i, j), left(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(right(i, j), t, 1, 0);
                    add(up(i, j), right(i, j), 1, 1);
                    add(down(i, j), right(i, j), 1, 1);
                    add(left(i, j), right(i, j), 1, 2);
                }
                continue;
            }
            if (map == 3)
            { // 0011
                realflow += 2;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, right(i, j), 1, 0);
                    add(up(i, j), down(i, j), 1, 1);
                    add(right(i, j), left(i, j), 1, 1);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(right(i, j), t, 1, 0);
                    add(down(i, j), up(i, j), 1, 1);
                    add(left(i, j), right(i, j), 1, 1);
                }
                continue;
            }
            if (map == 4)
            { // 0100
                realflow++;
                if (colur == 0)
                {
                    add(s, down(i, j), 1, 0);
                    add(down(i, j), right(i, j), 1, 1);
                    add(down(i, j), left(i, j), 1, 1);
                    add(down(i, j), up(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(down(i, j), t, 1, 0);
                    add(right(i, j), down(i, j), 1, 1);
                    add(left(i, j), down(i, j), 1, 1);
                    add(up(i, j), down(i, j), 1, 2);
                }
                continue;
            }
            if (map == 5)
            { // 0101
                realflow += 2;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                }
            } // 直线型不可旋转
            if (map == 6)
            { // 0110
                realflow += 2;
                if (colur == 0)
                {
                    add(s, right(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                    add(right(i, j), left(i, j), 1, 1);
                    add(down(i, j), up(i, j), 1, 1);
                }
                if (colur == 1)
                {
                    add(right(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                    add(left(i, j), right(i, j), 1, 1);
                    add(up(i, j), down(i, j), 1, 1);
                }
            }
            if (map == 7)
            { // 0111
                realflow += 3;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, right(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                    add(up(i, j), left(i, j), 1, 1);
                    add(down(i, j), left(i, j), 1, 1);
                    add(right(i, j), left(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(right(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                    add(left(i, j), up(i, j), 1, 1);
                    add(left(i, j), down(i, j), 1, 1);
                    add(left(i, j), right(i, j), 1, 2);
                }
            }
            if (map == 8)
            { // 1000
                realflow++;
                if (colur == 0)
                {
                    add(s, left(i, j), 1, 0);
                    add(left(i, j), up(i, j), 1, 1);
                    add(left(i, j), down(i, j), 1, 1);
                    add(left(i, j), right(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(left(i, j), t, 1, 0);
                    add(up(i, j), left(i, j), 1, 1);
                    add(down(i, j), left(i, j), 1, 1);
                    add(right(i, j), left(i, j), 1, 2);
                }
            }
            if (map == 9)
            { // 1001
                realflow += 2;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, left(i, j), 1, 0);
                    add(up(i, j), down(i, j), 1, 1);
                    add(left(i, j), right(i, j), 1, 1);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(left(i, j), t, 1, 0);
                    add(down(i, j), up(i, j), 1, 1);
                    add(right(i, j), left(i, j), 1, 1);
                }
            }
            if (map == 10)
            { // 1010
                realflow += 2;
                if (colur == 0)
                {
                    add(s, left(i, j), 1, 0);
                    add(s, right(i, j), 1, 0);
                }
                if (colur == 1)
                {
                    add(left(i, j), t, 1, 0);
                    add(right(i, j), t, 1, 0);
                }
                continue; // 直线型
            }
            if (map == 11)
            { // 1011
                realflow += 3;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, left(i, j), 1, 0);
                    add(s, right(i, j), 1, 0);
                    add(left(i, j), down(i, j), 1, 1);
                    add(right(i, j), down(i, j), 1, 1);
                    add(up(i, j), down(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(left(i, j), t, 1, 0);
                    add(right(i, j), t, 1, 0);
                    add(down(i, j), left(i, j), 1, 1);
                    add(down(i, j), right(i, j), 1, 1);
                    add(down(i, j), up(i, j), 1, 2);
                }
            }
            if (map == 12)
            { // 1100
                realflow += 2;
                if (colur == 0)
                {
                    add(s, left(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                    add(left(i, j), right(i, j), 1, 1);
                    add(down(i, j), up(i, j), 1, 1);
                }
                if (colur == 1)
                {
                    add(left(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                    add(right(i, j), left(i, j), 1, 1);
                    add(up(i, j), down(i, j), 1, 1);
                }
            }
            if (map == 13)
            { // 1101
                realflow += 3;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                    add(s, left(i, j), 1, 0);
                    add(up(i, j), right(i, j), 1, 1);
                    add(down(i, j), right(i, j), 1, 1);
                    add(left(i, j), right(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                    add(left(i, j), t, 1, 0);
                    add(right(i, j), up(i, j), 1, 1);
                    add(right(i, j), down(i, j), 1, 1);
                    add(right(i, j), left(i, j), 1, 2);
                }
            }
            if (map == 14)
            { // 1110
                realflow += 3;
                if (colur == 0)
                {
                    add(s, left(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                    add(s, right(i, j), 1, 0);
                    add(left(i, j), up(i, j), 1, 1);
                    add(right(i, j), up(i, j), 1, 1);
                    add(down(i, j), up(i, j), 1, 2);
                }
                if (colur == 1)
                {
                    add(left(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                    add(right(i, j), t, 1, 0);
                    add(up(i, j), left(i, j), 1, 1);
                    add(up(i, j), right(i, j), 1, 1);
                    add(up(i, j), down(i, j), 1, 2);
                }
            }
            if (map == 15)
            { // 1111
                realflow += 4;
                if (colur == 0)
                {
                    add(s, up(i, j), 1, 0);
                    add(s, right(i, j), 1, 0);
                    add(s, left(i, j), 1, 0);
                    add(s, down(i, j), 1, 0);
                }
                if (colur == 1)
                {
                    add(up(i, j), t, 1, 0);
                    add(down(i, j), t, 1, 0);
                    add(left(i, j), t, 1, 0);
                    add(right(i, j), t, 1, 0);
                }
            }
        }
    }
    Dinic();
    printf("flow = %d\n", maxflow);
    if (maxflow * 2 != realflow)
        printf("-1");
    else
        printf("%d", mincost);
    return 0;
}
