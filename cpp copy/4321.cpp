#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define int long long
#define deb(x) std::cout << #x << " = " << x << std::endl;
const int N = 305;
int n, m, p, q, func[N][N], b[N], ans[N];
int mo(int x, int m){return (x % m + m) % m;}
int power(int x, int p, int q){
    long long ans = 1;
    for (; p; p >>= 1, x = x * x % q)
        if (p & 1) ans = ans * x % q;
    return ans;
}
int inv(int a, int mod){
    return power(a, mod - 2, mod);
}
void solve(){
    for (int i = 1; i <= n; i++){
        int flag = 0;
        for (int j = i; j <= m; j++)
            if(func[i][j]){flag = j; break;}
        // if(!flag && ans[i]) continue;
        // if(!flag && func[i][m + 1]) {puts("0"); return;}
        std::swap(func[i], func[flag]);
        int tmp = inv(func[i][i], p);
        for (int j = 1; j <= n; j++){
            if(j == i) continue;
            int tmp2 = tmp * func[j][i];
            for (int k = i; k <= m + 1; k++)
                func[j][k] = ((func[j][k] - (tmp2 % p) * func[i][k]) % p + p) % p;
        }
        for (int j = 1; j <= m + 1; j++)
            func[i][j] = func[i][j] * tmp % p;
    }

    for (int i = 1; i <= n; i++){
        int flag = 0;
        for (int j = 1; j <= m; j++)
            if(func[i][j]){flag = j; break;}
        if(!flag && func[i][n + 1]) {puts("0"); return;}
    }
    
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        int flag = 0;
        for (int j = i; j <= n; j++)
            if(func[j][i]){flag = 1; break;}
        if(!flag) cnt++;
    }
    printf("%lld\n", power(p, cnt, q));
    for (int i = 1; i <= m; i++)
        printf("%lld ", (func[i][n + 1] * inv(func[i][i], p) + p) % p);
    putchar('\n');
}
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m + 1; j++)
            scanf("%lld", &func[i][j]);
        ans[i] = func[i][m + 1];
        // scanf("%lld", &ans[i]);
    }
    solve();
    return 0;
}