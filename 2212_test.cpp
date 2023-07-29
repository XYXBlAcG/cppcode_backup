#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[1001];
int f[1001]; //以第i项为起点的最长不下降子序列的长度
int mx = -1; 
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=1; 
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<=a[j])
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,f[i]);
	}
	printf("%d",mx);
	return 0;
}