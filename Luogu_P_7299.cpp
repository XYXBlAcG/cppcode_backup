#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 2005;
int n, k, cur[N];
struct Exchange{
    int a, b;
}mdf[N];
bool vis[N][N];
int cnt[N];
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1 ; i <= n; i++) cur[i] = i, vis[i][i] = 1, cnt[i] = 1;
    for (int i = 1; i <= k; i++){
        scanf("%d%d", &mdf[i].a, &mdf[i].b);
        if(!vis[cur[mdf[i].a]][mdf[i].b]) vis[cur[mdf[i].a]][mdf[i].b] = 1, cnt[cur[mdf[i].a]]++;
        if(!vis[cur[mdf[i].b]][mdf[i].a]) vis[cur[mdf[i].b]][mdf[i].a] = 1, cnt[cur[mdf[i].b]]++;
        std::swap(cur[mdf[i].a], cur[mdf[i].b]);
    }
    for (int i = 1; i <= n; i++){
        printf("%d\n", cnt[i]);
    }

    return 0;
}