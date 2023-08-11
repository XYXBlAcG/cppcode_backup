#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int len[N*4];
struct Tree{
    int l0,l1,long0,long1,r0,r1,tot0,tot1;
}tree[N*4];
struct Mark{
    int tg,rev;
}mark[N*4];
inline int ls(int x){ return x<<1; }
inline int rs(int x){ return x<<1|1; }
Tree push_up(Tree a,Tree b){
    return {
        a.tot1?a.l0:a.tot0+b.l0,
        a.tot0?a.l1:a.tot1+b.l1,
        max(max(a.long0,b.long0),a.r0+b.l0),
        max(max(a.long1,b.long1),a.r1+b.l1),
        b.tot1?b.r0:b.tot0+a.r0,
        b.tot0?b.r1:b.tot1+a.r1,
        a.tot0+b.tot0,
        a.tot1+b.tot1
    };
}
void build(int p,int l,int r){
    mark[p]={-1,0};
    len[p]=r-l+1;
    if(l==r){
        if(a[l]){
            tree[p]={0,1,0,1,0,1,0,1};
        }else{
            tree[p]={1,0,1,0,1,0,1,0};
        }
        return;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    tree[p]=push_up(tree[ls(p)],tree[rs(p)]);
}
void modify(int i,int type){
    if(type==0){
        mark[i]={0,0}; 
        tree[i]={len[i],0,len[i],0,len[i],0,len[i],0};
    }else if(type==1){
        mark[i]={1,0};
        tree[i]={0,len[i],0,len[i],0,len[i],0,len[i]};
    }else{
        mark[i].rev^=1;
        swap(tree[i].l0,tree[i].l1);
        swap(tree[i].long0,tree[i].long1);
        swap(tree[i].r0,tree[i].r1);
        swap(tree[i].tot0,tree[i].tot1);
    }
}
void push_down(int p){
    if(mark[p].tg!=-1){
        modify(ls(p),mark[p].tg);modify(rs(p),mark[p].tg);
    }
    if(mark[p].rev){
        modify(ls(p),2);modify(rs(p),2);
    }
    mark[p]={-1,0};
}
void update(int p,int l,int r,int ql,int qr,int c){
    if(r<ql||l>qr) return;
    if(l>=ql&&r<=qr){
        modify(p,c);
        return;
    }
    push_down(p);
    int mid=(l+r)>>1;
    update(ls(p),l,mid,ql,qr,c);
    update(rs(p),mid+1,r,ql,qr,c);
    tree[p]=push_up(tree[ls(p)],tree[rs(p)]);
}
Tree query(int p,int l,int r,int ql,int qr){
    if(r<ql||l>qr) return {0,0,0,0,0,0,0,0};
    if(l>=ql&&r<=qr) return tree[p];
    push_down(p);
    int mid=(l+r)>>1;
    return push_up(query(ls(p),l,mid,ql,qr),query(rs(p),mid+1,r,ql,qr));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    int type,l,r;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&type,&l,&r);
        if(type<=2){
            update(1,1,n,l,r,type);
        }else if(type==3){
            printf("%d\n",query(1,1,n,l,r).tot1);
        }else{
            printf("%d\n",query(1,1,n,l,r).long1);
        }
    }
    return 0;
}