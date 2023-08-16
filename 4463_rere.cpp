// #pragma GCC optimize("Ofast")
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using std::min;
const int N = 5e5 + 5, len = 128;
struct Node
{
    int id, val;
} h[N];
int n, num, m, ans[N], res, map[N], tmp[N];
int a, b, so[N], sum;
struct Note
{
    int id, l, r;
} pre[N], pre2[N];
int lowbit(int x) { return x & (-x); }
bool cmp(Node a, Node b)
{
    if (a.val == b.val)
        return a.id < b.id;
    return a.val < b.val;
}
void add(int x, int v)
{
    for (; x <= n; x += lowbit(x))
        ans[x] += v;
}
int query(int x)
{
    int res = 0;
    for (; x; x -= lowbit(x))
        res += ans[x];
    return res;
}
void sorter(int id)
{
    int l = pre2[id].l, r = pre2[id].r;
    for (int i = l; i <= r; i++)
    {
        so[i] = tmp[i];
    }
    std::sort(so + l, so + r + 1);
}
void kp(int low, int high)
{
    int i = low, j = high, mid = so[(i + j) / 2];
    while (i < j)
    {
        while (so[i] < mid)
            i++;
        while (so[j] > mid)
            j--;
        if (i <= j)
        {
            std::swap(so[i], so[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        kp(low, j);
    if (i < high)
        kp(i, high);
}

int find_down(int num, int left, int right)
{
    int mid;
    if (so[left] >= num)
        return left - 1;
    while (left < right)
    {
        mid = (left + right + 1) >> 1;
        if (so[mid] >= num)
            right = mid - 1;
        else
            left = mid;
    }
    return left;
}
int find_up(int num, int left, int right)
{
    int mid;
    if (so[right] <= num)
        return right + 1;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (so[mid] <= num)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
// int query_2(int l, int r, int c){ // 比他小的
//     int ll = pre[l].id, rr = pre[r].id, bans = 0;
//     if(ll + 1 >= rr){
//         for (int i = l; i <= r; i++) bans += (tmp[i] < c);
//         return bans;
//     }
//     // for (int i = ll + 1; i < rr; i++){
//     //     bans += std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l;
//     // }
//     for (int i = ll + 1; i < rr; i++){
//         bans += find_down(c, pre2[i].l, pre2[i].r) - pre2[i].l + 1;
//         // printf("test = %lld\n", find_down(c, pre2[i].l, pre2[i].r) - pre2[i].l + 1);
//     }
//     // printf("pre %lld r = %lld\n", l,  pre[l].r);
//     for (int i = l; i <= pre2[pre[l].id].r; i++) bans += (tmp[i] < c);
//     // puts("!");
//     for (int i = pre2[pre[r].id].l; i <= r; i++) bans += (tmp[i] < c);

//     // printf("%lld %lld %lld ans = %lld\n", l, r, c, ans);
//     return bans;
// }
// int query_3(int l, int r, int c){ // 比他大的
//     int ll = pre[l].id, rr = pre[r].id, bans = 0;
//     if(ll + 1 >= rr){
//         for (int i = l; i <= r; i++) bans += (tmp[i] > c);
//         // printf("%lld %lld %lld ans = %lld\n", l, r, c, ans);
//         return bans;
//     }
//     // for (int i = ll + 1; i < rr; i++){
//     //     // 加 1
//     //     bans += pre2[i].r + 1 - (std::lower_bound(so + pre2[i].l, so + pre2[i].r + 1, c) - so - pre2[i].l);
//     // }
//     for (int i = ll + 1; i < rr; i++){
//         bans += pre2[i].r - find_up(c, pre2[i].l, pre2[i].r) + 1;
//         // printf("test = %lld\n", pre2[i].r - find_up(c, pre2[i].l, pre2[i].r) + 1);
//     }
//     for (int i = l; i <= pre2[pre[l].id].r; i++) bans += (tmp[i] > c);
//     for (int i = pre2[pre[r].id].l; i <= r; i++) bans += (tmp[i] > c);

//     // printf("%lld %lld %lld ans = %lld\n", l, r, c, ans);
//     return bans;
// }
int down(int x, int y, int num)
{
    int i, ans = 0;
    if (pre[x].id + 1 >= pre[y].id)
    {
        for (i = x; i <= y; i++)
            if (tmp[i] < num)
                ans++;
        return ans;
    }
    for (i = x; i <= pre2[pre[x].id].r; i++)
        if (tmp[i] < num)
            ans++;
    for (i = pre2[pre[y].id].l; i <= y; i++)
        if (tmp[i] < num)
            ans++;
    for (i = pre[x].id + 1; i < pre[y].id; i++)
    {
        ans += find_down(num, pre2[i].l, pre2[i].r) - pre2[i].l + 1;
        // printf("test = %lld\n", find_down(num,L[i],R[i])-L[i]+1);
    }
    return ans;
}
int up(int x, int y, int num)
{
    int i, ans = 0;
    if (pre[x].id + 1 >= pre[y].id)
    {
        for (i = x; i <= y; i++)
            if (tmp[i] > num)
                ans++;
        return ans;
    }
    for (i = x; i <= pre2[pre[x].id].r; i++)
        if (tmp[i] > num)
            ans++;
    for (i = pre2[pre[y].id].l; i <= y; i++)
        if (tmp[i] > num)
            ans++;
    for (i = pre[x].id + 1; i < pre[y].id; i++)
    {
        ans += pre2[i].r - find_up(num, pre2[i].l, pre2[i].r) + 1;
    }
    return ans;
}

signed main()
{
    scanf("%lld", &n);
    // printf("%lld\n", num);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &h[i].val), h[i].id = i, tmp[i] = h[i].val;
    }
    std::sort(h + 1, h + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        map[h[i].id] = i;
    for (int i = 1; i <= n; i++)
    {
        add(map[i], 1);
        res += i - query(map[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i].id = (i - 1) / len + 1;
    }
    num = (n - 1) / len + 1;
    // return 0;
    for (int i = 1; i <= num; i++)
    {
        pre2[i].l = (i - 1) * len + 1;
        pre2[i].r = i * len;
    }
    pre2[num].r = n;
    for (int i = 1; i <= num; i++)
    {
        // sorter(i);
        for (int j = pre2[i].l; j <= pre2[i].r; j++){
            so[j] = tmp[j];
        }
        kp(pre2[i].l, pre2[i].r);
    }
    printf("%lld\n", res);
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &a, &b);
        // printf("%lld %lld\n", a, b);
        if (a > b)
            std::swap(a, b);
        // printf("a = %lld , b = %lld\n", a, b);
        if (b - a > 1)
        {
            //     for (int p = 1; p <= 60; p++){
            //         printf("pre[%lld] = %lld\n", p, pre[p].r);
            //     }
            //    printf("l = %lld, r = %lld\n", pre[a + 1].r, pre[b - 1].r);
            int ta = down(a + 1, b - 1, tmp[a]); // 左界移动
            int tb = down(a + 1, b - 1, tmp[b]);
            int ta2 = up(a + 1, b - 1, tmp[a]);
            int tb2 = up(a + 1, b - 1, tmp[b]);
            // int ta = query_2(a + 1, b - 1, tmp[a]); // 左界移动
            // int tb = query_2(a + 1, b - 1, tmp[b]);
            // int ta2 = query_3(a + 1, b - 1, tmp[a]);
            // int tb2 = query_3(a + 1, b - 1, tmp[b]);
            res -= (ta - ta2);
            res += (tb - tb2);
            // printf(" = %lld", - (ta - ta2) + (tb - tb2));
        }
        // printf("pre = %lld\n", res);
        if (tmp[a] < tmp[b])
            res++;
        if (tmp[a] > tmp[b])
            res--;
        // if(tmp[a] < tmp[b]) res--;
        // if(tmp[a] > tmp[b]) res++;
        std::swap(tmp[a], tmp[b]);
        // sorter(pre[a].id), sorter(pre[b].id);
        for (int j = pre2[pre[a].id].l; j <= pre2[pre[a].id].r; j++){
            so[j] = tmp[j];
        }
        kp(pre2[pre[a].id].l, pre2[pre[a].id].r);
        for (int j = pre2[pre[b].id].l; j <= pre2[pre[b].id].r; j++){
            so[j] = tmp[j];
        }
        kp(pre2[pre[b].id].l, pre2[pre[b].id].r);
        printf("%lld\n", res);

        // std::swap(h[a], h[b]);
    }
}