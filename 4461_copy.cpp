#include<cstdio>
#include<algorithm>
using namespace std;
int gi()
{
    int x=0,w=1;char ch=getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if (ch=='-') w=0,ch=getchar();
    while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return w?x:-x;
}
const int N = 5e4+5;
int n,m,a[N],maxa;
struct Data{int ll,rr,ml,mr,mm,sum;};
Data operator + (Data a,Data b)
{
    Data c;
    c.mm=max(a.mm,b.mm);c.ml=a.ml;c.mr=b.mr;
    if (a.rr<=b.ll)
    {
        c.mm=max(c.mm,a.mr+b.ml);
        if (a.mm==a.sum) c.ml=a.sum+b.ml;
        if (b.mm==b.sum) c.mr=b.sum+a.mr;
    }
    c.ll=a.ll;c.rr=b.rr;c.sum=a.sum+b.sum;
    return c;
}
struct segment_tree{
    Data t[N<<2];
    void build(int x,int l,int r)
        {
            if (l==r) {t[x]=(Data){a[l],a[l],1,1,1,1};return;}
            int mid=(l+r)>>1;
            build(x<<1,l,mid);build(x<<1|1,mid+1,r);
            t[x]=t[x<<1]+t[x<<1|1];
        }
    Data query(int x,int l,int r,int ql,int qr)
        {
            // if(l>ql||r<qr) {t[x].mm = 0; return t[x];}
            if (l>=ql&&r<=qr) return t[x];
            int mid=(l+r)>>1;
            if (qr<=mid) return query(x<<1,l,mid,ql,qr);
            if (ql>mid) return query(x<<1|1,mid+1,r,ql,qr);
            return query(x<<1,l,mid,ql,qr)+query(x<<1|1,mid+1,r,ql,qr);
        }
}A,B;
int main()
{
    n=gi();
    for (int i=1;i<=n;++i) a[i]=gi(),maxa=max(maxa,a[i]+1);
    A.build(1,1,n);
    for (int i=1;i<=n;++i) a[i]=maxa-a[i];
    B.build(1,1,n);
    m=gi();
    while (m--)
    {
        int l=gi(),r=gi();
        printf("%d\n",max(A.query(1,1,n,l,r).mm,B.query(1,1,n,l,r).mm));
    }
    return 0;
}