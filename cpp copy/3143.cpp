#include <iostream>
#include <vector>
using namespace std;
struct edge{int u,v,w;};
vector<edge>v;
int id[5000][5000],n=2e5,tp,m=1e6,a[1000000];
int r(){
	return rand();
	//return rand()<<13|rand();
}
int main(){
	freopen("3143_out.txt","w",stdout);
	srand(time(0));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			id[i][j]=++tp,a[tp]=tp;
//	random_shuffle(a+1,a+tp+1);
	int SIZE=29989;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(i<n){
				v.push_back(edge{id[i][j],id[i+1][j],1});
				v.push_back(edge{id[i+1][j],id[i][j],1});
				if(j<m){
					if(1)v.push_back(edge{id[i][j],id[i+1][j+1],r()%SIZE+10});
					else v.push_back(edge{id[i+1][j+1],id[i][j],r()%SIZE+10});
				}
			}
			if(j<m){
				v.push_back(edge{id[i][j],id[i][j+1],r()%SIZE+10});
				v.push_back(edge{id[i][j+1],id[i][j],r()%SIZE+10});
			}
		}
	fprintf(stderr,"[%lu,%d,%d]",v.size(),n,m);
	random_shuffle(v.begin(),v.end());
//	printf("%d %d %d\n",tp,v.size(),2);
	printf("%d %lu\n",tp,v.size());
	for(int i=0;i<(int)v.size();++i)printf("%d %d %d\n",a[v[i].u],a[v[i].v],v[i].w);
//	for(int i=1;i<=10;++i)printf("%d ",a[id[1][10*i]]);
//	printf("%d %d",a[1],a[2]);
}
