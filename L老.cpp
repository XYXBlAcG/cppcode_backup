#include<bits/stdc++.h> 
#define maxn 310
#define eps (1e-6)
using namespace std;
int n,m,p,q,x,y;
int f[310][310];
int in[310];
double a[maxn][maxn];
void gauss_jordan(){
	for(int i=1;i<=n;++i){
		int r=i;
		for(int j=i+1;j<=n;++j)
			if(fabs(a[r][i])<fabs(a[j][i]))
				r=j;
		if(r!=i)
			for(int j=1;j<=n+1;++j)
			swap(a[i][j],a[r][j]);
			for(int j=1;j<=n;++j)if(j!=i){
		 		double tmp=a[j][i]/a[i][i];
		 		for(int k=i+1;k<=n+1;++k)
	   		   		a[j][k]-=a[i][k]*tmp;
			}
   	}
	for(int i=1;i<=n;++i)
		a[i][n+1]/=a[i][i];
}
int main(){
	//freopen("dotp.in","r",stdin);
	//freopen("dotp.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
        if(x == y) in[y]--;
		f[x][y]=f[y][x]=true;
		in[x]++;in[y]++;
	}
	a[1][n+1]=1.0*p/q;
	for(int i=1;i<=n;i++){
		a[i][i]=1;
		for(int j=1;j<=n;j++)
			if(f[i][j])
				a[i][j]=-(1-(double)p/q)/in[j];
	}
	gauss_jordan();
	for(int i=1;i<=n;i++)
		printf("%.6lf\n",a[i][n+1]);
	return 0;
}
