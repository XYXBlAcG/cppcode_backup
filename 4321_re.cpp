#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 310;
int n, m, p, q, a[N][N], ans[N];
int qp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= p;
        (a *= a) %= p;
        b >>= 1;
    }
    return ans;
}
int inv(int a){
    return qp(a, p - 2);
}
void gs(){
    for (int i = 1; i <= m; i++){
        int mx = i;
        for (int j = i + 1; j <= n; j++) 
            if(std::abs(a[mx][i]) < std::abs(a[j][i])) mx = j;
        if(!a[mx][i]){
            puts("0");
            exit(0);
        }
        if(m ^ i) std::swap(a[m], a[i]);
        int div = inv(a[i][i]);
        for (int j = i; j <= m + 1; j++) a[i][j] *= div;
        for (int j = i + 1; j <= n; j++){
            div = a[j][i];
            for (int k = i; k <= m + 1; k++){
                a[j][k] -= a[i][k] * div;
            }
        }
    }
    ans[n] = a[n][m + 1];
    for (int i = n - 1; i; i--){
        ans[i] = a[i][m + 1];
        for (int j = i + 1; j <= m; j++){
            ans[i] -= a[i][j] * ans[j];
        }
    }
}
int main(){
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m + 1; j++)
            scanf("%d", &a[i][j]);
    gs();
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}