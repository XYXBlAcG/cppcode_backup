#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
const int N = 1e5 + 5, up = 1000, M = 1e3 + 5;
int n, q, a[N], isp[M], vis[N], sum0[N], sum[N], v2[M];
std::vector<int> pri, b[N], st[N], used;
std::queue<int> que;
void init() {
    for (int i = 2; i <= up; ++i){
        if (!v2[i])
            pri.push_back(i);
        for (auto v : pri){
            if (1ll * i * v > up) break;
            v2[i * v] = 1;
            if (i % v == 0) break;
        }
    }
}
int read() {
    int w = 1, x = 0;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x *= w;
}
bool bfs(int u, int g) {
    que.push(u);
    while (que.size()) {
        int top = que.front();
        que.pop();
        if (top == g) {
            for (auto v : used) {
                vis[v] = 0;
            }
            used.clear();
            que = {};
            return 1;
        }
        if (vis[top] || top < u || top > g)
            continue;
        vis[top] = 1, used.push_back(top);
        for (auto v : st[top]) {
            que.push(v);
        }
    }
    for (auto v : used) {
        vis[v] = 0;
    }
    used.clear();
    return 0;
}
struct FileIO {
    FileIO() {
        #ifdef ONLINE_JUDGE
            freopen("gcd.in", "r", stdin);
            freopen("gcd.out", "w", stdout);
        #else
        #endif
    }
    ~FileIO() {
        fclose(stdin);
        fclose(stdout);
    }
} FileIO;
int main() {
    n = read(), q = read();
    init();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 0; i < (int)pri.size(); i++) 
        for (int j = 1; j <= n; j++) 
            if (a[j] && a[j] % pri[i] == 0) 
                b[i].push_back(j);
    for (int i = 0; i < (int)pri.size(); i++) 
        for (int j = 0; j < (int)b[i].size() - 1; j++) {
            st[b[i][j]].push_back(b[i][j + 1]);
            if(j == (int)b[i].size() - 6) st[b[i][j]].push_back(b[i][j + 5]);
        }
    for (int i = 1; i <= n; i++) {
        sum0[i] = sum0[i - 1] + (a[i] == 0);
        sum[i] = sum[i - 1] + (a[i] > 1);
    }
    for (int i = 1, x = 0, y = 0; i <= q; i++) {
        x = read(), y = read();
        if (x == y) {
            puts("Shi");
            continue;
        }
        if (!a[x] && !a[y]) {
            puts(sum[y] - sum[x - 1] ? "Shi" : "Fou");
            continue;
        }
        if (a[x] == 1 || a[y] == 1) {
            puts("Fou");
            continue;
        }
        if ((a[x] > 1 && !a[y]) || (!a[x] && a[y] > 1)) {
            puts("Shi");
            continue;
        }
        if ((a[x] > 1 && a[y] > 1) && (sum0[y] - sum0[x - 1])) {
            puts("Shi");
            continue;
        }
        puts(bfs(x, y) ? "Shi" : "Fou");
    }
    return 0;
}