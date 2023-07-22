#include<bits/stdc++.h>
#define IL inline
#define RI register int
#define maxn 100008
int trie[maxn*31][2],xo[maxn],ans,rt;
int val[maxn],n,head[maxn],tot;
struct code{int u,v,w;}edge[maxn<<1];
IL void read(int &x){
	int f=1;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){x=x*10+s-'0';s=getchar();}
	x*=f;
}
IL void add(int x,int y,int z)
{
	edge[++tot].u=head[x];
	edge[tot].v=y;
	edge[tot].w=z;
	head[x]=tot;
	edge[++tot].u=head[y];
	edge[tot].v=x;
	edge[tot].w=z;
	head[y]=tot;
}
IL void build_trie(int x,int rt)
{
	for(RI i=1<<30;i;i>>=1)
	{
		bool c=x&i;
		if(!trie[rt][c])trie[rt][c]=++tot;
		rt=trie[rt][c];
	}
}
IL int query(int x,int rt)
{
	int ans=0;
	for(RI i=1<<30;i;i>>=1)
	{
		bool c=x&i;
		if(trie[rt][c^1])ans+=i,rt=trie[rt][c^1];
		else rt=trie[rt][c];
	}
	return ans;
}
IL void dfs(int u,int fa)
{
	for(RI i=head[u];i;i=edge[i].u)
	{
		if(edge[i].v!=fa)
		{
			xo[edge[i].v]=xo[u]^edge[i].w;
			dfs(edge[i].v,u);
		}
	}
}
int main()
{
	read(n);
	for(RI i=1,u,v,w;i<n;i++)read(u),read(v),read(w),add(u,v,w);
	dfs(1,0);
	for(RI i=1;i<=n;i++)build_trie(xo[i],rt);
	for(RI i=1;i<=n;i++)ans=std::max(ans,query(xo[i],rt));
	printf("%d",ans);
}