#include <cstdio>
#include <cmath>
#define int long long
const int N = 2e5 + 5;
int n, m, k[N], len, num, step[N], to[N];
struct Node{
    int id, l, r;
}pre[N], pre2[N];
void modify(int i){
    for (int j = pre2[i].r; j >= pre2[i].l; j--){
        if(k[j] + j > pre2[i].r){
            step[j] = 1, to[j] = k[j] + j;
        }else{
            step[j] += step[k[j] + j] + 1, to[j] = to[k[j] + j];
        }
    }
}
void init(){
    num = (n - 1) / len + 1;
    for (int i = 1; i <= num; i++)
        pre2[i] = (Node){0, (i - 1) * len + 1, i * len};
    pre2[num].r = n;
    for (int i = 1; i <= n; i++)
        pre[i].id = (i - 1) / len + 1;
    for (int i = 1; i <= n; i++)
        pre[i].l = pre2[pre[i].id].l, pre[i].r = pre2[pre[i].id].r;
    for (int i = 1; i <= num; i++){
        modify(i);
    }
}
int query(int x){
    int ans = 0;
    while(x <= n){
        ans += step[x];
        x = to[x];
    }
    return ans;
}
signed main(){
    scanf("%lld", &n), len = sqrt(n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", k + i);
    }
    init();
    scanf("%lld", &m);
    for (int o = 1; o <= m; o++){
        int op, kk, j;
        scanf("%lld", &op);
        if(op == 1){
            scanf("%lld", &j);
            printf("%lld\n", query(j + 1));
        }else{
            scanf("%lld%lld", &j, &kk), j++;
            k[j] = kk;
            for (int p = pre[j].l; p <= pre[j].r; p++){
                to[p] = step[p] = 0;
            }
            modify(pre[j].id);
        }
    }
    return 0;
}