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
    
    int maxl = 0;
    scanf("%d%d%d",&numsqr,&numpt,&maxpos);
    for (int i = 1; i <= numsqr; i++){
        int x = read();
        int y = read();
        int l = read();
        // printf("%d %d %d ", x, y, l);
        maxl = max(l,maxl);
        cha[x + l + 1][y + 1]--;
        cha[x - l - 1][y + 1]--;
        cha[x][y + l + 2]++;
        cha[x][y - l]++;
        // read(sqr[i][j]);
    }

    //scan
    maxpos += maxl;
    //rightdown 2 leftup
    for (int i = 1; i <= maxpos ; i++){
        // for (int j = 1; j <= i; j++){
            int j = 1;
            int x = i ,y = j;
            while(x){
                printf("x : %d, y : %d \n",x,y);
                map[x][y]=map[x+1][y-1]+cha[x][y];
                x--;
                y++;
            }
        // }
    }
    for (int x = 1; x <= maxpos; x++){
        for (int y = 1; y <= maxpos; y++){
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = maxpos; i >= 1 ; i--){
        // for (int j = 1; j <= i; j++){
            int j = 1;
            int x = i ,y = j;
            while(x){
                printf("x : %d, y : %d \n",x,y);
                map[x][y]=map[x+1][y-1]+cha[x][y];
                x--;
                y++;
            }
        // }
    }
    for (int x = 1; x <= maxpos; x++){
        for (int y = 1; y <= maxpos; y++){
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    //leftdown 2 rightup
    
    for (int i = maxpos; i >= 1 ; i--){
        // for (int j = 1; j <= i; j++){
            int j = 1;
            int x = i ,y = j;
            while(y){
                printf("x : %d, y : %d \n",x,y);
                map[x][y]+=map[x-1][y+1]/*+cha[x][y]*/;
                x++;
                y--;
            }
        // }
    }
    for (int x = 1; x <= maxpos; x++){
        for (int y = 1; y <= maxpos; y++){
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= maxpos ; i++){
        // for (int j = 1; j <= i; j++){
            int j = 1;
            int x = i ,y = j;
            while(y){
                printf("x : %d, y : %d \n",x,y);
                map[x][y]+=map[x-1][y+1]/*+cha[x][y]*/;
                x++;
                y--;
            }
        // }
    }

    
    for (int i = 1; i <= numpt; i++){
        // for (int j = 1; j <= 2; j++){
            
        //     // pt[i][j] = read();
        //     // read(pt[i][j]);
        // }
        int xx = read();
        int yy = read();
        printf("%d\n",map[xx][yy]);
    }

    for (int x = 1; x <= maxpos; x++){
        for (int y = 1; y <= maxpos; y++){
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }

    return 0;
}


// numsqr = getchar();
    // char numsqr[20];
    // int intnumsqr[20];
    // fgets(numsqr,20,stdin);
    // printf("%s\n",numsqr);

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

    // for (int x = maxpos; x >= 1; x--){
    //     int tmpx = x;
    //     for (int y = 1; y <= maxpos; y++){
            
    //         printf("x : %d, y : %d\n", tmpx, y);
    //         map[tmpx][y]+=map[tmpx+1][y-1]+cha[tmpx][y];
    //         if (tmpx) {tmpx--;} else {break;}
            
    //     }
    // }

    // for (int x = 1; x <= maxpos; x++){
    //     int tmpx = x;
    //     for (int y = maxpos; y >= 1; y--){
    //         printf("x : %d, y : %d\n", tmpx, y);
    //         map[tmpx][y]+=map[tmpx-1][y+1]/*+cha[x][y]*/;
    //         tmpx++;
    //     }
    // }