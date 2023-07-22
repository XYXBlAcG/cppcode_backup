#include <cstdio>
#include <algorithm>
using std::swap;
int n;
int city[15][15];
int mina, minb;
void dfs(int in){
    if (mina < minb || minb == 0){
        minb = mina;
    }
    if (in > n){
        return;
    }
    for (int i = in; i <= n; i++){
        swap(city[in][i],city[in][n]);
        for (int j = in; j <= n; j++)swap(city[j][i],city[j][n-in+1]);
        mina += city[in][i];
        dfs(in + 1);
        mina -= city[in][i];
        for (int j = in; j <= n; j++)swap(city[j][i],city[j][n-in+1]);
        swap(city[in][i],city[in][n]);
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            scanf("%d",&city[i][x]);
        }
    }
    dfs(1);
    printf("%d",minb);
    return 0;
}