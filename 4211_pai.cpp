#include<cstdio>
#define int long long
const int N=100011,Q=100011;
int t,n,m,q,F[100011],Pk[100011];
bool vis[100011];
void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int tmp=x;
	x=y,y=tmp-a/b*y;
}
int quick_pow(int a,int x,int mod){
	//printf("##$$%d\n",mod);
	//fflush(stdout);
	int rt=1;
	while(x){//printf("##%d\n",mod);
	//fflush(stdout);
		if(x&1)rt=1ll*rt*a%mod;
		a=1ll*a*a%mod;
		x>>=1;
	}
	return rt;
}
int Getinv(int a,int mod){
	int x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
int f(int x,int p,int pk){
	if(!x)return 1;
	int ff=f(x/p,p,pk);
	int mul1=1,mul2=1;
	for(int i=1;i<=pk;i++){
		if(i%p)mul1=mul1*i%pk;
	}
	mul1=quick_pow(mul1,x/pk,pk);
	for(int i=(x/pk)*pk;i<=x;i++){
		if(i%p)mul2=mul2*(i%pk)%pk;
		//printf("mul2=%d\n",mul2);
	}
	//printf("x=%d %d %d\n",x,mul1,mul2);
	return ff*mul1%pk*mul2%pk;
}
int g(int x,int p){
	if(x<p)return 0;
	return x/p+g(x/p,p);
}
int Lucas(int p,int pk){
	//printf("%d %d\n",p,pk);
	int son=f(n,p,pk),mom1=Getinv(f(m,p,pk),pk),mom2=Getinv(f(n-m,p,pk),pk);
	//printf("%d %d %d\n",son,mom1,mom2);
	son=son*mom1%pk*mom2%pk;//printf("##pk=%d\n",pk);
	int pow=g(n,p)-g(m,p)-g(n-m,p);
	int ppow=quick_pow(p,pow,pk);
	//printf("##%d\n",pow);
	return ppow*son%pk;
}
int exLucas(){
	//printf("ppm=%d\n",ppm);
	int p=q,pm=0;
	for(int i=2;i*i<=q;i++){
		if(!(p%i)){
			int pow=1;
			while(!(p%i)){
				p/=i;
				pow*=i;
			}
			Pk[++pm]=pow;
			F[pm]=Lucas(i,pow);
		//	printf("%d %d\n",i,F[pm]);
		}
		//printf("%d\n",F[pm]);
	}
	if(p!=1){
		Pk[++pm]=p,F[pm]=Lucas(p,p);
		//printf("%d\n",F[pm]);
	}
	int ans=0;
	for(int i=1;i<=pm;i++){
		int m1=q/Pk[i],inv=Getinv(m1,Pk[i]);
		ans=(ans+F[i]*m1%q*inv%q)%q;
	}
	return ans;
}
signed main(){
	scanf("%lld",&t);
	while(t){
		scanf("%lld%lld%lld",&n,&m,&q);
		printf("%lld\n",exLucas());
		t--;
	}
	return 0;
}