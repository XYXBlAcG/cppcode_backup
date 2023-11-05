#include <cstdio>
#include <algorithm>
#include <unordered_map>
const int N = 2e5 + 5;
typedef unsigned long long ll;
std::unordered_map<ll, int> mp;
int n, m, k, a[N], ans[N], cnt = 1; 
ll p[25], tmp[25];
struct Node{
    int l, r, id;
    ll has;
}seg[N];
bool cmp(Node a, Node b){return a.r < b.r;}
void init(){
    p[1] = 1;
    for (int i = 2; i <= 20; i++) p[i] = p[i - 1] * 10000000033;
}
ll gethas(){
    ll ret = 0;
    for (int i = 1; i <= k; i++) ret += p[i] * tmp[i];
    return ret;
}
int main(){
    init();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &seg[i].l, &seg[i].r), seg[i].id = i;
        for (int j = 1; j <= k; j++) scanf("%llu", tmp + j);
        seg[i].has = gethas();
    }
    std::sort(seg + 1, seg + 1 + m, cmp);
    for (int i = 1; i <= n; i++){
        if(i <= n - k + 1){
            for (int j = 1; j <= k; j++)
                tmp[j] = 1llu * a[i + j - 1];
            mp[gethas()] = i;
        }
        while(seg[cnt].r == i + k - 1){
            if(mp.find(seg[cnt].has) == mp.end() || mp[seg[cnt].has] < seg[cnt].l) ans[seg[cnt].id] = 1;
            else ans[seg[cnt].id] = 0;
            cnt++;
        }
    }
    for (int i = 1; i <= m; i++) puts(ans[i] ? "Yes" : "No");
    return 0;
}