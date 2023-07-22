#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
const int N = 2e5 + 5;
int n, dep[N], c, ord[N];
std::vector<int> st[N], order;
void dfs(int x, int fa, bool id){
    for (auto v : st[x]){
        if(v == fa) continue;
        dep[v] = dep[x] + 1;
        if(dep[v] > dep[c]) c = v;
        if(id) ord[v] = x;
        dfs(v, x, id);
    }
}
int main(){
    scanf("%d",&n);
    memset(ord, -1 ,sizeof(ord));
    for (int i = 1; i < n; i++){
        int a;
        scanf("%d",&a);
        st[a].push_back(i);
        st[i].push_back(a);
    }
    dfs(0, -1, 0), dep[c] = 0, dfs(c, -1, 1);
    printf("%d\n",dep[c]);
    order.push_back(c);
    while(ord[c] != -1){
        c = ord[c];
        order.push_back(c);
    }
    if(order.size() & 1) printf("%d\n", order[(order.size() >> 1)]);
    else printf("%d %d\n", order[(order.size() >> 1) - 1], order[((order.size()) >> 1)]);
    return 0;
}
