#include <cstdio>
#include <algorithm>
#include <math.h>
const int N = 1e6 + 10;
typedef unsigned long long llu;
int n;
int prime[N];
int cnt;
void get_prime()
{
    int i, j, k = 0;
    int n = 0;
    for (i = 2; i <= N; i++)
    {
        k = (int)sqrt(i);
        for (j = 2; j <= k; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j >= k + 1)
        {
            prime[++cnt] = i;
        }
    }
}

inline int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    { // ch 不是数字时
        if (ch == '-')
            w = -1;     // 判断是否为负
        ch = getchar(); // 继续读入
    }
    while (ch >= '0' && ch <= '9')
    {                            // ch 是数字时
        x = x * 10 + (ch - '0'); // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar(); // 继续读入
    }
    return x * w; // 数字 * 正负号 = 实际数值
}
int main()
{
    n = read();
    get_prime();
    int cnt1 = 1;
    while(prime[cnt1] < (int)sqrt(n)){
        int sum = 0;
        for(int i = n; i > 0; i /= prime[cnt1]){
            if(i != n) sum += i;
        }
        printf("%d\n", sum);
        cnt1++;
    }
    return 0;
}