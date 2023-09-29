#include <cstdio>
#include <algorithm>
#define int unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define len(x) (n - x + 1)
#define hasher(l, r) (hash[r] - hash[l - 1] * jc[r - l + 1])
#define comp(x) ((x > n) ? -INF : (int)str[x])
const int N = 2e5 + 5, P = 99991;
int n, jc[N], idx[N], hash[N];
char str[N];
void pre(){
    jc[0] = 1;
    for (int i = 1; i <= n; i++){
        jc[i] = jc[i - 1] * P, idx[i] = i;
        hash[i] = hash[i - 1] * P + str[i];
    }
}
bool check(int l, int r, int mid){
    if(l > r) return (hash[l + mid - 1] - hash[l - 1]) == (hash[r + mid - 1] - hash[r]) * jc[l - r];
    else return (hash[l + mid - 1] - hash[l]) * jc[r - l] == (hash[r + mid - 1] - hash[r]);
}
int bin(int a, int b){
    int ll = 0, rr = std::min(len(a), len(b));
    while(ll < rr){
        int mid = (ll + rr + 1) >> 1;
        if(hasher(a, a + mid - 1) != hasher(b, b + mid - 1)) rr = mid - 1;
        // if(!check(l, r, mid)) rr = mid - 1;
        else ll = mid;
    }
    // printf("ll = %lld\n", ll);
    return ll;
}
bool cmp(int a, int b){
    int st = bin(a, b);
    // printf("a = %llu, b = %llu, az = %d\n", comp(a + st), comp(b + st), (bool)(comp(a + st) < comp(b + st)));
    // return comp(a + st) < comp(b + st);
    return str[a + st] < str[b + st];
}
signed main(){
    for (char c = getchar(); c >= 'a' && c <= 'z'; c = getchar())
        str[++n] = c;
    pre();
    std::sort(idx + 1, idx + 1 + n, cmp);
    for (int i = 1; i <= n; i++) printf("%llu ", idx[i]); putchar('\n');
    return 0;
}