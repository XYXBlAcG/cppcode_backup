#include <iostream> 
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define res register int 
const int maxn=1005;
int dis[maxn][maxn];
int N,cost[maxn];
int path[maxn][maxn];
 
void floyed()
{
	for(res k=1;k<=N;k++){
		for(res i=1;i<=N;i++){
			for(res j=1;j<=N;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]+cost[k]){
					dis[i][j]=dis[i][k]+dis[k][j]+cost[k];
					path[i][j]=path[i][k];
				}else if(dis[i][j]==dis[i][k]+dis[k][j]+cost[k]&&path[i][j]>path[i][k]){
					path[i][j]=path[i][k];
				}
			}
		}
	}
}
 
void init()
{
	memset(path,-1,sizeof(path));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
            int u, v;
			scanf("%d %d %d", &u, &v, &cost[u]);

			if(-1==dis[i][j])
				dis[i][j]=inf;
			else
				path[i][j]=j;
		}
	}
}
 
//void output(int i,int j)
//{
//	if(-1==path[i][j]) return;
//	output(i,path[i][j]);
//	printf("%d-->",path[i][j]);
//	if(i!=path[i][j]&&path[i][j]!=path[path[i][j]][j]) output(path[i][j],j);
//}
 
void output(int from,int to)
{
	int u=from,v=to;
	while(u!=v){
		printf("%d-->",u);
		u=path[u][v];
	}
	
}
 
int main()
{
	while(EOF!=scanf("%d",&N)&&N)
	{
		init();
		floyed();
		int from,to;
		while(EOF!=scanf("%d%d",&from,&to)&&-1!=from&&-1!=to){
			printf("From %d to %d :\n",from,to);
			printf("Path: ");
			output(from,to);
			printf("%d\n",to);
			printf("Total cost : %d\n\n",dis[from][to]);
		}
	}
	return 0;
}
