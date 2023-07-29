#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 1000011, M = 1000011;
int n, m, nitem, ans[N];
struct Node
{
    int type;
    int idx;
    ll val;
}items[N + M * 2];

bool operator<(const Node& a, const Node& b){
    if(a.val != b.val){
        return a.val < b.val;
    }
    return a.type < b.type;
}

inline ll read() {
    ll x = 0, w = 1;
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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        ll a = read();
        items[++nitem] = (Node){1, i ,a};
    }
    for (int i = 1; i <= m; i++){
        ll l = read();
        ll r = read();
        items[++nitem] = (Node){0, i, l};
        items[++nitem] = (Node){2, i, r};
    }
    std::sort(items + 1, items + nitem + 1);
    int cnt = 0;
    for (int i = 1; i <= nitem; i++){
        switch (items[i].type){
        case 0:
            ans[items[i].idx] -= cnt;
            break;
        case 1:
            cnt++;
            break;
        case 2:
            ans[items[i].idx] += cnt;
            break;
        }
    }
    for (int i = 1; i <= m; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}