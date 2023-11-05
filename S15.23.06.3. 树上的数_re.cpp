#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, q, dfn[N], pdfn, fa[N][20], dis[N], sz[N], dep[N], poi[N];
struct Node{
    int v, w;
};
std::vector<Node> st[N], vt[N];
std::vector<int> qry;
bool cmpw(Node a, Node b){
	return a.w < b.w;
}
bool cmp(int a, int b){
    return dfn[a] < dfn[b];
}
void predfs(int u, int fath){
	dfn[u] = ++pdfn;
	dep[u] = dep[fath] + 1;
	fa[u][0] = fath;
	for (int i = 1; i <= 19; i++){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	std::sort(st[u].begin(), st[u].end(), cmpw);
	for (auto v : st[u]){
		if(v.v == fath) continue;
		dis[v.v] = dis[u] + v.w;
		predfs(v.v, u);
		sz[u] += sz[v.v];
	}
	sz[u]++;
}
int lca(int a, int b){
	if(a == b) return a;
	if(dep[a] < dep[b]) std::swap(a, b);
	for (int i = 19; ~i; i--){
		if(dep[fa[a][i]] >= dep[b]) a = fa[a][i]; 
	}
	if(a == b) return a;
	for (int i = 19; ~i; i--){
		if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
	}
	return fa[a][0];
}
int getdis(int a, int b, int lc){
    return dis[a] + dis[b] - dis[lc] * 2;
}
void addve(int u, int v, int w){
    vt[u].push_back({v, w});
    vt[v].push_back({u, w});
}
void dfs(int u, int fath){
    for (auto v : vt[u]){
        if(v.v == fath) continue;
        dfs(v.v, u);
    }
}
int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1, u, v, w; i < n; i++){
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
    predfs(1, 0);
    for (int i = 1, m; i <= q; i++){
        scanf("%d", &m);
        qry.clear();
        for (int j = 1; j <= m; j++)
            scanf("%d", poi + j);
        qry.push_back(poi[1]);
        for (int j = 2; j <= m; j++){
            qry.push_back(poi[j]);
            qry.push_back(lca(poi[j], poi[j - 1]));
        }
        std::sort(qry.begin(), qry.end(), cmp);
        qry.erase(std::unique(qry.begin(), qry.end()), qry.end());
        for (int i = 1; i < (int)qry.size(); i++){
            int lc = lca(qry[i - 1], qry[i]);
            addve(qry[i - 1], qry[i], getdis(qry[i - 1], qry[i], lc));
        }
        
    }
    return 0;
}