#include<stdio.h>
#include<stdlib.h>
#define int long long
#define SIZE 128
const int N = 5e5 + 5, M = 1005;
int h[N],a[N],block[N],L[M],R[M];
void jh(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void kp(int low,int high)
{
	int i=low,j=high,mid=a[(i+j)/2];
	while(i<j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			jh(&a[i],&a[j]);
			i++;
			j--;
		}
	}
	if(j>low) kp(low,j);
	if(i<high) kp(i,high);
}
int find_down(int num,int left,int right)
{
	int mid;
	if(a[left]>=num) return left-1;
	while(left<right)
	{
		mid=(left+right+1)/2;
		if(a[mid]>=num) right=mid-1;
		else left=mid;
	}
	return left;
}
int find_up(int num,int left,int right)
{
	int mid;
	if(a[right]<=num) return right+1;
	while(left<right)
	{
		mid=(left+right)/2;
		if(a[mid]<=num) left=mid+1;
		else right=mid;
	}
	return left;
}
int cx_down(int num,int x,int y)
{
	int i,ans=0;
	if(block[x]+1>=block[y])
	{
		for(i=x;i<=y;i++)
			if(h[i]<num) ans++;
		return ans;
	}
	for(i=x;i<=R[block[x]];i++)
		if(h[i]<num) ans++;
	for(i=L[block[y]];i<=y;i++)
		if(h[i]<num) ans++;
	for(i=block[x]+1;i<block[y];i++){
		ans+=find_down(num,L[i],R[i])-L[i]+1;
        // printf("test = %lld\n", find_down(num,L[i],R[i])-L[i]+1);
    }
	return ans;
}
int cx_up(int num,int x,int y)
{
	int i,ans=0;
	if(block[x]+1>=block[y])
	{
		for(i=x;i<=y;i++)
			if(h[i]>num) ans++;
		return ans;
	}
	for(i=x;i<=R[block[x]];i++)
		if(h[i]>num) ans++;
	for(i=L[block[y]];i<=y;i++)
		if(h[i]>num) ans++;
	for(i=block[x]+1;i<block[y];i++){
		ans+=R[i]-find_up(num,L[i],R[i])+1;
        // printf("test = %lld\n", R[i]-find_up(num,L[i],R[i])+1);
    }
	return ans;
}
signed main()
{
	int n,m,i,x,y,cnt,ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		a[i]=h[i];
		block[i]=(i-1)/SIZE+1;
	}
	cnt=(n-1)/SIZE+1;
	for(i=1;i<=cnt;i++)
	{
		L[i]=(i-1)*SIZE+1;
		R[i]=i*SIZE;
	}
	R[cnt]=n;
	for(i=1;i<=cnt;i++)
		kp(L[i],R[i]);
	for(i=1;i<=n;i++)
		ans+=cx_up(h[i],1,i-1);
	printf("%lld\n",ans);
	scanf("%lld",&m);
	for(;m>0;m--)
	{
		scanf("%lld%lld",&x,&y);
		if(x>y) jh(&x,&y);
		if(h[x]<h[y]) ans++;
		if(h[x]>h[y]) ans--;
		if(x+1<y)
		{
			ans=ans+cx_down(h[y],x+1,y-1)-cx_up(h[y],x+1,y-1);
			ans=ans-cx_down(h[x],x+1,y-1)+cx_up(h[x],x+1,y-1);
		}
		jh(&h[x],&h[y]);
		for(i=L[block[x]];i<=R[block[x]];i++)
			a[i]=h[i];
		kp(L[block[x]],R[block[x]]);
		for(i=L[block[y]];i<=R[block[y]];i++)
			a[i]=h[i];
		kp(L[block[y]],R[block[y]]);
		printf("%lld\n",ans);
	}
	return 0;
}