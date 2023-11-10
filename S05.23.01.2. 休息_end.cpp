#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e5 + 5;
int L, K;
struct Node{
    int l, r, a, b;
}node[N];
signed main(){
    scanf("%lld%lld", &L, &K);
    for (int i = 1, l, r, a, b; i <= L; i++){
        scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
        node[i] = {l, r, a, b};
    }
    for (int i = 1; i <= L; i++){
        
    }
    return 0;
}