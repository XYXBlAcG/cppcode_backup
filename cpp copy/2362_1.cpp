#include <cstdio>
#include <algorithm>
using std::max;
// #include <stdio.h>
// int x, y, r;
int numsqr, numpt, maxpos;
const int N = 3e6 + 5;
// int sqr[N][4];
int pt[N][3];
int cha[2400][2400];
int map[2400][2400];
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
    // numsqr = getchar();
    // char numsqr[20];
    // int intnumsqr[20];
    // fgets(numsqr,20,stdin);
    // printf("%s\n",numsqr);
    int maxl = 0;
    scanf("%d%d%d",&numsqr,&numpt,&maxpos);
    for (int i = 1; i <= numsqr; i++){
        // for (int j = 1; j <= 3; j++){
            // int x = sqr[i][1];
            // int y = sqr[i][2];
            // int l = sqr[i][3];
            int x = read();
            int y = read();
            int l = read();
            maxl = max(l,maxl);
            cha[x + l][y]--;
            cha[x - l][y]--;
            cha[x][y + l]++;
            cha[x][y - l]++;
            // read(sqr[i][j]);
        // }
    }
    // for (int i = 1; i <= numsqr; i++){
    //     for (int j = 1; j <= 3; j++){
    //         printf("%d ",sqr[i][j]);
    //     }
    //     printf("\n");
    // }
    //
    
    // for (int i = 1; i <= numsqr; i++){
            
    //         // cha[x + l - 1][y + l - 1]++;
    //         // cha[x - l + 1][y - l + 1]++;
    //         // cha[x + l][y]++;
    //         // cha[x - l][y]++;
    //         // cha[x][y + l]++;
    //         // cha[x][y - l]++;
    // }
    // for (int i = 1; i <= )
    //scan
    for (int x = maxpos + maxl; x >= 1; x--){
        for (int y = 1; y <= maxpos + maxl; y++){
            map[x][y]+=map[x+1][y-1]+cha[x][y];
            x--;
        }
    }

    for (int x = 1; x <= maxpos + maxl; x++){
        for (int y = maxpos + maxl; y >= 1; y--){

            map[x][y]+=map[x-1][y+1]/*+cha[x][y]*/;
            x++;
        }
    }

    for (int x = 1; x <= maxpos + maxl; x++){
        for (int y = 1; y <= maxpos + maxl; y++){
            printf("%d",map[x][y]);
        }
        printf("\n");
    }
    // for (int i = 1; i <= numpt; i++){
    //     printf("%d\n",map[][]);
    // }
    for (int i = 1; i <= numpt; i++){
        int xx, yy;
        // for (int j = 1; j <= 2; j++){
            
        //     // pt[i][j] = read();
        //     // read(pt[i][j]);
        // }
        xx = read();
        yy = read();
        printf("%d\n",map[xx][yy]);
    }
    return 0;
}

// for (int j = 1; j <= numsqr; j++){
    //     for (int k = 1; k <= 3; k++){
    //         for (int i = getchar(); i >= 32; i = getchar()){
    //             sqr[j][k] *= 10;
    //             sqr[j][k] += i;
    //         }
    //     }
    // }
    // printf("end 1\n");
    // for (int j = 1; j <= numpt; j++){
    //     for (int k = 1; k <= 2; k++){
    //         for (int i = getchar(); i >= 32; i = getchar()){
    //             pt[j][k] *= 10;
    //             pt[j][k] += i;
    //         }
    //         printf("pt: %d \n",pt[j][k]);
    //     }
    // }
    // //end input
    // printf("end input\n");

// for (int i = 1; i <= numsqr; i++){
    //     for (int j = 1; j <= 3; j++){
    //         printf("%d ",sqr[i][j]);
    //     }
    // }
    // printf("\n");
    // for (int i = 1; i <= numpt; i++){
    //     for (int j = 1; j <= 2; j++){
    //         printf("%d ",pt[i][j]);
    //     }
    // }