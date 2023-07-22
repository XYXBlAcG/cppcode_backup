#include <cstdio>
int n, m, t = 1;
int mem[10000][10000];
void f(int p, int l) {
    if (p == m + 1) {
        // printf("\n");
        putchar('\n');
        ++t;
        return;
    }
    for (int i = l + 1; i <= p + n - m; i++) {
        if (mem[t - 1][p] != i) {
            putchar(('A' + p - 1));
            putchar('-');
            putchar('>');
            printf("%d", i);
            putchar(' ');
            // printf("%c->%d ", (char)('A' + p - 1), i);
        }
        mem[t][p] = i;
        f(p + 1, i);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    f(1, 0);
    return 0;
}