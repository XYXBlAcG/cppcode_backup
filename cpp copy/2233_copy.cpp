#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N][N];//存储数塔
int f[N][N];//表示从第i行第j列到第n行的最大路径
int n;

int main()
{
    while (cin >> n)
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= i;j++)
                cin >> a[i][j];
                
        for (int i = n;i >= 1;i--)
            for (int j = 1;j <= i;j++)
                f[i][j] = max(f[i + 1][j],f[i + 1][j + 1]) + a[i][j];//自底向上计算最长路径
                
        cout << f[1][1] << endl;//当for循环结束完毕之后f[1][1]:从数塔第1行第1列开始的最长路径
    }
    return 0;
}