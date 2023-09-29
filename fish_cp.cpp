
#include<cstdio>
using namespace std;
#define ri register int
#define ll long long
const ll MOD=20130427;
ll b,n,m,l[100005],r[100005],f[2][100005],pb[100005],spb[100005],s1[100005],s2[100005];
void testcase1(ll len);
void testcase2(ll len);
ll getans(ll a[],ll len)
{
    pb[0]=spb[0]=1;
    for(ri i=1;i<=len;i++)
    {
        pb[i]=pb[i-1]*b%MOD;
        spb[i]=(spb[i-1]+pb[i])%MOD;
        printf("pw = %lld %lld\n", pb[i], spb[i]);
        s1[i]=(s1[i-1]+a[i]*pb[i-1]%MOD)%MOD;
    }
    s2[len+1]=0;
    for(ri i=len;i;i--)s2[i]=(s2[i+1]*b%MOD+a[i])%MOD;
	testcase1(len);
    testcase2(len);
    for(ri i=1;i<=len;i++)
    {
        f[0][i]=(f[0][i-1]*b%MOD+b*(b-1)/2%MOD*pb[i-1]%MOD*spb[i-1]%MOD)%MOD;
        f[1][i]=(f[0][i-1]*a[i]%MOD+(a[i]-1)*a[i]/2%MOD*pb[i-1]%MOD*spb[i-1]%MOD+f[1][i-1]+a[i]*(s1[i-1]+1)%MOD*spb[i-1])%MOD;
        printf("%lld %lld\n", f[0][i-1]*a[i]%MOD+(a[i]-1)*a[i]/2%MOD*pb[i-1]%MOD*spb[i-1]%MOD, a[i]*(s1[i-1]+1)%MOD*spb[i-1]);
    }
	testcase2(len);
    ll res=0;
    for(ri i=1;i<=len;i++)
    {
        res=(res+f[1][i])%MOD;
        if(s2[i+1]>1)res=(res+(s2[i+1]-1)*f[0][i]%MOD)%MOD;
    }
    return res;
}
int main()
{
    scanf("%lld",&b);
    scanf("%lld",&n);
    for(ri i=n;i;i--)scanf("%lld",l+i);
    scanf("%lld",&m);
    for(ri i=m;i;i--)scanf("%lld",r+i);
    l[1]--;
    for(ri i=1;i<n;i++)
        if(l[i]<0)l[i]+=b,l[i+1]--;
    if(l[n]==0)n--;
    printf("%lld",(getans(r,m)-getans(l,n)+MOD)%MOD);
}
void testcase1(ll len){
	puts("debug");
	for (int i = 1; i <= len; i++){
		printf("%lld %lld\n", s2[i], s1[i]);
	}
	puts("end");
}
void testcase2(ll len){
	puts("testcase2");
	for (int i = 1; i <= len; i++){
		printf("f[%d][0] = %lld\n", i, f[0][i]);
		printf("f[%d][1] = %lld\n", i, f[1][i]);
	}
	puts("end");
}