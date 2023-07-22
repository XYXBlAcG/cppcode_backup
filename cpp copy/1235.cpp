#include <cstdio>
int fa[1009];
int n, m;
int find(int a) {
    if (fa[a] == a) return a;
    return fa[a] = find(fa[a]);
}
void merge(int a, int b) { fa[find(a)] = find(b); }
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
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int k = 1; k <= m; k++) {
        int t, i, j;
        t = read(), i = read(), j = read();
        if (!t)
            merge(i, j);
        else
            if(find(i) == find(j)) puts("1");
            else puts("0");
    }
    return 0;
}