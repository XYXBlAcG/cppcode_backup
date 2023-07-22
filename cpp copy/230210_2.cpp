#include <cstdio>
#include <iostream>
int n, m, s, t;
char map[25][25];
int used[25][25];
int ans = 0, bigg;
int tmp;
void pmap(){
    for (int i = 0; i <= n + 1; i++){
        for (int x = 0; x <= m + 1; x++){
        printf("%d ",used[i][x]);
    }
    printf("\n");
    }
}
void addall(int a){
    for (int i = 0; i <= n + 1; i++){
        for (int x = 0; x <= m + 1; x++){
        if (used[i][x] == a){
            used[i][x] = -a;
        }
    }
    }
}
// void delall(int a){
//     for (int i = 0; i <= n + 1; i++){
//         for (int x = 0; x <= m + 1; x++){
//         if (used[i][x] == a){
//             used[i][x] = -a;
//         }
//     }
//     }
// }
bool nogo(int inx, int iny){
    if (used[inx+1][iny] <= 0 && used[inx-1][iny] <= 0 && used[inx][iny+1] <= 0 && used[inx][iny-1] <= 0){
        return true;
    }else{
        return false;
    }
}
void dfs(int inx, int iny){
    // pmap();
    // printf("inx %d iny %d ", inx, iny);
    // printf("ans:%d\n",bigg);
    if (nogo(inx,iny)){
        if (bigg >= ans){
            ans = bigg;
            // bigg = 0;
        }
        return;
    }
    // for (int i = 1; i <= 4; i++){
    //     if (i == 1){
            // printf("nmsl%d ",used[inx+1][iny]);

        // for (int i = 1; i <= 6; i++){
            if (used[inx+1][iny] > 0){
                bigg++;
                addall(used[inx+1][iny]);
                dfs(inx+1,iny);
                addall(used[inx+1][iny]);
                bigg--;
            }
        // }
        // if (i == 2){
            // printf("nmsl%d ",used[inx-1][iny]);
            if (used[inx-1][iny] > 0){
                bigg++;
                addall(used[inx-1][iny]);
                dfs(inx-1,iny);
                addall(used[inx-1][iny]);
                bigg--;
            }
        // }
        // if (i == 3){
            // printf("nmsl%d ",used[inx][iny+1]);
            if (used[inx][iny+1] > 0){
                bigg++;
                addall(used[inx][iny+1]);
                dfs(inx,iny+1);
                addall(used[inx][iny+1]);
                bigg--;
            }
        // }
        // if (i == 4){
            // printf("nmsl%d ",used[inx][iny-1]);
           if (used[inx][iny-1] > 0){
                bigg++;
                addall(used[inx][iny-1]);
                dfs(inx,iny-1);
                addall(used[inx][iny-1]);
                bigg--;
            }
        // }
        // }
    // }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i = 0; i <= n + 1; i++){
        for (int x = 0; x <= m + 1; x++){
        used[i][x] = 0;
        }
    }
    // getchar();
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= m; x++){
            // char aaaa = getchar();
            // if (aaaa >= 0 && aaaa < 32){
                std::cin >> map[i][x];
                // break;
            // }
            // map[i][x] = aaaa;
            used[i][x] = (int)map[i][x];
        }
    }
    addall(used[s][t]);
    // addall(used[s][t]);
    // for (int i = 1; i <= n + 1; i++){
    //     for (int x = 1; x <= m + 1; x++){
    //     printf("%c ",map[x][i]);
    // }
    // printf("\n");
    // }
    bigg++;
    dfs(s,t);
    addall(used[s][t]);
    printf("%d\n",ans);
    return 0;
}