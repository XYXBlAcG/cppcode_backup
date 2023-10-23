#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define int long long
const int N = 3e5 + 5;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
int n, m, vis[N], mx;
std::queue<Node> que;
int cal(int x){
    que = std::queue<Node>();
    que.push({1, 0});
    while(que.size()){
        auto u = que.front(); que.pop();
        if(u.v == n) return 1;
        for (auto v : st[u.v]){
            if((u.w + 1) * v.w <= x) que.push({v.v, u.w + 1});
        }
    }
    return 0;
}
int bin(){
	int l = 1, r = m * mx, mid; 
	while(l < r){
        // memset(vis, 0, sizeof(vis));
		mid = (l + r) >> 1; 
        if(!cal(mid)) l = mid + 1;
		else r = mid;
	}
	return l; 
}
struct FileIO{
    FileIO(){
        freopen("path.in", "r", stdin);
        freopen("path.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &w), mx = std::max(mx, w);
        st[u].push_back({v, w});
    }
    printf("%lld\n", bin());
    return 0;
}