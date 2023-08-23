#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 40040;
const int K = 220;
int n, m, L, len, s[K][N], vis[N];
int tong[N], B[N], last, pre[N];
struct getin {
    int id, d, to;
}a[N];
struct node {
    int num, s;
}p[K][K];
inline bool cmp1(getin x, getin y) { return x.d < y.d; }
inline bool cmp2(getin x, getin y) { return x.id < y.id; }
inline int getB(int x) {
    int ret = x / L;
    if(x % L) ret++;
    return ret;
}
inline void prework() {
    for(int i = 1; i <= len; i++) {
        memset(B, 0, sizeof(B)); node tmp;
        tmp.num = tmp.s = 0;
        for(int j = i; j <= len; j++) {
            for(int k = (j - 1) * L + 1; k <= min(n, j * L); k++) {
                B[a[k].to]++;
                if(B[a[k].to] > tmp.s) {
                    tmp.num = a[k].to;
                    tmp.s = B[a[k].to];
                }
                else if(B[a[k].to] == tmp.s)
                    tmp.num = min(tmp.num, a[k].to), 
                    tmp.s = B[a[k].to];
            }
            p[i][j] = tmp;
        }
    }
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= n; j++) s[i][a[j].to] = s[i - 1][a[j].to];
        for(int j = (i - 1) * L + 1; j <= min(n, i * L); j++) 
            s[i][a[j].to]++;
    }
}
int main() {
    scanf("%d%d", &n, &m); L = sqrt(n);
    len = (n + L - 1) / L;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i].d), a[i].id = i;
    sort(a + 1, a + n + 1, cmp1); a[0].d = -1;
    for(int i = 1; i <= n; i++) {
        a[i].to = a[i - 1].to;
        if(a[i - 1].d != a[i].d) 
            a[i].to++;
        pre[a[i].to] = a[i].d;
    }
    sort(a + 1, a + n + 1, cmp2);
    prework(); 
    for(int i = 1; i <= m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        l = (l + last - 1) % n + 1;
        r = (r + last - 1) % n + 1;
        if(l > r) swap(l, r);
        int posl = getB(l), posr = getB(r);
         if(posr - posl <= 2) {
            int ans = 0;
            for(int j = l; j <= r; j++) tong[a[j].to] = 0;
            for(int j = l; j <= r; j++) {
                tong[a[j].to]++;
                if(tong[a[j].to] > tong[ans]) ans = a[j].to;
                else if(tong[a[j].to] == tong[ans]) ans = min(ans, a[j].to);
            }
            printf("%d\n", last = pre[ans]);
        } 
        else {
            int ans = p[posl + 1][posr - 1].num;
            tong[ans] = 0, vis[ans] = 0;
            for(int j = l; j <= min(n, posl * L); j++) tong[a[j].to] = 0, vis[a[j].to] = 0;
            for(int j = (posr - 1) * L + 1; j <= r; j++) tong[a[j].to] = 0, vis[a[j].to] = 0;
            for(int j = l; j <= min(n, posl * L); j++) tong[a[j].to]++;
            for(int j = (posr - 1) * L + 1; j <= r; j++) tong[a[j].to]++;
            int MXnum, MX = 0;
            for(int j = l; j <= min(n, posl * L); j++)
                if(!vis[a[j].to]) {
                    vis[a[j].to] = 1;
                    int val = tong[a[j].to] + s[posr - 1][a[j].to] - s[posl][a[j].to];
                    if(MX < val)
                        MX = val, 
                        MXnum = a[j].to;
                    else if(MX == val) MXnum = min(MXnum, a[j].to);
                }
            for(int j = (posr - 1) * L + 1; j <= r; j++)
                if(!vis[a[j].to]) {
                    vis[a[j].to] = 1;
                    int val = tong[a[j].to] + s[posr - 1][a[j].to] - s[posl][a[j].to];
                    if(MX < val)
                        MX = val, 
                        MXnum = a[j].to;
                    else if(MX == val) MXnum = min(MXnum, a[j].to);
                }
            if(MX > tong[ans] + p[posl + 1][posr - 1].s) ans = MXnum;
            else if(MX == tong[ans] + p[posl + 1][posr - 1].s) ans = min(ans, MXnum);
            printf("%d\n", last = pre[ans]);
        } 
    }
    return 0;
}
