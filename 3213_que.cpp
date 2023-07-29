#include <cstdio>
// #include <cmath>

const int N = 1e6 + 50;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}


template<typename T>
inline T read()
{
	T res = 0, neg = 1;
	char ch;
	do
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

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
	*n = read<int>(), *m = read<int>(), *k = read<int>(), *t = read<int>();
	maze_io::n = *n;
	maze_io::m = *m;
	maze_io::k = *k;
	maze_io::t = *t;
}

void get_line(int* p, int* u, int* v, long long* w){
	int x, y;
	*p = read<int>(), *u = read<int>(), *v = read<int>(), *w = read<long long>(), x = read<int>(), y = read<int>();
	*u = (*u + (x & ans_buff) - 1) % n + 1;
	*v = (*v + (y & ans_buff) - 1) % n + 1;
}

void put_ans(int ans){
	printf("%d\n", ans);
	ans_buff = ((ans_buff << 1) | ans) & BUFF_MAGIC;
}

#ifdef LLD

#undef LLD

#endif

}

typedef long long ll;
int f[N];
ll dis[N], val[N];
inline int find(int x)
{
	if (x == f[x]) return x;
	int y = find(f[x]);
	dis[x] += dis[f[x]];
	return f[x] = y;
}

inline ll abs(ll x) { return x >= 0 ? x : -x; }

inline ll gcd(ll x, ll y)
{
	return y ? gcd(y, x % y) : x;
}

int main()
{
	int n, m, k, t, p, u, v, ans;
	long long w;
	maze_io::get_args(&n, &m, &k, &t);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		maze_io::get_line(&p, &u, &v, &w);
		int fu = find(u), fv = find(v);
		if (p == 0)
		{
			if (fu != fv)
			{
				f[fu] = fv;
				dis[fu] = w + dis[v] - dis[u];
				val[fv] = gcd(val[fu], val[fv]);
			}
			else
			{
				val[fu] = gcd(val[fu], abs(w + dis[v] - dis[u]));
			}
		}
		else
		{
			ans = 0;
			if (fu != fv) ans = 0;
			else
			{
				ll len = abs(w + dis[v] - dis[u]);
				ans = (!len && !val[fu]) || (val[fu] && len % val[fu] == 0);
			}
			maze_io::put_ans(ans);
		}
	}
		
	return 0;
}

