#include <cstdio>
#include <algorithm>
using std::push_heap;
using std::pop_heap;
typedef long long ll;
const int N = 1e6 + 5;
struct Node
{
    ll nid, score;
}res[N];
struct Note{
    ll sid, iid;
}item[N];
ll ans[N];
bool cmp(const Note& a, const Note& b){
    return a.sid < b.sid;
}
ll rec[N];
int n;
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
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        item[i].sid = read();
        rec[i] = item[i].sid;
        res[i].score = read();
        item[i].iid = i;
    }
    std::sort(item + 1, item + n + 1, cmp);
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        if(item[i].sid != item[i - 1].sid){
            tmp++;
        }
        res[item[i].iid].nid = tmp; 
    }
    // int len = 0;
    for (int i = 1; i <= n; i++){
        printf("%lld ",rec[i]);
        printf("%lld\n",ans[res[i].nid] += res[i].score);
    }
    return 0;
}