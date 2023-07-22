#include <cstdio>
#include <cmath>
#define INF 0x3f3f3f3f
namespace maze_io{

#ifdef WIN32

#define LLD "%I64d"

#else

#define LLD "%lld"

#endif

typedef long long lld;
const int BUFF_MAGIC = (1 << 30) - 1;
int n, m, k, t;
int ans_buff = 0;
	
void get_args(int* n, int* m, int* k, int* t){
	scanf("%d%d%d%d", n, m, k, t);
	maze_io::n = *n;
	maze_io::m = *m;
	maze_io::k = *k;
	maze_io::t = *t;
}

void get_line(int* p, int* u, int* v, long long* w){
	int ku, kv;
	scanf("%d%d%d" LLD "%d%d", p, u, v, w, &ku, &kv);
	*u = (*u + (ku & ans_buff) - 1) % n + 1;
	*v = (*v + (kv & ans_buff) - 1) % n + 1;
}

void put_ans(int ans){
	printf("%d\n", ans);
	ans_buff = ((ans_buff << 1) | ans) & BUFF_MAGIC;
}

#ifdef LLD

#undef LLD

#endif

}
#define N 100005
int fa[N],n,Q,k,t;
typedef long long ll;
ll ans[N],dis[N];
int find(int u)
{
	if(fa[u]==u) return u;
	int tmp=fa[u];
	fa[u]=find(fa[u]);
	dis[u]+=dis[tmp];
	return fa[u];
}
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
signed main()
{
	maze_io::get_args(&n,&Q,&k,&t);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int _=1;_<=Q;_++)
	{
		int opt,u,v; ll w;
		maze_io::get_line(&opt,&u,&v,&w);
		if(!opt)
		{
			int U=find(u),V=find(v);
			if(U==V)
			{
				ll R=dis[u]-dis[v]-w;
				ans[U]=gcd(ans[U],abs(R));
			}
			else
			{
				fa[U]=V;
				dis[U]=dis[v]+w-dis[u];
				ans[V]=gcd(ans[U],ans[V]);
			}
		}
		else
		{
			int U=find(u),V=find(v);
			if(U!=V) {printf("!"); maze_io::put_ans(0);}
			else
			{
				ll R=abs(w-dis[u]+dis[v]);
				if(ans[V]==0) maze_io::put_ans(R==0);
				else maze_io::put_ans(R%ans[V]==0);
			}
		}
	}
	return 0;
}