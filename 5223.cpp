#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#define int long long
#define lowbit(x) (x & -x)
#define debug(u) std::cout << #u << " = " << u << std::endl
using std::sort;
using std::unique;
const int M = 1e5 + 5, mod = 2147483648;
struct Node{
    int x, y;
}pos[M];
bool cmp(Node a, Node b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(Node a, Node b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
int n, m, w, k, C[M][12], tx[M], ty[M], lx, ly, res[M], leng[M], dep[M], high[M], sum[M], anss, top;
void init(){
    C[0][0] = 1;
    for (int i = 1; i <= M - 5; i++){
        C[i][0] = 1;
        for (int j = 1; j <= 10; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}
void add(int x, int c){
    for (; x <= top; x += lowbit(x)) res[x] += c;
}
int query(int x){
    int result = 0;
    for (; x; x -= lowbit(x)) result += res[x];
    return result;
}
signed main(){
    init();
    scanf("%lld%lld%lld\n", &n, &m, &w);
    for (int i = 1; i <= w; i++){
        scanf("%lld%lld", &pos[i].x, &pos[i].y);
    }
    scanf("%lld", &k);
    sort(pos + 1, pos + 1 + w, cmp);
    for (int i = 1, cnt = 0; i <= w; i++){
        if(i == 1 || pos[i].x != pos[i - 1].x) cnt++;
        tx[i] = cnt;
    }
    for (int i = 1; i <= w; i++) leng[pos[i].x = tx[i]]++;
    // for (int i = 1; i <= w; i++){
    //     printf("leng[%lld] = %lld\n", i, leng[i]);
    // }
    sort(pos + 1, pos + 1 + w, cmp2);
    for (int i = 1, cnt = 0; i <= w; i++){
        if(i == 1 || pos[i].y != pos[i - 1].y) cnt++;
        ty[i] = cnt;
    }
    for (int i = 1; i <= w; i++) dep[pos[i].y = ty[i]]++;
    // for (int i = 1; i <= w; i++){
    //     printf("dep[%lld] = %lld\n", i, dep[i]);
    // }
    int td = 0; top = pos[w].y;
    std::sort(pos + 1, pos + 1 + w , cmp);
    // for (int i = 1; i <= w; i++){
    //     printf("pos[%lld] = {%lld,%lld}\n", i, pos[i].x, pos[i].y);
    // }
    for (int i = 1; i <= w; i++){
        if(pos[i].x != pos[i - 1].x) td = 0;
        int tm = pos[i].y, val = (++high[tm] < k || dep[tm] - high[tm] < k) ? 0 : (C[high[tm]][k] * C[dep[tm] - high[tm]][k] % mod);
        add(tm, val - sum[tm]), sum[tm] = val, td++;
        // debug(tm); debug(val);
        // printf("%d %d %d %d %d\n", (i == w), (td < k), (leng[pos[i].x] - td < k), (pos[i].x != pos[i + 1].x), (pos[i + 1].y - pos[i].y <= 1));
        if(i == w || td < k || leng[pos[i].x] - td < k || pos[i].x != pos[i + 1].x || pos[i + 1].y - pos[i].y <= 1) continue;
        // puts("reach!");
        anss += C[td][k] * C[leng[pos[i].x] - td][k] % mod * (query(pos[i + 1].y - 1) - query(pos[i].y)) % mod;
        // printf("%lld %lld %lld %lld %lld\n", td, pos[i].x - td, )
    }
    printf("%lld\n", (anss % mod + mod) % mod);
    return 0;
}