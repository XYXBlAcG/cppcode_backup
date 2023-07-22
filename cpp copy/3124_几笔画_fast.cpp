#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, N = 6e5 + 10;
template <typename T>
inline void rd_(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

int n, m, deg[N], cnt = 1, h[N];
bool vis[N];
stack<int> stk;
vector<int> ans;
struct Edge {
    int to, next;
} e[N << 1];

void add_(int u, int v) {
    e[++cnt] = (Edge){ v, h[u] };
    h[u] = cnt, deg[v]++;
}

void dfs_(int u) {
    for (int v, &i = h[u]; i; i = e[i].next) {
        v = e[i].to;
        if (vis[i >> 1])
            continue;
        vis[i >> 1] = 1, deg[v]--, deg[u]--, dfs_(v);
    }
    stk.push(u);
}

int main() {
    rd_(n), rd_(m);
    for (int u, v, i = 1; i <= m; i++) {
        rd_(u), rd_(v);
        add_(u, v), add_(v, u);
    }
    rep(i, 1, n) if (deg[i] & 1) add_(0, i), add_(i, 0);
    rep(i, 0, n) {
        if (!deg[i])
            continue;
        dfs_(i);
        while (!stk.empty()) {
            ans.clear();
            while (!stk.empty() && !stk.top()) stk.pop();
            while (!stk.empty() && stk.top()) ans.push_back(stk.top()), stk.pop();
            if (ans.size()) {
                cout << ans.size() - 1 << " ";
                rep(i, 0, ans.size() - 1) printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
            }
        }
    }
}