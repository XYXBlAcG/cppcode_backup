#include <cstdio>
#include <algorithm>
using std::sort;
using std::max;
using std::min;
const int N = 3010;
int n, m;
int uselen = 1;
// int useless[N];
struct Node{
    int idx, w, v;
}car[N], use[N];
// struct Sort{
//     int idx, val;
//     bool ifw;
// }sorter[N];
bool vis[N][N];
double ans[N][N];
int lens;
bool cmp(const Node& a, const Node& b){
    if(a.w != b.w) return a.w < b.w;
    return a.v > b.v;
}
// dp 指的是 最小时间
// i 指的是 将第一辆车换成车i
// j 指的是 将第一辆车换成车j
double dp(int i, int j){
    // printf("!");
    // fflush(stdout);
    // if(i == uselen && j == uselen) return 0;
    
    if(i == 0 || j == 0) return (double)1e9;
    // if(i == 1 || j == 1) return 0;
    if(i == 1 && j == 1){
        return 0;
    }
    if(vis[i][j]) return ans[i][j];
    vis[i][j] = 1;
    //换车
    
    
    ans[i][j] = min(ans[i][j], dp(i - 1, j) + (double)(use[i].w - use[i - 1].w)/(double)(use[i - 1].v + use[j].v));
    ans[i][j] = min(ans[i][j], dp(i, j - 1) + (double)(use[j].w - use[j - 1].w)/(double)(use[i].v + use[j - 1].v));
    return ans[i][j];
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
    scanf("%d%d", &n, &m);
    // car[0] = (Node){0, 0, 0};
    for (int i = 1; i <= n; i++){
        car[i].idx = i;
        car[i].w = read();
        car[i].v = read();
    }
    sort(car + 1, car + 1 + n, cmp);
     int max1 = 0;
    // int min1;
    for (int i = 1; i <= n; i++){
        if(car[i].v > max1){
            max1 = car[i].v;
            ++uselen;
            use[uselen] = (Node){uselen, car[i].w, car[i].v};
        }
        // if((max(car[i].v, max1) == car[i].v)){
        //     
        // }
    }
    for (int i = 1; i <= uselen; i++){
        for (int j = 1; j <= uselen; j++){
            ans[i][j] = (double)1e9;
        }
    }
    use[1] = (Node){0, 0, 1};
    // for (int i = 1; i <= n; i++){
    //     printf("v: %d , w : %d ; ", car[i].v, car[i].w);
    // }
    // printf("\n");
    // for (int i = 1; i <= uselen; i++){
    //     printf("v:%d, w:%d; ", use[i].v, use[i].w);
    // }
    // printf("\n");
    // fflush(stdout);
    // use[0].v = 1;
    // use[0].w = 0;
    dp(uselen, uselen);
    if(ans[uselen][uselen] == m){
        printf("%.4lf\n", ans[uselen][uselen]);
    }else{
        printf("%.4lf\n", ans[uselen][uselen] + (double)(m - use[uselen].w * 2)/(double)(use[uselen].v * 2));
    }
    return 0;
}