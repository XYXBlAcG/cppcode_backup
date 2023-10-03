#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
struct edge {int to,from; }e[200010*2],c[200010*2];
int n,m,q,dis,tot,cnt,num,cnt1,cnt2,head[200010],last[200010],dfn[100010],low[100010],k[100010],sh[200010],f[200010][21],dep[200010],d[200010];
void insert(int x,int y) { e[++cnt].to=y; e[cnt].from=head[x]; head[x]=cnt; }
void insert1(int x,int y) { c[++cnt2].to=y; c[cnt2].from=last[x]; last[x]=cnt2; }
void tarjan(int x)
{
    dfn[x]=low[x]=++cnt1; k[++num]=x;
    for (int i=head[x];i;i=e[i].from)
    {
        int v=e[i].to;
        if (dfn[v]==-1)
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
            if (low[v]>=dfn[x])
            {
                tot++;
                int j;
                do
                {
                    j=k[num--];
                    insert1(tot,j); insert1(j,tot);
                }
                while (j!=v);
                insert1(x,tot);insert1(tot,x);
            }
        }
        else low[x]=min(low[x],dfn[v]);
    }
}
void dfs(int x,int fa)
{
    sh[sh[0]++]=x; f[x][0]=fa;
    for (int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
    for (int i=last[x];i;i=c[i].from)
    {
        int v=c[i].to;
        if (v==fa) continue;
        printf("%d %d\n", x, v);
        dep[v]=dep[x]+1;
        dfs(v,x);
    }
}
int lca(int x,int y)
{
    if (dep[x]>dep[y]) swap(x,y);
    for (int i=20;i>=0;i--)
        if (dep[f[y][i]]>=dep[x])
            y=f[y][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
        if (f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    tot=n;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v); insert(v,u);
    }
    memset(dfn,-1,sizeof(dfn));
    tarjan(1);
    dep[1]=1; dfs(1,0);
    for (int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        dis=lca(x,y);
        printf("anc = %d\n", dis);
        d[x]++; d[y]++; d[dis]--; d[f[dis][0]]--;
    }
    for (int i=tot;i>=1;i--)
    {
        int now=sh[i];
        d[f[now][0]]+=d[now];
    }
    for (int i=1;i<=n;i++) printf("%d\n",d[i]);
    return 0;
}