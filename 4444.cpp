#include <cstdio>
#define int long long
const int N = 1e3 + 5;
int n, m, k, a[N][N], t1[N][N], t2[N][N], t3[N][N], t4[N][N];
int lowbit(int x){
    return x & -x;
}
void add(int x1, int y1, int c){
    for (int i = x1; i <= n; i += lowbit(i)){
        for (int j = y1; j <= m; j += lowbit(j)){
            t1[i][j] += c;
            t2[i][j] += c * x1;
            t3[i][j] += c * y1;
            t4[i][j] += c * x1 * y1;
        }
    }
}   
int sum(int x, int y){
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)){
        for (int j = y; j; j -= lowbit(j)){
            ans += t1[i][j] * (x * y + x + y + 1) - t2[i][j] * (y + 1) - t3[i][j] * (x + 1) + t4[i][j];
        }
    }
    return ans;
}
void modify(int x1, int y1, int x2, int y2, int c){
    add(x1, y1, c);
    add(x2 + 1, y2 + 1, c);
    add(x1, y2 + 1, -c);
    add(x2 + 1, y1, -c);
}
int query(int x1, int y1, int x2, int y2){
    return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1);
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%lld", &a[i][j]);
            modify(i, j, i, j, a[i][j]);
        }
    }
    for (int i = 1; i <= k; i++){
        int op, x1, y1, x2, y2, c;
        scanf("%lld", &op);
        if(!op){
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            printf("%lld\n", query(x1, y1, x2, y2));
        }else{
            scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &c);
            modify(x1, y1, x2, y2, c);
        }
    }
    return 0;
}