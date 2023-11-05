#include <cstdio>

const char c[] = "DRUL";

void f(int a, int s, int t) {
    if (!a)
        return;
    f(a - 1, (s + t) & 3, -t);
    putchar(c[s]);
    f(a - 1, s, t);
    putchar(c[(s + t) & 3]);
    f(a - 1, s, t);
    putchar(c[(s + t * 2) & 3]);
    f(a - 1, (s - t) & 3, -t);
}

int main() {
    int n;
    scanf("%d", &n);
    f(n, 0, 1);
    putchar('\n');
    return 0;
}