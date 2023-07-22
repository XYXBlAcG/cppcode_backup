#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 2011;
int a[maxn][maxn], hz[maxn][maxn], ho[maxn][maxn], stack[maxn];
// ho[][]存连续的1的个数，hz[][]存连续的0的个数
int n, m, nstack;
int ans;
void init()
{ // 隔位进行取反
	for (int i = 1; i <= n; i += 2)
	{
		for (int j = 1; j <= m; j += 2)
		{
			if (a[i][j] == 1)
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
	for (int i = 2; i <= n; i += 2)
	{
		for (int j = 2; j <= m; j += 2)
		{
			if (a[i][j] == 1)
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
}
void pre()
{ // 预处理把每个位置上往前连续的1或0的个数统计
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 1 && a[i][j - 1] == 1 && j - 1 != 0)
				ho[i][j] = ho[i][j - 1] + 1;
			else if (a[i][j] == 1 && j == 1)
				ho[i][j] = 1;
			else if (a[i][j] == 1 && a[i][j - 1] != 1 && j - 1 != 0)
				ho[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 0 && a[i][j - 1] == 0 && j - 1 != 0)
				hz[i][j] = hz[i][j - 1] + 1;
			else if (a[i][j] == 0 && j == 1)
				hz[i][j] = 1;
			else if (a[i][j] == 0 && a[i][j - 1] != 0 && j - 1 != 0)
				hz[i][j] = 1;
		}
	}
}
void run1()
{
	for (int j = 1; j <= m; j++)
	{ // 遍历每一列
		std::memset(stack, 0, sizeof(stack));
		nstack = 0;
		for (int i = 1; i <= n + 1; i++)
		{
			for (; 0 <= nstack && ho[stack[nstack]][j] > ho[i][j]; nstack--)
			{
				// 将末尾大于新元素的元素弹出
				int s = (i - stack[nstack - 1] - 1) * ho[stack[nstack]][j];
				ans = std::max(ans, s); // 把答案更新
			}
			stack[++nstack] = i;
		}
	}
}
void run0()
{
	for (int j = 1; j <= m; j++)
	{
		std::memset(stack, 0, sizeof(stack));
		nstack = 0;
		for (int i = 1; i <= n + 1; i++)
		{
			for (; 0 <= nstack && hz[stack[nstack]][j] > hz[i][j]; nstack--)
			{
				int s = (i - stack[nstack - 1] - 1) * hz[stack[nstack]][j];
				ans = std::max(ans, s);
			}
			stack[++nstack] = i;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		char ch = getchar();
		for (int j = 1; j <= m; j++)
		{
			char ch = getchar();
			a[i][j] = (int)ch - '0';
		}
	}
	init();
	pre();
	run0();
	run1();
	printf("%d", ans);
	return 0;
}