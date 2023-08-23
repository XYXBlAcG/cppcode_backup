#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e3 + 5;
int n, T, m, Q, facc[N], invv[N], pre[N][N];
int qp(int a, int b, int c){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= c;
        (a *= a) %= c;
        b >>= 1;
    }
    return ans;
}
int inv(int a, int c){
    return qp(a, c - 2, c);
}
void pr(){
    for (int i = 1; (1 << i) <= n; i++){
        int k = (1 << i);
        for (int j = 1; j <= std::min(m, k); j++){
            pre[i][j] = 
        }
    }
}

signed main(){
    scanf("%lld", &T);
    for (int i = 1; i <= T; i++){
        
        scanf("%lld%lld%lld", &n, &m, &Q);
        
    }
}