#include <cstdio>
#include <cstring>
const int N = 1e5 + 5, mod = 1000000007, M = 1005;
typedef long long ll;
ll n, h[N], f[N], m, k, p, q, ans, vis[M], sum[M], flag20_ = 1, fa[N];
struct Hand{
    ll l, r, ha, mov;
}ani[N];
struct Op{
    ll k, p, q;
}op[N];
// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// bool check(int x, int y){
//     int X = find(x), Y = find(Y);
//     return (X == Y);
// }
// void merge(int x, int y){
//     int X = find(x), Y = find(Y);
//     if(X == Y) return;
//     fa[y] = X;
// }
// void debug(int xxx){
//     puts("---start---\n");
//     printf("i = %d 的牵手情况:\n", xxx);
//     for (int i = 1; i <= n; i++){
//         printf("%lld <- %d -> %lld, happy = %lld, move = %lld\n", ani[i].l, i, ani[i].r, ani[i].ha, ani[i].mov);
//     }
//     puts("---end---\n");
// }
int main(){
    // freopen("cycle.in", "r", stdin);
    // freopen("cycle.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", h + i, f + i);
    }
    for (int i = 1; i <= n; i++){
        ani[i] = (Hand){i - 1, i + 1, h[i], f[i]};
        // fa[i] = i - 1;
    }ani[1].l = n, ani[n].r = 1;
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &op[i].k, &op[i].p, &op[i].q);
        if(op[i].k != 1) flag20_ = 0;
    }
    for (int i = 1; i <= m; i++){
        memset(vis, 0, sizeof(vis));
        ans = 0;
        k = op[i].k, p = op[i].p , q = op[i].q;
        if(k == 1){
                int pr = ani[p].r, ql = ani[q].l;
                // fa[pr] = pr;
                // fa[ql] = pr;
                ani[pr].l = ani[q].l;
                ani[ql].r = ani[p].r;
                ani[p].r = q;
                ani[q].l = p;
                // fa[p] = ani[p].l;
                // fa[q] = ani[q].r;
            }else if(k == 2){
                ani[p].ha = q;
            }else if(k == 3){
                ani[p].mov = q;
            }
        // scanf("%lld%lld%lld", &k, &p, &q);
        if(n <= 100){
            for (int j = 1; j <= n; j++){
                bool flag = 1; int cnt = 0;
                if(!vis[j]){
                    for (int kk = j; kk != j || flag; kk = ani[kk].r){
                        vis[kk] = 1;
                        cnt++;
                        flag = 0;
                    }flag = 1;
                    for (int kk = j; kk != j || flag; kk = ani[kk].r){
                        flag = 0;
                        for (int o = ani[kk].r, oo = 1; o != kk; o = ani[o].r, oo++){
                            (ans += (cnt - oo) * ani[o].mov % mod * ani[kk].ha % mod) %= mod;
                        }
                    }
                }
            }
            printf("%lld\n", (ans + mod) % mod);
            // debug(i);
        }
        else 
        if(n <= 1000){
            for (int j = 1; j <= n; j++){
                ll sbsum = 0, ssum2 = 0;
                bool flag = 1; int cnt = 0;
                if(!vis[j]){
                    ssum2 = 0;
                    for (int kk = j, oo = 1; kk != j || flag; kk = ani[kk].r, oo++){
                        ssum2 += ani[kk].mov;
                        vis[kk] = 1;
                        cnt++;
                        flag = 0;
                    }flag = 1;
                    for (int kk = ani[j].r, oo = 1; kk != j || flag; kk = ani[kk].r, oo++){
                        flag = 0;
                        sbsum += ani[kk].mov * (cnt - oo);
                    }
                    // ll asum = ((cnt * (cnt - 1) % mod) >> 1) % mod;
                    flag = 1;
                    for (int kk = j; kk != j || flag; kk = ani[kk].r){
                        flag = 0;
                        // asum * ani[kk].mov % mod * 
                        ans += (ani[kk].ha * sbsum % mod);
                        sbsum = (sbsum + ssum2 - ani[ani[kk].r].mov * cnt) % mod;
                        // for (int o = ani[kk].r, oo = 1; o != kk; o = ani[o].r, oo++){
                        //     (ans += (cnt - oo) * ani[o].mov % mod * ani[kk].ha % mod) %= mod;
                        // }
                    }
                }
            }
            printf("%lld\n", (ans + mod) % mod);
        }
        // else if(flag20_){
        //     for (int j = 1; j <= n; j++){

        //     }
        // }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}


        //     if(k == 1){
        //         int pr = ani[p].r, ql = ani[q].l;
        //         ani[pr].l = ani[q].l;
        //         ani[ql].r = ani[p].r;
        //         ani[p].r = q;
        //         ani[q].l = p;
        //     }else if(k == 2){
        //         ani[p].ha = q;
        //     }else if(k == 3){
        //         ani[p].mov = q;
        //     }