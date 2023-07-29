#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define inf 999999999
#define dl double
#define ll long long
#define re register
#define V inline void
#define LL inline ll
#define I inline int
#define B inline bool
#define FOR(i,a,b) for(re int i=(a) ,i##i=(b) ; i<=i##i ; ++i)
#define AFOR(i,a,b) for(re int i=(a) , i##i=(b) ; i>=i##i ; --i)
#define REP(i,u) for(re int i=head[u],v=edge[i].to;i!=-1;i=edge[i].nxt,v=edge[i].to)
#define gc (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin),fs==ft))?0:*fs++
// #define gc getchar()
using namespace std;
const int N=2e7+10,mo=20170408;
char buf[1<<18],*fs,*ft;
inline ll read() {
	ll w=0,p=0;
	char ch=gc;
	while(!isdigit(ch)) w=ch=='-'?1:0,ch=gc;
	while(isdigit(ch)) p=p*10+ch-'0',ch=gc;
	return w?-p:p;
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return ;
}
int p,cnt,vis[N],pre[N];
ll n,m,f[300],g[300],F[300],G[300],c[300];
V mul(ll *a,ll *b){
	FOR(i,0,p-1) FOR(j,0,p-1) c[i+j]=(c[i+j]+a[i]*b[j])%mo;
	FOR(i,0,p-1) a[i]=(c[i]+c[i+p])%mo,c[i]=c[i+p]=0;
	return ;
}
int main(){
	n=read(),m=read(),p=read();
	f[1]=g[1]=F[0]=G[0]=1;
	FOR(i,2,m){
		++f[i%p];
		if(!vis[i]) pre[++cnt]=i;
		else ++g[i%p];
		FOR(j,1,cnt){
			if(i*pre[j]>m) break;
			vis[i*pre[j]]=1;
			if(i%pre[j]==0) break;
		}
	}
	while(n){
		if(n&1) mul(F,f),mul(G,g);
		mul(f,f),mul(g,g),n>>=1;
	}
	write((F[0]-G[0]+mo)%mo);
	return 0;
}
