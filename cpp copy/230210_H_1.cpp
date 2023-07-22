#include <stdio.h>
 
long long f(int n, int x, int y) {
    if (n == 0) return 1;
    int m = 1 << (n - 1);
    if (x <= m && y <= m) {
        return f(n - 1, y, x);
    }
    if (x > m && y <= m) {
        return 3LL * m * m + f(n - 1, m - y + 1 , m * 2 - x + 1); //  填空
    }
    if (x <= m && y > m) {
        return 1LL * m * m + f(n - 1, x, y - m);
    }
    if (x > m && y > m) {
        return 2LL * m * m + f(n - 1, x - m, y - m);
    }
}
 
int main() {
	int n, x, y;
    scanf("%d", &n); 
    printf("%lld", f(n, 1, 1));
 
    return 0;
}
