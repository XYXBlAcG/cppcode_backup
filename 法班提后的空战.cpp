#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
const int N = 3e5 + 5;
typedef long long ll;
int n, m, k, q;
struct Node {
    int v;
    ll w;
};
std::vector<Node> st[N];
std::vector<int> huan;
std::vector<ll> result;
std::map<ll, ll> remain;
int dfn[N], low[N], pdfn, scc[N], pscc, sta[N], psta, mx, mxid, cnt[N], pre[N], suf[N];
int base, dep[N], fath[N], pedge;
ll zheng[N], fan[N], ww[N], finalres;
bool vis[N], dvis[N];
namespace tree {
int fa[N][21], dep1[N], q, d[N], sum[N];
ll fians;
void tdfs(int u, int fath) {
    dep1[u] = dep1[fath] + 1;
    fa[u][0] = fath;
    for (int i = 1; i < 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto v : st[u]) {
        int to = v.v;
        if (to != fath) {
            tdfs(to, u);
        }
    }
}
int lca(int a, int b) {
    if (a == b)
        return a;
    if (dep1[a] < dep1[b])
        std::swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (dep1[fa[a][i]] >= dep1[b]) {
            a = fa[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i], b = fa[b][i];
        }
    }
    return fa[a][0];
}
void treedfs(int u, int fath) {
    //		sum[u] += d[u];
    for (auto v : st[u]) {
        int to = v.v;
        if (to == fath)
            continue;
        //			sum[to] = sum[u];
        //			fians += v.w * val;
        treedfs(to, u);
        d[u] += d[to];
    }
}
void treedfs2(int u, int fath) {
    for (auto v : st[u]) {
        int to = v.v;
        if (to == fath)
            continue;
        // fians += v.w * 1ll * d[to];
        fians += v.w * 1ll * std::min(d[to], d[u]);
        // fians += v.w * 1ll * d[u];
        treedfs2(to, u);
    }
}
void main() {
    tdfs(1, 0);
    //		scanf("%d", &q);
    //		tdfs(1, 0);
    for (int i = 1; i <= q; i++) {
        int x = 0, y = 0;
        scanf("%d%d", &x, &y);
        int lc = lca(x, y);
        //			printf("%d, %d -> %d\n", x, y, lc);
        d[x]++, d[y]++;
        d[lc]--;
        d[fa[lc][0]]--;
    }
    treedfs(1, 0);
    treedfs2(1, 0);
    printf("%lld\n", fians);
}
}  // namespace tree

