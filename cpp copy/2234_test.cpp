#include <cstdio>
#include <iostream>
using std::max;
using std::min;
int n, m, r;
int arr[3010];
int fa[3010];
bool vis[3010];
int f(int i, int j) {
    if (vis[i]) {
        return fa[i];
    }
    fa[i] = 1;
    vis[i] = true;
    int tmp = 0, tmp2 = 0;
    tmp = fa[i];
    for (int z = 1; z < i; z++) {
        if (arr[z] < arr[i] && tmp < f(z, j) + 1)
            tmp = max(f(z, j) + 1, tmp);
    }
    if (j > 0) {
        for (int z = 1; z < i; z++) {
            tmp2 = max(f(z, j - 1) + 1, tmp2);
        }
    }
    fa[i] = max(tmp, tmp2);
    return fa[i];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        r = max(f(i, 1), r);
    }
    printf("%d\n", r);
    return 0;
}