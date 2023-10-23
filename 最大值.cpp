#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using std::max;
const int N = 1e3 + 5, M = 2e4 + 5, top = 2e4;
int n, m, f[N][M], b[N], c[N], ans;
void mx(int& x, int y){x = max(x, y);}
struct FileIO{
    FileIO(){
        #ifdef ONLINE_JUDGE
            freopen("max.in", "r", stdin);
            freopen("max.out", "w", stdout);
        #else
        #endif
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
};
FileIO fio;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i < n; i++) scanf("%lld", b + i);
    for (int i = 2; i <= n; i++) scanf("%lld", c + i);
    for (int i = 0; i < m; i++) f[1][i] = i;
    for (int i = 1, tmp = 0; i < n; i++){
        for (int j = 0; j <= top; j++){
            if(j < b[i]){
                mx(tmp, f[i][j]);
                if(c[i + 1] + j <= top) mx(f[i + 1][c[i + 1] + j], f[i][j] + c[i + 1]);
            }
            if(j >= b[i] && j < b[i] + c[i + 1]){
                mx(f[i + 1][j - b[i]], f[i][j]);
            }
            if(j >= b[i] + c[i + 1]){
                mx(f[i + 1][j], f[i][j]);
            }
        }
        for (int k = 0; k < c[i + 1]; k++) mx(f[i + 1][k], tmp + k);
    }
    for (int i = 0; i <= top; i++) {
        mx(ans, f[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}