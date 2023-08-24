#include <cstdio>
#include <algorithm>
#include <vector>
const long long INF = 0x3f3f3f3f3f3f3f3f, N = 1e6 + 5;
long long n, az[15], cnt[N], P, M, qp[6][N];
void pre(){
    qp[1][0] = 1, qp[2][0] = 1;
    for (int i = 1; i <= N - 5; i++){
        qp[1][i] = qp[1][i - 1] * 2 % 100019;
        qp[2][i] = qp[2][i - 1] * 2 % 9223372036854775807;
        // printf("%lld %lld\n", qp[1][i], qp[2][i]);
    }
}
struct NN{
    long long id, h0, h1;
};
struct Node{
    NN a;
    long long nxt;
}L[N];
long long head[N], nL;
long long hash_(long long c){
    long long fh = INF, th = 0, T = 0;
    if(c == 0) P = 100019, M = 2, T = 1;
    else P = 9223372036854775807, M = 2, T = 2;
    for (long long i = 1; i <= 6; i++){
        th = 0;
        for (long long j = i; j <= i + 5; j++){
            th += az[j] * qp[T][j - i + 1] % P;
        }
        fh = std::min(fh, th);
    }
    for (long long i = 1; i <= 6; i++){
        th = 0;
        for (long long j = i + 5, c = i + 5; j >= i; j--){
            th += az[j] * qp[T][c - j + 1] % P;
        }
        fh = std::min(fh, th);
    }
    return fh;
}
NN& query(long long h0, long long h1, long long ii){
    // printf("h1 = %lld\n", h1);
    for (int i = head[h0]; i; i = L[i].nxt){
        if(L[i].a.h1 == h1){
            return L[i].a;
        }
    }
    L[++nL] = {{ii, h0, h1}, head[h0]};
    head[h0] = nL;
    return L[nL].a;
}
// std::vector<Node> has;
signed main(){
    scanf("%lld", &n);
    pre();
    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= 6; j++)
            scanf("%lld", az + j), az[j + 6] = az[j];
        // long long th1 = hash_(0), th2 = hash_(1);
        // prlong longf("%lld %lld\n", th1, th2);
        // if(hash[th1] && cnt[hash[th1]] == th2){
        //     printf("%lld\n", hash[th1]);
        //     continue;
        // }
        // hash[th1] = i;
        // cnt[i] = th2;
        long long th1 = hash_(0), th2 = hash_(1);
        NN &res = query(th1, th2, i);
        printf("%lld\n", res.id);
    }
    return 0;
}