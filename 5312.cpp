#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

typedef unsigned long long u64;

const int MaxN = 100000;

std::string str;

inline int hash_handle(const char *s, const int &n, const int &l, const int &base){
	const int Mod = 1000000007;

	u64 hash_pow_l = 1;
	for (int i = 1; i <= l; i++)
		hash_pow_l = (hash_pow_l * base) % Mod;

	int li_n = 0;
	static int li[MaxN];

	u64 val = 0;
	for (int i = 0; i < l; i++)
		val = (val * base + s[i] - 'a') % Mod;
	li[li_n++] = val;
	for (int i = l; i < n; i++){
		val = (val * base + s[i] - 'a') % Mod;
		val = (val + Mod - ((s[i - l] - 'a') * hash_pow_l) % Mod) % Mod;
		li[li_n++] = val;
	}

	std::sort(li, li + li_n);
	li_n = std::unique(li, li + li_n) - li;
	return li_n;
}

int main(){
    int nn, ll;
    scanf("%d%d", &nn, &ll);
    std::cin >> str;
    printf("%d\n", hash_handle(str.c_str(), nn, ll, 114514));
	return 0;
}