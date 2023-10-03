#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 3005;
int n; ll a[N], tval[N], tpos[N], ans, rec[N][N];
bool vis[N][N];
struct Node{
	ll val, pos;
}tmp[N];
bool cmp(Node a, Node b){
	if(a.val == b.val) return a.pos < b.pos;
	return a.val < b.val;
}
ll cal(int p, int q){
	if(q > n || !q || !p || p > n) return 0;
	if(vis[p][q]) return rec[p][q]; vis[p][q] = 1;
	ll target = a[p] + a[q];
	int left = std::lower_bound(tval + 1, tval + n + 1, target) - tval - 1;
	int right = std::upper_bound(tval + 1, tval + n + 1, target) - tval - 1;
	int res = std::upper_bound(tpos + left + 1, tpos + right + 1, q) - tpos;
	int tmp2 = res;
	res = tpos[res];
	if(res > n || !res || res <= q || tval[tmp2] != target) return rec[p][q] = 0;
	return rec[p][q] = cal(q, res) + 1;
}
int main(){
	// freopen("seq.in", "r", stdin);
	// freopen("seq.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		tmp[i] = {a[i], i};
	}
	if(n == 1){
		puts("1");
		return 0;
	}
	std::sort(tmp + 1, tmp + 1 + n, cmp);
	for (int i = 1; i <= n; i++){
		tval[i] = tmp[i].val;
		tpos[i] = tmp[i].pos;
//		printf("%d t = %lld %lld\n", i, tval[i], tpos[i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			ans = std::max(ans, cal(i, j) + 2);
//			printf("i, j, ans = %d %d %lld\n", i, j, cal(i, j) + 2);
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
