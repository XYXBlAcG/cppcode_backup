// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <stack>
// #define ll long long
// using std::min;
// using std::max;
// const int N=2e5+10, inf=0x3f3f3f3f;
// #define ls ch[now][0]
// #define rs ch[now][1]
// int L[N*40],R[N*40],ch[N*40][2],tot;
// int n,a[N],root;
// /*Insert函数用来将一个数组元素插入到字典树中。
// 它接受三个参数：now表示当前节点的编号，
// x表示要插入的元素在数组中的下标，dep表示当前处理的二进制位数。
// 函数首先更新当前节点所包含的元素下标范围，
// 然后判断是否已经处理完所有二进制位。
// 如果没有，则根据当前处理位上的0或1选择相应的子节点，
// 并递归地调用Insert函数。*/
// void Insert(int &now,int x,int dep){
//     if(!now) now=++tot;
//     L[now]=min(L[now],x),R[now]=max(R[now],x);
//     if(dep<0) return;
//     int bit=a[x]>>dep&1;
//     Insert(ch[now][bit],x,dep-1);
// }
// /*query函数用来在字典树中查询一个给定值与哪个元素的异或值最小。
// 它接受三个参数：now表示当前节点的编号，val表示要查询的值，
// dep表示当前处理的二进制位数。函数首先判断是否已经处理完所有二进制位。
// 如果没有，则根据当前处理位上的0或1选择相应的子节点，
// 并递归地调用query函数。如果当前处理位上与val相同的子节点存在，
// 则优先选择它；否则选择另一个子节点，并在返回时加上当前处理位上产生的差异。
// */
// int query(int now,int val,int dep){
//     if(dep<0) return 0;
//     int bit=val>>dep&1;
//     return (ch[now][bit]) ? query(ch[now][bit],val,dep-1) : query(ch[now][bit^1],val,dep-1)+(1<<dep);
// }
// ll dfs(int now,int dep){
//     if(dep<0) return 0;
//     if(R[ls]&&R[rs]){
//         int mi=inf;
//         for(int i=L[ls];i<=R[ls];i++) mi=min(mi,query(rs,a[i],dep-1));
//         return dfs(ls,dep-1)+dfs(rs,dep-1)+mi+(1<<dep);
//     }
//     if(R[ls]) return dfs(ls,dep-1);
//     if(R[rs]) return dfs(rs,dep-1);
//     return 0;
// }


// int main(){
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++) scanf("%d",a+i);
//     std::sort(a+1,a+1+n), memset(L,0x3f,sizeof(L));
//     for(int i=1;i<=n;i++) Insert(root,i,30);
//     printf("%lld\n",dfs(root,30));
//     return 0;
// }


#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200010,INF=0x3f3f3f3f;
int n,tot=1;
long long cost, ans;
int ch[N<<5][2],si[N<<5],val[N<<5],num[N<<5];
inline int read()//养成函数加inline，大数据写快读的好习惯（不
{
	int f=1,ret=0;char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return f*ret;
}
inline void insert(int a)
{
	int u=0;
	for(int i=1<<30;i;i>>=1)
	{
		int c=(a&i)?1:0;
		if(!ch[u][c])
		{
			memset(ch[tot],0,sizeof(ch[tot]));
			num[tot]=val[tot]=0;
			ch[u][c]=tot++;
		}
		u=ch[u][c];
		num[u]++;
	}
	val[u]=a;
}//trie树读入
inline int gets(int x)
{
	if(!ch[x][0]&&!ch[x][1])
		return si[x]=1;
	if(ch[x][0]) si[x]+=gets(ch[x][0]);
	if(ch[x][1]) si[x]+=gets(ch[x][1]);
	return si[x];
}//初始化size
inline int query(int x,int p)
{
	int u=0;
	for(int i=1<<30;i;i>>=1)
	{
		int c=(x&i)?1:0;
		if(!ch[u][c])
			c=1-c;
		if(p==u) c=1-c;
		u=ch[u][c];
	}
	return u;
}
inline void calc(int x,int u)
{
	
	if(!ch[x][0]&&!ch[x][1])
	{
		int c=query(val[x],u);
		cost=min(cost,(long long)val[c]^val[x]);
	}
    if(ch[x][0]) calc(ch[x][0],u);
	if(ch[x][1]) calc(ch[x][1],u);
}
inline void dfs(int x)
{
	
	if(ch[x][0]&&ch[x][1])
	{
		cost=INF;
		int lson=ch[x][0],rson=ch[x][1];
		if(si[lson]<si[rson]) calc(lson,x);
		else calc(rson,x);//根据深度大小判断
		ans+=cost;
	}if(ch[x][0]) dfs(ch[x][0]);
	if(ch[x][1]) dfs(ch[x][1]);
}//dfs部分
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a;
		a=read();
		insert(a);
	}
	gets(0);
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
