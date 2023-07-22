#include <cstdio>
#include <iostream>
using std::min;
using std::max;
int n, p, P;
int m[210],v[210];
int f1[210][10010];
bool vis[210][10010];
int f(int i, int j){
    if (i == 0){
        if (j == p){
            return 0;
        }else{
            return -1000000;
        }
    }
    if(vis[i][j])return f1[i][j];
    vis[i][j] = true;
    int fl = f(i - 1, j);
    /*if ((j * m[i]) % P <= p)*/ fl = max(f(i - 1, /*j - m[i]*/(j * m[i]) % P) + v[i], fl);
    return f1[i][j] = fl;
}
int main(){
    scanf("%d%d%d", &n, &p, &P);
    for (int i = 1; i <= n; i++){
        scanf("%d%d",&m[i],&v[i]);
    }
    
    int ans = f(n, 1);
    // printf("%d\n",ans);
    if (ans < 0){
        ans = -1;
    }
    printf("%d\n",ans);
    return 0;
}