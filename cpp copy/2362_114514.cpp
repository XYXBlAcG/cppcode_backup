#include <cstdio>
#include <algorithm>
using std::max;
// #include <stdio.h>
// int x, y, r;
int numsqr, numpt, maxpos;
// const int N = 3e6 + 5;
// const int tf = 2400;
// int sqr[N][4];
// int pt[N][3];
int cha[6010][6010];
int map[6010][6010];
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
    
    int maxl = 0;
    scanf("%d%d%d",&numsqr,&numpt,&maxpos);
    for (int i = 1; i <= numsqr; i++){
        int x = read();
        int y = read();
        int l = read();
        // printf("%d %d %d ", x, y, l);
        maxl = max(l,maxl);
        int x1 = x + l, y1 = y;
        cha[x1 - y1 + 2400 + 1][x1 + y1 + 2400 + 1]++;
        x1 = x - l; y1 = y;
        cha[x1 - y1 + 2400][x1 + y1 + 2400]++;
        x1 = x; y1 = y + l;
        cha[x1 - y1 + 2400][x1 + y1 + 2400 + 1]--;
        x1 = x; y1 = y - l;
        cha[x1 - y1 + 2400 + 1][x1 + y1 + 2400]--;
        // read(sqr[i][j]);
    }
    maxpos += maxl;
    // for (int i = 2400 - maxpos; i <= 2400 + maxpos; i++){
    //     for (int j = 2400 - maxpos; j <= 2400 + maxpos; j++){
    //         printf("%d ",cha[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 1; i <= 6000; i++){
        for (int j = 1; j <= 6000; j++){
            map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + cha[i][j];
        }
    }
    // printf("\n");
    // for (int i = 2400 - maxpos; i <= 2400 + maxpos; i++){
    //     for (int j = 2400 - maxpos; j <= 2400 + maxpos; j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 1; i <= numpt; i++){
        int a = read();
        int b = read();
        int x1 = a - b;
        int y1 = a + b;
        printf("%d\n",map[x1+2400][y1+2400]);
    }
    return 0;
}