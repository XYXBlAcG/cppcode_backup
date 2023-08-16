#include<cstdio>
#include<algorithm>
#include<iostream>
using std::max;
#define len(x) tree[x].r - tree[x].l + 1
#define de(x) std::cout << " = " << x << std::endl
int n,m,a[100011],L,R;
struct Tree{
	int l,r,lm,rm,mi;//ml,mr;
}tree[100011*8];
void pushup(int v){
	Tree &u=tree[v],&l=tree[v<<1],&r=tree[v<<1|1];
	bool tmp = a[l.r]<a[r.l];
	u.lm=l.lm,u.rm=r.rm;
	// if(l.mi==l.r-l.l+1)u.lm=l.r-l.l+1+r.lm*(a[r.l]>a[l.r]);
	// if(r.mi==r.r-r.l+1)u.rm=r.r-r.l+1+l.rm*(a[r.l]>a[l.r]);
	if(l.mi==len(v<<1))u.lm=len(v<<1)+r.lm*(tmp);
	if(r.mi==len(v<<1|1))u.rm=len(v<<1|1)+l.rm*(tmp);
//	printf("v=%d l=%d r=%d\n",v,u.lm,u.rm);
	if(l.mi>=r.mi&&l.mi>=(l.rm+r.lm)*(tmp)){
//		printf("##v=%d\n",v);
		u.mi=l.mi;
        // u.ml=l.ml;
        // u.mr=l.mr;
	}	
	else if(l.mi<=r.mi&&r.mi>=(l.rm+r.lm)*(tmp)){
//		printf("!!v=%d\n",v);
		u.mi=r.mi;
        // u.ml=r.ml;
        // u.mr=r.mr;
	}
	else{
//		printf("??v=%d l=%d r=%d\n",v,l.rm,r.lm);
		u.mi=l.rm+r.lm;
		// u.ml=l.r-l.lm+1;
		// u.mr=r.l+r.rm-1;
	}
	de(u.lm), de(u.rm), de(u.mi);
	de(l.lm), de(l.rm), de(l.mi);
	de(r.lm), de(r.rm), de(r.mi);
}
void debug(int u, int l, int r){
	printf("%d %d %d %d %d\n", tree[u].l, tree[u].r, tree[u].lm, tree[u].rm, tree[u].mi);
	if(l == r) return;
	int mid = (l + r) >> 1;
	debug(u << 1, l, mid);
	debug(u << 1 | 1, mid + 1, r);
}
void build(int v,int l,int r){
    tree[v].l=l,tree[v].r=r;
	if(l==r){
		tree[v]=(Tree){l,r,1,1,1};
		return;
	}
	int mid=(l+r)>>1;
	build(v<<1,l,mid),build(v<<1|1,mid+1,r);
	// tree[v].l=l,tree[v].r=r;
	pushup(v);
//	printf("v=%d l=%d r=%d mi=%d\n",v,l,r,tree[v].mi);
}
void modify(int v,int l,int r){
	if(R<l||r<L)return;
	if(L<=l&&r<=R)return;
	int mid=(l+r)>>1;
	modify(v<<1,l,mid),modify(v<<1|1,mid+1,r);
	pushup(v);
	printf("modify "), de(tree[v].mi);
	printf("modify "), de(tree[v<<1].mi);
	printf("modify "), de(tree[v<<1|1].mi);
}
int query(int l,int r,int v){
	if(l>R||L>r){printf("query 0\n");return 0;}
	if(L<=l&&r<=R){
		printf("query "), de(tree[v].mi);
		return tree[v].mi;}
	int mid=(l+r)>>1;
//	printf("v=%d l=%d r=%d spl=%d\n",v,l,r,(std::min(tree[v<<1].rm,tree[v<<1].r-L+1)+std::min(tree[v<<1|1].lm,R-tree[v<<1|1].l+1))*(a[tree[v<<1].r]<a[tree[v<<1|1].l]));
	return max(max(query(l,mid,v<<1),\
    query(mid+1,r,v<<1|1)),\
    (std::min(tree[v<<1].rm,tree[v<<1].r-L+1)\
    +std::min(tree[v<<1|1].lm,R-tree[v<<1|1].l+1))\
    *(a[tree[v<<1].r]<a[tree[v<<1|1].l]));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	int type;
	for(int i=1;i<=m;i++){
		scanf("%d",&type);
		if(!type){
			int v,c;
			scanf("%d%d",&v,&c);
			L=v,R=v;
			a[v]=c;modify(1,1,n);
			debug(1, 1, n);
			for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }putchar('\n');
		}
		else{
			scanf("%d%d",&L,&R);
			printf("%d\n",query(1,n,1));
			debug(1, 1, n);
			for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }putchar('\n');
		}
	}
	return 0;
}