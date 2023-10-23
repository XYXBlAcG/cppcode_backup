#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
int t, n, a, b, mn;
int p(int x){return x * x;}
struct FileIO{
    FileIO(){
        #ifdef ONLINE_JUDGE
            freopen("backroom.in", "r", stdin);
            freopen("backroom.out", "w", stdout);
        #else 
        #endif
    }
}FileIO;
signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld%lld", &n, &a, &b);
        if(!(a % n) && !(b % n)){
            puts("-1");
            continue;
        }
        int ta = a % n, tb = b % n;
        mn = p(ta) + p(tb);
        while(1){
            int t1 = !ta ? INF : ((n - ta) / a) + (bool)((n - ta) % a), t2 = !tb ? INF : ((n - tb) / b) + (bool)((n - tb) % b); 
            if(t1 > t2) std::swap(t1, t2);
            (ta += t1 * a) %= n, (tb += t1 * b) %= n;
            if((!ta && !tb) || (ta == a && tb == b)) break;
            mn = std::min(mn, p(ta) + p(tb));
        }
        printf("%lld\n", mn);
    }
    return fclose(stdin), fclose(stdout), 0;
}