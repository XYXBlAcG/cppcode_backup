#include <cstdio>
#include <vector>
const int N = 2e5 + 5;
int n, m, k, q;
std::vector<int> st[N];
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
    }
    for (int i = 1; i <= m; i++){
        int s, t, p, r;
        scanf("%d%d%d%d", &s, &t, &p, &r);
        
    }
    for (int i = 1; i <= q; i++){
        int u, w;
        scanf("%d%d", &u, &w);
    }
    
    
    return 0;
}