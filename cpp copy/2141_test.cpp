#include <cstdio>
int n;
int bene[15][15];
int maxb, maxa;
int a = 0;
int used[15];
void dfs(int in) {
    if (maxb > maxa) {
        maxa = maxb;
    }
    if (in > n) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }
        // a++;
        maxb += bene[in][i];
        used[i] = 1;
        dfs(in + 1);
        used[i] = 0;
        maxb -= bene[in][i];
        // a--;
    }
}
int main() {
    // int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= n; o++) {
            scanf("%d", &bene[i][o]);
        }
    }
    dfs(1);

    printf("%d", maxa);
    return 0;
}