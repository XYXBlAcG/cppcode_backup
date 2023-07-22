#include <cstdio>
#include <iostream>
#include <algorithm>
using std::max;
using std::min;
typedef unsigned long long ull;
const int N = 4e5 + 10;
// const int M = 2e5 + 5;
int n;
ull e2s[N];
ull s2id[N];
// ull list[N];
struct Node
{
    ull s, e ,v;
    int idx;
    // int ids, ide, idv;
}list[N];
// lsan[N];
struct Sortw
{
    int idx;
    ull val;
    int ife;// 0 s 1 e
}sorter[N];

// int c[N];
// ull sorter[N];
int vis[N];
// ull back[N];
bool cmp(const Sortw& a, const Sortw& b){
    if(a.val == b.val) return a.ife > b.ife;
    return a.val < b.val;
}
ull maxe, mins;
ull res[N];
// ull max1;
int cnt;
int cur;
ull dp(int now){
    // printf("%d ",++cnt);
    // printf(" ", vis[now]);
    // fflush(stdout);
    // for (int i = now; i <= cur; i++){
    //     res[i] = max(res[i], res[cur]);
    // }
    if(now < 1) return 0;
    if(vis[now]) return res[now];
    vis[now] = 1;
    if(e2s[now]) res[now] = max(res[now],  dp(e2s[now]) + list[s2id[e2s[now]]].v);
    res[now] = max(res[now], dp(now - 1));
    cur = now;
    // max1 = vis[now];
    return res[now];
}
int solen;
// s左界 e右界 v内容
inline ull read() {
    ull x = 0, w = 1;
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
    list[0].s = list[0].e = list[0].v = -1e9 - 7;
    for (int i = 1; i <= n; i++){
        list[i].s = read();
        ++solen;
        sorter[solen] = (Sortw){i ,list[i].s, 0};
        // mins = min(mins, list[i].s);

        list[i].e = read();
        ++solen;
        sorter[solen] = (Sortw){i ,list[i].e, 1};
        // maxe = max(maxe, list[i].e);

        list[i].v = read();
        list[i].idx = i;
        // c[list[i].v]++;
    }
    // for (int i = 1; i <= n; i++){
    //     c[i] += c[i - 1];
    // }
    std::sort(sorter + 1, sorter + solen + 1, cmp);
    int num = 0;
    for (int i = 1; i <= solen; i++){
        // vis[i] = -1;
        // if(sorter[i].val != sorter[i - 1].val || i == 1)
            num++;
        if(sorter[i].ife){
            list[sorter[i].idx].e = num;
        }else{
            list[sorter[i].idx].s = num;
        }
        // printf("%d ", num);
    }
    maxe = solen;

    for (int i = 1; i <= n; i++){
        e2s[list[i].e] = list[i].s;
        s2id[list[i].s] = list[i].idx;
        // printf("s: %llu e: %llu id: %d \n",list[i].s, list[i].e, list[i].idx);
    }
    printf("%llu\n", dp(maxe));
    
    return 0;
}