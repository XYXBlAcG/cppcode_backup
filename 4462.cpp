#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
const int N = 8e4 + 5, M = 500;
struct Node{
    int id, l, r;
}pre[N], pre2[M];
int n, a[N], tag[M], m, so[N];
void debug(){
    printf("sort\n");
    for (int i = 0; i < n; i++){
        printf("%lld ", so[i]);
    }putchar('\n');
    printf("a\n");
    for (int i = 0; i < n; i++){
        printf("%lld ", a[i]);
    }putchar('\n');
    printf("tag\n");
    for (int i = 1; i <= pre[n - 1].id; i++){
        printf("%lld ", tag[i]);
    }putchar('\n');
}
void sorter(int id){
    int l = pre[id].l, r = pre[id].r;
    for (int i = l; i <= r; i++){
        so[i] = a[i];
    }
    std::sort(so + l, so + r + 1);
}
void add(int l, int r, int c){
    int ll = pre[l].id, rr = pre[r].id;
    if(ll == rr) {
        for (int i = l; i <= r; i++) a[i] += c;
        sorter(l); return;
    }
    for (int i = ll + 1; i < rr; i++) tag[i] += c;
    for (int i = l; i <= pre[l].r; i++) a[i] += c;
    for (int i = pre[r].l; i <= r; i++) a[i] += c;
    sorter(l); sorter(r);
}
int query(int l, int r, int c){
    int ll = pre[l].id, rr = pre[r].id, ans = 0;
    if(ll == rr){
        for (int i = l; i <= r; i++) ans += (a[i] + tag[ll] < c);
        return ans;
    }
    for (int i = ll + 1; i < rr; i++){
        // ans += std::lower_bound(so + pre[i].l, so + pre[i].r + 1, c - tag[i]) - so - pre[i].l;
        ans += std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c - tag[i]) - so - pre2[i].l;
    }
    for (int i = l; i <= pre[l].r; i++) ans += (a[i] + tag[pre[i].id] < c);
    for (int i = pre[r].l; i <= r; i++) ans += (a[i] + tag[pre[i].id] < c);
    return ans;
}
signed main(){
    scanf("%lld", &n), m = std::sqrt(n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0, j = 0; i < n; i++){
        if(i % m == 0) j++;
        pre[i] = (Node){j, (j - 1) * m, j * m - 1};
    }
    for (int i = 0, j = 0; i < n; i++){
        if(i % m == 0){
            pre2[++j].l = i;
            pre2[j - 1].r = i - 1;
        }
    }
    pre2[pre[n - 1].id].r = n - 1;
    // for (int i = 1; i <= pre[n - 1].id; i++){
    //     printf("%lld %lld\n", pre2[i].l, pre2[i].r);
    //     sorter(i);
    // }
    for (int i = 0; i < n; i++){
        if(i % m == 0) sorter(i);
    }
    
    // for (int i = 0; i < n; i++){
    //     printf("%lld %lld %lld\n", pre[i].id, pre[i].l, pre[i].r);
    // }
    for (int i = 1; i <= n; i++){
        int op, l, r, c;
        scanf("%lld%lld%lld%lld", &op, &l, &r, &c);
        l--, r--;
        if(!op){
            add(l, r, c);
        }else{
            printf("%lld\n", query(l, r, c * c));
            // printf("%lld %lld %lld %lld\n", l + 1, r + 1, c * c, query(l, r, c * c));
        }
        // debug();
    }
    return 0;
}