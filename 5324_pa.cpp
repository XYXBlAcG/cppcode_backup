#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
typedef unsigned int       u32;
typedef unsigned long long u64;
int qread(){
    int w=1,c,ret;
    while((c=getchar())> '9'||c< '0') w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';
    return ret*w;
}
const int MAXN=500+3,P=13331;
char S[MAXN][MAXN],T[MAXN*MAXN]; u64 h;
bool vis[MAXN][MAXN]; int n,m,p,s,t; i64 ans1,ans2;
const int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
u64 pwr(u64 a,u64 b){
    u64 r=1; while(b){if(b&1) r=r*a; a=a*a,b>>=1;} return r;
}
const int SIZ =999997,MAXM=MAXN*MAXN*8;
int head[SIZ],val[MAXM],nxt[MAXM],tot; u64 ver[MAXM];
void add(int u,u64 v){
    ver[++tot]=v,nxt[tot]=head[u],val[tot]=1,head[u]=tot;
}
void inc(u64 h){
    for(int p=head[h%SIZ];p;p=nxt[p])
    if(ver[p]==h){ans1+=2ll*val[p]+1,++val[p];return;}
    add(h%SIZ,h),++ans1;
}
u64 calc(u64 a,u64 b){  //calc a^0+a^1+a^2+...+a^(b-1)
    if(b==0) return 0; if(b==1) return 1;
    if(b&1) return (1ull+a)*calc(a*a,b>>1)*a+1;
    else    return (1ull+a)*calc(a*a,b>>1);
}
u64 gcd(u64 a, u64 b){
    return b ? gcd(b, a % b) : a;
}
int main(){
    n=qread(),m=qread(),p=qread(); u64 q=pwr(P,p);
    up(0,n-1,i) scanf("%s",S[i]);
    up(0,7,d){
        up(0,n-1,i) up(0,m-1,j) if(!vis[i][j]){
            int a=i,b=j; h=0; while(!vis[a][b]){
                h=h*P+S[a][b],T[t++]=S[a][b],vis[a][b]=true;
                a=(n+a+dir[d][0])%n,b=(m+b+dir[d][1])%m;
            }
            printf("t = %d\n", t);
            int x=p%t; h*=calc(pwr(P,t),p/t);
            up(0,x-1,k) h=h*P+T[k];
            up(0,t-1,k) inc(h),h=h*P+T[(x+k)%t]-T[k]*q;
            t=0;
        }
        up(0,n-1,i) up(0,m-1,j) vis[i][j]=0;
    }
    ans2=1ll*n*m*8*(1ll*n*m*8); i64 d=gcd(ans1,ans2);
    printf("%lld/%lld\n",ans1/d,ans2/d);
    return 0;
}
