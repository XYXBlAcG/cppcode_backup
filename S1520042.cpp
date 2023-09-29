#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using std::max;
#define de(x) std::cout << #x << " = " << x << std::endl
typedef long long ll;
const int N = 1e7 + 5;
ll n, a[N], b[N], c[N], M = 1e6 + 3, P = 103, jc[7], ans;
ll M2 = 9223372036854775807;
struct Node{
	ll a, b, c;
}dr[N];
struct Hash{
	int h0; ll h1;
};
std::vector<Hash> st[N];
void insert(int h0, ll h1){
	st[h0].push_back({h0, h1});
}
ll query(ll h0, ll h1){
	for (auto v : st[h0]){
		if(v.h1 == h1){
			return 1;
		}
	}
	return 0;
}
void pre(){
	jc[0] = 1;
	for (int i = 1; i <= 3; i++){
		jc[i] = jc[i - 1] * P % M2;
//		de(jc[i]);
	}
}
ll hash(Node az, int op){
	ll MOD = M;
	if(op == 1) MOD = M2;
	ll res = 0;
	res += az.a * jc[1] % MOD;
	res += az.b * jc[2] % MOD;
	res += az.c * jc[3] % MOD;
//	de(res);
	return res;
}
void solve(Node drink){
	int hh0 = hash(drink, 0), hh1 = hash(drink, 1);
	if(!query(hh0, hh1)){
		ans++;
		insert(hh0, hh1);
	}
}
int main(){
	// freopen("drinks.in", "r", stdin);
	// freopen("drinks.out", "w", stdout);
	pre();
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld%lld%lld", &dr[i].a, &dr[i].b, &dr[i].c);
		a[i] = dr[i].a, b[i] = dr[i].b, c[i] = dr[i].c;
		insert(hash(dr[i], 0), hash(dr[i], 1));
	}
	ans = n;
	Node drink = {0, 0, 0};
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			drink = {max(a[i], a[j]), max(b[i], b[j]), max(c[i], c[j])};
			solve(drink);
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
