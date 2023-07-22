#include <cstdio>
#include <algorithm>
const int N = 100010;
long long n, m;
long long a[N], b[N], c[N];
// int ans[4][N];
struct Node
{
    long long idx;
    long long val;
}anss[N * 5];

long long ansl[N * 5];
long long ans[N * 5];
// long long ans1[2000 * 5000 + 10];
bool cmp(const Node& a, const Node& b){
    return a.val > b.val;
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
        // for (int i = 0; i <= m; i++){
            anss[++cnt].val = 0 * 0 * a[j] + 0 * b[j] + c[j];
            anss[cnt].idx = j;
        // }
    }
    std::make_heap(anss + 1, anss + cnt + 1, cmp);
    for (int i = 1; i <= m; i++){
        ans[i] = anss[1].val;
        long long tmp = anss[1].idx;
        ansl[anss[1].idx]++;
        std::pop_heap(anss + 1, anss + cnt + 1, cmp);
        anss[cnt].val = ansl[tmp] * ansl[tmp] * a[tmp] + ansl[tmp] * b[tmp] + c[tmp];
        std::push_heap(anss + 1, anss + cnt + 1, cmp);
    }
    // std::sort(ans1 + 1, ans1 + n * m + 1);
    // ms(1 , n * m);
    for (int i = 1; i <= m; i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}