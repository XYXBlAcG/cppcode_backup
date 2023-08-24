#include <bits/stdc++.h>

#define hash ha
#define ull unsigned long long
using namespace std;

const int base = 173;

struct IO
{
#define gc getchar
#define pt putchar

    inline int read()
    {
        int sum = 0, ff = 1;
        char ch = gc();
        while (!isdigit(ch))
        {
            if (ch == '-')
                ff = -1;
            ch = gc();
        }
        while (isdigit(ch))
            sum = sum * 10 + (ch ^ 48), ch = gc();
        return sum * ff;
    }

    inline void write(int x)
    {
        if (x < 0)
            pt('-'), x = -x;
        if (x > 9)
            write(x / 10);
        pt(x % 10 + 48);
    }

    inline void writeln(int x)
    {
        write(x);
        pt('\n');
    }
} fast;

int n, ans, len, id;
char ch[11][2005];
ull jc[2005], hash[11][2005];
int sum[11][2005];
map<int, ull> ma[11];

inline void init()
{
    jc[0] = 1;
    for (int i = 1; i <= 2000; i++)
        jc[i] = jc[i - 1] * base;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= strlen(ch[i] + 1); j++)
            hash[i][j] = hash[i][j - 1] * base + sum[i][j];
}

inline ull get(int now, int l, int r)
{
    return hash[now][r] - hash[now][l - 1] * jc[r - l + 1];
}

inline bool check(int mid)
{
    for (int i = 1; i <= n; i++)
        ma[i].clear();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j + mid - 1 <= strlen(ch[i] + 1); j++)
        {
            ull tmp = get(i, j, j + mid - 1);
            //   cout<<tmp<<endl;
            ma[i][tmp] = 1;
        }
    }
    // cout<<strlen(ch[n]+1)<<endl;
    for (int i = 1; i + mid - 1 <= strlen(ch[n] + 1); i++)
    {
        ull tmp = get(n, i, i + mid - 1);
        bool ok = false;
        for (int j = 1; j < n; j++)
            if (!ma[j][tmp])
                ok = true;
        if (ok == false)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch[i] + 1);
        for (int j = 1; j <= strlen(ch[i] + 1); j++)
            sum[i][j] = ch[i][j] - 'a' + 1;
        if (strlen(ch[i] + 1) > len)
        {
            len = strlen(ch[i] + 1);
            id = i;
        }
    }
    init();
    // cout<<get(1,1,3)<<endl;
    // for ( int i=1;i<=n;i++ ) {
    //  for ( int j=1;j<=strlen(ch[i]+1);j++ )
    //   cout<<hash[i][j]<<" ";
    //  printf("\n");
    // }
    int l = 1, r = strlen(ch[id] + 1);
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    fast.writeln(ans);
    return 0;
}