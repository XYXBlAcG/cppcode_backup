#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
long long n, m, Max;
long long a[N], s[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i] * 10000;
        Max = max(Max, a[i]);
    }
    int l = 0, r = Max;
    while (l <= r)
    {
        bool ok = 0;
        long long mid = (l + r) / 2, Min = 0;
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + (a[i] - mid);
            if (i >= m)
            {
                Min = min(Min, s[i - m]);
                if (s[i] > Min)
                {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << (l / 10) << endl;
    return 0;
}