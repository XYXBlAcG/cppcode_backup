#include <cstdio>
#include <algorithm>
const int N = 4 * 1e5 + 5;
typedef long long llu;
int n, m;
struct Node
{
    int x;
    int y;
    int idx;
    int type;
}all[N], tmp[N];
llu ans[N];
// fish[N], net[N];
void msort(int lef, int rig){
    if(lef + 1 == rig)
        return;
    int mid = (lef + rig) / 2;
    msort(lef, mid);
    msort(mid, rig);
    int p = 0;
    long long cnt = 0;
    for (int i = lef, j = mid; i < mid or j < rig;)
        if (j == rig or (i < mid and all[i].y <= all[j].y)){
            if(all[i].type) cnt++;
            tmp[p++] = all[i++];
        }else{
            if(!all[j].type) ans[all[j].idx] += cnt;
            tmp[p++] = all[j++];
        }
    for (int i = 0, j = lef; i < p;)
        all[j++] = tmp[i++];
}
bool cmp(Node a, Node b){
    if(a.x == b.x) return a.type > b.type;
    return a.x > b.x;
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
        int x = read();
        int y = read();
        all[i] = (Node){x + y, x - y, i, 1};//fish
    }
    for (int i = 1; i <= m; i++){
        int x = read();
        int y = read();
        all[i + n] = (Node){x + y, x - y, i, 0};//net
    }
    // for (int i = 1; i <= n + m; i++){
    //     printf("%d %d\n", all[i].x , all[i].y);
    // }
    std::sort(all + 1, all + n + m + 1, cmp);
    msort(1, n + m + 1);
    for (int i = 1; i <= m; i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}