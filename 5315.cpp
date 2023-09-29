#include <cstdio>
#include <vector>
typedef unsigned long long ll;
const ll N = 1e6 + 5, MAXM = 32;
ll n, k, id[N], sum[N][MAXM], s[N][MAXM], c[N][MAXM], jc[MAXM], P = 99991, M = 100003, ans;
struct Node{
    ll ii, h0, h1;
};
std::vector<Node> hash[N];
void pre(){
    jc[0] = 1;
    for (ll i = 1; i <= k; i++)
        jc[i] = jc[i - 1] * P;
}
ll find(ll h0, ll h1, ll ii){
    for (auto v : hash[h0])
        if(v.h1 == h1)
            return v.ii;
    hash[h0].push_back({ii, h0, h1});
    return ii;
}
ll hash_(ll x){
    ll res = 0;
    for (ll i = 1; i <= k; i++)
        res += c[x][i] * jc[i];
    return res;
}
signed main(){
    scanf("%llu%llu", &n, &k);
    pre();
    for (ll i = 1; i <= n; i++){
        scanf("%llu", id + i);
        for (ll tmp = id[i], cnt = 1; tmp; tmp >>= 1, cnt++)
            sum[i][cnt] = tmp & 1;
    }
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= k; j++){
            s[i][j] += s[i - 1][j] + sum[i][j];
        }
    }
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= k; j++){
            c[i][j] = s[i][j] - s[i][1];
        }
    }
    for (ll i = 0; i <= n; i++){
        ll hasher = hash_(i);
        ll l = find(hasher % M, hasher, i);
        ans = std::max((i - l), ans);
    }
    printf("%llu\n", ans);
    return 0;
}