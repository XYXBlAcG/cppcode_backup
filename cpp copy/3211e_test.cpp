#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e7 + 10;
int n, m;
int fa[N], ra[N], maxx[N];
struct Rec {
    int u, v, rk, m, fau;
} rec[N];
int prec;
int find(int u) {
    if (fa[u] == u)
        return u;
    else
        return find(fa[u]);
}
void merge(int u, int v) {
    int x = find(u), y = find(v);
    if (ra[x] > ra[y])
        swap(x, y);
    rec[++prec] = { x, y, ra[y], maxx[y], fa[x] };
    fa[x] = y;
    maxx[y] = max(maxx[x], maxx[y]);
    if (ra[x] == ra[y]) {
        ra[y]++;
    }
}
void cz() {
    int u = rec[prec].u, v = rec[prec].v, rk = rec[prec].rk, m = rec[prec].m, fau = rec[prec].fau;
    fa[u] = fau;
    ra[v] = rk;
    maxx[v] = m;
    prec--;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        ra[i] = 1;
        maxx[i] = i;
    }
    string oper;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> oper;
        if (oper[0] == 'm') {
            cin >> u >> v;
            merge(u, v);
            printf("%d\n", maxx[find(u)]);
        } else if (oper[0] == 'q') {
            cin >> u >> v;
            if (find(u) == find(v)) {
                putchar('1');
                putchar('\n');
            } else {
                putchar('0');
                putchar('\n');
            }
        } else {
            cz();
        }
    }
    return 0;
}