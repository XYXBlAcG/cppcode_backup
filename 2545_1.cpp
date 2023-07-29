#include <iostream>
#define maxn 105
#define maxm 205
using namespace std;
int n, m, V, a[maxn], b[maxn], sum, f[maxm], ans[maxn], id[maxn];
void Maxsolve()
{
    for (int k = 1; k <= n; k++)
    {
        a[k] += V - sum, memset(b, 0, (n + 1) << 2);
        for (int t = 1, p; t <= m; b[p]++, t++)
        {
            for (p = 1; p <= n; p++)
                if (a[p] * 20 >= V)
                    break;
            for (int i = p + 1; i <= n; i++)
                if (a[i] * 20 >= V && a[i] * (b[p] + 1) > a[p] * (b[i] + 1))
                    p = i;
        }
        a[k] -= V - sum, printf("%d%c", b[k], k == n ? 10 : 32);
    }
}
bool cmp(int i, int j) { return a[i] > a[j]; }
bool cmp2(int i, int j) { return i > j; }
bool cal(int x, int mid){
    memset(f, 0x3f, sizeof f), f[0] = 0;
    f[0] = 0;
    for (int i = 1; i <= min(n, 20); i++){
        if(i != x)
        {
            for (int j = m - mid; j >= 1; j--){
                for (int k = 1; k <= j; k++){
                    int cost = max((a[x] * k % (mid + 1) ? a[x] * k / (mid + 1) + 1 : a[x] * k / (mid + 1) + (id[i] > id[x])) - a[i], 0);
                    // int cost = (k * a[x] + mid) / (mid + 1) - a[i];
                    // if(a[x] * k % (mid + 1) == 0 && a[x] < a[i] && k) cost++;
                    // cost = max(cost, 0);
                    if(((a[i] + cost) * 20 < V)) cost = /*(v - 20 * (a[i] + cost) + 19) / 20*/ (V - 1) / 20 + 1 - a[i];
                    f[j] = min(f[j], f[j - k] + cost);
                }
            }
        }
    }
    return f[m - mid] <= V - sum;
}
// bool check(int x, int mid)
// {
//     memset(f, 0x3f, sizeof f), f[0] = 0;
//     for (int i = 1; i <= n && i <= 20; i++)
//         if (i != x)
//         {
//             for (int j = m - mid; j >= 1; j--)
//                 for (int k = 1; k <= j; k++)
//                 {
//                     int cst = max((a[x] * k % (mid + 1) ? a[x] * k / (mid + 1) + 1 : a[x] * k / (mid + 1) + (id[i] > id[x])) - a[i], 0);
//                     if ((a[i] + cst) * 20 < V)
//                         cst = (V - 1) / 20 + 1 - a[i];
//                     f[j] = min(f[j], f[j - k] + cst);
//                 }
//         }
//     return f[m - mid] <= V - sum;
// }
int main()
{
    scanf("%d%d%d", &V, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum += a[i];
    Maxsolve();
    for (int i = 1; i <= n; i++)
        id[i] = i;
    sort(id + 1, id + 1 + n, cmp), sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
        if (a[i] * 20 >= V)
        {
            int l = 0, r = m, mid;
            while (l < r)
            {
                mid = (l + r) >> 1;
                if (cal(i, mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            ans[id[i]] = l;
        }
    for (int i = 1; i <= n; i++)
        printf("%d%c", ans[i], i == n ? 10 : 32);
}