#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 1e5 + 5;
struct Node{
    int v, w;
};

std::vector<Node> st[N];
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i < n; i++){
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
    for (int i = 1, op, s, t, a, b; i <= m; i++){
        scanf("%d%d%d", &op, &s, &t);
        if(op == 1){
            scanf("%d%d", &a, &b);

        }else{

        }
    }
    return 0;
}