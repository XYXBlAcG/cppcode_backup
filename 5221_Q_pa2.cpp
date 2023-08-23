#include<cstdio>
#include<algorithm> 
#define int long long
using std::sort;
using std::unique;
using std::lower_bound;
const int N=400011;
int n,tr[N*2];
struct Edge{
	int x,y1,y2,val;
}edge[N*2];
bool operator<(Edge a,Edge b){
	return a.x<b.x;
}
int ab(int x){
	return x<0?-x:x;
}
struct Tree{
	int len,disc,tim;
	bool il,ir;
}tree[N<<2];
void pushup(int x,int l,int r){
	Tree &u=tree[x];
	if(u.tim>0){
		u.len=tr[r]-tr[l];
//		printf("len=%d\n",u.len);
		u.il=u.ir=1;
		u.disc=1;
	}else if(l==r-1){
		u.disc=u.len=0;
		u.il=u.ir=0;
	}else{
		u.len=tree[x<<1].len+tree[x<<1|1].len;
		u.disc=tree[x<<1].disc+tree[x<<1|1].disc-(tree[x<<1].ir&tree[x<<1|1].il);
		u.il=tree[x<<1].il;
		u.ir=tree[x<<1|1].ir;
	}
}
void modify(int x,int l,int r,int L,int R,int val){
//	printf("l=%lld r=%lld L=%lld r=%lld\n",l,r,L,R);
	if(L<=l&&r<=R){
		tree[x].tim+=val;
//		printf("x=%d val=%d\n",x,val);
		pushup(x,l,r);
		return;
	}
	if(r==l+1)return;
	int mid=(l+r)>>1;
	if(L<=mid)modify(x<<1,l,mid,L,R,val);
	if(mid<R)modify(x<<1|1,mid,r,L,R,val);
	pushup(x,l,r);
}
signed main(){
	scanf("%lld",&n);
	int x1,y1,x2,y2,pedge=0,ptr=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		edge[++pedge]={x1,y1,y2,1};
		edge[++pedge]={x2,y1,y2,-1};
		tr[++ptr]=y1,tr[++ptr]=y2;
	}
	sort(edge+1,edge+1+pedge);
	sort(tr+1,tr+1+ptr);
//	for(int i=1;i<=ptr;i++){
//		printf("%d ",tr[i]);
//	}
	int anss=0,ansl=0,len=unique(tr+1,tr+1+ptr)-(tr+1);
	int las=0;
//	printf("len=%d\n",len);
	for(int i=1;i<=pedge;i++){
		int L=lower_bound(tr+1,tr+1+len,edge[i].y1)-tr;
		int R=lower_bound(tr+1,tr+1+len,edge[i].y2)-tr;
//		printf("L=%d R=%d\n",L,R);
		modify(1,1,len,L,R,edge[i].val);
//		printf("%d\n",tree[1].len);
		ansl+=ab(tree[1].len-las);
		las=tree[1].len;
		ansl+=tree[1].disc*2ll*(edge[i+1].x-edge[i].x);
		anss+=tree[1].len*(edge[i+1].x-edge[i].x);
	}
	printf("%lld %lld\n",ansl,anss);
	return 0;
}