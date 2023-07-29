#include <cstdio>
#include <algorithm>
#define int long long
const int N = 1e6 + 5;
int n;
int hei[N];
int dan[N];
int lef[N];
int dlen;
// int hlen;
int ans;
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
signed main(){
    n = read();
    hei[0] = -1; dan[0] = 0;
    for (int i = 1; i <= n + 1; i++){
        if(i <= n) hei[i] = read();
        for (; hei[dan[dlen]] >= hei[i]; dlen--){
            ans = std::max(ans, hei[dan[dlen]] * (i - lef[dan[dlen]] - 1));
        }
        lef[i] = dan[dlen];
        dan[++dlen] = i;
    }
    printf("%lld\n", ans);
    return 0;
}