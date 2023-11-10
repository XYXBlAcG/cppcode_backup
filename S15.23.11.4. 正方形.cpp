#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e6 + 5, top = 1e6, mod = 19260817;
int t, n, fac[N], g[N], f[N];
struct Node{int v, t;};
std::vector<Node> w[N];
int qp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int inv(int a){return qp(a, mod - 2);}
void pre(){
    for (int i = 2; i <= top; i++){
        if(w[i].empty()){
            w[i].push_back({i, 1});
            for (int j = 2; i * j <= top; j++){
                int tmp = j, len = 1;
                while(tmp % i == 0) tmp /= i, len++;
                w[i * j].push_back({i, len});
            }
        }
    }
}
void calc(){
    fac[0] = 1;
    for (int i = 1; i <= top; i++){
        fac[i] = fac[i - 1] * i % mod * i % mod;
        g[i] = fac[i] * qp(i, i * 2) % mod;
        for (auto V : w[i]){
            int t = V.t, v = V.v;
            int cur = 1, tmp;
            for (int j = 1; j <= t; j++){
                cur *= v, tmp = inv(qp(v, i / cur) % mod) % mod;
                (tmp *= tmp) %= mod, (g[i] *= (tmp * tmp % mod)) %= mod;
            }
        }
    }
}

void getf(){
    f[1] = 1;
    for (int i = 2; i <= top; i++)
        f[i] = f[i - 1] * g[i] % mod;
}

signed main(){
    scanf("%lld", &t);
    pre();
    calc();
    getf();
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}