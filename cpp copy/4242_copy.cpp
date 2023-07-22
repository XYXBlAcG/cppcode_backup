#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1010
#define M 110
using namespace std;
int t,n,ssgg[M][M];
struct node{int x,y;}pt[N];
int sg(int x,int y){
    if(x==0||y==0)return 0;
    if(x==y)return ssgg[x][y]=0;
    if(ssgg[x][y]!=-1)return ssgg[x][y];
    bool v[10010];
    memset(v,0,sizeof(v));
    for(int k=1;;k++){
        if(x-k<=0&&y-k<=0)break;
        if(x-k>0&&x-k!=y)v[sg(x-k,y)]=1;
        if(y-k>0&&y-k!=x)v[sg(x,y-k)]=1;
        if(x-k>0&&y-k>0)v[sg(x-k,y-k)]=1;
    }
    for(int i=0;;i++)
        if(!v[i])return ssgg[x][y]=ssgg[y][x]=i;
}
int main()
{
    scanf("%d",&t);
    memset(ssgg,-1,sizeof(ssgg));
    while(t--){ 
        scanf("%d",&n);
        int flag=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&pt[i].x,&pt[i].y);
       if(pt[i].x==0||pt[i].y==0||pt[i].x==pt[i].y)flag=1;
        }
        if(flag){
            puts("^o^");
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans^=sg(pt[i].x,pt[i].y);
        if(ans==0)puts("T_T");
        else puts("^o^");
    }
}