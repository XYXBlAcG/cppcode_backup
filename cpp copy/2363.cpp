#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
typedef long long ll;
const ll mod = 1000000007;
int n, m;
ll ans;
const int N = 2010;
int sum[N][N];
int map[N][N];
int vis[N][N];
// int f(int x, int y);
// int s(int i, int j);
struct Node{
    int t, b, l, r;
}oop[N][N];
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n - 1; i++){
        for (int j = 1; j <= m - 1; j++){
            oop[i][j].t = read();
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = 1; j <= m - 1; j++){
            oop[i][j].b = read();
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = 1; j <= m - 1; j++){
            oop[i][j].l = read();
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = 1; j <= m - 1; j++){
            oop[i][j].r = read();
        }
    }
     for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= m; j++){
            sum[i][j] = 1;
        }
    }
    // for (int i = 1; i <= n - 1; i++){
    //     for (int j = 1; j <= m - 1; j++){
    //         int t = oop[i][j].t;
    //         int b = oop[i][j].b;
    //         int l = oop[i][j].l;
    //         int r = oop[i][j].r;
    //         sum[t][l]++; sum[t][r + 1]--;
    //         sum[b + 1][l]--; sum[b + 1][r + 1]++;
    //     }
    // }
    map[n][m] = 1;
    
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            if(j == m || i == n){continue;}
            int t = oop[i][j].t;
            int b = oop[i][j].b;
            int l = oop[i][j].l;
            int r = oop[i][j].r;
            map[i][j] = (((sum[t][l] - sum[t][r + 1])% mod - sum[b + 1][l])% mod + sum[b + 1][r + 1])% mod;
            sum[i][j] = (((sum[i + 1][j] + sum[i][j + 1])% mod - sum[i + 1][j + 1])% mod + map[i][j])% mod;
            // if(map[i][j] >= mod )map[i][j] %= mod;
            // if(sum[i][j] >= mod )sum[i][j] %= mod;
            // ans += map[i][j];
            // if (!i) break;
            // if (!j) continue;
        }
        // map[1][1] %= mod;
        // ans %= mod;
    }
    

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         printf("%d ",map[i][j]);
    //     }printf("\n");
    // }
    // ans = sum(n,m);
    
    printf("%lld",(map[1][1]+mod)%mod);
    return 0;
}

// map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + read();

// int s(int i, int j){
//     if (j == -1) return 0;
//     else return s(i, j - 1) + f(i, j);
// };
// int f(int x, int y){
//     int t = oop[x][y].t;
//     int b = oop[x][y].b;
//     int l = oop[x][y].l;
//     int r = oop[x][y].r;
//     return s(t, l) - s(b + 1, l) - s(t, r + 1) + f(b + 1, r + 1);
// };
