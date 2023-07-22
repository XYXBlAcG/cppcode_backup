#include<iostream>
#include<queue>
# define INF (0x3f3f3f3f)
# define min(x,y) (x<y?x:y)
# define max(x,y) (x>y?x:y)
# define N (200005)
using namespace std;
inline int read(){
	char c=getchar();int sum=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){sum=(sum<<3)+(sum<<1)+(c^48);c=getchar();}
	return sum*f;
}
struct node{
	int a,b,r,p;
	bool operator<(const node &x)const{
		return r<x.r;
	}
}edge[N];
queue<int>q;
int ans[N],vis[N],n,m,dep[N];
int head[N],nxt[N],to[N],tot;
inline void add(int &x,int &y){
	to[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
int main(){
	int i,j,k,u,v;
	memset(ans,0x3f,sizeof(ans));
	n=read();m=read();
	for(i=1;i<=m;++i){
		edge[i].a=read();edge[i].b=read();
		edge[i].r=read();edge[i].p=read();
		++dep[edge[i].a];
	}
	sort(edge+1,edge+1+m);
	for(i=1;i<=m;++i) add(edge[i].b,i);
	for(i=1;i<=n;++i) if(!dep[i])q.push(i);
	for(i=m;i>=1;--i){
		while(!q.empty()){
			u=q.front();q.pop();
			for(j=head[u];j;j=nxt[j]){
				k=to[j];if(vis[k])continue;
				vis[k]=1;--dep[edge[k].a];
				if(!dep[edge[k].a])	q.push(edge[k].a);
				if(ans[u]!=INF)
					ans[edge[k].a]=min(ans[edge[k].a],max(edge[k].r,ans[u]-edge[k].p));
			}
		}
		if(!vis[i]){
			vis[i]=1;--dep[edge[i].a];
			if(!dep[edge[i].a])q.push(edge[i].a);
			ans[edge[i].a]=min(ans[edge[i].a],edge[i].r);
		}
	}
	for(i=1;i<=n;++i) printf("%d ",(ans[i]==INF?-1:ans[i]));
	return 0;
}