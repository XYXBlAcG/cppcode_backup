#include <cstdio>
#include <vector>
typedef unsigned long long ll;
const int N = 1e6 + 5, P = 99991, M = 100003;
ll n, l, a, jc[N];
struct Node{
    ll h0, h1, cnt;
};
std::vector<Node> hash[N];
void pre(){
    jc[0] = 1;
    for (ll i = 1; i <= N - 5; i++)
        jc[i] = jc[i - 1] * P;
}
ll find(ll h0, ll h1){
    for (auto& v : hash[h0]){
        if(v.h1 == h1){
            return ++v.cnt;
        }
    }
    hash[h0].push_back({h0, h1, 0});
    return 0;
}
int main(){
    scanf("%llu", &n);
    pre();
    for (ll i = 1; i <= n; i++){
        scanf("%llu", &l);
        ll res = 0;
        for (ll j = 1; j <= l; j++){
            ll tmp = 0;
            scanf("%llu", &tmp);
            res += tmp * jc[j];
            // printf("resM = %llu, res = %llu\n", res % M, res);
            printf("%llu ", find(res % M, res));
        }
        putchar('\n');
    }
    return 0;
}