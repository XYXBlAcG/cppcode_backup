#include <cstdio>
#include <algorithm>
#define int unsigned long long
const int N = 1e6 + 5;
int n, a[N], b[N], zhan[N], pzhan, cnt[N], pcnt, ta[N];
bool cmp(int a, int b){return a > b;}
signed main(){
    scanf("%llu", &n);
    for (int i = 1; i <= n; i++) scanf("%llu", a + i), ta[i] = a[i];
    for (int i = 1; i <= n; i++) scanf("%llu", b + i);
    std::sort(a + 1, a + 1 + n), std::sort(b + 1, b + 1 + n), std::sort(ta + 1, ta + 1 + n);
    int mmax = a[1];
    for (int i = 1; i <= n; i++){
        int tmp = i, tcnt = 0;
        for(;ta[++tmp] == ta[i];); tmp -= 2;
        
    }
}
// if(i == 1){
//     if(tmp <= 2) continue;
//     cnt[++pcnt] = ((tmp - 1) * (tmp - 2)) >> 1;
//     mmax = a[1] + tmp - 2;
// }else{
//     int cha = ta[i] - ta[tmp];
//     cnt[++pcnt] = (cha * (cha - 1)) >> 1;
// }