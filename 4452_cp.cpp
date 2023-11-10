#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <algorithm>
#define read(n) scanf("%d", &n)
#define write(...) printf(__VA_ARGS__)
using std::min;
using std::max;
using std::swap;


const int maxn=1e5+10,inf=0x3f3f3f3f;
int n,m,val[6][maxn];

#define clr(x,y) memset(x,y,sizeof(x))
namespace SegmentTree {
	struct Node {
		int ll[6][6],rr[6][6],lr[6][6];
	}st[maxn<<2];

	Node operator + (const Node &lc,const Node &rc) {
		static Node res;
		static int lm[6][6],rm[6][6];
		clr(lm,0x3f);clr(rm,0x3f);
		for(int i(0);i<6;i++)
			for(int j(0);j<6;j++)
				for(int k(0);k<6;k++) {
					lm[i][j]=min(lm[i][j],lc.lr[i][k]+rc.ll[k][j]+lc.rr[j][j]);
					rm[i][j]=min(rm[i][j],rc.ll[i][i]+lc.rr[i][k]+rc.lr[k][j]);
				}
		for(int i(0);i<6;i++)
			for(int j(0);j<6;j++) {
				res.ll[i][j]=lc.ll[i][j];
				res.rr[i][j]=rc.rr[i][j];
				res.lr[i][j]=inf;
				for(int k(0);k<6;k++) {
					res.ll[i][j]=min(res.ll[i][j],lm[i][k]+lc.lr[j][k]-lc.rr[k][k]);
					res.rr[i][j]=min(res.rr[i][j],rm[k][i]+rc.lr[k][j]-rc.ll[k][k]);
					res.lr[i][j]=min(res.lr[i][j],min(lm[i][k]+rm[k][j]-lc.rr[k][k]-rc.ll[k][k],lc.lr[i][k]+rc.lr[k][j]));
				}
			}
		return res;
	}

#define lc (a<<1)
#define rc ((a<<1)|1)
	inline void Calc(const int &a,const int &l) {
		static int sum[6],tmp;
		for(int i(0);i<6;i++) sum[i]=val[i][l]+(i?sum[i-1]:0);
		for(int i(0);i<6;i++)
			for(int j(0);j<6;j++) {
				if(i<j) tmp=sum[j]-(i?sum[i-1]:0);
				else tmp=sum[i]-(j?sum[j-1]:0);
				st[a].ll[i][j]=st[a].rr[i][j]=st[a].lr[i][j]=tmp;
			}
	}
	void Build(const int &a=1,const int &l=1,const int &r=n) {
		if(l==r) return Calc(a,l);
		int mid=(l+r)>>1;
		Build(lc,l,mid);
		Build(rc,mid+1,r);
		st[a]=st[lc]+st[rc];
	}
	void Modify(const int &x,const int &y,const int &k,const int &a=1,const int &l=1,const int &r=n) {
		if(l==r) {
			val[x][y]=k;
			Calc(a,l);
			return;
		}
		int mid=(l+r)>>1;
		if(y<=mid) Modify(x,y,k,lc,l,mid);
		else Modify(x,y,k,rc,mid+1,r);
		st[a]=st[lc]+st[rc];
	}
	Node Query(const int &left,const int &right,const int &a=1,const int &l=1,const int &r=n) {
		if(left<=l&&right>=r) return st[a];
		int mid=(l+r)>>1;
		if(right<=mid) return Query(left,right,lc,l,mid);
		if(left>mid) return Query(left,right,rc,mid+1,r);
		return Query(left,right,lc,l,mid)+Query(left,right,rc,mid+1,r);
	}
	inline int Solve(const int &x1,const int &y1,const int &x2,const int &y2) {
		static Node l,mid,r;
		l=Query(1,y1);
		mid=Query(y1,y2);
		r=Query(y2,n);
		int ans=inf;
		for(int i(0);i<6;i++)
			for(int j(0);j<6;j++)
				for(int k(0);k<6;k++)
					for(int p(0);p<6;p++)
						ans=min(ans,mid.ll[x1][i]+l.rr[i][j]+mid.lr[j][k]+r.ll[k][p]
							+mid.rr[p][x2]-mid.ll[i][i]-mid.ll[j][j]-mid.rr[k][k]-mid.rr[p][p]);
		return ans;
	}
#undef lc
#undef rc
}

int main(void) {
// #ifndef ONLINE_JUDGE
// 	freopen("load.in","r",stdin);
// #endif
	read(n);
	for(int i(0);i<6;i++)
		for(int j(1);j<=n;j++)
			read(val[i][j]);
	SegmentTree::Build();
	read(m);
	for(int i(1);i<=m;i++) {
		int opt,x1,y1,x2,y2;
		read(opt);
		if(opt==1) {
			read(x1), read(y1), read(x2);
			SegmentTree::Modify(x1-1,y1,x2);
		}
		else if(opt==2) {
			read(x1), read(y1), read(x2), read(y2);
			if(y1>y2) swap(x1,x2),swap(y1,y2);
			write("%d\n", SegmentTree::Solve(x1-1,y1,x2-1,y2));
		}
	}
	return 0;
}

