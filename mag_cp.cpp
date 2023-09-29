/*
luogu P4663
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, rk, ans, f[65][65][2][2][3][2];
int dig[65], num;

int dp(int x, int j, int a, int b, int lim, int c)
{
	if (j > m)
		return 0;
	if (x == (n + 1) / 2)
	{
		if (n % 2 == 0)
		{
			if (lim == 2)
				return 0;
			j += (a != b);
			return j <= m ? 1 : 0;
		}
		if (n % 2 == 1)
		{
			int res = 0;
			for (int d = 0; d <= 1; d++)
			{
				if (lim == 2 && d >= dig[n / 2 + 1])
					break;
				if (lim == 1 && d > dig[n / 2 + 1])
					break;
				int t = (d != a) + (d != b);
				if (j + t <= m)
					res++;
			}
			return res;
		}
	}
	if (f[x][j][a][b][lim][c] >= 0)
		return f[x][j][a][b][lim][c];
	int res = 0;
	for (int a1 = 0; a1 <= 1; a1++)
		for (int b1 = 0; b1 <= 1; b1++){
			if (lim >= 1 && a1 > dig[x])
				break;
			int t = 0, c1 = c;
			if (x < n)
			{
				if (a != a1)
					t++;
				if (b != b1)
					t++;
			}
			if (a1 > b1 && c == 1)
				continue;
			else if (a1 == b1)
				c1 = c;
			else if (a1 < b1)
				c1 = 0;
			if (lim == 0)
				res += dp(x - 1, j + t, a1, b1, lim, c1);
			else
			{
				int lim1 = lim;
				if (a1 < dig[x])
					lim1 = 0;
				else if (b1 > dig[n - x + 1])
					lim1 = 2;
				else if (b1 < dig[n - x + 1])
					lim1 = 1;
				res += dp(x - 1, j + t, a1, b1, lim1, c1);
			}
		}
	return f[x][j][a][b][lim][c] = res;
}

int calc(int x)
{
	num = x;
	memset(dig, 0, sizeof(dig));
	memset(f, -1, sizeof(f));
	int tmp = x;
	for (int i = 1; i <= n; i++)
		dig[i] = tmp % 2, tmp /= 2;
	return dp(n, 0, 0, 0, 1, 1);
}

signed main()
{
	cin >> n >> m >> rk;
	int l = 0, r = (1ll << n) - 1;
	// for (int i = l; i <= r; i++)
	// {
	// 	printf("i = %lld, cal(i) = %lld\n", i, calc(i));
	// }
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		int res = calc(mid);
		printf("l = %lld, r = %lld, mid = %lld, res = %lld\n", l, r, mid, res);
		if (res >= rk)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	if (calc(ans) < rk)
		return puts("NO SUCH STONE"), 0;
	for (int i = n; i >= 1; i--)
		if (ans >> (i - 1) & 1)
			cout << 'X';
		else
			cout << 'I';

	return puts(""), 0;
}
