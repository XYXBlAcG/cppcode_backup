#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int head[N] , to[N] , nxt[N] , cnt , f[510][N] , deep[N] , md[N] , ans[520];
void add(int x , int y)
{
    to[++cnt] = y , nxt[cnt] = head[x] , head[x] = cnt;
}
void dfs(int x)
{
    int i , j , k;
    md[x] = deep[x] , f[deep[x]][x] ++ ;
    for(i = head[x] ; i ; i = nxt[i])
    {
        deep[to[i]] = deep[x] + 1 , dfs(to[i]);
        for(j = deep[x] ; j <= md[x] ; j ++ )
            for(k = deep[to[i]] ; k <= md[to[i]] ; k ++ )
                ans[(j - deep[x]) ^ (k - deep[x])] += f[j][x] * f[k][to[i]];
        for(j = deep[to[i]] ; j <= md[to[i]] ; j ++ )
            f[j][x] += f[j][to[i]];
        md[x] = max(md[x] , md[to[i]]);
    }
}
int main()
{
    int n , i , x;
    scanf("%d" , &n);
    for(i = 2 ; i <= n ; i ++ ) scanf("%d" , &x) , add(x , i);
    dfs(1);
    for(i = 0 ; ans[i] ; i ++ ) printf("%d\n" , ans[i]);
    return 0;
}