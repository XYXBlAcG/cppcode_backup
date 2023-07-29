#include <cstdio>
int no[70][70];
int map[70][70];
struct point {
    int x, y;
};
int tmpx, tmpy;
int res = 0;
int n, m;
// point dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
point move = {1, 1};
// void reset(){

// }
void place(int a){
    if (a == n){
        for (int i = 1; i <= n; i++){
        for (int z = 1; z <= n; z++){
            printf("%d ",map[i][z]);
        }
        
        printf("\n");
    }
        for (int i = 0; i <= n+1; i++){
        for (int z = 0; z <= n+1; z++){
            no[i][z] = map[i][z];
        }
    }
        res++;
        return;
    }
    // if (map[move.x][move.y] == 0){
        for (; move.x <= n; move.x++){
            
            for (; move.y <= n; move.y++){
                if (map[move.x][move.y] == 0){
                    for (int i = 1; i <= n; i++){
                        map[move.x][i] = 1;
                        map[i][move.y] = 1;
                        if (move.x+move.y-i > 0 && move.x+move.y-i < n) map[move.x+move.y-i][i] = 1;
                        if (move.x+move.y-i > 0 && move.x+move.y-i < n) map[i][move.x+move.y-i] = 1;
                    }
                    tmpx = move.x;
                    tmpy = move.y;
                    place(a+1);
                    move.x = tmpx;
                    move.y = tmpy;
                    for (int i = 1; i <= n; i++){
                    map[move.x][i] = 0;
                    map[i][move.y] = 0;
                    if (move.x+move.y-i > 0 && move.x+move.y-i < n) map[move.x+move.y-i][i] = 0;
                    if (move.x+move.y-i > 0 && move.x+move.y-i < n) map[i][move.x+move.y-i] = 0;
        }
        // if (move.x == n){}
                }else{
                    break;
                }
            }
        }
        
    // }

    

}
int main(){
    
    scanf("%d%d",&n,&m);
    for (int i = 0; i <= n+1; i++){
        for (int z = 0; z <= n+1; z++){
            // no[i][z] = 1;//0可放，1不可放
            map[i][z] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int z = 1; z <= n; z++){
            // no[i][z] = 0;//0可放，1不可放
            map[i][z] = 0;
        }
    }
    int tmpmx, tmpmy;
    for (int i = 1; i <= m; i++){
        scanf("%d%d",&tmpmx, &tmpmy);
        map[tmpmx][tmpmy] = 1;
    }
    for (int i = 0; i <= n+1; i++){
        for (int z = 0; z <= n+1; z++){
            no[i][z] = map[i][z];
        }
    }
    place(1);
    printf("%d",res);
    return 0;
}