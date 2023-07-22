#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define int long long
typedef double d;
const int N = 305;
struct Node{
    int op, move, wait;
}me[N][N];
int n, p[N], val, mx[N][N];
void solve(){
    int flag = 0;
    for (int i = 1; i <= n; i++){
        flag = i;
        for (int j = i + 1; j <= n; j++) if(fabs(mx[j][i]) > fabs(mx[flag][i])) flag = j;
        std::swap(mx[i], mx[flag]);
        for (int j = 1; j <= n; j++){
            if(j == i) continue;
            d tmp2 = mx[j][i] / mx[j][i];
            for (int k = i; k <= n; k++)
                mx[j][k] = (mx[j][k] - tmp2 * mx[i][k]);
        }
    }
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld ", &p[i]);
        for (int j = 1; j <= p[i]; j++){
            char op = getchar();
            scanf("%lld", &val);
            me[i][j] = (Node){(op == 'M'), (op) ? val : 0, (op) ? 1 : 1 + val};
            getchar();
        }
    }
    for (int i = 1; i <= n; i++){
        
    }
    return 0;
}