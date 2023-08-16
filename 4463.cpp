#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
const int N = 5e4 + 5;
int n, h[N], m, a, b, num, back[N], so[N], tag[N], sum;
struct Node{
    int id, l, r;
}pre[N], pre2[N];
void sorter(int id){
    int l = pre[id].l, r = pre[id].r;
    std::copy(h + l, h + r + 1, so + l);
    std::sort(so + l, so + r + 1);
}
int query(int l, int r, int c){
    int ll = pre[l].id, rr = pre[r].id, ans = 0;
    if(ll == rr){
        for (int i = l; i <= r; i++) ans += (h[i] < c);
        return ans;
    }
    for (int i = ll + 1; i < rr; i++){
        ans += std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l;
    }
    for (int i = l; i <= pre[l].r; i++) ans += (h[i] < c);
    for (int i = pre[r].l; i <= r; i++) ans += (h[i] < c);
    return ans;
}
void add(int l, int r, int c){
    int ll = pre[l].id, rr = pre[r].id;
    if(ll == rr) {
        for (int i = l; i <= r; i++) h[i] += c;
        sorter(l); return;
    }
    for (int i = ll + 1; i < rr; i++) tag[i] += c;
    for (int i = l; i <= pre[l].r; i++) h[i] += c;
    for (int i = pre[r].l; i <= r; i++) h[i] += c;
    sorter(l); sorter(r);
}
signed main(){
    scanf("%lld", &n), num = sqrt(n);
    for (int i = 0; i < n; i++){
        scanf("%lld", h + i);
    }
    for (int i = 0, j = 0; i < n; i++){
        if(i % num == 0) j++;
        pre[i] = (Node){j, (j - 1) * m, j * m - 1};
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
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(h[i] > h[j]) back[i]++;
        }
    }
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld", &a, &b);
        a++, b++;
        int ta = query(a + 1, b - 1, h[a]);
        int tb = query(a + 1, b - 1, h[b]);
        
        std::swap(h[a], h[b]);
        
        // std::swap(h[a], h[b]); 
    }
    return 0;
}