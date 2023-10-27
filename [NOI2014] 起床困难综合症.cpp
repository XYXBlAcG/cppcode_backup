#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#define int long long
using std::cin;
using std::cout;
using std::string;
int n, m, a = 0, b = -1, ans;
signed main(){
    std::ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, t; i <= n; i++){
        string op;
        cin >> op >> t;
        if(op == "AND"){
            a &= t, b &= t;
        }else if(op == "OR"){
            a |= t, b |= t;
        }else{
            a ^= t, b ^= t;
        }
    }
    for (int i = 32; ~i; i--){
        if(a >> i & 1) ans += (1ll << i);
        else if((b >> i & 1) && m >= (1ll << i)) ans += (1ll << i), m -= (1ll << i);
    }
    cout << ans << '\n';
    return 0;
}