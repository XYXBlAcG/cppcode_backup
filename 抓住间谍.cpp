#include <cstdio>
const int N = 205;
int t[N][N], a[N], n, m;
int main(){
    #ifdef ONLINE_JUDGE
        freopen("spy.in", "r", stdin);
        freopen("spy.out", "w", stdout);
    #else
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1, l; i <= m; i++){
        scanf("%d%d", a + i, &l);
        for (int j = 1, id; j <= l; j++) scanf("%d", &id), t[i][id] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int flag = 1;
            for (int k = 1; k <= m; k++){
                if(a[k]){
                    if(t[k][i] || t[k][j]) {flag = 0; break;}
                }else{
                    if(!t[k][i] && !t[k][j]) {flag = 0; break;}
                }
            }
            if(flag){
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
}