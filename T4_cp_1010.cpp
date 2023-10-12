#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define get(i) (i / size + 1)
const int N = 1e5 + 5;
int n, m, a[N], size, num[N], cnt[N], ans[N];
struct Query{
    int id, l, r, k;
}q[N];
bool cmp(Query a, Query b){
    if(get(a.l) ^ get(b.l)) return get(a.l) < get(b.l);
    return a.r < b.r;
}
void add(int id){
    num[cnt[a[id]]]--;
    cnt[a[id]]++;
    num[cnt[a[id]]]++;
}
void del(int id){
    num[cnt[a[id]]]--;
    cnt[a[id]]--;
    num[cnt[a[id]]]++;
}
int main(){
    freopen("repeat.in", "r", stdin);
    freopen("repeat.out", "w", stdout);
    scanf("%d", &n);
    size = ceil(sqrt(n));
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k), q[i].id = i;
    std::sort(q + 1, q + 1 + m, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++){
        auto z = q[i];
        while(l > z.l) add(--l);
        while(r < z.r) add(++r);
        while(l < z.l) del(l++);
        while(r > z.r) del(r--);
        ans[z.id] = num[z.k];
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}