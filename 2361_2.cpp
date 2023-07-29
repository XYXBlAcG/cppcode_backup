#include <cstdio>

const int N = 1e6 + 5;

int a[N] = {0};
int cha[N] = {0};
int cha2[N] = {0};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int l, r, b, d;
        scanf("%d%d%d%d", &l, &r, &b, &d);
        cha2[l] += b;
        cha2[l + 1] += d - b;
        cha2[r + 1] -= d;
        cha2[r + 2] += b;
    }
    for (int i = 1; i <= n; i++) {
        cha[i] = cha[i - 1] + cha2[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + cha[i];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
