#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N = 65;
struct Node{
    int v, w;
};
int n, m, pra[N][N], sum[N][N], res[N][N][N], ans;
std::vector<Node> st[N * N * N]; 
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            int read; scanf("%d", &read);
            pra[i][j] = read;
        }
    }
    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= n; j++){
            sum[i][j] = sum[i + 1][j] + pra[i][j];
        }
    }
    printf("   ");
    for (int i = 1; i <= n; i++){
        printf("%d  ", i);
    }printf("\n");
    for (int i = 1; i <= n; i++){
        printf("%d  ", i);
        for (int j = 1; j <= i; j++){
            printf("%d  ", sum[i][j]);
        }printf("\n");
    }
    for (int x = 1; x <= n; x++){
        for (int y = x; y >= 1; y--){
            for (int i = 1; i <= m; i++){    
                res[x][y][i] = std::max( \
                (i - (n + 2 - x) && x > 1 && y > 1) ? res[x - 1][y - 1][i - (n + 2 + x)] - sum[n][y - 1] + sum[x - 2][y - 1] : 0, \
                res[x + 1][y][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%d: %d\n", i, res[n][i][m]);
    }
    for (int i = 1; i <= n; i++){
        ans = std::max(ans, res[n][i][m]);
    }
    printf("%d\n", ans);
    return 0;
}