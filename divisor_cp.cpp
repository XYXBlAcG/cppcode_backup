#include<cstdio>
#include<algorithm>
#include<map>
using std::sort;
using std::unique;
using std::map;
typedef long long ll;
int avnum[10][20],T,k,trnum[1000011],ptr,pnode[20],len[15]={0,1,1,2,3,6,6,15};
ll a,b,ans;
int gcd(int a,int b){
 return b?gcd(b,a%b):a;
}
map<ll,int>av[10];
int main(){
 freopen("divisor.in","r",stdin);
 freopen("divisor.out","w",stdout);
 scanf("%d",&T);
 avnum[1][1]=1;
 avnum[2][1]=2;
 avnum[3][1]=3,avnum[3][2]=4;
 avnum[4][1]=4,avnum[4][2]=6,avnum[4][3]=10;
 avnum[5][1]=5,avnum[5][2]=6,avnum[5][3]=8,avnum[5][4]=9,avnum[5][5]=14,avnum[5][6]=21;
 avnum[6][1]=6,avnum[6][2]=8,avnum[6][3]=10,avnum[6][4]=14,avnum[6][5]=44,avnum[6][6]=52;
 avnum[7][1]=7,avnum[7][2]=8,avnum[7][3]=9,avnum[7][4]=10,avnum[7][5]=12,avnum[7][6]=15;
 avnum[7][7]=22,avnum[7][8]=33,avnum[7][9]=39,avnum[7][10]=52,avnum[7][11]=55,avnum[7][12]=68;
 avnum[7][13]=102,avnum[7][14]=114,avnum[7][15]=138;
 for(int k=1;k<=7;k++){
  int n=len[k];
  for(int S=1;S<(1<<n);S++){
   ll lca=1,s=-1;
   for(int i=1;i<=n;i++) 
    if(S&(1<<(i-1)))
     lca=lca/gcd(lca,avnum[k][i])*avnum[k][i],s*=-1;
   av[k][lca]+=s;
  }
 }
// T=5000;
 while(T--){
  scanf("%lld%lld%d",&a,&b,&k);
  for(auto v:av[k]){
   ans+=(b/v.first-(a-1)/v.first)*v.second;
  }
  printf("%lld\n",ans);
  ans=0;
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}