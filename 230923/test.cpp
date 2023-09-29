#include <stdio.h>
typedef const int ci; ci d(1e9 + 7); // 模数
int n, k, h[502], f[1000006], v[1000006];
// h 表示高度，f 预处理阶乘，v 预处理阶乘的逆元
struct node { int p[502]; };
#define $ % d * // 在乘之后取模
inline int min(ci x, ci y) { return x < y ? x : y; } // 最小值函数
inline int count(ci a, ci b, ci c) // 求解矩形的问题
{
    if (c > a || c > b) return 0;
    return 1ll * f[a] * f[b] $ v[a - c] $ v[b - c] $ v[c] % d;
}
inline node dp(ci l, ci r, int q) 
{
    node x; ci s(r - l + 1); 
    for (int i(1); i <= k; ++i) x.p[i] = 0; x.p[0] = 1; 
    if (l == r) { x.p[1] = h[l] - q; return x; } 
    int w(r); for (int i(l); i < r; ++i) if (h[i] < h[w]) w = i; 
    q = h[w] - q; 
//    printf("prh = %lld\n", q);
    if (w == l || w == r) 
    {
        node y(w ^ r ? dp(l + 1, r, h[w]) : dp(l, r - 1, h[w]));
        for (int i(0); i <= k; ++i)
            for (int j(0); i + j <= min(k, s) && j <= q; ++j)
                if (i + j) 
                    x.p[i + j] = (x.p[i + j] + 1ll * y.p[i] * count(q, s - i, j) % d) % d;
        return x;
    }
    const node a(dp(l, w - 1, h[w])), b(dp(w + 1, r, h[w])); node y(x);
    puts("merge");
	for (int i = 0; i <= k; i++)
		printf("%d ", y.p[i]);
	putchar('\n');
    for (int i(0); i <= k; ++i)
        for (int j(0); j <= k && i + j <= k; ++j)
            if (i + j) 
                y.p[i + j] = (y.p[i + j] + 1ll * a.p[i] * b.p[j] % d) % d;
    puts("merge");
	for (int i = 0; i <= k; i++)
		printf("%d ", y.p[i]);
	putchar('\n');
    for (int i(1); i <= min(k, s); ++i)
        for (int j(0); j <= i; ++j) 
            x.p[i] = (x.p[i] + 1ll * y.p[i - j] * count(q, s - i + j, j) % d) % d;
    for (int i = 0; i <= k; i++)
    	printf("%d ", x.p[i]);
    putchar('\n');
    return x;
}
inline int power(int b)
{
    int r(1), i(d - 2);
    while (i) { if (i & 1) r = 1ll * r * b % d; b = 1ll * b * b % d; i >>= 1; }
    return r;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i(1); i <= n; ++i) scanf("%d", &h[i]);
    f[0] = f[1] = 1; v[0] = v[1] = power(1); // 预处理
    for (int i(2); i <= 1e6; ++i) v[i] = power(f[i] = 1ll * i * f[i - 1] % d); // 递推预处理
    printf("%d\n", dp(1, n, 0).p[k]);
    return 0;
}
