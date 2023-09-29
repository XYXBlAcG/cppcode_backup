#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 1047199, L = 100;
int pdata, head[N], prange, range[411], coe[7];
struct Linker{
    int cnt, next; ll val;
}data[L * L * 4 + 11];
void init(){
    for(int i = 1; i <= 5; i++)
        scanf("%d", coe + i);
    for(int i = -L; i < 0; i++)
    range[++prange] = i;
    for(int i = 1; i <= L; i++)
        range[++prange] = i;
}
ll pow3(int a){
    return ll(range[a]) * range[a] * range[a]; 
}
void ins(ll v){
    int h = (v % N + N) % N;
    for(int i = head[h]; i; i = data[i].next)
        if(data[i].val == v){
            data[i].cnt++;
            return; 
        }
    data[++pdata] = {1, head[h], v};
    head[h] = pdata;
}
int que(ll v){
    int h = (v % N + N) % N, ans = 0; 
    for(int i = head[h]; i; i = data[i].next)
        if(data[i].val == v){
            ans += data[i].cnt;
            break; 
        }
    return ans;
 }
void gen(){
    for(int i = 1; i <= prange; i++)
        for(int j = 1; j <= prange; j++)
            ins(pow3(i) * coe[1] + pow3(j) * coe[2]);
}
void solve(){
    ll ans = 0;
    for(int i = 1; i <= prange; i++) 
        for(int j = 1; j <= prange; j++)
            for(int k = 1; k <= prange; k++) 
                ans += que(- pow3(i) * coe[3] - pow3(j) * coe[4] - pow3(k) * coe[5]); printf("%lld\n", ans);
}
int main(){
    init();
    gen();
    solve();
    return 0;
}

