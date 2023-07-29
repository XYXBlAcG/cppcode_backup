#include <cstdio>
#include <iostream>
using std::max;
using std::min;
int n, m, r, k;
int arr[3010][11];
int fa[3010][11];
bool vis[3010][11];
int f(int i, int j){
    if(vis[i][j]){
        return fa[i][j];
    }
    fa[i][j] = 1;
    vis[i][j] = true;
    int tmp = fa[i][j], tmp2 = fa[i][j];
    for(int z = 1; z < i; z++){
		if(arr[z][j] <= arr[i][j] && tmp < f(z,j) + 1)
			tmp = max(f(z,j) + 1, tmp);
    }
    if (j > 0){
        for (int z = 1; z < i; z++){
            tmp2 = max(f(z,j - 1) + 1, tmp2);
        }
    }
    fa[i][j] = max(tmp, tmp2);
	return fa[i][j];
}
int main(){
    scanf("%d%d",&n, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d",&arr[i][0]);
    }
    for (int i = 0; i <= k; i++){
        for (int j = 1; j <= n; j++){
            arr[j][i + 1] = arr[j][i];
        }
    }
    for (int i = 1; i <= n; i++){
        r = max(f(i, k), r);
    }
    printf("%d\n",r);
    return 0;
}

