#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 2e6 + 5;
int n, ans, mmin, mmax, sman, bsize;
std::vector<int> st[N];
void dfs(int x, int fath, int fa){
	if(!st[x].size()) return;
	for (auto v : st[x]){
		if(v == fa) continue;
		mmax = std::max(mmax, v);
		if(v > fath){
			if(v >= mmax){
				ans++;
			}
		}else return;
		dfs(v, fath, x);
	}
}
int main(){
	freopen("charity.in", "r", stdin);
	freopen("charity.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int p;
		scanf("%d", &p);
		st[p].push_back(i);
		st[i].push_back(p); 
	}
	for (int i = 1; i <= n; i++){
		if(st[i].size() >= sman){
			sman = st[i].size();
			bsize = i;
		}
//		sman = std::max(sman, st[i].size());
	}
	if(n <= 1000){
		for (int i = 1; i <= n; i++){
			mmax = i;
			dfs(i, i, 0);
		}
		printf("%d\n", ans);
	}else if(sman == n){
		if(bsize == n){
			printf("%d\n", n - 1);
		}else{
			printf("%d\n", (n - bsize) * (n - bsize + 1) >> 1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
