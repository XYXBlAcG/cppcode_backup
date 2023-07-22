#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline int read() {
    bool sym = false; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

const int N = 5e5 + 10;
int fa[N], head[N], cnt, head_query[N], cnt_query, ans[N];

bool vis[N];

struct Edge {
    // 链式前向星
    int to, next, num;
} edge[N << 1], query[N << 1];

void addedge(int u, int v) {
    // 链式前向星加边
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void add_query(int x, int y, int num) {
    query[++cnt_query].to = y;
    query[cnt_query].num = num;
    query[cnt_query].next = head_query[x];
    head_query[x] = cnt_query;
}

int find(int x) {
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

void tarjan(int x) {
    vis[x] = true;
    for (int i = head[x]; i; i = edge[i].next) {
        int y = edge[i].to;
        if (!vis[y]) {
            tarjan(y);
            fa[y] = x;
        }
    }
    for (int i = head_query[x]; i; i = query[i].next) {
        int y = query[i].to;
        if (vis[y]) {
            ans[query[i].num] = find(y);
        }
    }
}

int main() {
    std::memset(vis, false, sizeof(vis));
    int n = read(), m = read(), root = read();
    for (int i = 1; i < n; i++) {
        fa[i] = i;
        int u = read(), v = read();
        addedge(u, v), addedge(v, u);
    }
    fa[n] = n;
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        add_query(x, y, i);
        add_query(y, x, i);
    }
    tarjan(root);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}