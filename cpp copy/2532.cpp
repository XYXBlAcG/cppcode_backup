#include <cstdio>
#include <algorithm>
const int N = 1e6 + 10;
typedef unsigned long long llu;
int n, m;

int dlen;
struct Node
{
    int l;
    int r;
    int idx;
}ask[N];
struct Node2
{
    int idx;
    int val;
}dan[N], a[N];

int ans[N];
int bin2(int l1, int x){
    int l = 1, r = x;
    int mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(dan[mid].idx < l1){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return dan[l].val;
}
bool cmp(const Node& a, const Node& b){
    return a.r < b.r;
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
    n = read(); m = read();
    for (int i = 1; i <= n; i++){
        a[i] = (Node2){i, read()};
    }
    for (int i = 1; i <= m; i++){
        ask[i] = (Node){read(), read(), i};
    }
    std::sort(ask + 1, ask + 1 + m, cmp);
    // for (int i = 1; i <= m; i++){
    //     printf("l:%d r:%d \n",ask[i].l,ask[i].r);
    // }printf("\n");
    int cnt = 0;
    int past = 0;
    for (int i = 1; i <= m; i++){
        for (; cnt < ask[i].r; ){
            ++cnt;
            for ( ; dan[dlen].val < a[cnt].val && dlen > 0; --dlen);
            dan[++dlen] = a[cnt];
        }
        ans[ask[i].idx] = bin2(ask[i].l, dlen);
    }
    // printf("\n");
    for (int i = 1; i <= m; i++){
        printf("%d ", ans[i]);
    }
    
    return 0;
}


//  for (int i = 1; i <= n; i++){
//         int s = read();
//         for(; 0 < len && a[dan[len]] <= a[i]; len--);
//         dan[++len] = i;
//         for(left = min(left, len); dan[left] < s; left++);
//         printf("%d ", a[dan[left]]);
//     }printf("\n");