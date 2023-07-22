#include <cstdio>
const int N = 1e4 + 3;
//使用数组
int n, m;
// int i, j, a;
// struct Node
// {
//     int pass;
//     int next;
// }list[N];
int list[N][N];
// int leng[N];
// struct Note{
//     int stui;
//     int stuj;
//     int a;
// }order[N];
// int i[N];
// int j[N];
// int a[N];
int head[N];

int main(){
    //input
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        list[i][1] = i;
    }
    for (int o = 1; o <= m; o++){
        int i = 0,j = 0,a = 0;
        scanf("%d%d%d",&i,&j,&a);
        int poix = 0, poiy = 0, pojx = 0, pojy = 0;
        //
        // printf("1 ");
        for (int p = 1; list[p][1]; p++){
            int jump = 0;
            for (int q = 1; list[p][q]; q++){
                if (list[p][q] == i){
                    poix = p;
                    poiy = q;
                    jump = 1;
                    break;
                }
            }
            if (jump == 1) break;
        }
        //
        // printf("2 ");
        for (int p = 1; list[p][1]; p++){
            int jump = 0;
            for (int q = 1; list[p][q]; q++){
                if (list[p][q] == j){
                    pojx = p;
                    pojy = q;
                    jump = 1;
                    break;
                }
            }
            if (jump == 1) break;
        }
        //
        //有多少人要操作
        // printf("3 ");
        int cnt = 0;
        for (int r = pojy; r <= a + pojy ; r++){
            cnt = r - pojy;
            if (!list[pojx][r]) break;
        }
        // printf("%d ",cnt);
        for (int s = 0; s <= cnt; s++){
                //移动
                list[poix][poiy + s + cnt] = list[poix][poiy + s];
                //复制
                list[poix][poiy + s] = list[pojx][pojy + s];
                //删除
                list[pojx][poiy + s] = 0;
                // list[poix][s] = list[pojx][r]; ?questioned
            }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
        printf("%d ",list[i][j]);
        }
    printf("\n");
    }
    
    int cnt = n;
    for (int i = 1; /*list[i][1]*/ i <= n; i++){
        if (!list[i][1]) {cnt--; continue;}
        for (int j = 1; list[i][j]; j++){
            printf("%d ",list[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",cnt);
    return 0;
}