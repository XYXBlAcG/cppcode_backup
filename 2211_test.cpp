#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int n,v;
int m[N],vx[N];
int f[N][N];

int main(){
	
	cin >> n >> v;
	for(int i = 1; i <= n; i++ ){
		cin >> vx[i] >> m[i];
	}
	for(int i = 1; i <= n; i++ ){//前i个 
		for(int j = 0; j <= v; j++ ){//此时的体积 
			f[i][j] = f[i - 1][j];//不选第i个物品
			if(j >= vx[i])//此时存在一个体积不超过 j-vx[i] 的zdzl，如果在加上v[i]则才是，体积不超过j 
				f[i][j] = max(f[i][j], f[i - 1][j - vx[i]] + m[i]);//为啥是j-vx[i]，是因为当选择了第i个商品，
				//此时的空间就变为：选择前i件，体积不超过j的zdzl 
		}
	}
	cout << f[n][v];
	return 0;
} 