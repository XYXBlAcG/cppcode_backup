/**************************************************************
    Problem: 2141
    User: ypxrain
    Language: C++
    Result: Accepted
    Time:1460 ms
    Memory:1448 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
const int maxn=2e4+7;
 
int n,m,ans,x,y;
int a[maxn],b[maxn];
 
void solve(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    int d=mid;
    for (int i=l;i<=mid;i++)
    {
        while ((d<r) && (b[d+1]<b[i])) d++;
        ans+=d-mid;
    }
    sort(b+l,b+r+1);
}
 
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }   
    solve(1,n); 
    printf("%d\n",ans);
    scanf("%d",&m); 
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);
        for (int j=x+1;j<=y;j++)
        {
            if (a[x]>a[j]) ans--;
            if (a[x]<a[j]) ans++;
        }
        for (int j=x+1;j<y;j++)
        {
            if (a[j]>a[y]) ans--;
            if (a[j]<a[y]) ans++;
        }
        swap(a[x],a[y]);
        printf("%d\n",ans);
    }
}
