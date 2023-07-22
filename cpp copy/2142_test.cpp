#include <cstdio>
#include <algorithm>
using std::swap;
int n;
int bene[16][16];
int minb, mina;
int a = 0;
int used[16];
int tmp;
void dfs(int in){
    printf("%d\n",minb);
    if (in > n){
        if ((minb < mina || mina == 0)){
            mina = minb;
        }
        return;
    }
    
    for (int i = 1; i <= n - in + 1; i++){
        // swap(bene[in][i],bene[in][n]);
        if(bene[in][i] == 0 || used[i] != 0){
            continue;
        }
        // swap(bene[in][in],bene[in][i]);
        // for (int j = in; j <= n + 1; j++)swap(bene[j][i],bene[j][n-in+2]);
        minb += bene[in][i];
        used[i] = 1;
        tmp = bene[in][1];
        dfs(in + 1);
        used[i] = 0;
        minb -= bene[in][i];
        // swap(bene[in][in],bene[in][i]);
        // for (int j = in; j <= n + 1; j++)swap(bene[j][i],bene[j][n-in+2]);
        // swap(bene[in][i],bene[in][n]);
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
    for (int i = 1; i <= n; i++){
        bene[n+1][i] = bene[1][i];
    }
    dfs(1);
    mina += tmp;
    printf("%d",mina);
    return 0;
}