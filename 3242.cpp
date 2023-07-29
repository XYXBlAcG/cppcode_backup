#include <bits/stdc++.h>
#define I int
const I N = 2e5 + 5;
I n, u[N], q[N], a[N], l, f;
std::vector<I> d[N];
void dfs(I x, I f, I b){
    u[x]=1;q[x]=l;a[x]=b;int s=d[x].size();
    if(!s) l = x;
    for(I i = 0; i < s; i++){
        I v = d[x][i];
        if(!u[v]) dfs(v,i<s-1?x:f,i<s-1?d[x][i+1]:b);
    }
}
I main(){
    std::cin >> n;
    for (I i = 1; i < n; i++){
        std::cin >> f;
        d[f].push_back(i + 1);
    }
    dfs(1, 1, 0);
    for (I i = 1; i <= n; i++)
        printf("%d %d\n", q[i], a[i]);
    return 0;
}