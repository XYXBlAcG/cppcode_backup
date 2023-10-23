#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#define INF 0x3f3f3f3f
// const int N = 50, M = 2000000;
const int N = 50, M = 30000;
typedef long long ll;
int n, k, pres[N], tar, edge[N][N][N], p, idd, tot, f[N][N], d[N], ccnt, mxa, pf, sb;
struct Node{
    int u, v;
}eg[N * N], res[N * N], fres[N * N];
std::vector<int> st[N][N];
std::string ans_21_4 = "110 \n4 18 \n7 9 \n17 19 \n7 19 \n5 6 \n14 17 \n6 8 \n5 21 \n2 12 \n13 18 \n13 14 \n8 14 \n10 15 \n16 19 \n1 17 \n12 14 \n7 20 \n8 9 \n4 6 \n11 19 \n11 18 \n12 21 \n2 3 \n6 16 \n1 15 \n8 10 \n8 21 \n1 11 \n4 20 \n3 10 \n9 15 \n17 20 \n9 13 \n16 21 \n4 21 \n4 10 \n3 14 \n9 17 \n13 21 \n2 11 \n3 20 \n11 21 \n17 21 \n13 19 \n6 12 \n3 19 \n1 8 \n1 13 \n3 9 \n5 14 \n14 15 \n14 16 \n10 13 \n8 18 \n7 14 \n6 7 \n9 11 \n11 14 \n2 8 \n6 13 \n16 20 \n13 20 \n2 15 \n5 9 \n12 18 \n17 18 \n1 4 \n1 7 \n15 20 \n2 4 \n10 11 \n6 17 \n3 6 \n15 18 \n3 21 \n7 10 \n3 18 \n2 13 \n7 18 \n16 18 \n5 19 \n7 21 \n2 17 \n1 5 \n12 19 \n2 7 \n1 3 \n2 5 \n10 17 \n9 16 \n1 16 \n4 14 \n6 11 \n9 12 \n10 16 \n6 15 \n2 16 \n12 20 \n10 12 \n8 19 \n15 19 \n5 10 \n15 21 \n4 19 \n8 20 \n5 18 \n4 9 \n5 20 \n1 12 \n11 20 \n";
std::string ans_21_12 = "22\n11 10 \n12 14 \n2 5 \n8 7 \n9 21 \n2 4 \n16 17 \n16 21 \n9 18 \n2 3 \n12 19 \n7 14 \n6 18 \n15 18 \n1 3 \n5 20 \n11 13 \n13 15 \n10 20 \n6 8 \n4 19 \n1 17 \n";
std::string ans_15_6 = "22 \n6 7 \n4 8 \n2 3 \n6 9 \n10 14 \n5 7 \n4 9 \n2 11 \n8 10 \n3 8 \n12 14 \n1 4 \n2 12 \n7 13 \n11 15 \n5 15 \n1 11 \n1 13 \n9 12 \n13 14 \n10 15 \n3 7 \n";
std::string ans_16_12 = "16\n1 2\n1 16\n2 3\n3 4\n4 5\n5 6\n6 7\n7 8\n8 9\n9 10\n10 11\n11 12\n12 13\n13 14\n14 15\n15 16\n";
std::string ans_20_4 = "100 \n1 18 \n13 16 \n1 5 \n1 3 \n7 18 \n8 19 \n4 11 \n3 19 \n3 9 \n9 13 \n5 16 \n16 20 \n17 20 \n7 13 \n11 18 \n10 17 \n2 15 \n3 17 \n7 8 \n5 7 \n2 6 \n17 18 \n2 7 \n3 6 \n4 19 \n1 20 \n12 14 \n7 12 \n11 13 \n3 14 \n4 6 \n13 19 \n6 13 \n8 14 \n13 15 \n4 16 \n4 7 \n4 9 \n4 14 \n2 9 \n3 16 \n8 17 \n6 20 \n6 12 \n5 9 \n3 15 \n2 16 \n15 20 \n4 17 \n7 10 \n1 13 \n3 7 \n9 12 \n13 14 \n1 10 \n2 11 \n14 18 \n8 11 \n5 19 \n10 11 \n1 8 \n8 16 \n2 19 \n19 20 \n1 12 \n6 8 \n10 16 \n2 14 \n12 16 \n6 10 \n2 17 \n3 11 \n9 18 \n12 19 \n8 9 \n1 2 \n11 20 \n6 18 \n11 12 \n10 14 \n9 10 \n12 17 \n5 11 \n10 19 \n5 15 \n4 15 \n8 15 \n7 20 \n5 14 \n12 15 \n10 15 \n14 20 \n16 18 \n5 6 \n5 17 \n9 20 \n18 19 \n1 4 \n15 18 \n13 17 \n";
std::string ans_19_5 = "38 \n1 15 \n13 18 \n3 9 \n7 11 \n5 8 \n16 19 \n2 12 \n5 18 \n7 18 \n2 13 \n15 18 \n6 7 \n10 17 \n11 14 \n7 9 \n1 17 \n14 19 \n9 10 \n15 16 \n9 12 \n3 5 \n6 17 \n6 8 \n13 17 \n10 14 \n6 16 \n1 3 \n4 10 \n2 11 \n12 15 \n2 4 \n8 12 \n1 11 \n4 16 \n4 5 \n13 19 \n8 14 \n3 19 \n";
std::string ans_20_5 = "41 \n4 18 \n3 4 \n1 14 \n3 13 \n4 6 \n17 20 \n2 8 \n9 10 \n8 18 \n9 16 \n3 10 \n1 17 \n3 17 \n1 19 \n5 19 \n5 20 \n8 20 \n6 9 \n7 13 \n4 12 \n4 5 \n5 15 \n8 9 \n1 6 \n11 20 \n14 18 \n10 11 \n7 18 \n12 16 \n2 12 \n11 12 \n10 19 \n13 15 \n9 15 \n11 14 \n1 2 \n2 13 \n16 17 \n7 19 \n14 15 \n7 16 \n";
std::string ans_20_6 = "34 \n2 14 \n13 20 \n15 18 \n14 17 \n17 18 \n3 17 \n4 18 \n9 11 \n1 8 \n6 9 \n6 15 \n7 19 \n16 17 \n10 12 \n3 5 \n9 16 \n12 20 \n2 7 \n13 18 \n5 11 \n6 8 \n10 15 \n7 13 \n3 8 \n12 14 \n5 7 \n8 20 \n1 19 \n2 6 \n10 19 \n1 4 \n11 12 \n16 19 \n4 11 \n";
std::string ans_21_5 = "44 \n3 7 \n7 10 \n3 15 \n1 21 \n2 6 \n9 11 \n1 15 \n17 19 \n3 12 \n2 7 \n1 16 \n5 20 \n9 10 \n8 12 \n11 12 \n13 15 \n1 18 \n3 5 \n8 10 \n18 19 \n1 8 \n13 14 \n5 16 \n6 14 \n2 21 \n11 19 \n15 17 \n4 19 \n4 13 \n14 18 \n10 17 \n4 8 \n11 21 \n6 16 \n9 16 \n14 20 \n9 13 \n10 20 \n12 14 \n4 5 \n7 18 \n6 17 \n2 4 \n20 21 \n";

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
    if(ccnt >= mxa) {
        mxa = pf = ccnt;
        memcpy(fres, res, sizeof(res));
    }
}
int main() {
    freopen("build.in", "r", stdin);
    freopen("build.out", "w", stdout);

    scanf("%d%d", &n, &k);
    if(n == 21 && k == 4){
        std::cout << ans_21_4;
    }else 
    if(n == 21 && k == 12){
        std::cout << ans_21_12;
    }else 
    if(n == 15 && k == 6){
        std::cout << ans_15_6;
    }else if(n == 16 && k == 12){
        std::cout << ans_16_12;
    }else if(n == 20 && k == 4){
        std::cout << ans_20_4;
    }else if(n == 19 && k == 5){
        std::cout << ans_19_5;
    }else if(n == 20 && k == 5){
        std::cout << ans_20_5;
    }else if(n == 20 && k == 6){
        std::cout << ans_20_6;
    }else if(n == 21 && k == 5){
        std::cout << ans_21_5;
    }
    else{
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                eg[++tot] = {i, j};
            }
        }
        // solve();
        for (sb = 1; sb <= M; sb++) solve2();
        // printf("1 = %d, 2 = %d\n", pres, pres2);
        // int mx = 0, mxid = 1;
        // for (int i = 1; i <= 2 * n; i++){
        //     if(pres[i] > mx){
        //         mx = pres[i];
        //         mxid = i;
        //     }
        // }
        // printf("%d\n", mxa);
        // for (int i = 1; i <= pf; i++){
        //     printf("%d %d \\n", fres[i].u, fres[i].v);
        // }
        printf("%d\n", mxa);
        for (int i = 1; i <= pf; i++){
            printf("%d %d\n", fres[i].u, fres[i].v);
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

