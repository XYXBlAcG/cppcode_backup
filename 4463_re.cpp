// #pragma GCC optimize("Ofast")
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using std::min; 
const int N = 5e4 + 5;
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
void sorter(int id){
    int l = pre[id].l, r = pre[id].r;
    std::copy(tmp + l, tmp + r + 1, so + l);
    std::sort(so + l, so + r + 1);
}
int query_2(int l, int r, int c){ // 比他小的
    int ll = pre[l].id, rr = pre[r].id, ans = 0;
    if(ll == rr){
        for (int i = l; i <= r; i++) ans += (tmp[i] < c);
        return ans;
    }
    for (int i = ll + 1; i < rr; i++){
        ans += std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l;
    }
    for (int i = l; i <= pre[l].r; i++) ans += (tmp[i] < c);
    for (int i = pre[r].l; i <= r; i++) ans += (tmp[i] < c);
    return ans;
}
int query_3(int l, int r, int c){ // 比他大的
    int ll = pre[l].id, rr = pre[r].id, ans = 0;
    if(ll == rr){
        for (int i = l; i <= r; i++) ans += (tmp[i] > c);
        return ans;
    }
    for (int i = ll + 1; i < rr; i++){
        ans += pre2[i].r + 1 - (std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l);
    }
    for (int i = l; i <= pre[l].r; i++) ans += (tmp[i] > c);
    for (int i = pre[r].l; i <= r; i++) ans += (tmp[i] > c);
    return ans;
}

signed main(){
    scanf("%lld", &n), num = sqrt(n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &h[i].val), h[i].id = i, tmp[i - 1] = h[i].val;
    }
    std::sort(h + 1, h + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        map[h[i].id] = i;
    for (int i = 1; i <= n; i++){
        add(map[i], 1);
        res += i - query(map[i]);
    }
    for (int i = 0, j = 0; i < n; i++){
        if(i % num == 0) j++;
        pre[i] = (Note){j, (j - 1) * m, j * m - 1};
    }
    for (int i = 0, j = 0; i < n; i++){
        if(i % m == 0){
            pre2[++j].l = i;
            pre2[j - 1].r = i - 1;
        }
    }
    pre2[pre[n - 1].id].r = n - 1;
    for (int i = 0; i < n; i++){
        if(i % m == 0) sorter(i);
    }
    printf("%lld\n", res);
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld", &a, &b);
        if(a > b) std::swap(a, b);
        a++, b++;
        int ta = query_2(a + 1, b - 1, tmp[a]); // 左界移动
        int tb = query_2(a + 1, b - 1, tmp[b]);
        int ta2 = query_3(a + 1, b - 1, tmp[a]);
        int tb2 = query_3(a + 1, b - 1, tmp[b]);
        res = res + (ta - ta2);
        res = res - (tb - tb2);
        std::swap(tmp[a], tmp[b]);
        sorter(a), sorter(b);
        printf("%lld\n", res);
        // std::swap(h[a], h[b]); 
    }
}