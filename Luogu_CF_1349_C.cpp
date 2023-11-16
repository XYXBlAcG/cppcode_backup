#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
using std::string;
const int N = 1e3 + 5;
int n, m, t;
bool mat[N][N];
char rd[N];
signed main(){
    scanf("%lld%lld%lld", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%s", rd);
        for (int j = 1; j <= m; j++) mat[i][j] = rd[j - 1] - '0';
    }
    for (int i = 1, p, x, y; i <= t; i++){
        scanf("%lld%lld%lld", &t, &x, &y);
        
    }
    return 0;
}