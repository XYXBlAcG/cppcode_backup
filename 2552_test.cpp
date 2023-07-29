#include <cstdio>
#include <algorithm>
#include <math.h>
using std::max;
const int N = 105;
typedef unsigned long long llu; // 注意，这里应该是 unsigned long long
llu n, m; llu mod = 1000000007;
llu pos[N][N];
bool sign[N];
llu f[2][N][N];
inline llu read() {
    llu x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
  }
  return x * w;
}
int main(){
    n = read(); m = read();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            pos[i][j] = read();
        }
    }
    int lent = 0;
    for (llu a = m; a > 1;){ // 注意，这里应该是 unsigned long long
        if(a & 1) {a >>= 1; sign[++lent] = 1;}
        else {a--; ++lent;}
    }
    int roll = 0;
    for (int i = 1; i <= n; i++){
        f[roll ^ 1][1][i] = 1;
        for (int j = 2; j <= n; j++){
            f[roll ^ 1][j][i] = 0;
        }
    }
    llu t = m;
    if(lent){
        if(sign[lent]){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    f[roll][i][j] = 0; // 注意，这里需要清零
                    for (int k = 1; k <= n; k++){
                        f[roll][i][j] += f[roll ^ 1][i][k] * f[roll ^ 1][k][j];
                        f[roll][i][j] %= mod;
                    }
                }
            }
        }else{
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    f[roll][i][j] = 0; // 注意，这里需要清零
                    for (int k = 1; k <= n; k++){
                        f[roll][i][j] += f[roll ^ 1][i][k] * pos[k][j];
                        f[roll][i][j] %= mod;
                    }
                }
            }
        }
        lent--; roll ^= 1;
    }
    llu res = 0;  
        for (int j = 1; j <= n; j++){
            res += f[roll][1][j];
        }
    printf("%llu\n", res % mod); // 注意，这里需要对结果取模
    return 0;
}
