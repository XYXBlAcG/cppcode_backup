#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#define int long long
const int N = 50005, M = 300;
std::map<int, int> to;
struct Node{
    int id, l, r;
}pre[N], pre2[N];
int n, m, a[N], past, p[M][M], s[M][M], num, nu;
signed main(){
    scanf("%lld%lld", &n, &m);
    num = sqrt(n);
    for (int i = 0, cnt = 1; i < n; i++){
        scanf("%lld", a + i);
        if(!to[a[i]]) to.insert(a[i], cnt++);
    }
    for (int i = 0; i < n; i++){
        if(i % num == 0) nu++;
        pre[i] = (Node){nu, (nu - 1) * num, nu * num - 1};
    }
    for (int i = 0, j = 0; i < n; i++){
        if(i % num == 0){
            pre2[++j].l = i;
            pre2[j - 1].r = i - 1;
        }
    }
    pre2[pre[n - 1].id].r = n - 1;
    for (int i = 1; i <= nu; i++){
        for (int j = i; j <= nu; j++){
            int vis[N], maxn, maxnu; memset(vis, 0, sizeof(vis));
            for (int k = pre2[i].l; k <= pre2[j].r; k++){
                vis[to[a[k]]]++;
                if(vis[to[a[k]]] > maxn){
                    maxn = vis[to[a[k]]], maxnu = a[k];
                }else if(vis[to[a[k]]] == maxn){
                    maxnu = std::min(a[k], maxnu);
                }
            }
            s[i][j] = maxnu;
        }
    }
    for (int i = 1; i <= n; i++)
    for (int i = 1; i <= m; i++){
        int l, r, ll, rr;
        scanf("%lld%lld", &l, &r);
        ll = (l + past - 1) % n + 1, rr = (r + past - 1) % n + 1;
        if(ll > rr) std::swap(l, r);

    }
    return 0;
}