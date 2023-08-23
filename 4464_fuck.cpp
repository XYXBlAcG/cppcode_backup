#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;
using std::sort;
using std::swap;
const int N = 40040;
const int M = 220;
int n, m, num, len, s[M][N], vis[N];
int tong[N], last, back[N];
struct A {
    int id, d, to;
}a[N];
struct Node {
    int num, s;
}p[M][M];
struct Pre{
    int id, l, r;
}pp[N], pp2[N];
inline bool cmp(A x, A y) { return x.d < y.d; }
inline bool pmc(A x, A y) { return x.id < y.id; }
inline void init() {
    for (int i = 1; i <= len; i++){
        pp2[i] = {0, (i - 1) * num + 1, i * num};
    }
    pp2[len].r = n;
    for (int i = 1; i <= n; i++){
        pp[i].l = pp2[pp[i].id].l;
        pp[i].r = pp2[pp[i].id].r;
    }
    for(int i = 1; i <= len; i++) {
        memset(tong, 0, sizeof(tong)); 
        Node tmp; tmp.num = tmp.s = 0;
        for(int j = i; j <= len; j++) {
            for(int k = pp2[j].l; k <= pp2[j].r; k++) {
                tong[a[k].to]++;
                if(tong[a[k].to] > tmp.s) {
                    tmp.num = a[k].to;
                    tmp.s = tong[a[k].to];
                }
                else if(tong[a[k].to] == tmp.s)
                    tmp.num = min(tmp.num, a[k].to), 
                    tmp.s = tong[a[k].to];
            }
            p[i][j] = tmp;
        }
    }
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= n; j++) 
            s[i][a[j].to] = s[i - 1][a[j].to];
        for(int j = (i - 1) * num + 1; j <= min(n, i * num); j++) 
            s[i][a[j].to]++;
    }
}
inline void query(int l, int r){
    int il = pp[l].id, ir = pp[r].id;
         if(ir - il <= 2) {
            int ans = 0;
            for(int j = l; j <= r; j++) tong[a[j].to] = 0;
            for(int j = l; j <= r; j++) {
                tong[a[j].to]++;
                if(tong[a[j].to] > tong[ans]) ans = a[j].to;
                else if(tong[a[j].to] == tong[ans]) ans = min(ans, a[j].to);
            }
            printf("%d\n", last = back[ans]);
        } 
        else {
            int ans = p[il + 1][ir - 1].num;
            tong[ans] = 0, vis[ans] = 0;
            for(int j = l; j <= pp[l].r; j++) tong[a[j].to] = 0, vis[a[j].to] = 0;
            for(int j = pp[r].l; j <= r; j++) tong[a[j].to] = 0, vis[a[j].to] = 0;
            for(int j = l; j <= pp[l].r; j++) tong[a[j].to]++;
            for(int j = pp[r].l; j <= r; j++) tong[a[j].to]++;
            int maxn, maxnu = 0;
            for(int j = l; j <= pp[l].r; j++)
                if(!vis[a[j].to]) {
                    vis[a[j].to] = 1;
                    int val = tong[a[j].to] + s[ir - 1][a[j].to] - s[il][a[j].to];
                    if(maxnu < val)
                        maxnu = val, 
                        maxn = a[j].to;
                    else if(maxnu == val) maxn = min(maxn, a[j].to);
                }
            for(int j = pp[r].l; j <= r; j++)
                if(!vis[a[j].to]) {
                    vis[a[j].to] = 1;
                    int val = tong[a[j].to] + s[ir - 1][a[j].to] - s[il][a[j].to];
                    if(maxnu < val)
                        maxnu = val, 
                        maxn = a[j].to;
                    else if(maxnu == val) maxn = min(maxn, a[j].to);
                }
            if(maxnu > tong[ans] + p[il + 1][ir - 1].s) ans = maxn;
            else if(maxnu == tong[ans] + p[il + 1][ir - 1].s) ans = min(ans, maxn);
            printf("%d\n", last = back[ans]);
        } 
}
int main() {
    scanf("%d%d", &n, &m); 
    num = sqrt(n);
    len = (n + num - 1) / num;
    // len = (n - 1) / num + 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].d), a[i].id = i;
        pp[i].id = (i - 1) / num + 1;
    }
    sort(a + 1, a + n + 1, cmp); a[0].d = -1;
    for(int i = 1; i <= n; i++) {
        a[i].to = a[i - 1].to;
        if(a[i - 1].d != a[i].d) 
            a[i].to++;
        back[a[i].to] = a[i].d;
    }
    sort(a + 1, a + n + 1, pmc);
    init(); 
    for(int i = 1; i <= m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        l = (l + last - 1) % n + 1;
        r = (r + last - 1) % n + 1;
        if(l > r) swap(l, r);
        query(l, r);
    }
    return 0;
}
