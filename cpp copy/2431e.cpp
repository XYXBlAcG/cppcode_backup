#include <cstdio>
#include <algorithm>
using std::push_heap;
using std::pop_heap;
using std::sort;
const int N = 5e5 + 5;
int n;
// int heap[N];
struct Node
{
    int idx;
}heap[N];
int lenh, lenv, val[N];
bool del[N];

bool operator<(const Node& a, const Node& b){
    return val[a.idx] < val[b.idx];
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
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        int op = read();
        if(op == 1){
            int x = read();
            val[++lenv] = x;
            heap[++lenh] = (Node){lenv};
            push_heap(heap + 1, heap + lenh + 1);
        }else if(op == 2){
            int x = read();
            del[x] = true;
        }else{
            if(!lenh){
                printf("empty\n");
                continue;
            }
            while(del[heap[1].idx]){
                del[heap[1].idx] = false;
                pop_heap(heap + 1, heap + lenh + 1);
                lenh--;
            }
            if(!lenh){
                printf("empty\n");
                continue;
            }else{
                printf("%d\n",val[heap[1].idx]);
            }
        }
    }
    return 0;
}