#include <bits/stdc++.h>
#include "xyx.h"
using namespace std;

#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define _Rep(i, a, b) for (int i = a; i >= b; i--)
#define RepG(i, u) for (int i = head[u]; ~i; i = e[i].next)

typedef long long ll;

const int N = 1e5 + 5;

template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + c - '0';
    x *= f;
}

typedef unsigned int ull;
const int base = 29;

int n, m;
char s[N];
int son[N][2], siz[N], val[N], treap[N];
ull haxi[N], poww[N];
int rt, tot;

int newnode(int value)
{
    int u = ++tot;
    siz[u] = 1, treap[u] = rand();
    haxi[u] = val[u] = value;
    return u;
}

void update(int x)
{
    siz[x] = siz[son[x][0]] + siz[son[x][1]] + 1;
    haxi[x] = haxi[son[x][0]] * poww[siz[son[x][1]] + 1] + val[x] * poww[siz[son[x][1]]] + haxi[son[x][1]];
}

int merge(int u, int v)
{
    if (!u || !v)
        return u | v;
    int rt;
    if (treap[u] < treap[v])
        son[rt = u][1] = merge(son[u][1], v);
    else
        son[rt = v][0] = merge(u, son[v][0]);
    return update(rt), rt;
}

void split(int o, int &u, int &v, int k)
{
    if (!o)
    {
        u = v = 0;
        return;
    }
    int rank = siz[son[o][0]] + 1;
    if (rank <= k)
        split(son[u = o][1], son[o][1], v, k - rank);
    else
        split(son[v = o][0], u, son[o][0], k);
    update(o);
}

ull gethash(int l, int r)
{
    int x, y, z;
    split(rt, x, z, r);
    split(x, x, y, l - 1);
    ull res = haxi[y];
    rt = merge(merge(x, y), z);
    return res;
}
 
void dfs(int u){
    if(son[u][0]) dfs(son[u][0]);
    xyx::output(10, son[u][0], "<--", u, "-->", son[u][1]);
    if(son[u][1]) dfs(son[u][1]);
}

int main()
{
    srand(19260817);
    poww[0] = 1;
    Rep(i, 1, 1e5) poww[i] = poww[i - 1] * base;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    Rep(i, 1, n) rt = merge(rt, newnode(s[i] - 'a'));
    read(m);
    Rep(i, 1, m)
    {
        char opt[10];
        scanf("%s", opt);
        if (opt[0] == 'Q')
        {
            int x, y;
            read(x), read(y);
            if (x > y)
                swap(x, y);
            int l = 1, r = siz[rt] - y + 1, res = 0;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (gethash(x, x + mid - 1) == gethash(y, y + mid - 1))
                    res = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            printf("%d\n", res);
        }
        if (opt[0] == 'R')
        {
            int x, y, z;
            read(x);
            char ch;
            cin >> ch;
            int pos = x, value = ch - 'a';
            split(rt, x, z, pos);
            split(x, x, y, pos - 1);
            haxi[y] = val[y] = value;
            rt = merge(merge(x, y), z);
        }
        if (opt[0] == 'I')
        {
            int x, y;
            read(x);
            char ch;
            cin >> ch;
            int k = x, val = ch - 'a';
            split(rt, x, y, k);
            rt = merge(merge(x, newnode(val)), y);
        }
        dfs(rt), putchar('\n');
    }
    return 0;
}
