#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define YES puts("YES")
#define NO puts("NO")
const int N = 105;
int n, t[N], d[N], ans;
int fa[N];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", t + i);
    for (int i = 1; i <= n; i++) scanf("%d", d + i);
    for (int i = 1; i <= n; i++){
        for (int j = )
    }
    return 0;
}