#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
// #include <map>
#include <iostream>
#define de(x) std::cout << #x << " = " << x << std::endl
#define int long long
const int N = 50005, M = 300;
// std::map<int, int> to;
struct Node{
    int id, l, r;
}pre[N], pre2[N];
struct Pre{
    int val, num;
}p[M][M];
struct Note{
    int val, idx, to;
}a[N];
bool cmp(Note x, Note y){return x.val < y.val;}
bool pmc(Note x, Note y){return x.idx < y.idx;}
int n, m, past, s[M][M], num, nu, back[N], cnt, tong[N], vis[N], len;
inline int query(int l, int r){
    int il = pre[l].id, ir = pre[r].id;
    if(ir - il <= 2){
        int maxn = 0, maxnu = 0;
        for (int i = l; i <= r; i++)
            tong[a[i].to] = 0;
        for (int i = l; i <= r; i++){
            tong[a[i].to]++;
            // de(i), de(a[i]), de(tong[a[i].to]);
            if(tong[a[i].to] > maxn){
                maxn = tong[a[i].to], maxnu = a[i].to;
            }else if(tong[a[i].to] == maxn){
                maxnu = std::min(maxnu, a[i].to);
            }
        }
        return maxnu;
    }
    // 2 side
    
    int ttmp = p[il + 1][ir - 1].num;
    // de(ttmp);
    tong[ttmp] = vis[ttmp] = 0;
    for (int i = l; i <= pre[l].r; i++) tong[a[i].to] = vis[a[i].to] = 0;
    for (int i = pre[r].l; i <= r; i++) tong[a[i].to] = vis[a[i].to] = 0;
    for (int i = l; i <= pre[l].r; i++) tong[a[i].to]++;
    for (int i = pre[r].l; i <= r; i++) tong[a[i].to]++;
    int maxn = 0, maxnu = 0;
    for (int i = l; i <= pre[l].r; i++){
        if(!vis[a[i].to]){
            vis[a[i].to] = 1;
            int v = tong[a[i].to] - s[il][a[i].to] + s[ir - 1][a[i].to];
            if(v > maxn){
                maxn = v;
                maxnu = a[i].to;
            }else if(v == maxn){
                maxnu = std::min(maxnu, a[i].to);
            }
        }
    }
    for (int i = pre[r].l; i <= r; i++){
        if(!vis[a[i].to]){
            vis[a[i].to] = 1;
            int v = tong[a[i].to] - s[il][a[i].to] + s[ir - 1][a[i].to];
            if(v > maxn){
                maxn = v;
                maxnu = a[i].to;
            }else if(v == maxn){
                maxnu = std::min(maxnu, a[i].to);
            }
        }
    }
    if(tong[ttmp] + p[il + 1][ir - 1].val < maxn) return maxnu;
    else if(tong[ttmp] + p[il + 1][ir - 1].val == maxn) return std::min(maxnu, p[il + 1][ir - 1].num);
    return p[il + 1][ir - 1].num;
    
}
signed main(){
    scanf("%lld%lld", &n, &m);
    len = sqrt(n);
    // num = 300;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i].val), a[i].idx = i;
        pre[i].id = (i - 1) / len + 1;
    }
        // if(!a[i].to) ++cnt, a[i].to = cnt, back[cnt] = a[i].val;
    std::sort(a + 1, a + n + 1, cmp);
    a[0].val = -1;
    for (int i = 1; i <= n; i++){
        if(i){
            a[i].to = a[i - 1].to;
            if(a[i - 1].val != a[i].val) a[i].to++;
        }
        back[a[i].to] = a[i].val;
    }
    std::sort(a + 1, a + n + 1, pmc);
    // for (int i = 0; i < n; i++){
    //     printf("%lld %lld\n", a[i].val, a[i].to);
    // }putchar('\n');
    for (int i = 1; i <= (num = (n - 1) / len + 1); i++)
        pre2[i] = {0, (i - 1) * len + 1, i * len};
    pre2[num].r = n;
    for (int i = 1; i <= n; i++){
        pre[i].l = pre2[pre[i].id].l;
        pre[i].r = pre2[pre[i].id].r;
    }
    for (int i = 1; i <= nu; i++){
        for (int j = i; j <= nu; j++){
            int maxn = 0, maxnu = 0; 
            for (int k = pre2[i].l; k <= pre2[j].r; k++)
                tong[a[k].to] = 0;
            for (int k = pre2[i].l; k <= pre2[j].r; k++){
                tong[a[k].to]++;
                if(tong[a[k].to] > maxn){
                    maxn = tong[a[k].to], maxnu = a[k].to;
                }else if(tong[a[k].to] == maxn){
                    maxnu = std::min(a[k].to, maxnu);
                }
            }
            p[i][j] = {maxn, maxnu}; // val 
        }
    }
    // for (int i = 1; i <= nu; i++){
    //     for (int j = i; j <= nu; j++){
    //         printf("p[%lld][%lld] = {%lld,%lld}\n", i, j, p[i][j].val, p[i][j].num);
    //     }
    // }
    for (int i = 1; i <= nu; i++){
        for (int j = 1; j <= n; j++){
            s[i][a[j].to] = s[i - 1][a[j].to];
        }
        for (int j = pre2[i].l; j <= pre2[i].r; j++){
            s[i][a[j].to]++;
        }
    }
    // for (int i = 1; i <= nu; i++){
    //     for (int j = 0; j < n; j++){
    //         printf("s[%lld][%lld] = %lld\n", i, a[j], s[i][a[j].to]);
    //     }
    // }
    for (int i = 1; i <= m; i++){
        int l, r;
        scanf("%lld%lld", &l, &r);
        l = ((l + past - 1) % n) + 1, r = ((r + past - 1) % n) + 1;
        if(l > r) std::swap(l, r);
        // printf("l = %lld, r = %lld\n", l, r);
        printf("%lld\n", past = back[query(l, r)]);
    }
    return 0;
}