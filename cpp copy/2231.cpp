#include <cstdio>
#include <iostream>
using std::min;
int ans;
int l[100010], r[100010], n, m;
int f[100011];
bool vis[100011];
int jump(int a){
    if(a == n)return 0;
    if(vis[a])return f[a];
    vis[a] = true;
    int fl = 99999999;
    for (int i = l[a]; i <= r[a]; i++){
        fl = min(fl, jump(i));
    }
    return f[a] = fl + 1;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    printf("%d",jump(1));
    return 0;
}