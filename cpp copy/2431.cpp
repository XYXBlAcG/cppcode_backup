#include <cstdio>
#include <algorithm>
#include <queue>
using std::push_heap;
using std::pop_heap;
// ./2431 > out_2431.txt < in_2431.txt
const int N = 3e5 + 10;
int n;
using std::priority_queue;
priority_queue<int> luc;
priority_queue<int> del;
struct Node
{
    int idx, luck;
}lucky[N];
// int id2seat[N];
// int seat2id[N];
int seat[N];
int lens;
// int lucky[N];
int lenl;
// int del[N];
// int lend;
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
        int op = read();
        if(op - 1){//2
        int a = lens;
            if(!luc.empty() && !del.empty()){
                while(luc.top() == del.top() && !luc.empty() && !del.empty()){
                    luc.pop(); del.pop();
                }
            }
            int mod = luc.top() % a + 1;
            printf("%d\n", lucky[seat[mod]].luck);
            del.push(lucky[seat[mod]].luck);
            seat[mod] = seat[lens--];
            seat[lens + 1] = 0;
            // printf("2:%d\n", luc.pop());
        }else{//1
            int x = read();
            luc.push(x);
            lucky[++lenl].luck = x;
            seat[++lens] = lenl;
            if(!luc.empty() && !del.empty()){
                while(luc.top() == del.top() && !luc.empty() && !del.empty()){
                    luc.pop(); del.pop();
                }
            }
            printf("%d\n", luc.top());
        }
    }
    return 0;
}

// while(del[1] == lucky[1].luck && lend && lenl){
            //     pop_heap(del + 1, del + (lend--) + 1);
            //     int a = lenl;
            //     if((lucky[1].luck % lenl) + 1 != lenl){
            //         int b = (lucky[1].luck % a) + 1;
            //         lucky[b] = lucky[lenl--];
            //     }
            //     lucky[lenl--].luck = 0;
            //     // lucky[(lucky[1] % a) + 1] = 0;
            //     // push_heap(lucky + 1, lucky + lenl + 1);
            //     // push_heap(del + 1, del + lend + 1);
            // }
            // int y = lucky[1];
            
            // del[++lend] = lucky[1].luck;

// while(del[1] == lucky[1].luck && lend && lenl){
            //     pop_heap(del + 1, del + (lend--) + 1);
            //     int a = lenl;
            //     if((lucky[1].luck % lenl) + 1 != lenl){
            //         int b = (lucky[1].luck % a) + 1;
            //         lucky[b].luck = lucky[lenl--].luck;
            //     }
            //     lucky[lenl--].luck = 0;
            //     // lucky[(lucky[1] % a) + 1] = 0;
            //     // push_heap(lucky + 1, lucky + lenl + 1);
            //     // push_heap(del + 1, del + lend + 1);
            // }