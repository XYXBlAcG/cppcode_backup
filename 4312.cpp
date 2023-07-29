#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
const int N = 1e5 + 5, M = 105;
int n, m, p, q, a[N], op, ii ,jj, kk, mat[M][M], mat2[M][M], last[M][M], res[M][M], ans[M];
void mul(){
    // memset(res, 0, sizeof(ans));
    memset(res, 0, sizeof(res));
    for (int k = 0; k <= n; k++){
        for (int i = 0; i <= n; i++){
            int tmp = mat[i][k];
            for (int j = 0; j <= n; j++){
                (res[i][j] += mat[k][j] * tmp) %= q;
            }
        }
    }
    memcpy(mat, res, sizeof(mat));
    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= n; j++){
    //         (ans[j] += a[i] * mat[i][j]) %= q;
    //     }
    // }
    // memcpy(a, ans, sizeof(a));
}
void mul3(){
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            (ans[j] += a[i] * mat[i][j]) %= q;
        }
    }
    memcpy(a, ans, sizeof(a));
}
void mul4(){
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            (ans[j] += a[i] * last[i][j]) %= q;
        }
    }
    memcpy(a, ans, sizeof(a));
}
void mul2(){
    memset(res, 0, sizeof(res));
    for (int k = 0; k <= n; k++){
        for (int i = 0; i <= n; i++){
            int tmp = mat2[i][k];
            for (int j = 0; j <= n; j++){
                (res[i][j] += mat[k][j] * tmp) %= q;
            }
        }
    }
    memcpy(mat, res, sizeof(res));
}
void qpow(int mmm){
    while(mmm){
        if(mmm & 1) mul3(); /*memcpy(mat2, res, sizeof(res));*/
        mul(); 
        mmm >>= 1;
    }
    // for (int k = 1; k <= n; k++){
    //     for (int i = 1; i <= n; i++){
    //         int tmp = last[i][k];
    //         for (int j = 1; j <= n; j++){
    //             (res[i][j] += mat[k][j] * tmp) %= q;
    //         }
    //     }
    // }
    mul4();
    // memcpy(mat, ans, sizeof(ans));
    // for (int k = 1; k <= n; k++){
    //     for (int i = 1; i <= n; i++){
    //         ans[i] += mat[k][i] * a[i];
    //     }
    // }
    for (int i = 1; i <= n; i++){
        printf("%lld ", a[i]);
    }printf("\n");
}

signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
    a[0] = 1;
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 0; i <= n; i++) mat[i][i] = 1;
    if(p % m == 0)
        for (int i = 1; i <= n; i++){
            last[i][i] = 1;
        }
    for (int i = 1; i <= m; i++){
        scanf("%lld", &op);
        if(op == 1){
            scanf("%lld%lld", &ii, &jj);
            for (int j = 0; j <= n; j++)
                std::swap(mat[j][ii], mat[j][jj]);
        }else if(op == 2){
            scanf("%lld%lld%lld", &ii, &jj, &kk);
            for (int j = 0; j <= n; j++)
                mat[j][ii] = (mat[j][ii] + kk * mat[j][jj]) % q;
        }else if(op == 3){
            scanf("%lld%lld", &ii, &jj);
            // for (int j = 1; j <= n; j++)
                // mat[j][ii] = (mat[j][ii] + jj) % q;
            (mat[0][ii] += jj) %= q;
        }
        if(p % m == i) memcpy(last, mat, sizeof(mat));
    }
    qpow(p / m);
    return 0;
}