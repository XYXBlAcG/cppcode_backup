#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

inline int read(void) {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return f * x;
}

const int maxn = 1e5 + 5;

int T, n, head[maxn], tot, top, deg[maxn];
bool vis[maxn];

pair<int, int>pa[maxn];

struct Edge {
    int y, next;
    bool tag;
    Edge() {}
    Edge(int _y, int _next, bool _tag) : y(_y), next(_next), tag(_tag) {}
}e[maxn << 1];

struct Opt{
    int x1, y1, x2, y2;
}opt[maxn];

inline void connect(int x, int y) {
    e[++ tot] = Edge(y, head[x], 1);
    head[x] = tot;
}

void dfs(int x, int fa) {
    int pos = 0;
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].y;
        if (y == fa) { pos = i; continue; }
        dfs(y, x);
    }
    int cnt = 0;
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].y;
        if (y == fa || !e[i].tag) continue;
        ++ cnt;
    }
    if (cnt <= 1) return;
    if (cnt == 2) {
        if (!fa) return;
        e[pos].tag = e[pos ^ 1].tag = false;
        opt[++ top].x1 = x; opt[top].y1 = fa;
        -- deg[x]; -- deg[fa];
        return;
    }

    if (fa) {
        e[pos].tag = e[pos ^ 1].tag = false;
        opt[++ top].x1 = x; opt[top].y1 = fa;
        -- deg[x]; -- deg[fa];
    }
    int tmp = 0;
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].y;
        if (y == fa || !e[i].tag) continue;
        ++ tmp;
        if (tmp <= cnt - 2) {
            e[i].tag = e[i ^ 1].tag = false;
            opt[++ top].x1 = x; opt[top].y1 = y;
            -- deg[x];
            -- deg[y];
        }
    }
}

void dfs2(int x, int fa, int &to) {
    int cnt = 0;
    vis[x] = true;
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].y;
        if (y == fa || !e[i].tag) continue;
        dfs2(y, x, to);
        ++ cnt;
    }
    if (!cnt) to = x;
}

int main() {
    T = 1;
    while (T --) {
        tot = 1;
        memset(head, 0, sizeof head);
        memset(deg, 0, sizeof deg);
        memset(vis, false, sizeof vis);

        n = read();
        for (int i = 1; i < n; ++ i) {
            int a = read(), b = read();
            connect(a, b); connect(b, a);
            ++ deg[a]; ++ deg[b];
        }
        top = 0;
        dfs(1, 0);
        printf("%d\n", top);

        top = 0;
        for (int x = 1; x <= n; ++ x) {
            if (deg[x] == 0 && !vis[x]) {
                vis[x] = true;
                pa[++ top] = make_pair(x, x);
            }
            if (deg[x] == 1 && !vis[x]) {
                int y = 0;
                dfs2(x, 0, y);
                pa[++ top] = make_pair(x, y);
            }
        }
        -- top;
        for (int i = 1; i <= top; ++ i) {
            opt[i].x2 = pa[i].second;
            opt[i].y2 = pa[i + 1].first;
            printf("%d %d %d %d\n", opt[i].x1, opt[i].y1, opt[i].x2, opt[i].y2);
        }
    }
    return 0;
}

