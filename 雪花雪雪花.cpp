#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int unsigned long long
const int N = 1e5 + 5, mod = 99991, mod2 = 9223372036854775807;
struct Node{
    int hasval, id;
};
std::vector<Node> has[N];
int n, p0[N], hasv[N];
struct Snow{
    int data[10];
    int& operator[](int x){return data[x];}
}snow[N];
void init(){
    p0[1] = 1;
    for (int i = 2; i <= 10; i++)
        p0[i] = p0[i - 1] * 2 % mod2;
}
void insert(int x){
    int ha = mod2;
    for (int i = 0; i <= 5; i++){
        int cur = i, tmp = 0, tmp2 = 0;
        for (int j = 0; j <= 5; j++){
            (cur += 1) %= 6;
            tmp += p0[j] * snow[x][cur] % mod2;
            tmp2 += p0[5 - j] * snow[x][cur] % mod2;
        }
        ha = std::min({ha, tmp, tmp2});
    }
    // printf("x = %llu, ha = %llu\n", x, ha);
    has[ha % mod].push_back({ha, x});
    hasv[x] = ha;
}
int query(int x){
    for (auto v : has[x % mod])
        if(x == v.hasval) return v.id;
    return 0;
}
signed main(){
    scanf("%lld", &n);
    init();
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 5; j++) scanf("%lld", &snow[i][j]);
        insert(i);
    }
    for (int i = 1; i <= n; i++)
        printf("%llu\n", query(hasv[i]));
    return 0;
}