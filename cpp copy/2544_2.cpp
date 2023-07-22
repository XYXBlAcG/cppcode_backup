#include <cstdio>
#include <algorithm>
int n, a[1000006], p, x[1000006];
long long m, s[1000006];
int check(int z) {
    p = 0;
    long long cur = 0;

    for (int i = 1; i <= n; i++)
        x[i] = a[i];

    for (int i = 1; i < n; i++) {
        cur += std::max(0, x[i + 1] - x[i] - z);
        x[i + 1] = std::min(x[i + 1], x[i] + z);
    }

    for (int i = n; i > 1; i--) {
        cur += std::max(0, x[i - 1] - x[i] - z);
        x[i - 1] = std::min(x[i - 1], x[i] + z);
    }

    if (cur > m)
        return 0;

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + x[i];

    int l = 1, r = 1;

    for (int i = 1; i <= n; i++) {
        while (x[l] < 1ll * (i - l) * z)
            l++;

        while (r < n && x[r + 1] >= 1ll * (r - i + 1) * z)
            r++;

        long long X = 1ll * (i - l) * (i - l + 1) / 2 * z + 1ll * (r - i) * (r - i + 1) / 2 * z;

        if (cur + (s[r] - s[l - 1]) - X <= m)
            return p = i, 1;
    }

    return 0;
}
int main() {
    scanf("%d%lld", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    int l = 0, r = 1e9, ans = 1e9;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }

    check(ans);
    printf("%d %d\n", p, ans);
}