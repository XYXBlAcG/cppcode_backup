#include <cstdio>
// const int N = 0;
int n;
int a[10000];
int cnt;
int vis[10000], visall;
void f(int x){
    if(x < 1) return;
    if(x > 1000) return;
    if(vis[x]) return;
    vis[x] = 1;
    visall++;
    a[x] = ++cnt;
    f(x >> 1);
    f(x * 3 >> 1);
}
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
    // f(500);
    int aa = 1;
    for (int i = 1000;i >= 1; i--){
        f(i);
    }
    // while (visall < 1000){
        
    // }
    // for (int i = 1; i <= 1000; i++){
    //     printf("%d ",a[i]);
    // }
    for (int i = 1; i <= 1000; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}