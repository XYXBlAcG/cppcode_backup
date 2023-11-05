#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;
int n, q, a[N], pos[N], sz, ml[N], mr[N], suml[N], sumr[N], ans[N], res;
struct Seg{
    int l, r, id;
}seg[N];
struct Mn{
    int mn, id;
}f[N][20];
Mn operator+(Mn a, Mn b){
    if(a.mn < b.mn) return a;
    return b;
}
double lg[N];
struct ST{
    void init(){
        for (int i = 1; i <= n; i++) lg[i] = log(i);
        for (int j = 0; j <= 19; j++){
            for (int i = 1; i + (1 << j) - 1 <= n; i++){
                if(!j) f[i][j] = {a[i], i};
                else {
                    f[i][j] = f[i][j - 1] + f[i + (1 << (j - 1))][j - 1];
                }
            }
        }
    }
    Mn query(int l, int r){
        int k = lg[r - l + 1] / lg[2];
        return f[l][k] + f[r - (1 << k) + 1][k];
    }
}st;
struct Stack{
    int data[N], pdata;
    inline void push(int x){data[++pdata] = x;}
    inline void pop(){pdata--;}
    inline int top(){return data[pdata];}
    inline void clean(){pdata = 0;}
}sta;
void init(){
    a[0] = -INF, sta.push(0);
    for (int i = 1; i <= n; i++){
        while(sta.pdata && a[sta.top()] >= a[i]) sta.pop();
        ml[i] = sta.top(), sta.push(i);
    }
    a[n + 1] = -INF, sta.clean(), sta.push(n + 1);
    for (int i = n; i; i--){
        while(sta.pdata && a[sta.top()] >= a[i]) sta.pop();
        mr[i] = sta.top(), sta.push(i);
    }
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
        suml[i] = suml[ml[i]] + a[i] * (i - ml[i]);
    for (int i = n; i; i--)
        sumr[i] = sumr[mr[i]] + a[i] * (mr[i] - i);
}
bool cmp(Seg a, Seg b){
    if(pos[a.l] ^ pos[b.l]) return a.l < b.l;
    return (pos[a.l] & 1) ? a.r > b.r : a.r < b.r;
}
int l = 1, r = 0;
void L(int op){
    auto mn = st.query(l, r);
    res += op * (sumr[l] - sumr[mn.id] + mn.mn * (r - mn.id + 1));
}
void R(int op){
    auto mn = st.query(l, r);
    res += op * (suml[r] - suml[mn.id] + mn.mn * (mn.id - l + 1));
}
signed main(){
    scanf("%lld%lld", &n, &q), sz = (int)sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    init(), st.init();
    for (int i = 1; i <= n; i++) pos[i] = (i - 1) / sz;
    for (int i = 1, l, r; i <= q; i++){
        scanf("%lld%lld", &l, &r);
        seg[i] = {l, r, i};
    }
    std::sort(seg + 1, seg + 1 + q, cmp);
    for (int i = 1; i <= q; i++){
        auto x = seg[i];
        while(l > x.l) --l, L(1);
        while(r < x.r) ++r, R(1);
        while(l < x.l) L(-1), l++;
        while(r > x.r) R(-1), r--;
        ans[x.id] = res;
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}