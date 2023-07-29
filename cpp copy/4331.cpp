#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
const int N = 1005;
struct Node{
    int num, magic;
}az[N];
int n, ans, who[N];
bool check(int in){
    for (int i = 63; i >= 0; i--){
        if(~in & (1ll << i)) continue;
        if(!who[i]) {who[i] = in; break;}
        in ^= who[i];
    }
    return in;
}
bool cmp(Node a, Node b){
    return a.magic > b.magic;
}
signed main(){
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &az[i].num, &az[i].magic);
    std::sort(az, az + n, cmp);
    for (int i = 0; i < n; i++){
        if(check(az[i].num)) ans += az[i].magic;
    }
    printf("%lld\n", ans);
    return 0;
}