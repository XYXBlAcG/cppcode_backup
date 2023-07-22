#include <cstdio>
#include <algorithm>
int n, m;
int dla[50];
int dlb[50];
int res[50];
using namespace std;

void dfs(int in){
    if (in > n){
        for (int i = 1; i <= n; i++){
            if (res[i] == 0){
                printf("0");
            }else{
                printf("1");
            }
        }
        printf("\n");
        return;
    }
    for (res[in] = 0; res[in] <= 1; res[in]++){
        int checked = 0;
        // dfs(in + 1);
        for (int x = 1; x <= m; x++){
            
        if ((dla[x] == in || dlb[x] == in) && min(dla[x],dlb[x])!= in){
        if (res[dla[x]] == res[dlb[x]]){
            // dfs(in + 1);
            // break;
            // if (dla[x] > dlb[x]){
            //     if (res[dlb[x]] == 0){
            //         res[dla[x]] = 1;
            //     }else{
            //         res[dla[x]] = 0;
            //     }
            // }else{
            //     if (res[dla[x]] == 0){
            //         res[dlb[x]] = 1;
            //     }else{
            //         res[dlb[x]] = 0;
            //     }
            // }
            // break;
            // continue;
            checked = 1;
        }
        }
        // dfs(in + 1);
        }
        if (checked == 1){
            continue;
        }else{
            dfs(in + 1);
        }
    }
    
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++){
        scanf("%d",&dla[i]);
        scanf("%d",&dlb[i]);
    }
    dfs(1);
    return 0;
}