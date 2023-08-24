#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read() {
    int res = 0; bool bo = 0; char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-');
    if (c == '-') bo = 1; else res = c - 48;
    while ((c = getchar()) >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - 48);
    return bo ? ~res + 1 : res;
}
const int N = 1e5 + 5;
int w, K, C[N][12], Ans, tmp[N], T[N], col, tot[N], cnt[N], r[N], h[N];
struct cyx {int x, y;} a[N];
bool comp(cyx a, cyx b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
bool cmp2(cyx a, cyx b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
void change(int x, int v) {
    for (; x <= col; x += x & -x)
        T[x] += v;
}
int ask(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += T[x];
    return res;
}
int main() {
    int i, j, tt = 0; read(); read(); w = read();
    for (i = 1; i <= w; i++) a[i].x = read(), a[i].y = read();
    K = read(); sort(a + 1, a + w + 1, comp);
    for (i = 0; i <= w; i++) C[i][0] = 1;
    for (i = 1; i <= w; i++) for (j = 1; j <= min(i, K); j++)
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    for (i = 1; i <= w; i++) {
        if (i == 1 || a[i].x != a[i - 1].x) tt++;
        tmp[i] = tt;
    }
    for (i = 1; i <= w; i++) tot[a[i].x = tmp[i]]++;
    for (int i = 1; i <= w; i++){
        printf("leng[%d] = %d\n", i, tot[i]);
    }
    sort(a + 1, a + w + 1, cmp2); tt = 0;
    for (i = 1; i <= w; i++) {
        if (i == 1 || a[i].y != a[i - 1].y) tt++;
        tmp[i] = tt;
    }
    for (i = 1; i <= w; i++) cnt[a[i].y = tmp[i]]++; col = a[w].y;
    sort(a + 1, a + w + 1, comp);
    for (i = 1; i <= w; i++) {
        if (i == 1 || a[i].x != a[i - 1].x) tt = 0;
        int le = a[i].y, v = (++h[le]) >= K && cnt[le] - h[le] >= K ?
            1ll * C[h[le]][K] * C[cnt[le] - h[le]][K] % 2147483648ll
            : 0; tt++;
        change(le, v - r[le]); r[le] = v;
        printf("i = %d, td = %d, tm = %d, val = %d, \n", i, tt, le, v);
        if (i == w || a[i].x != a[i + 1].x || a[i + 1].y - a[i].y <= 1
            || tt < K || tot[a[i].x] - tt < K) continue;
        puts("reach!");
        Ans += 1ll * C[tt][K] * C[tot[a[i].x] - tt][K] % 2147483648ll
            * (ask(a[i + 1].y - 1) - ask(a[i].y)) % 2147483648ll;
        printf("anss = %d\n", Ans);
    }
    printf("%lld\n", Ans >= 0 ? Ans : (1ll * Ans + 2147483648ll)
        % 2147483648ll);
    return 0;
}
