#include <cstdio>
#define int long long
const int N = 1e5 + 5;
int n, m, a[N], cc[N];
int lowbit(int x){
    return x & -x;
}
void add(int x, int c){
    while(x <= n){
        // printf("x = %d\n", x);
        cc[x] += c;
        x += lowbit(x);
    }
}
int ask(int x){
    int ans = 0;
    while(x > 0){
        // printf("ans = %d\n", ans);
        ans += cc[x];
        x -= lowbit(x);
    }
    return ans;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        add(i, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= m; i++){
        int op = 0, x = 0, l = 0, r = 0, c = 0;
        scanf("%lld", &op);
        if(op == 0){
            scanf("%lld", &x);
            printf("%lld\n", ask(x));
        }else{
            scanf("%lld%lld%lld", &l, &r, &c);
            add(r + 1, -c);
            add(l, c);
        }
    }
    return 0;
}