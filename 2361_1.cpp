#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;

int a[N], cha[N], cha2[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    // 读入每个区间的加法和减法操作，并计算差分数组cha2
    for (int i = 1; i <= m; i++) {
        int l, r, b, d;
        scanf("%d%d%d%d", &l, &r, &b, &d);

        cha2[l] += b;
        cha2[l+1] += d;
        cha2[r+1] -= (r-l+1)*d + b;
    }

    // 计算差分数组cha
    for (int i = 1; i <= n; i++) {
        cha[i] = cha[i-1] + cha2[i];
    }

    // 计算原始数组a
    for (int i = 1; i <= n; i++) {
        a[i] = a[i-1] + cha[i];
    }

    // 打印原始数组a
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
