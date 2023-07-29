#include <cstdio>
#include <algorithm>
const int N = 500010;
int n;
long long ans[N];
struct Node
{
    int idx;
    int x;
    int y;
    int type;
}d[N * 5], tmp[N * 5];

void msort(int lef, int rig){
    if(lef + 1 == rig)
        return;
    int mid = (lef + rig) / 2;
    msort(lef, mid);
    msort(mid, rig);
    int p = 0;
    long long cnt = 0;
    for (int i = lef, j = mid; i < mid or j < rig;)
        if (j == rig or (i < mid and d[i].y > d[j].y)){
            if(d[i].type) cnt++;
            tmp[p++] = d[i++];
        }else{
            if(!d[j].type) ans[d[j].idx] += cnt;
            tmp[p++] = d[j++];
        }
    for (int i = 0, j = lef; i < p;)
        d[j++] = tmp[i++];
}

bool cmp(Node a, Node b){
    if(a.x == b.x) return a.type > b.type;
    return a.x < b.x;
}
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' or ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' and ch <= '9') {  // ch 是数字时
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
        d[i] = (Node){i, read(), i, 1};//input = 1
        d[i + n] = (Node){i, d[i].x, i, 0};//ask = 0
    }
    std::sort(d + 1, d + 2 * n + 1, cmp);
    // for (int i = 1; i <= 2 * n; i++){
    //     printf("%d %d\n", d[i].x, d[i].y);
    // }
    msort(1, 2 * n + 1);
    for (int i = 1; i <= n; i++){
        ans[i] += ans[i - 1];
        // printf("%d\n", ans[i] - 1);
    }
    printf("%lld ",ans[n]);
    return 0;
}