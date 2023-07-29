#include <cstdio>
#include <algorithm>
const int N = 5050;
long long n, m;
long long a[N], b[N], c[N];
// int ans[4][N];
long long ans1[2000 * 5000 + 10];
bool cmp(const long long& a, const long long& b){
    return a > b;
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
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    n = read(); m = read();
    for (int i = 1; i <= n; i++){
        a[i] = read();
        b[i] = read();
        c[i] = read();
    }
    long long cnt = 0;
    for (int j = 1; j <= n; j++){
        for (int i = 0; i <= m; i++){
            ans1[++cnt] = i * i * a[j] + i * b[j] + c[j];
        }
    }
    std::make_heap(ans1 + 1, ans1 + cnt + 1, cmp);
    // std::sort(ans1 + 1, ans1 + n * m + 1);
    // ms(1 , n * m);
    for (int i = 1; i <= m; i++){
        printf("%lld ", ans1[1]);
        std::pop_heap(ans1 + 1, ans1 + cnt + 2 - i, cmp);
    }
    return 0;
}