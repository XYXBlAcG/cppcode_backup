#include <cstdio>
#include <iostream>
#define deb(x) std::cout << #x << " = " << x << std::endl
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;
int n;
struct Node{
    int xi, nor;
}f[N];
int m(int in){
    return (in % mod + mod) % mod;
}
int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int tmp = exgcd(b, a % b, x, y);
    int t = x; x = y, y = t - (a / b) * y;
    return tmp;
}
int inv(int a){
    int x, y, g = exgcd(a, mod, x, y);
    return (g != 1) ? 0 : (x % mod + mod) % mod;
}
// void debug(){
//     for (int i = 0; i <= n; i++){
//         printf("f[%lld] = {%lld,%lld}\n", i, f[i].xi, f[i].nor);
//     }
// }
signed main(){
    scanf("%lld", &n);
    // f[0] = (Node){1, 0};
    // f[1] = (Node){1, 1 * inv(n)};
    f[0] = (Node){1, 0};
    f[1] = (Node){1, -1};
    // for (int i = 2; i <= n; i++){
    //     // int div = inv(n - i + 1);
    //     // f[i] = (Node){f[i - 1].xi * n * div - f[i - 2].xi * (i - 1) * div, f[i - 1].nor * n * div - (i - 1) * div * f[i - 2].nor - n * div};
    // }
    for (int i = 1; i <= n; i++){
        int div = inv(n - i);
        // deb(div);
        f[i + 1].xi = (n * f[i].xi - i * f[i].xi) % mod * div % mod;
        f[i + 1].nor = (n * f[i].nor - i * f[i - 1].nor - n) % mod * div % mod;
        // f[i] = (Node){m(f[i + 1].xi * n * div - f[i + 2].xi * (n - i - 1) * div), m(f[i + 1].nor * n * div - f[i + 2].nor * (n - i - 1) * div - n * div)};
        // deb(f[i].xi), deb(f[i].nor);
    }
    int f_0 = m(-f[n].nor * inv(f[n].xi));
    // deb(f_0);
    for (int i = 0; i < n; i++){
        printf("%lld\n", m(m(f[i].xi * f_0) + f[i].nor));
    }printf("0\n");
    
    // debug();

    return 0;
}