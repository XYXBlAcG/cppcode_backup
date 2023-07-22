#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <ext/rope>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define rsp(it,s) for(set<int>::iterator it=s.begin();it!=s.end();it++)
#define vi vector<int>
#define pii pair<int,int>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pi acos(-1.0)
const int maxn=1e2+10;
const int dis[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
using namespace std;
using namespace __gnu_cxx;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
int n,m,p[maxn]={0},ma;
string a[maxn];
char b;
void dfs(string q,int cnt,int p[])
{
    ma=max(ma,cnt);
    int len=q.length();
    for(int i=0;i<2*n;i++)
    {
        if(!p[i])
        {
            int len2=a[i].length();
            int len1=min(len2,len);
            for(int j=1;j<=len1-1;j++)
            {
                if(q.substr(len-j,j)==a[i].substr(0,j))
                {
                    p[i]=1;
                    dfs(a[i],cnt+a[i].length()-j,p);
                    p[i]=0;
                    goto loop;
                }
            }
        }
        loop:;
    }
}
int main()
{
    int i,j,k,t;
    scanf("%d",&n);
    rep(i,0,n-1)cin>>a[i],a[n+i]=a[i];
    cin>>b;
    rep(i,0,n-1)if(a[i][0]==b)p[i]=1,dfs(a[i],a[i].length(),p),p[i]=0;
    printf("%d\n",ma);
    //system ("pause");
    return 0;
}