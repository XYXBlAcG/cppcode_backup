#include <cstdio>
#include <algorithm>
const int N = 2e5 + 5;
typedef long long ll;
ll t, n, s, pre[N];
struct Node{
	ll l, r;
}node[N];
bool cmp(Node a, Node b){
	if(a.l != b.l) return a.l < b.l;
	return a.r < b.r;
	// if(a.r != b.r) return a.r < b.r;
	// return a.l > b.l;
}
void clean(){
	for (int i = 1; i <= n; i++){
		node[i] = {0, 0};
	}
}
bool cal(ll u){
	ll res = 0, tim = 0;
    for (int i = n; i; i--){
        if(node[i].r >= u && tim < (n >> 1) + 1){
            res += std::max(node[i].l, u), tim++;
        }else res += node[i].l;
    }
    return res <= s && tim >= ((n >> 1) + 1);
}
ll solve(){
	std::sort(node + 1, node + 1 + n, cmp);
	// ll mmm = (n >> 1) + 1;
	// ll l = node[mmm].l, r = node[mmm].r, res = l;
    ll l = 0, r = 1e14;
	while(l < r){
		ll mid = (l + r + 1) >> 1;
//		printf("%lld %lld %lld\n", l, r, mid);
		if(cal(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
int main(){
	freopen("salary.in", "r", stdin);
	freopen("salary.out", "w", stdout);
	
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &s);
		for (int i = 1; i <= n; i++){
			scanf("%lld%lld", &node[i].l, &node[i].r);
			// pre[i] = pre[i - 1] + node[i].l;
		}
		printf("%lld\n", solve());
		clean();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
