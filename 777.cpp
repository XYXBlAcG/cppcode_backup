#include <cstdio>
#include <cstring>
#define int long long
const int N = 23, mod = 1e9 + 7;
int T, l, r, num[N], len, vis[N][10][10], mpow[N];
struct Node{
    int _1, _2, _3;
    void add(Node a, int x, int pos){
        (_1 += a._1) %= mod;
        (_2 += (a._2 + (x * mpow[pos] % mod) * a._1 % mod)) %= mod;
        (_3 += (a._3 + (2 * x * mpow[pos] % mod * a._2) % mod) % mod + (x * mpow[pos] % mod) * ((x * mpow[pos] % mod) * a._1 % mod) % mod) %= mod; 
    }
}f[N][10][10];
Node dfs(int a, int c, int d, bool lim){
    if(!a) return {c && d, 0, 0};
    if(!lim && vis[a][c][d]) return f[a][c][d]; 
    Node ans = {0, 0, 0};
    int top = lim ? num[a] : 9;
    for (int i = 0; i <= top; i++){
        if(i == 7) continue;
        ans.add(dfs(a - 1, (c * 10 + i) % 7, (d + i) % 7, lim && (i == num[a])), i, a);
    }
    if(!lim) f[a][c][d] = ans, vis[a][c][d] = 1;
    return ans;
}
int solve(int a){
    len = 0;
    while(a) num[++len] = a % 10, a /= 10;
    return dfs(len, 0, 0, 1)._3;
}
void clean(){
    memset(vis, 0, sizeof(vis));
    memset(f, 0, sizeof(f));
}
void init(){
    mpow[1] = 1;
    for (int i = 2; i <= 19; i++)
        mpow[i] = mpow[i - 1] * 10 % mod;
}
void work(){
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", (solve(r) - solve(l - 1) + mod) % mod);
}
signed main(){
    scanf("%lld", &T);
    init();
    while(T--)
        work(), clean();
    return 0;
}