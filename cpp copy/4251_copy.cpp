#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define maxn 1000000
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}
ll fact[maxn+5],invfact[maxn+5];
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
} 
 
int n,k;
ll f[maxn+5],g[maxn+5];
int main(){
	scanf("%d %d",&n,&k);
	ini(n);
	ll pw=2;//2^(2^(n-i))
	for(int i=n;i>=0;i--){
		f[i]=C(n,i)*(pw-1)%mod;
		pw=pw*pw%mod;
	}
	ll ans=0;
	for(int i=k;i<=n;i++){
		if((i-k)%2==1) ans=ans-C(i,k)*f[i]%mod;
		else ans=ans+C(i,k)*f[i]%mod;
		ans=(ans+mod)%mod;
	}
	printf("%lld\n",ans);
}
 