#include <cstdio>
#include <cstring>
#include <vector>
#define int long long
#define yes puts("Connected")
#define no puts("Disconnected")
const int N = 5e5 + 5;
struct Node{
    int v, w;
};
int n, m, q, k, u, v, c[N], ans[N];
std::vector<Node> st[N];
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld", &u, &v);
        st[u].push_back((Node){v, 1});
        st[v].push_back((Node){u, 1});
    }
    for (int i = 1; i <= q; i++){
        memset(c, 0, sizeof(c));
        scanf("%lld", &k);
        for (int j = 1; j <= k; j++)
            scanf("%lld", c + j), c[j] ^= ans[i - 1];
        
    }
    return 0;
}