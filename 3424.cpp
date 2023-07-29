#include <cstdio>
#include <bitset>
const int N = 1005, M = 1e6 + 5;
int n, m, w[N], ans;
std::bitset<M> bits[3];
int main(){
    scanf("%d%d",&n,&m), bits[0][0] = 1;
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    for (int j = 1; j <= n; j++){
        bits[j & 1] |= bits[(j - 1) & 1];
        bits[j & 1] |= bits[(j - 1) & 1] << w[j];        
    }
    for (int i = 0; i <= m; i++)
        ans += bits[n & 1][i];
    printf("%d\n", ans);
    return 0;
}