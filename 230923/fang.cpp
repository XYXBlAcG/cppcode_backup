#include <cstdio>
#define int long long
const int N = 20;
int l, r, k;
struct Num{
	int data[20], len, pre[20], suf[20];
	Num(int x){
		int tm = x, tl = 0;
		while(tm > 0) tm /= k, tl++;
		while(x > 0) data[tl - (++len) + 1] = x % k, x /= k;
		for (int i = 1; i <= len; i++)
			pre[i] = pre[i - 1] + data[i];
		for (int i = len; i; i--)
			suf[i] = suf[i + 1] + data[i];
	}
	void output(){
		for (int i = 1; i <= len; i++)
			printf("%lld", data[i]);
		putchar('\n');
	}
};
int get(int x){
	Num tmp(x);
	for (int i = 1; i < tmp.len; i++)
		if(tmp.pre[i] - tmp.suf[i + 1] >= 0) return i;
	return tmp.len;
}
void solve(int l, int r){
	Num L(l), R(r);
	
}
signed main(){
	scanf("%lld%lld%lld", &l, &r, &k);
	
	return 0;
}
