#include <cstdio>
#include <algorithm>
const int N = 100010;
typedef unsigned long long llu;
int n, m;
int num[N * 2];
int bin(int x){// min in big
    int l = 1, r = n, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(num[mid] <= x){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
int bin2(int x){//max in small
    int l = 1, r = n, mid;
    while(l < r){
        mid = (l + r + 1) >> 1;
        if(num[mid] < x){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
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
        num[i] = read();
    }
    std::sort(num + 1, num + 1 + n);
    // num[n + 1] = 1e9;
    // num[0] = 1e9;
    // for (int i = 1; i <= n; i++){
    //     printf("%d ",num[i]);
    // }printf("\n");
    for (int i = 1; i <= m; i++){
        int x = read();
        if(x > num[n]){
            printf("FAIL "); continue;
        }x = bin(x);
        // printf("idx:%d ", x);
        printf("%d ", num[x]);
    }
    return 0;
}