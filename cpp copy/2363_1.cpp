#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
typedef long long ll;
const ll mod = 1000000007;
int n, m;
ll ans;
const int N = 2010;
int cha[N][N];
int map[N][N];
int vis[N][N];
struct Node{
    int t, b, l, r;
}oop[N][N];
inline int read() {
    int x = 0, w = 1;
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
    scanf("%d%d",&n,&m);
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            oop[i][j].t = read();
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            oop[i][j].b = read();
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            oop[i][j].l = read();
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            oop[i][j].r = read();
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            int t = oop[i][j].t;
            int b = oop[i][j].b;
            int l = oop[i][j].l;
            int r = oop[i][j].r;
            cha[t][l]++; cha[t][r+1]--;
            cha[b+1][l]--; cha[b+1][r+1]++;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + cha[i][j];
            ans += map[i][j];
            ans %= mod;
        }
    }
    printf("%lld", ans);
    return 0;
}
