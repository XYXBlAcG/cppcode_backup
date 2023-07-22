#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
char s[105];
double tmp, a[105][105];
double Abs(double x){return x > 0 ? x : -x;}
void Gauss()
{
	for(int i = 1, j, k;i <= n; ++ i)
	{
		for(k = i, j = i + 1;j <= n;++ j)
			if(Abs(a[j][i]) > Abs(a[k][i]))k = j;
		swap(a[k], a[i]);
		for(j = i + 1;j <= n; ++ j)
			for(tmp = a[j][i] / a[i][i],k = i;k <= n + 1;++ k)a[j][k] -= a[i][k] * tmp;
	}
	for(int i = n; i >= 1; -- i)
	{
		for(int j = i + 1; j <= n;++ j)a[i][n+1] -= a[i][j] * a[j][n + 1];
		a[i][n+1] /= a[i][i];
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i < n; ++ i)
	{
		a[i][i] = 1 - n;
		for(int j = 1; j <= n; ++ j)
		{
			scanf("%lf", &tmp);
			if(i != j)a[i][j] = tmp,a[i][i] += tmp;
		}
	}
	for(int i = 1; i <= n; ++ i)scanf("%lf", &tmp),a[n][i] = 1;
	a[n][n + 1] = 1;
	Gauss();
	while(m--)
	{
		scanf("%s", s+1);tmp = 0;
		for(int i = 1; i <= n; ++ i)
			if(s[i] == '1')tmp += a[i][n + 1];
		printf("%0.8f\n", tmp);
	}
	return 0;
}
