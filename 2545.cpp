#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using std::sort;
using std::max; using std::min;
const int N = 210;
typedef unsigned long long llu;
typedef double d;
int v, n, m, remain, id[N], a[N];
struct Node
{
    int idx;
    int val;
}party[110];
int ticket[N], seat[N], ans[N];
bool cmp(const int& x, const int& y){
    return a[x] > a[y];
}
bool cmp2(const int& a, const int& b){
    return a > b;
}
d qp(int vp, int sp){
    return (d)vp / (d)(sp + 1);
}
int f[N];
int calm(int x){
    int id = 0;
    ticket[x] = party[x].val + remain;
    for (int i = 1; i <= n; i++){
        if(ticket[i] < v / 20) ticket[i] = -1;
    }
    for(int o = 1; o <= m; o++){
        d max1 = 0;
        for (int i = 1; i <= n; i++){
            if(ticket[i] == -1) continue;
            d a = qp(ticket[i], seat[i]);
            if(max1 == a) continue;
            if(max(max1, a) == a) id = i;
            max1 = max(max1, a);
        }seat[id]++; 
    }
    return seat[x];
}
bool cal(int x, int mid){
    memset(f, 0x3f, sizeof f), f[0] = 0;
    for (int i = 1; i <= min(n, 20); i++){
        if(i != x){
        for (int j = m - mid; j >= 1; j--){
            for (int k = 1; k <= j; k++){
                int cost = max((a[x] * k % (mid + 1) ? a[x] * k / (mid + 1) + 1 : a[x] * k / (mid + 1) + (id[i] > id[x])) - a[i], 0);
                if(((a[i] + cost) * 20 < v)) cost = (v - 1) / 20 + 1 - a[i];
                f[j] = min(f[j], f[j - k] + cost);
            }
        }
        }
    }
    return f[m - mid] <= remain;
}
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = (x<<3)+(x<<1) + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int main(){
    remain = v = read(); n = read(); m = read(); 
    for (int i = 1; i <= n; i++){
        party[i]= (Node){i, read()};
        remain -= party[i].val;
    }
    //max
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            seat[j] = 0; 
            ticket[j] = party[j].val;
        }
        // printf("%d ", calm(i));
        write(calm(i)); putchar(' ');
    }putchar('\n');
    //min
    //席位
    for (int i = 1; i <= n; i++){
        a[i] = party[i].val;
    }
    for (int i = 1; i <= n; i++)
        id[i] = i;
    std::sort(id + 1, id + 1 + n, cmp);
    std::sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i <= n; i++){
        if(a[i] * 20 < v) continue;
        int l = 0, r = m;
        while(l < r){
            int mid = (l + r) >> 1;
            if (!cal(i, mid)) l = mid + 1;
            else r = mid;
        }
        ans[id[i]] = l;
        // printf("%d ", l);
    }
    for (int i = 1; i <= n; i++){
        // printf("%d ", ans[i]);
        write(ans[i]); putchar(' ');
    }
    // printf("\n");
    putchar('\n');
    return 0;
}

// int a = qp(ticket[i], seat[i]), b = qp(ticket[i + 1], seat[i + 1]);
// printf("i %d ", i);
// printf("a = %d, b = %d\n", a, b);
// if(a < b){
//     if(std::max(max1, b) == b) {id = i + 1; max1 = b;}
// }else if(a == b){
//     if(std::max(max1, b) == b) {id = i; max1 = b;}
// }

// printf("qp: %lf ", qp(ticket[id], seat[id]));
// printf("id %d seat %d\n", id, seat[id]);

// min1 = min(min1, (d)f[i - 1][j - k]);
// min2 = min(qp(party[i].val + k, seat[i]), min2);
// if(party[x].val * k < (mid + 1) * party[i].val 
// || (party[x].val * k == (mid + 1) * party[i].val 
// && party[i].idx < party[x].idx)) 