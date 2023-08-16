#include <cstdio>
#define int long long
const int N = 1e3 + 5;
int n, m, k, a[N][N], az[N][N];
int lowbit(int x){
    return x & -x;
}
void add(int x, int y, int c){
    for (int i = x; i <= n; i += lowbit(i)){
        for (int j = y; j <= m; j += lowbit(j)){
            az[i][j] += c;
        }
    }
}
int sum(int x, int y){
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)){
        for (int j = y; j; j -= lowbit(j)){
            ans += az[i][j];
        }
    }
    return ans;
}
int query(int x1, int y1, int x2, int y2){
    return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1);
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%lld", &a[i][j]);
            add(i, j, a[i][j]);
        }
    }
    for (int i = 1; i <= k; i++){
        int op, x1, y1, x2, y2, c;
        scanf("%lld", &op);
        if(!op){
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            printf("%lld\n", query(x1, y1, x2, y2));
        }else{
            scanf("%lld%lld%lld", &x1, &y1, &c);
            add(x1, y1, c);
        }
    }
    return 0;
}