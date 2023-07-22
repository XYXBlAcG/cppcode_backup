#include <cstdio>
int n;
void dfs(int x, int a[]){
    if (x == n){
        for (int i = 0; i < n; ++i){
            printf("%d",a[i]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; ++i){
        bool ok = true;
        for (int j = 0; j < x; ++j){
            if (a[j] == i){
                ok = false;
                break;
            }
        }
        if(ok){
            a[x] = i;
            dfs(x + 1, a);
        }
    }
}
int main(){
    scanf("%d",&n);
    int a[9] = {0};
    dfs(0,a);
    return 0;
}