#include <cstdio>

const int N = 1011;
struct Num {
    int a[2 * N];
} a, b, c, add1, add2, jian1, jian2, mul1, mul2, divis1;
int c1;

int read() {
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
void print(const Num& x) {
    //	printf("                  \n");
    if (x.a[0] == 1)
        printf("-");
    int t = 2000;
    for (; x.a[t] == 0 && t > 0;) t--;
    if (t == 0)
        printf("0");
    for (; t >= 1; t--) printf("%d", x.a[t]);
    printf("\n");
}
bool cmp(const Num& x, const Num& y) {  // x < y
    for (int i = 1000; i >= 1; i--)
        if (x.a[i] != y.a[i])
            return x.a[i] < y.a[i];
    return false;
}
void add_(const Num& x, const Num& y, Num& add) {
    for (int i = 1; i <= 1000; i++) {
        add.a[i] += x.a[i] + y.a[i];
        if (add.a[i] >= 10)
            add.a[i] -= 10, add.a[i + 1]++;
    }
}
void jian_(Num x, Num y, Num& jian) {
    if (cmp(x, y)) {
        jian.a[0] = 1;
        Num t = x;
        x = y;
        y = t;
    }
    for (int i = 1; i <= 1000; i++) {
        jian.a[i] += x.a[i] - y.a[i];
        if (jian.a[i] < 0)
            jian.a[i + 1]--, jian.a[i] += 10;
    }
}
void mul_(const Num& x, const Num& y, Num& mul) {
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            mul.a[i + j - 1] += x.a[i] * y.a[j];
            mul.a[i + j] += mul.a[i + j - 1] / 10;
            mul.a[i + j - 1] %= 10;
        }
    }
}
void divis_(Num x, int y, Num& divis) {
    int rest = 0, p = 1000;
    while (p >= 1) {
        rest = rest * 10 + x.a[p];
        divis.a[p--] = rest / y;
        rest %= y;
    }
}

int main() {
    int len_a, len_b;
    len_a = read();
    for (int i = len_a; i >= 1; i--) a.a[i] = read();
    len_b = read();
    for (int i = len_b; i >= 1; i--) b.a[i] = read();
    c1 = read();
    int t = c1, p = 0;
    while (t) {
        c.a[++p] = t % 10;
        t /= 10;
    }
    add_(a, b, add1);
    print(add1);
    add_(a, c, add2);
    print(add2);
    jian_(a, b, jian1);
    print(jian1);
    jian_(b, c, jian2);
    print(jian2);
    mul_(a, b, mul1);
    print(mul1);
    mul_(a, c, mul2);
    print(mul2);
    divis_(b, c1, divis1);
    print(divis1);
    return 0;
}