#include <cstdio>
int map[9][9] = {-1};
int n, m;
int checked = 0;
int res = 0;
void paint(int x, int y){
    if(x == n){
        ++res;
        return;
    }
    int x1 = x;
    int y1 = y + 1;
    if(y1 == m){
        x1++;
        y1 = 1;
    }
    map[x][y] = 1;
    paint(x1,y1);
    //  if(x1 == n){
    //     res++;
    //     return;
    // }
    // for (int i = 1; i <= n; i++){
    //     for (int x = 1; x <= m; x++){
    //         if (map[i][x] != -1){
    //             checked = 1;
    //         }
    //     }
    // }
    // if (checked == 1){
    //     res++;
    //     return;
    // }
    
    
    for (map[x][y] = 0; map[x][y] <= 1; map[x][y]++){
        if (((/*map[x+1][y] == map[x][y] ||*/ map[x-1][y] == map[x][y] || /*map[x][y+1] == map[x][y] ||*/ map[x][y-1] == map[x][y]) && map[x][y] == 1) || x == 0 || y == 0){
            continue;
        }else{
            paint(x1,y1);
        }
    }
}
int main(){
    scanf("%d%d",&n ,&m);
    paint(1,1);
    printf("%d",res);
    return 0;
}

// #include <cstdio>
// int map[9][9] = {-1};
// int n, m;
// int checked = 0;
// int res = 0;
// void paint(int x, int y){
//     if(x == n){
//         ++res;
//         return;
//     }
//     int x1 = x;
//     int y1 = y + 1;
//     if(y1 == m){
//         x1++;
//         y1 = 0;
//     }
//     //  if(x1 == n){
//     //     res++;
//     //     return;
//     // }
//     // for (int i = 1; i <= n; i++){
//     //     for (int x = 1; x <= m; x++){
//     //         if (map[i][x] != -1){
//     //             checked = 1;
//     //         }
//     //     }
//     // }
//     // if (checked == 1){
//     //     res++;
//     //     return;
//     // }
    
    
//     // for (map[x][y] = 0; map[x][y] <= 1; map[x][y]++){
//         // if (((/*map[x+1][y] == map[x][y] ||*/ map[x-1][y] == map[x][y] || /*map[x][y+1] == map[x][y] ||*/ map[x][y-1] == map[x][y]) && map[x][y] == 1) || x == 0 || y == 0){
//             // continue;
//         /*}*/
//         map[x][y] = 1;
//         paint(x1,y1);
//         int check = 1;
//         if (x == 0 || map[x - 1][y] == 1){
//             check = 0;
//         }
//         if (y == 0 || map[x][y - 1] == 1){
//             check = 0;
//         }
//         if(check == 1){
//             map[x][y] = 1;
//             paint(x1,y1);
//         }
//             // paint(x1,y1);

//         // }
//     // }
// }
// int main(){
//     scanf("%d%d",&n ,&m);
//     paint(0,0);
//     printf("%d",res);
//     return 0;
// }