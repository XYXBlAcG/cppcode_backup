#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
using std::min;
using std::sort;
using std::swap;
int t[50011], n, h[50011], fl[50011], m, num, q;
ll plist[2300], ans, cnt[2300];
struct List
{
    int id;
    ll w;
} list[2311][2311], lis[2311], lis1[2311], ls[50011];
bool operator<(List a, List b)
{
    return a.w < b.w;
}
bool cmp(List a, List b)
{
    return a.id < b.id;
}
void re(int id, int l, int r)
{
    plist[id] = 0;
    int pl = 0, pl1 = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!list[id][i].id)
            break;
        if (list[id][i].id <= r && list[id][i].id >= l)
        {
            lis1[++pl1] = list[id][i];
            lis1[pl1].w = h[list[id][i].id];
        }
        else
            lis[++pl] = list[id][i];
    }
    for (int i = 1, j = 1; i <= pl || j <= pl1;)
    {
        if (i > pl || (j <= pl1 && lis1[j] < lis[i]))
            list[id][++plist[id]] = lis1[j++];
        else
            list[id][++plist[id]] = lis[i++];
    }
}
int bin(ll x, int id)
{
    int l = 1, r = plist[id] + 1;
    while (r > l)
    {
        int mid = (l + r) >> 1;
        if (list[id][mid].w < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int lowbit(int x)
{
    return x & (-x);
}
void add(int x)
{
    for (int i = x; i <= n; i += lowbit(i))
        t[i]++;
}
int sum(int x)
{
    int rt = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        rt += t[i];
    }
    return rt;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
        ls[i] = {i, h[i]};
    }
    sort(ls + 1, ls + 1 + n);
    int cnt = 0, las = -1;
    for (int i = 1; i <= n; i++)
    {
        if (las != ls[i].w)
            ls[i].w = ++cnt;
        else
            ls[i].w = cnt;
        las = h[ls[i].id];
    }
    sort(ls + 1, ls + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        h[i] = ls[i].w;
        add(ls[i].w);
        ans += (i - sum(ls[i].w));
    }
    printf("%lld\n", ans);
    m = sqrt(n);
    num = n / m + (n % m);
    for (int i = 1; i <= n; i++)
    {
        fl[i] = (i - 1 + m) / m;
        list[fl[i]][++plist[fl[i]]] = {i, h[i]};
    }
    for (int i = 1; i <= num; i++)
        sort(list[i] + 1, list[i] + 1 + plist[i]);
    int l, r;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {   
        ll sh=0;
        scanf("%d%d", &l, &r);
        if (l > r)
            swap(l, r);
        int ll = fl[l], lr = fl[r], cnt = 0, cnt1 = 0;
        if (ll != lr)
        {
            for (int j = l; j <= min(ll * m, n); j++)
                cnt += (h[j] < h[l]), cnt1 += (h[j] > h[l]);
            ans += cnt1 - cnt,sh+=cnt1-cnt;
            cnt = cnt1 = 0;
            for (int j = (lr - 1) * m + 1; j <= r; j++)
                cnt += (h[j] > h[r]), cnt1 += (h[j] < h[r]);
            ans += -cnt + cnt1,sh+=cnt1-cnt;
            cnt = cnt1 = 0;
            for (int j = l; j <= min(ll * m, n); j++)
                cnt += (h[j] > h[r]), cnt1 += (h[j] < h[r]);
            ans += -cnt + cnt1,sh+=cnt1-cnt;
            cnt = cnt1 = 0;
            for (int j = (lr - 1) * m + 1; j <= r; j++)
                cnt += (h[j] < h[l]), cnt1 += (h[j] > h[l]);
            ans += -cnt + cnt1,sh+=cnt1-cnt;
            cnt = cnt1 = 0;
        }
        else
        {
            for (int j = l; j <= r; j++)
                cnt += (h[j] < h[l]), cnt1 += (h[j] > h[l]);
            ans += -cnt + cnt1,sh+=cnt1-cnt;
            cnt = cnt1 = 0;
            for (int j = l; j <= r; j++)
                cnt += (h[j] > h[r]), cnt1 += (h[j] < h[r]);
            ans += -cnt + cnt1,sh+=cnt1-cnt;
            cnt = cnt1 = 0;
        }
        // printf("side = %lld\n", ans);
        for (int j = ll + 1; j < lr; j++)
        {
            ans += (plist[j] - bin(h[l] + 1, j) + 1) - bin(h[l], j) + (h[l] <= list[j][bin(h[l], j)].w || bin(h[l], j) > plist[j]);
            sh+=(plist[j] - bin(h[l] + 1, j) + 1) - bin(h[l], j) + (h[l] <= list[j][bin(h[l], j)].w || bin(h[l], j) > plist[j]);
            ans += bin(h[r], j) - (h[r] <= list[j][bin(h[r], j)].w || bin(h[r], j) > plist[j]) - (plist[j] - bin(h[r] + 1, j) + 1);
            sh+=bin(h[r], j) - (h[r] <= list[j][bin(h[r], j)].w || bin(h[r], j) > plist[j]) - (plist[j] - bin(h[r] + 1, j) + 1);
        }
        printf(" = %lld", sh);
        // printf("pre = %lld\n", ans);
        if (h[l] < h[r])
            ans--;
        if (h[l] > h[r])
            ans++;
        swap(h[l], h[r]);
        re(ll, l, l), re(lr, r, r);
        printf("%lld\n", ans);
    }
    return 0;
}