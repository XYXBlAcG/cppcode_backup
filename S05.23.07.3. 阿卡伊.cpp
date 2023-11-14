#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define int long long
const int N = 1e5 + 5;
int n, m, v[N], sum[N], mx, s2[13][N], cnt[N];
bool vis[N], aq0 = 1;
struct Node {
    int c, q, id;
} song[N], song2[N];
int cc[N], qq[N];
std::vector<int> used;
bool cmp(Node a, Node b) {
    if (a.c == b.c)
        return a.q > b.q;
    return a.c < b.c;
}
bool cmp2(Node a, Node b) {
    if (a.q == b.q)
        return a.c < b.c;
    return a.q > b.q;
}
namespace pt20 {
void clean() {
    for (auto v : used) {
        vis[v] = 0;
    }
    used.clear();
}
bool chk(int v) {
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && v >= song2[i].c)
            return 1;
    }
    return 0;
}
void main() {
    scanf("%lld", &m);
    for (int i = 1, v; i <= m; i++) {
        clean();
        scanf("%lld", &v);
        int ans = 0;
        while (v > 0 && chk(v)) {
            for (int j = 1; j <= n; j++) {
                if (song2[j].c <= v && !vis[j]) {
                    v -= song2[j].c;
                    vis[j] = 1;
                    used.push_back(j);
                    ans++;
                    break;
                }
            }
        }
        printf("%lld ", ans);
    }
    putchar('\n');
}
}  // namespace pt20
namespace pt10 {
void main() {
    scanf("%lld", &m);
    for (int i = 1, v; i <= m; i++) {
        scanf("%lld", &v);
        int ccnt = std::lower_bound(sum + 1, sum + 1 + n, v) - sum;
        if (sum[ccnt] > v)
            ccnt--;
        printf("%lld ", ccnt);
    }
    putchar('\n');
}
}  // namespace pt10
namespace pt15 {
void main() {
    for (int i = 1; i <= n; i++) {
        ++cnt[song2[i].q];
        s2[song2[i].q][cnt[song2[i].q]] = s2[song2[i].q][cnt[song2[i].q] - 1] + song2[i].c;
        //			printf("%lld %lld = %lld\n", song2[i].q, cnt[song2[i].q],
        //s2[song2[i].q][cnt[song2[i].q]]);
    }
    scanf("%lld", &m);
    for (int i = 1, v; i <= m; i++) {
        scanf("%lld", &v);
        int ans = 0;
        for (int j = mx; j; j--) {
            if (cnt[j] == 0)
                continue;
            int ccnt = std::lower_bound(&s2[j][1], &s2[j][cnt[j]], v) - &s2[j][0];
            if (s2[j][ccnt] > v)
                ccnt--;
            //				printf("s2 ccnt = %lld, %lld\n", s2[j][ccnt], s2[j][ccnt + 1]);
            //				printf("j = %lld, ccnt = %lld, v = %lld\n", j, ccnt, v);
            ans += ccnt;
            v -= s2[j][ccnt];
        }
        printf("%lld ", ans);
    }
    putchar('\n');
}
}  // namespace pt15
signed main() {
    // freopen("arcaea.in", "r", stdin);
    // freopen("arcaea.out", "w", stdout);

    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", cc + i, qq + i), song2[i] = song[i] = { cc[i], qq[i], i };
        if (qq[i] != 1)
            aq0 = 0;
        mx = std::max(mx, qq[i]);
    }
    std::sort(song + 1, song + 1 + n, cmp);
    std::sort(song2 + 1, song2 + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
        cc[i] = song[i].c;
        qq[i] = song2[i].q;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + cc[i];
    }
    if (n <= 1000 && m <= 1000) {
        pt20::main();
    } else if(aq0) {
        pt10::main();
    }else{
        pt15::main();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}