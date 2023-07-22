#include <cstdio>
#include <algorithm>
const int N = 5e5 + 5;
typedef long long ll;
int n, m, sans[N], num;
ll way[N], away = 1, sum[N];
ll mod = 1e9 + 7;
int fath[N];
struct Node {
    int u, v, w;
}st[N];
int find(int x) { return fath[x] != x ? fath[x] = find(fath[x]) : x; }
bool cmp(Node a, Node b) { return a.w < b.w; }
void unite(int x, int y) {
    fath[x] = fath[y];
}
void Pro() {
    for (int i = 1; i <= m; i++) {
        int U = find(st[i].u), V = find(st[i].v);
        if (i != m && st[i + 1].w == st[i].w && find(st[i + 1].u) != find(st[i + 1].v) && (( find(st[i + 1].u) == U && find(st[i + 1].v) == V) || (find(st[i + 1].u) == V && find(st[i + 1].v) == U))) {
            away = away * 2 % mod;
        }
        way[i + 1] = away;
        sum[i] = sum[i - 1];
        if (U != V) {
            unite(U, V);
            sans[i] = --num;
        } else {
            sans[i] = num;
            sum[i] += st[i].w;
        }
    }
}
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
inline void write(ll x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    n = read(), m = read();
    num = n - 1;
    for (int i = 1; i <= n; i++) {
        fath[i] = i;
        sum[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        st[i] = (Node){ u, v, w };
    }
    away = 1;
    way[1] = 1;
    Pro();
    for (int i = 1; i <= m; i++) {
        write(sans[i]); putchar(' ');
        write(sum[i]); putchar(' ');
        write(way[i]); putchar('\n');
    }
    return 0;
}