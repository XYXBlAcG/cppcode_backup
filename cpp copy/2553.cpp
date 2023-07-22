#include <cstdio>
#include <algorithm>
const int N = 105;
typedef unsigned long long llu;
llu n, m;
llu pos[N][N];
inline llu read() {
    llu x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 llu 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    llu T = read();
    for (int a = 1; a <= T; a++) {
        n = read(); m = read();
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                pos[i][j] = read();
            }
        }
    }
    return 0;
}