void predfs(int u, int fa) {
    dfn[u] = low[u] = ++pdfn;
    sta[++psta] = u, vis[u] = 1;
    for (auto v : st[u]) {
        if (v.v != fa) {
            if (!dfn[v.v]) {
                predfs(v.v, u);
                low[u] = std::min(low[u], low[v.v]);
            } else if (dfn[v.v] < low[u]) {
                low[u] = std::min(low[u], dfn[v.v]);
            }
        }
    }
    if (dfn[u] == low[u]) {
        pscc++;
        while (vis[u]) {
            int top = sta[psta--];
            vis[top] = 0;
            scc[top] = pscc;
        }
    }
}
void dfs1(int u, int fa, int de) {
    if (u == base && fa != -1)
        return;
    if (vis[u])
        return;
    vis[u] = 1;
    huan.push_back(u);
    dep[u] = de;
    for (auto v : st[u]) {
        if (v.v != fa) {
            if (scc[v.v] == mxid) {
                if (!fan[u])
                    fan[u] = v.w;
                if (!zheng[v.v])
                    zheng[v.v] = v.w;
                //				printf("zheng %d = %d, fan %d = %d\n", v.v, v.w, u, v.w);
                dfs1(v.v, u, de + 1);
            }
        }
    }
}
void dfs2(int u, int fa, int top) {
    for (auto v : st[u]) {
        if (v.v != fa && scc[v.v] != scc[u]) {
            fath[v.v] = top;
            ww[v.v] = ww[u] + v.w;
            dfs2(v.v, u, top);
        }
    }
}
bool cmp(int a, int b) { return a > b; }
int main() {
    // freopen("ace.in", "r", stdin);
    // freopen("ace.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int x = 0, y = 0;
        ll t = 0;
        scanf("%d%d%lld", &x, &y, &t);
        if (remain[x * (n + 1) + y] == 0) {
            pedge++;
            if (t == 0)
                remain[x * (n + 1) + y] = remain[y * (n + 1) + x] = -1;
            else
                remain[x * (n + 1) + y] = remain[y * (n + 1) + x] = t;
        } else {
            if (remain[x * (n + 1) + y] <= t) {
                continue;
            } else
                pedge++;
        }

        st[x].push_back({ y, t });
        st[y].push_back({ x, t });
        // use -1 instead of 0
    }
    scanf("%d", &q);
    if (pedge == n - 1 && k != 1) {
        tree::q = q;
        tree::main();
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            predfs(i, -1);
    //	for (int i = 1; i <= n; i++)
    //		printf("%d -> %d\n", i, scc[i]);
    for (int i = 1; i <= n; i++) {
        cnt[scc[i]]++;
        if (cnt[scc[i]] > mx) {
            mx = cnt[scc[i]];
            mxid = scc[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (scc[i] == mxid) {
            base = i;
            break;
        }
    }
    dfs1(base, -1, 1);
    for (int i = 0; i < (int)huan.size(); i++) {
        int v = huan[i];
        if (i != 0) {
            pre[v] = pre[huan[i - 1]] + zheng[v];
        }
    }
    for (int i = (int)huan.size() - 1; i >= 0; i--) {
        int v = huan[i];
        if (i != (int)huan.size() - 1) {
            suf[v] = suf[huan[i + 1]] + fan[v];
        } else {
            suf[v] = fan[v];
        }
    }
    for (auto v : huan) {
        dfs2(v, 0, v);
    }
    suf[base] = 0;
    //	for (auto v : huan){
    //		printf("pre[%d] = %d, suf[%d] = %d\n", v, pre[v], v, suf[v]);
    //	}
    //

    for (int i = 1; i <= q; i++) {
        int x = 0, y = 0;
        scanf("%d%d", &x, &y);
        if (scc[x] == scc[y]) {
            if (dep[x] > dep[y])
                std::swap(x, y);
            ll tmpa = std::abs(pre[x] - pre[y]);
            //			ll tmpb = pre[x] + suf[base] - suf[y];
            ll tmpb = pre[x] + suf[y];
            result.push_back(std::min(tmpa, tmpb));
        } else {
            if (scc[x] == mxid || scc[y] == mxid) {
                if (scc[y] == mxid) {
                    std::swap(x, y);
                }
                ll vall = ww[y];
                y = fath[y];
                if (dep[x] > dep[y])
                    std::swap(x, y);
                ll tmpa = std::abs(pre[x] - pre[y]);
                //				ll tmpb = pre[x] + suf[base] - suf[y];
                ll tmpb = pre[x] + suf[y];
                result.push_back(vall + std::min(tmpa, tmpb));
            } else {
                ll valx = ww[x], valy = ww[y];
                int fx = fath[x], fy = fath[y];
                if (fx == fy) {
                    result.push_back(std::abs(valx - valy));
                    continue;
                }
                if (dep[x] > dep[y])
                    std::swap(x, y);
                ll tmpa = std::abs(pre[x] - pre[y]);
                //				ll tmpb = pre[x] + suf[base] - suf[y];
                ll tmpb = pre[x] + suf[y];
                result.push_back(valx + valy + std::min(tmpa, tmpb));
            }
        }
    }
    //	for (auto v : result){
    //		printf("result contain %lld\n", v);
    //	}
    std::sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < (int)result.size(); i++) {
        finalres += result[i];
    }
    //	puts("fuck");
    printf("%lld\n", finalres);
    fclose(stdin);
    fclose(stdout);
    return 0;
}