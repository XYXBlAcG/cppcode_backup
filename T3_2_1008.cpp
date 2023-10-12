#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <random>
#define INF 0x3f3f3f3f
const int N = 50, M = 30000;
typedef long long ll;
int n, k, pres[N], tar, edge[N][N][N], p, idd, tot, f[N][N], d[N], ccnt, mxa, pf, sb;
struct Node{
    int u, v;
}eg[N * N], res[N * N], fres[N * N];
std::vector<int> st[N][N];
bool dfs(int u, int fa, int len) {
    if (u == tar && fa != -1 && len < k)
        return 0;
    if (len >= k)
        return 1;
    for (auto v : st[idd][u]) {
        if (v != fa) {
            bool ttmp = dfs(v, u, len + 1);
            if (ttmp == 0)
                return 0;
        }
    }
    return 1;
}
bool chk(int u) {
    tar = u;
    for (int i = 1; i <= n; i++) if(st[idd][i].size() == 1) return 0;
    return dfs(u, -1, 0);
}
std::mt19937 ran(1141);
void solve2(){
    std::shuffle(eg + 1, eg + 1 + tot, ran);
    ccnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i != j) f[i][j] = INF; else f[i][j] = 0;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= tot; i++){
        int u = eg[i].u, v = eg[i].v;
        if(f[u][v] < k - 1) continue;
        res[++ccnt] = {u, v};
        f[u][v] = f[v][u] = 1;
        d[u]++, d[v]++;
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                f[j][k] = std::min(f[j][k], std::min(f[j][u] + f[v][k] + 1, f[j][v] + f[u][k] + 1));
            }
        }
    }
    if(ccnt > mxa) {
        mxa = pf = ccnt;
        memcpy(fres, res, sizeof(res));
    }
}
void solve() {
    for (p = 1; p <= n; p++){
        for (int q = 0; q <= 1; q++){
            idd = q * n + p;
            for (int i = 1; i < n; i++) {
                st[idd][i].push_back(i + 1);
                st[idd][i + 1].push_back(i);
            }
            if(q == 0){
                for (int i = n + p - 1 - 1 + n; i >= p; i--) {
                    int ti = i;
                    if(ti > n) ti -= n;
                    for (int j = i + 2; j <= p + n - 1; j++) {
                        int tj = j;
                        if(tj > n) tj -= n;
                        st[idd][ti].push_back(tj);
                        st[idd][tj].push_back(ti);
                        bool result = 1;
                        for (int o = p; o <= i; o++) {
                            int to = o;
                            if(to > n) to -= n;
                            result = chk(to);
                            if (!result)
                                break;
                        }
                        if (result) {
                            continue;
                        } else {
                            st[idd][ti].pop_back();
                            st[idd][tj].pop_back();
                        }
                    }
                }
            }else{
                for (int i = p; i < n + p - 1; i++) {
                    int ti = i;
                    if(ti > n) ti -= n;
                    for (int j = i + 2; j <= p + n - 1; j++) {
                        int tj = j;
                        if(tj > n) tj -= n;
                        st[idd][ti].push_back(tj);
                        st[idd][tj].push_back(ti);
                        bool result = 1;
                        for (int o = p; o <= i; o++) {
                            int to = o;
                            if(to > n) to -= n;
                            result = chk(to);
                            if (!result)
                                break;
                        }
                        if (result) {
                            continue;
                        } else {
                            st[idd][ti].pop_back();
                            st[idd][tj].pop_back();
                        }
                    }
                }
                
            }
            // for (int i = 1; i <= n; i++){
            //     printf("chk = %d\n", chk(i));
            // }
            for (int i = 1; i <= n; i++) {
                for (auto v : st[idd][i]) {
                    edge[idd][i][v] = edge[idd][v][i] = 1;
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (edge[idd][i][j])
                        pres[idd]++;
                }
            }
        }
    }
    
}
int main() {
    // freopen("build.in", "r", stdin);
    // freopen("build.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            eg[++tot] = {i, j};
        }
    }
    solve();
    for (sb = 1; sb <= M; sb++) solve2();
    // printf("1 = %d, 2 = %d\n", pres, pres2);
    int mx = 0, mxid = 1;
    for (int i = 1; i <= 2 * n; i++){
        if(pres[i] > mx){
            mx = pres[i];
            mxid = i;
        }
    }
    if(mxa > mx){
        printf("%d\n", mxa);
        for (int i = 1; i <= pf; i++){
            printf("%d %d\n", fres[i].u, fres[i].v);
        }
        return 0;
    }

    printf("%d\n", mx);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (edge[mxid][i][j])
                printf("%d %d\n", i, j);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

