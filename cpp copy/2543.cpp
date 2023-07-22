#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10;
typedef double d; typedef long long ll;
ll n, m, list[N]; d sum[N];
// d tmp[N];
bool cal(d x){
    int cur = 1; d max1 = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++){
        // tmp[i] = (d)list[i] - x * (d)i;
        sum[i] = sum[i - 1] + (d)list[i] - x;
    }
    // int j = m;
    for (int i = m; i <= n; i++){
        max1 = std::max(max1, -sum[i - m]);
        if(sum[i] + max1 >= 0) return 1;
    }
    return 0;
}
inline ll read() {
    ll x = 0, w = 1;
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
    n = read(); m = read(); d max0 = 0;
    for (int i = 1; i <= n; i++){
        list[i] = read();
        max0 = std::max(max0, (d)list[i]);
    }
    d l = 0, r = max0;
    while(r - l > 1e-8){
        d mid = (l + r) * 0.5;
        if(cal(mid)) l = mid;
        else r = mid;
        // printf("%lf \n", l);
    }
    printf("%.10lf", l);
    return 0;
}
// if(i >= m){
        //     min1 = std::min(min1, list[i - m]);
        //     if(list[i - m] != min1) cur++; else cur = m;
        //     arr = (list[i] - min1) / (double)cur;
        //     max1 = std::max(arr, max1);
        // }