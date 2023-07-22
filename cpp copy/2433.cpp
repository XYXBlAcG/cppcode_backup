#include <cstdio>
#include <algorithm>
typedef long long ll;
using std::push_heap;
using std::pop_heap;
const int N = 1e6 + 5;
// int add[N];
// int he[N];
struct Node
{
    ll val, add, idx, nv;
}item[N], ans[N];
struct Note
{
    ll add, idx, val;
}heap[N]; int lenh;
ll addd[N];
ll res[N];
// struct Note{
//     int idx, val;
// }ans[N];
bool cmp(const Node& a, const Node& b){
    return a.val < b.val;
}
bool cmpn(const Note& a, const Note& b){
    return a.val > b.val;
}
bool cmpf(const Note& a, const Note& b){
    if(a.add == b.add) return a.val > b.val;
    return a.add < b.add;
}
// bool cmp2(const Node& a, const Node& b){
//     return a.idx < b.idx;
// }
bool cmp3(const Node& a, const Node& b){
    // if(a.idx == b.idx) return a.val < b.val;
    return a.idx < b.idx;
}
// bool cmp4(const Node& a, const Node& b){
//     return a.val > b.val;
// }
// bool cmp3(const Note& a, const Note& b){
//     if(a.idx == b.idx) return a.val < b.val;
//     return a.idx < b.idx;
// }
ll cnt[N];
int lenp;
// int lenh;
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
    item[0].val = -1e9 - 7;
    for (int i = 1; i <= n; i++){
        item[i].val = read();
        item[i].add = read();
        item[i].idx = i;
        
    }
    std::sort(item + 1, item + n + 1, cmp);
    
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        
        if(item[i].val != item[i - 1].val){
            addd[++tmp] = item[i].val;
        }
        res[item[i].idx] = tmp; 
    }//res是离散化后的编号
    // for (int i = 1; i <= n; i++){
    //     printf("%d ",res[i]);
    // }printf("\n");
    int len = 0;
    std::sort(item + 1, item + n + 1, cmp3);
    // for(int i=1;i<=n;i++){
    //     printf("%d ",item[i].val);
    // }printf("\n");
    // for(int i=1;i<=n;i++){
    //     printf("%d ",item[i].add);
    // }printf("\n");

    for (int i = 1; i <= n; i++){
        cnt[res[i]] += item[i].add;
        // cnt[res[i]] += addd[i];
        heap[++lenh] = (Note){cnt[res[i]] , res[i], addd[res[i]]};
        push_heap(heap + 1, heap + lenh + 1, cmpf);
        for(;lenh && heap[1].add != cnt[heap[1].idx]; pop_heap(heap + 1, heap + (lenh--) + 1, cmpf));
        printf("%lld\n", heap[1].val);
    }
    return 0;
}