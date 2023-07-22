#include <cstdio>
#include <queue>
using std::priority_queue;
priority_queue<int> he;
priority_queue<int> del;
const int N = 3e5 + 5;
int n;
int a[N];
// int heap[N];
// int s[N];
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        a[i] = read();
    }
    int s = 1;
    for (int i = 1; i <= n; i++){
        he.push(a[i]);
        // s[i] = read();
        int tmp = s;
        s = read(); // s to i
        while(tmp < s){
            del.push(a[tmp++]);
        }
        while(!he.empty() && !del.empty() && he.top() == del.top()){
            he.pop(); del.pop();
        }
        printf("%d ", he.top());
    }printf("\n");
    return 0;
}