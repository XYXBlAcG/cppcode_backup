#include <bits/stdc++.h>

using namespace std;

#define ris(i, a, b) for (int i = a; i <= b; ++i)

const int N = 100011, Lg = 27;

int n, m;
vector<int> e[N];
int dfn[N], pdfn, low[N], vis[N];
stack<int> st;
int pscc = 1, scc[N], f[N][Lg], pre[N], d[N], cnt[N];
vector<int> e2[N];
queue<int> que;
int dep[N], siz[N];
vector<int> t[N];

int dfs(int u) {
    dfn[u] = low[u] = ++pdfn, vis[u] = 1, st.push(u);
    for (int v : e[u]) {
        if (!dfn[v])
            low[u] = min(low[u], dfs(v));
        else if (vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        pscc++;
        while (vis[u]) {
            int top = st.top();
            st.pop(), vis[top] = 0, scc[top] = pscc, cnt[pscc]++;
        }
    }
    return low[u];
}

int lca(int u, int v) {
    if (!u || !v)
        return u | v;
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 16; i >= 0; --i)
        if (dep[f[u][i]] > dep[v])
            u = f[u][i];
    if (dep[u] > dep[v])
        u = pre[u];
    for (int i = 16; i >= 0; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return u == v ? u : pre[u];
}

int dfs1(int u) {
    siz[u] = cnt[u];
    for (int v : t[u]) siz[u] += dfs1(v);
    return siz[u];
}

int main() {
    freopen("defense.in", "r", stdin), freopen("defense.out", "w", stdout), scanf("%d%d", &n, &m);
    ris(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v), e[u].emplace_back(v);
    }
    ris(i, 1, n) if (!dfn[i]) dfs(i);
    ris(u, 1, n) for (int v : e[u]) if (scc[u] != scc[v]) e2[scc[v]].emplace_back(scc[u]), d[scc[u]]++;
    ris(i, 2, pscc) if (!d[i]) que.push(i);
    while (!que.empty()) {
        int u = que.front();
        f[u][0] = pre[u] = pre[u] ? pre[u] : 1, dep[u] = dep[pre[u]] + 1;
        ris(i, 1, 16) f[u][i] = f[f[u][i - 1]][i - 1];
        for (int v : e2[u]) {
            d[v]--, pre[v] = lca(pre[v], u);
            if (!d[v])
                que.push(v);
        }
        que.pop();
    }
    ris(i, 2, pscc) t[pre[i]].emplace_back(i);
    dfs1(1);
    ris(i, 1, n) printf("%d\n", siz[scc[i]]);
    return 0;
}