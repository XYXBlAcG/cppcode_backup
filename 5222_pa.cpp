#include<bits/stdc++.h>
 
#define N 100010
 
using namespace std;
 
struct Point
{
    int x,y;
}p[N];
 
struct Line 
{
    int opt,x,r,y;//1 竖线下端点 0 横线 -1 竖线上端点
}l[N*10];
 
int n,ans,cnt,b[N],c[N];
 
 //树状数组
int lowbit(int x)
{
    return x&-x;
}
 
void add(int x,int y)
{
    for(;x<=n;x+=lowbit(x))c[x]+=y;
}
 
int query(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x))ans+=c[x];
    return ans;
}
 
bool cmpx(Point a,Point b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmpy(Point a,Point b){return a.y==b.y?a.x<b.x:a.y<b.y;}
bool cmpLine(Line a,Line b){return a.y==b.y?a.opt<b.opt:a.y<b.y;}
 
void work()
{
    sort(p+1,p+n+1,cmpx);
    for(int i=1;i<n;i++)
    {
        if(p[i].x==p[i+1].x)
        {
            l[++cnt]=(Line){1,p[i].x,0,p[i].y};
            l[++cnt]=(Line){-1,p[i].x,0,p[i+1].y};
        }
    }
    sort(p+1,p+n+1,cmpy);
    for(int i=1;i<n;i++)
        if(p[i].y==p[i+1].y)
            l[++cnt]=(Line){0,p[i].x,p[i+1].x,p[i].y};
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        b[i]=p[i].x;
    }   
    sort(b+1,b+n+1);//离散化
    int tot=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
        p[i].x=lower_bound(b+1,b+tot+1,p[i].x)-b;
  	work();//加入线段
    sort(l+1,l+cnt+1,cmpLine);//扫描
    for(int i=1;i<=cnt;i++)
    {
        if(!l[i].opt)ans+=query(l[i].r-1)-query(l[i].x);
        else add(l[i].x,l[i].opt);
        printf("%d\n", ans);
    }
    printf("%d\n",ans+n);
    return 0;
}
