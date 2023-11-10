#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int M = 105, top = 100, mod = 1e9 + 7;
int n, m;
struct Mat{
    int data[M][M];
    int* operator[](int x){return data[x];}
    Mat(){memset(data, 0, sizeof(data));}
}a, res;
Mat operator*(Mat a, Mat b){
    Mat res;
    
    for (int i = 1; i <= top; i++){
        for (int k = 1; k <= top; k++){
            for (int j = 1; j <= top; j++){
                (res[i][j] += a[i][k] * b[k][j]) %= mod;
            }
        }
    }
    return res;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", a[i] + j);
    for (int i = 1; i <= n; i++) res[i][i] = 1;
    while(m){
        if(m & 1) res = res * a;
        a = a * a;
        m >>= 1;
    }
    for (int j = 1; j <= n; j++){
        printf("%lld ", res[1][j]);
    }putchar('\n');
    return 0;
}