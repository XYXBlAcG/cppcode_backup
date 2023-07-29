#include <cstdio>
#include <algorithm>
#include <iostream>
#define rep(ii,a,b) for(int ii=a;ii<=b;++ii)
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;//head
const int maxn=4e5+10,maxm=2e6+10;
int casn,n,m,k,cnt;
class bit{public:
  int node[maxn];
  inline int lb(int x) {return x&(-x);}
  inline void update(int pos,int val){
    for(;pos<=n;pos+=lb(pos)) node[pos]+=val;
  }
  inline int ask(int pos){
    int sum=0;
    for(;pos>0;pos-=lb(pos)) sum+=node[pos];
    return sum;
  }
  inline int query(int l,int r){
    return ask(r)-ask(l-1);
  }
}tree;
struct node{int x,l,r,k;}q[maxn],ql[maxn],qr[maxn];
int ans[maxn],b[maxn];
namespace divide{
  void dc(int s,int t,int l,int r){ 
    if(l>r||s>t) return ;
    if(l==r){
      rep(i,s,t) if(q[i].x)ans[q[i].x]=l;
      return ;
    }
    int mid=(l+r)>>1,cntl=0,cntr=0,tmp;
    rep(i,s,t){
      if(!q[i].x){
        if(q[i].k<=mid) ql[++cntl]=q[i],tree.update(q[i].l,1);
        else qr[++cntr]=q[i];        
      }else{
        tmp=tree.query(q[i].l,q[i].r);
        if(tmp<q[i].k)q[i].k-=tmp,qr[++cntr]=q[i];
        else ql[++cntl]=q[i];
      }
    }
    rep(i,1,cntl){
      q[s-1+i]=ql[i];
      if(!ql[i].x) tree.update(ql[i].l,-1);
    }
    rep(i,1,cntr)q[s-1+cntl+i]=qr[i];
    dc(s,s+cntl-1,l,mid);dc(s+cntl,t,mid+1,r);
  }
}
int main() {IO;
  cin>>n>>m;
  rep(i,1,n) cin>>b[i];
  rep(i,1,n) q[i]=(node){0,i,i,b[i]};
  int l,r,k;
  rep(i,1,m){
    cin>>l>>r>>k;
    q[n+i]=(node){i,l,r,k};
  }
  divide::dc(1,n+m,-1e9-10,1e9+10);
  rep(i,1,m) cout<<ans[i]<<endl;
}