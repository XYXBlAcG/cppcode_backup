#include <cstdio>
#include <cstring>
int T, n, m, tim[100011], cnt[100011], a[100011];
int main() {
    // freopen("internationalization.in", "r", stdin);
    // freopen("internationalization.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        memset(tim, 0, sizeof(tim));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d", &n, &m);
        int b;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            tim[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b);
            // tim[a[i]]++;
            cnt[a[i]] += b;
        }
        int tmp = 0, ch = 0, loc = 0;
        for (int i = 1; i <= m; i++) {
            if (tim[i] != cnt[i] && cnt[i] != 0) {
                ch = 2;
                break;
            }
            if (tim[i] && tim[i] == cnt[i]){
                tmp++, loc = i;
                break;
            }
                
        }
        if (tmp == 1)
            ch = 1;
        if (tmp > 1)
            ch = 2;
        if (ch == 0)
            printf(">-<\n");
        if (ch == 1)
            printf("%d\n", loc);
        if (ch == 2)
            printf("^v^\n");
    }
    fclose(stdin), fclose(stdout);
    return 0;
}