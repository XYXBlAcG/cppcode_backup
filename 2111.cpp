#include <cstdio>
int b[25];
int checked = 0;
int n;

void dfs(int in){
    if (in > n){
        for (int i = 1; i <= n; i++){
            if (b[i] == 0){
                printf("B");
            }else{
                printf("R");
            }
        }
        printf("\n");
        return;
    }
    // b[in] = 1;
    // dfs(in + 1);
    // if (b[in] == 0){
    //     dfs(in + 1);
    // }
    for (b[in] = 0; b[in] <= 1; b[in]++){
        if (b[in] == 1 && b[in - 1] == 1)continue;
        else{
            dfs(in + 1);
        }
    }
    
}
int main(){
    
    scanf("%d",&n);
    dfs(1);
    return 0;
} 