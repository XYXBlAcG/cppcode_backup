#include <cstdio>
#include <algorithm>
using std::max;
const long long N = (1 << 22) + 11;
long long map[25][8];
long long choice[25];
long long num[2][N];
// long long cnt[N];
// long long ans[25][8];
// long long xl;
// long long xz;
long long n, m;
long long res;
// long long key = 0, flag = 0;
// long long ans[13][8];
// bool cmp(const Node& a, const Node& b){
//     return a.val < b.val;
// }
void f1(long long x){
    if(x == (n >> 1) + 1){
        long long cur = 0;
        for(long long i = 1; i <= x - 1; i++){
            cur ^= map[i][choice[i]];
        }
        num[0][cur]++;
        return;
    }
    for(long long i = 1; i <= m; i++){
        choice[x] = i;
        f1(x + 1);
    }
}
void f2(long long x){
    if(x == n + 1){
        long long cur = 0;
        for(long long i = (n >> 1) + 1;i <= x - 1; i++){
            cur ^= map[i][choice[i]];
        }
        num[1][cur]++;
        return;
    }
    for(long long i = 1; i <= m; i++){
        choice[x] = i;
        f2(x + 1);
    }
}
inline long long read() {
    long long x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 long long 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    n = read(); m = read();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            map[i][j] = read();
        }
    }
    f1(1); f2((n >> 1) + 1);
    // printf("res: %lld\n", res);
    for(int i = 0; i <= N - 12; i++){
        if(!num[0][i] || !num[1][i]) continue;
        res += num[0][i] * num[1][i];
        // printf("num[0]: %d ", num[0][i]);
        // printf("num[1]: %d ", num[1][i]);
        // printf("res: %lld\n", res);
    }
    printf("%lld ", res);
    return 0;
}

// cnt[map[x][y]]++;
//     if(x == key){
//         if(ans[x][y] == 0){
//             return 1;
//         }else{
//             return 0;
//         }
//     }
//     long long result = 0;
//     for (long long i = 1; i <= m; i++){
//         result += f(x + 1, i);
//         ans[x + 1][i] = ans[x][y] ^ map[x + 1][i];
//     }
//     return result;