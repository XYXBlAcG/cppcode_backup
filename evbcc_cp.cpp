#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5+3;

int n,m,tot=1,ans1,ans2;
vector<int> t[N],tmp;
bool vis[N];

struct Union{
	int f[N],fb[N],dep[N],siz[N];
	void init(){
		for (int i=1;i<=n;++i)
			f[i] = i, fb[i] = i, dep[i] = 1, siz[i] = 1;
	} 
	int findf(int x){
		return f[x]==x ? x : findf(f[x]);
	}
	int findfb(int x){
		return fb[x]==x ? x : fb[x] = findfb(fb[x]);
	} 
	bool con(int x,int y){
		return findf(x)==findf(y);
	}
	void dfs(int u,int fa){
		dep[u] = dep[fa]+1;
		f[u] = fa;
		for (int v:t[u]){
			if (v==fa) continue;
			dfs(v,u);
		}
		if (dep[u] < dep[findfb(u)]) {
	        fb[findfb(u)] = u;
	        fb[u] = u;  //尽量把深度小的点作为边双并查集的根
	        //也可以保证在一个边双并查集的根跳一次父边一定可以跳到另外一个边双
    	}
	}
	void cc_merge(int x,int y){
		int fx = findf(x), fy = findf(y);
		if (siz[fx]<siz[fy]) swap(x,y), swap(fx,fy);
		siz[fx] += siz[fy];
		dfs(y,x);
		t[x].push_back(y); 
		t[y].push_back(x);
	}
	void bcc_merge(int x,int y){
		x = findfb(x), y = findfb(y);
		while (x!=y){
			if (dep[x]<dep[y]) swap(x,y);
			fb[x] = f[x];
			ans2--;
			x = findfb(x);
		}
	}
}cc;
void work(){
	cc.init();
	for (int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if (cc.con(u,v)){
			cc.bcc_merge(u,v);
		} else {
			cc.cc_merge(u,v);
			ans1--;
		}
		printf("%d %d\n",ans1,ans2); 
	} 
}
void init(){
	scanf("%d%d",&n,&m);
	ans1 = ans2 = n;
}

int main(){
	int T = 1;
	//scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	return 0;
}
