#include<iostream>
#include<cstdio>
#include<cmath>
#define re register
#define il inline
#define ll long long
using namespace std;

il ll read(){
    ll s=0,f=0;char c=getchar();
    while(c<'0'||c>'9') f=(c=='-'),c=getchar();
    while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^'0'),c=getchar();
    return f?-s:s;
}

const int N=405,mod=1e9+7;
int n;
ll a[N][N<<1];
il ll qpow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans%mod;
}

il void Gauss_j(){	
	for(re int i=1,r;i<=n;++i){
		r=i;
		for(re int j=i+1;j<=n;++j)
			if(a[j][i]>a[r][i]) r=j;
		if(r!=i) swap(a[i],a[r]);
		if(!a[i][i]){puts("No Solution");return;}
		
		int kk=qpow(a[i][i],mod-2);	//求逆元 
		for(re int k=1;k<=n;++k){
			if(k==i) continue;
			int p=a[k][i]*kk%mod;
			for(re int j=i;j<=(n<<1);++j) 
				a[k][j]=((a[k][j]-p*a[i][j])%mod+mod)%mod;
		} 
		
		for(re int j=1;j<=(n<<1);++j) a[i][j]=(a[i][j]*kk%mod);
		//更新当前行 如果放在最后要再求一次逆元,不如直接放在这里  
	}	
	
	for(re int i=1;i<=n;++i){
		for(re int j=n+1;j<(n<<1);++j) printf("%lld ",a[i][j]);
		printf("%lld\n",a[i][n<<1]);
	}
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			a[i][j]=read(),a[i][i+n]=1;
	
	Gauss_j();
    return 0;
}

