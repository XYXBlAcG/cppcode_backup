#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
typedef unsigned long long ll;
const int N = 505;
char rd[N];
bool vis[N][N];
struct Node{
    ll v, w;
};
std::vector<Node> st[N * N * 8];
ll m, n, k, mat[N][N], P = 99991, M = 1000003, jc[N * N * 8], chr[N * N * 8], tc, up, ed;
ll qp(ll a, ll b){
    ll ans = 1;
    while(b){ if(b & 1) ans *= a; a *= a; b >>= 1; }
    return ans;
}
void query(ll hash){
    // printf("mod = %llu, hash = %llu\n", hash % M, hash);
    for (auto& v : st[hash % M]){
        if(v.v == hash) {up += v.w * 2 + 1, v.w++; return;}
    }
    st[hash % M].push_back({hash, 1}), up++;
}
void clean(){
    for (int i = 1; i <= (int)m; i++)
        for (int j = 1; j <= (int)n; j++)
            vis[i][j] = 0;
}
void pre(){
    jc[0] = 1;
    for (int i = 1; i <= (N - 5) * (N - 5) * 8; i++)
        jc[i] = jc[i - 1] * P;
}
ll f(ll q, ll o){
    if(o <= 1) return o;
    if(o & 1) return (1 + q) * f(q * q, o >> 1) * q + 1;
    else return (1 + q) * f(q * q, o >> 1);
}
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
int main(){
    scanf("%llu%llu%llu", &m, &n, &k), pre(), ed = qp(P, k);
    for (int i = 1; i <= (int)m; i++){
        scanf("%s", rd + 1);
        for (int j = 1; j <= (int)n; j++)
            mat[i][j] = rd[j] - 'a' + 1;
    }
    for (int d = 0; d < 8; d++){
        for (int i = 1; i <= (int)m; i++){
            for (int j = 1; j <= (int)n; j++){
                if(!vis[i][j]){
                    ll hash = 0;
                    int x = i, y = j;
                    while(!vis[x][y]){
                        hash = hash * P + mat[x][y], chr[++tc] = mat[x][y], vis[x][y] = 1;
                        x += "11022002"[d] - '1', y += "02110022"[d] - '1';
                        if(x == (int)m + 1) x = 1; if(y == (int)n + 1) y = 1;
                        if(x == 0) x = m; if(y == 0) y = n;
                        // printf("x = %d, y = %d\n", x, y);
                    }
                    int az = k % tc;
                    hash *= f(jc[tc], k / tc);
                    for (int o = 1; o <= az; o++) hash = hash * P + chr[o];
                    for (int o = 1; o <= (int)tc; o++) {
                        query(hash);
                        int cnm = o + az;
                        if(o + az >= (int)tc + 1) cnm = o + az - tc; 
                        hash = hash * P - chr[o] * ed + chr[cnm];
                    }
                    tc = 0;
                }
            }
        }
        clean();
    }
    ll down = (n * m * 8) * (n * m * 8), gg = gcd(up, down);
    printf("%llu/%llu\n", up / gg, down / gg);
    return 0;
}