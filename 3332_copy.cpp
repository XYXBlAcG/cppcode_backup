#include <iostream>
#include <string.h>
#define inf 0x3f3f3f3f
#define maxn 105
using namespace std;
int N,K,A,B,C;
//dp二维数组代表答案更新数组，grap代表所输入的二维矩阵 
int dp[maxn][maxn][2],grap[maxn][maxn];
 
int main()
{
	cin>>N>>K>>A>>B>>C;
	
	for(int i=1;i<=N;i++)
	  for(int j=1;j<=N;j++)cin>>grap[i][j];
	
	//方向数组其中：dir[j][3]：j=0->3:分别代表左，上，右，下
	//dir[j][0]为x坐标的增加情况，dir[j][1]为y坐标的增加情况
	//dir[j][2]为是否需要增加费用 ，即是否进行了坐标减小的走法 
	int dir[4][3]={{0,-1,0},{-1,0,0},{0,1,B},{1,0,B}};
 
	memset(dp,inf,sizeof(dp));//dp数组初始化为极大值 
    dp[1][1][0]=0;dp[1][1][1]=K;//初始化状态在（1,1）处花费应为0，还能走的步数为K 
    
    bool ok=true;//ok为true是代表还能进行更新 
    while(ok)
    {
    	ok=false;
    	
    	for(int i=1;i<=N;i++)
    	{
    		for(int j=1;j<=N;j++)
    		{
    			if(i+j==2)continue;//当为起点时略过 
    			
    			int now0=dp[i][j][0];//当前坐标的花费 
    			int now1=dp[i][j][1];//当前坐标还能行走的步数 
    			
    			for(int k=0;k<4;k++)//考虑与当前坐标相邻的四个方向的状态，称做QD 
    			{
    				int dx=i+dir[k][0];//QD的横坐标计算 
    				int dy=j+dir[k][1];//QD的纵坐标计算 
    				int db=dir[k][2];//从（dx,dy)到（i，j）是否需要额外增加费用,即从QD到现在是否需要额外费用 
    				
    				if(dx<1||dx>N||dy<1||dy>N)continue;//当在地图外时忽略该种状态 
    				
    				int newn0=dp[dx][dy][0]+db;//利用QD更新后的dp[i][j]的费用 
    				int newn1=dp[dx][dy][1]-1;//利用QD更新后的dp[i][j]还能走的步数 
    				if(grap[i][j])//当（i,j）为一个油库时，需要进行如下处理 
    				{			
    					newn0+=A;
    					newn1=K;
					}
					//当从QD到(i,j)后能走的步数为0时，我们需要在(i,j)处增设一个油库
					//但(i,j)不能是终点(N,N),因为终点不能增设油库 
					if(newn1==0&&(i+j!=2*N))
					{
						newn0+=(A+C);
						newn1=K;
					}
					//当更新后的状态优于更新前的状态执行本次更新 
					if(newn0<now0) 
					{
						dp[i][j][0]=newn0;
						dp[i][j][1]=newn1;
						ok=true;
					}	
				}	
			}
		}
	}
	
	
	cout<<dp[N][N][0];
}
/*
//测试样例 
9 3 2 3 6
0 0 0 0 1 0 0 0 0
0 0 0 1 0 1 1 0 0
1 0 1 0 0 0 0 1 0
0 0 0 0 0 1 0 0 1
1 0 0 1 0 0 1 0 0
0 1 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0 1
1 0 0 1 0 0 0 1 0
0 1 0 0 0 0 0 0 0
3 3 3 3 3 
0 0 0
0 1 0
0 0 0
*/ 