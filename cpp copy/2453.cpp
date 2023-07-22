#include <cstdio>
#include <algorithm>
using std::min;
const int N = 1e6 + 5;
struct Node{
    int h, idx;
}hei[N];
int len, dan[N], left = 1;
int n, m;
int k;
int ans[N];
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
    n = read();
    for (int i = 1; i <= n; i++){
        hei[i].h = read();
        hei[i].idx = i;
    }
    ans[n] = 0; 
    m = read();
    hei[0].h= -1;
    for (int i = 1; i <= m; i++){
        k = read();
        left = 1;
        len = 0;
        ans[1]= 0;
        dan[++len] = 1;
        for (int j = 2; j <= n; j++){
            for(left = min(left, len); dan[left] < j - k ; left++);
            ans[j] = ans[hei[dan[left]].idx] + (hei[j].h>=hei[dan[left]].h);
            for(; len >= 0 && (ans[hei[j].idx]<ans[hei[dan[len]].idx]||(ans[hei[j].idx]==ans[hei[dan[len]].idx]&&hei[dan[len]].h < hei[j].h)); len--);
            dan[++len] = j;
            
        }
        printf("%d\n", ans[n]);
        for (int j = 1; j <= n; j++){
            ans[j] = 0;
            dan[j] = 0;
        }
    }
    return 0;
}