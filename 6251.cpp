#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define pos(u) u / num + 1 
const int N = 50005;
int n, m, c[N], num, cnt[N], res;
struct Ans{
    int a, b;
}ans[N];
struct Node{
    int l, r, id;
}node[N];
bool cmp(Node a, Node b){
    if(pos(a.l) ^ pos(b.l)) return pos(a.l) < pos(b.l);
    if(pos(a.l) & 1) return a.r < b.r;
    else return a.r > b.r;
}
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
void add(int x){
    cnt[c[x]]++;
    if(cnt[c[x]] > 1) res += ((cnt[c[x]] - 1) * cnt[c[x]]) - ((cnt[c[x]] - 2) * (cnt[c[x]] - 1));
}
void del(int x){
    cnt[c[x]]--;
    if(cnt[c[x]]) res += ((cnt[c[x]] - 1) * cnt[c[x]]) - ((cnt[c[x]]) * (cnt[c[x]] + 1));
}
signed main(){
    scanf("%lld%lld", &n, &m);
    num = (int)sqrt(n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", c + i);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld", &node[i].l, &node[i].r), node[i].id = i;
    std::sort(node + 1, node + 1 + m, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++){
        Node& q = node[i];
        while(l > q.l) add(--l);
        while(r < q.r) add(++r);
        while(l < q.l) del(l++);
        while(r > q.r) del(r--);
        ans[q.id].a = res;
        ans[q.id].b = (q.r - q.l) * (q.r - q.l + 1);
        int gc = gcd(ans[q.id].a, ans[q.id].b);
        if(ans[q.id].a == 0){
            ans[q.id] = {0, 1};
        }else ans[q.id] = {ans[q.id].a / gc, ans[q.id].b / gc};
    }
    for (int i = 1; i <= m; i++) printf("%lld/%lld\n", ans[i].a, ans[i].b);
    return 0;
}