
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define mem(a,b) memset(a,b,sizeof(a))
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxm=200010,maxn=5010;
struct Edge{
    int u,v,w,power,next;
    Edge() {}
    Edge(int _1,int _2,int _3,int _4,int _5):u(_1),v(_2),w(_3),power(_4),next(_5) {}
}e[maxm],E[420];
int n,m,Energy,a,b,c,d,c1=-1,c2=-1,First[60],first[maxn],dis[maxn],ans=2147483647;
bool vis[maxn];
priority_queue <PII,vector<PII>,greater<PII> > Q;
int id(int x,int y){return (x-1)*(Energy+1)+y;}
void AddEdge(int a,int b,int c,int d){E[++c2]=Edge(a,b,c,d,First[a]);First[a]=c2;}
void addEdge(int a,int b,int c){e[++c1]=Edge(a,b,c,0,first[a]);first[a]=c1;}
void Dijkstra()
{
    mem(dis,42);
    dis[id(1,Energy/2)]=0;
    Q.push(make_pair(0,id(1,Energy/2)));
    while(Q.size())
    {
        int now=Q.top().second;Q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(int i=first[now];i!=-1;i=e[i].next)
            if(dis[e[i].v]>dis[now]+e[i].w)
            {
                dis[e[i].v]=dis[now]+e[i].w;
                Q.push(make_pair(dis[e[i].v],e[i].v));
            }
    }
    for(int i=0;i<=Energy;i++)ans=min(ans,dis[id(n,i)]);
    return;
}
int main()
{
    // freopen("star.in","r",stdin);
    // freopen("star.out","w",stdout);
    mem(first,-1);mem(First,-1);
    n=read();m=read();Energy=read();
    for(int i=1;i<=m;i++)a=read(),b=read(),c=read(),d=read(),AddEdge(a,b,c,d);
    for(int k=1;k<=n;k++)
        for(int j=0;j<=Energy;j++)
            for(int i=First[k];i!=-1;i=E[i].next)
                if(j+E[i].power<=Energy && j+E[i].power>=0)addEdge(id(k,j),id(E[i].v,j+E[i].power),E[i].w);
    Dijkstra();
    printf("%d\n",ans);
    return 0;
}