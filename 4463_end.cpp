#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using std::min; 
const int N = 5e5 + 5, len = 128;
struct Node{
    int id, val;
}h[N];
int n, num, m, ans[N], res, map[N], tmp[N];
int a, b, back[N], so[N], sum;
struct Note{
    int id, l, r;
}pre[N], pre2[N];
int lowbit(int x) {return x & (-x);}
bool cmp(Node a, Node b){
    if(a.val == b.val) return a.id < b.id;
    return a.val < b.val; 
}
void add(int x, int v){
    for (; x <= n; x += lowbit(x))
        ans[x] += v;
}
int query(int x){
    int res = 0;
    for (; x; x -= lowbit(x))
        res += ans[x];
    return res;
}
void sorter(int id, int op){
    int l, r;
    if(!op) l = pre[id].l, r = pre[id].r;
    else l = pre2[id].l, r = pre2[id].r;
    for (int i = l; i <= r; i++)
        so[i] = tmp[i];
    std::sort(so + l, so + r + 1);
}
int query_2(int l, int r, int c){
    int ll = pre[l].id, rr = pre[r].id, bans = 0;
    if(ll + 1 >= rr){
        for (int i = l; i <= r; i++) bans += (tmp[i] < c);
        return bans;
    }
    for (int i = ll + 1; i < rr; i++)
        bans += std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l;
    for (int i = l; i <= pre[l].r; i++) bans += (tmp[i] < c);
    for (int i = pre[r].l; i <= r; i++) bans += (tmp[i] < c);
    return bans;
}
int query_3(int l, int r, int c){
    int ll = pre[l].id, rr = pre[r].id, bans = 0;
    if(ll + 1 >= rr){
        for (int i = l; i <= r; i++) bans += (tmp[i] > c);
        return bans;
    }
    for (int i = ll + 1; i < rr; i++)
        bans += pre2[i].r - (std::upper_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l); 
    for (int i = l; i <= pre[l].r; i++) bans += (tmp[i] > c);
    for (int i = pre[r].l; i <= r; i++) bans += (tmp[i] > c);
    return bans;
}

signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &h[i].val), h[i].id = i, tmp[i] = h[i].val, pre[i].id = (i - 1) / len + 1;
    std::sort(h + 1, h + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        map[h[i].id] = i;
    for (int i = 1; i <= n; i++)
        add(map[i], 1), res += i - query(map[i]);
    for (int i = 1; i <= (num = (n - 1) / len + 1); i++)
        pre2[i] = {0, (i - 1) * len + 1, i * len};
    pre2[num].r = n;
    for (int i = 1; i <= n; i++){
        pre[i].l = pre2[pre[i].id].l;
        pre[i].r = pre2[pre[i].id].r;
    }
    for (int i = 1; i <= num; i++)
        sorter(i, 1);
    printf("%lld\n", res);
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld", &a, &b);
        if(a > b) std::swap(a, b);
        if(b - a > 1){
            int ta = query_2(a + 1, b - 1, tmp[a]);
            int tb = query_2(a + 1, b - 1, tmp[b]);
            int ta2 = query_3(a + 1, b - 1 , tmp[a]);
            int tb2 = query_3(a + 1, b - 1, tmp[b]);
            res -= (ta - ta2);
            res += (tb - tb2);
        }
        if(tmp[a] < tmp[b]) res++;
        if(tmp[a] > tmp[b]) res--;
        std::swap(tmp[a], tmp[b]);
        sorter(a, 0), sorter(b, 0);
        printf("%lld\n", res);
    }
}