#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
int val[maxn];          //点权
int cost[maxn][maxn];   //路径的花费
int lowcost[maxn][maxn];//路径花费的copy
int path[maxn][maxn];   //最短路径  path[i][j] 表示从i到j要经过path[i][j]这个点
void floyd(int n){      
    memcpy(lowcost,cost,sizeof(cost));  //copy一下
    for(int i = 0;i <= n;i++){          //初始化path
        for(int j = 0;j <= n;j++){
            path[i][j] = j;
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                int temp = lowcost[i][k] + lowcost[k][j] + val[k];  //注意是有点权的    要加上val的值
                if(lowcost[i][j] > temp){                   //松弛
                    lowcost[i][j] = temp;           
                    path[i][j] = k;         //记录路径
                }else if(lowcost[i][j] == temp && path[i][j] > path[i][k]){ //如果经不经过k点花费都相等 就判断字典序(最小的优先)
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}
void disp(int u,int v){
    if(path[u][v] == v)  return;
    disp(u,path[u][v]);
    cout << "-->" << path[u][v];
    disp(path[u][v],v);
}
int n,m;
int u,v,w;
int main()
{
    cin >> n >> m;      //点数和边数
    memset(cost,inf,sizeof(cost));  //初始化图
    for(int i = 1;i <= n;i++){  //从1到n的点权
        cin >> val[i];
    }
    while(m--){ //输入边建图
        cin >> u >> v >> w;
        cost[u][v] = w;
    }   
    floyd(n);
    cin >> u >> v;  //要输出从u点到v点的路径
    cout << u;
    disp(u,v);
    cout << "-->" << v << endl;
    return 0;
}