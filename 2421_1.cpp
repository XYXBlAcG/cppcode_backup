#include <cstdio> 

const int N = 1e5 + 6;

int n, m;
int heap[N];
int len = 0;

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

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void ins(int val){
    heap[++len] = val;
    for (int t = len; t != 1; t >>= 1){
        if (heap[t >> 1] < heap[t]){
            swap(heap[t >> 1], heap[t]);
        } else {
            break;
        }
    }
}

void del(){
    heap[1] = heap[len--];
    for (int i = 1, son;; i = son){
        son = i * 2;
        if (son < len && heap[son] < heap[son + 1]){
            son++;
        }
        if (son <= len && heap[i] < heap[son]){
            swap(heap[i],heap[son]);
        } else {
            break;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        ins(read());
    }
    for (int i = 1; i <= m; i++){
        int op = read();
        if (op == 1){
            ins(read());
        } else {
            printf("%d\n",heap[1]);
            del();
        }
    }
    return 0;
}
