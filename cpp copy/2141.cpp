#include <cstdio>
#include <algorithm>
int n;
int bene[15][15];
int maxb, maxa;
int a = 0;
// int used[15];
void dfs(int in){
    if (maxb > maxa){
        maxa = maxb;
    }
    if (in > n){
        return;
    }
    for (int i = 1; i <= n - in + 1; i++){
        maxb += bene[in][i];
        for (int j = in; j <= n; j++)std::swap(bene[j][i],bene[j][n-in+1]);
        dfs(in + 1);

        for (int j = in; j <= n; j++)std::swap(bene[j][i],bene[j][n-in+1]);
        maxb -= bene[in][i];
    }
}
int main(){
    // int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        for (int o = 1; o <= n; o++){
            scanf("%d",&bene[i][o]);
        }
    }
    dfs(1);
    printf("%d",maxa);
    return 0;
}