#include<bits/stdc++.h>
using namespace std;
const int Bit=30;
const int maxn=Bit*(12005);
#define int long long
int tot=0;
struct seg_tree{
	int son[2];
	int cnt;
}tr[1500000];
/*
2023.0904
查询的时候是丢root[r/l]进去，太久没写主席树了
位运算是(val>>step)&1不是val&(1<<step)
insert的时候step和当前的指向是错开一位的，所以step<0不能马上return
插入0.. 
*/
void insert(int pre,int& _root,int val,int step){
	_root=++tot;
	tr[_root]=tr[pre];
	tr[_root].cnt++;
	// 相当于主席树的那个区间累加
	if(step<0) return;
	int bit=(val>>step)&1;
	insert(tr[pre].son[bit],tr[_root].son[bit],val,step-1);
}
const int N=12000+5;
int n,m,a[N],root[N],sum[N];
int query(int ql,int qr,int val,int step){
	if(step<0) return 0;
	int bit=(val>>step)&1;
	if(tr[tr[qr].son[bit^1]].cnt-tr[tr[ql].son[bit^1]].cnt>0){
		return (1<<step)+query(tr[ql].son[bit^1],tr[qr].son[bit^1],val,step-1);
	}
	else return query(tr[ql].son[bit],tr[qr].son[bit],val,step-1); 
}
int block,pos[N],f[1005][12000+5];
void Block(){
	block=sqrt(n);
	for(int i=1;i<=n;i++) pos[i]=i/block+1;
	for(int i=1;i<=pos[n];i++){
		int L=(i-1)*block+1;
		for(int j=L;j<=n;j++){
			f[i][j]=f[i][j-1];
			int ans;
	        if(L!=1) ans=query(root[L-2],root[j],sum[j],Bit);
			else ans=query(0,root[j],sum[j],Bit);
			f[i][j]=max(f[i][j],ans);
		}
	}
}
void solve(){
	int lastans=0;
	while(m--){
		int x,y;cin>>x>>y;
		int l,r;
		l=min( ((x+lastans)%n) +1, ((y+lastans)%n) +1);
		r=max( ((x+lastans)%n) +1, ((y+lastans)%n) +1);
		int ans=0;
		if(pos[l]^pos[r]){ //x、y 不在同一块内 
			ans=f[pos[l]+1][r];
		}
		int up=min(pos[l]*block,r);
		
		for(int i=l;i<=up;i++){
			ans=max(ans,query(root[i-1],root[r],sum[i-1],Bit));
		}
		cout<<ans<<endl;
		lastans=ans; 
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	 
	//freopen("lys.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	
	root[0]=++tot;
	insert(0,root[0],0,Bit);
	for(int i=1;i<=n;i++){
		insert(root[i-1],root[i],sum[i],Bit);
	}
	
	Block();
	solve();
}