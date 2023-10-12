#include <cstdio>
#include <algorithm>
#include <random>
using std::max;
const int P = 205;
int n, p, w, e[P][P], ans;
int main() {
    freopen("missile.in", "r", stdin);
    freopen("missile.out", "w", stdout);
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w), w %= p;
        int l = (w + 1) % p, r = (w - 1 + p) % p;
        e[w][w] = max({e[w][l], e[l][w], e[w][r], e[r][w], e[w][w]}) + 1;
        for (int i = 0; i < p; i++)
            if(i ^ w) e[w][i] = max({e[w][i], e[l][i], e[r][i]}) + 1, e[i][w] = max({e[i][w], e[i][l], e[i][r]}) + 1; 
    }
    for (int i = 0; i < p; i++) for (int j = 0; j < p; j++) ans = max(e[i][j], ans);
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}