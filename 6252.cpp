#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define get(i) (i / size + 1)
const int N = 1e5 + 5;
int n, m, k, a[N], size, num, cnt[N], ans[N];
struct Query{
    int id, l, r;
}q[N];
bool cmp(Query a, Query b){
    if(get(a.l) ^ get(b.l)) return get(a.l) < get(b.l);
    if(get(a.l) & 1) return a.r < b.r;
    else return a.r > b.r;
}
void add(int id){
    num += 2 * cnt[a[id]] + 1;
    cnt[a[id]]++;
}
void del(int id){
    num -= 2 * cnt[a[id]] - 1;
    cnt[a[id]]--;
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    size = (int)sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= m; i++) scanf("%lld%lld", &q[i].l, &q[i].r), q[i].id = i;
    std::sort(q + 1, q + 1 + m, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++){
        auto z = q[i];
        while(l > z.l) add(--l);
        while(r < z.r) add(++r);
        while(l < z.l) del(l++);
        while(r > z.r) del(r--);
        ans[z.id] = num;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}