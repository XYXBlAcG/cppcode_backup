#include <cstdio>
#include <vector>
const int N = 5e5 + 5;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
typedef double d;
int a, b;
d n, q[N], p, az[N];
void dfs(int x, int fa){
    for (auto v : st[x]){
        if(v.v != fa){
            dfs(v.v, x);
            d pv = v.w * q[x];
            az[x] = q[x] + pv - q[x] * pv;
        }
    }
}
void dfs2(int x, int fa){
    for (auto v : st[x]){
        if(v.v != fa){
            
            dfs2(v.v, x);
        }
    }
}
int main(){
    scanf("%lf", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%lf", &a, &b, &p);
        st[a].push_back((Node){b, p * 0.01});
        st[b].push_back((Node){a, p * 0.01});
    }
    for (int i = 1; i <= n; i++) scanf("%lf", q + i);
    dfs(1, 0);
    
    return 0;
}