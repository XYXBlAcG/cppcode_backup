#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define MT int _T;cin>>_T;while(_T--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N=310;
int n,k,p[N],root,siz[N],Bsiz[N],Son[N],Bro[N],P[N];
int tot,b[N],f[N][N][N],g[N][N][N];
vector<int>son[N];
int Fd(int x){return lower_bound(b+1,b+tot+1,x)-b;}
int h(int x){return x>0?x:0;}
void Pre_dfs(int v){
	siz[v]=1;int pre=-1;
	for(auto u:son[v]){
		if(pre!=-1)Bro[u]=pre,Bsiz[u]+=Bsiz[pre];
		pre=u;Pre_dfs(u);
		siz[v]+=siz[u];
	}
	Bsiz[v]+=siz[v];Son[v]=h(pre);
}
void dfs(int v){
	for(auto u:son[v])dfs(u);
	rep(j,0,tot){
	
		rep(i,0,siz[v]){
			rep(t,P[v],tot)f[v][i][j]=min(f[v][i][j],g[Son[v]][h(i-(t<=j))][min(t,j)]+b[t]-b[P[v]]);
		}
		rep(i,0,Bsiz[v]){
			rep(s,0,i)g[v][i][j]=min(g[v][i][j],g[Bro[v]][i-s][j]+f[v][s][j]);
		}
	}
}
int main(){
	memset(f,0x3f,sizeof f);memset(g,0x3f,sizeof g);
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		int fa;
		scanf("%d%d",&fa,&p[i]);b[i]=p[i];
		if(fa!=-1)son[fa].push_back(i);
		else root=i;
	}
    sort(b+1,b+n+1);
    tot=unique(b+1,b+n+1)-b-1;
    rep(i,1,n)P[i]=Fd(p[i]);
    rep(i,0,tot)g[0][0][i]=0;
    Pre_dfs(root);dfs(root);
	int ans=inf;
	rep(j,P[root],tot)ans=min(ans,f[root][k][j]);
	printf("%d",ans);
	return 0;
}
