// cd .. ; g++ 3162.cpp -o /Users/xiexie/Desktop/cpp/output/3162 -Wall -Wextra -g3 ; cd output ; ./3162 < 3162.in > 3162.out ; code 3162.out
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using std::push_heap;
using std::pop_heap;
typedef long long ll;
const int N = 5e3 + 5;
const int M = 5e3 + 5;
int n, m, k;
struct edge{
    ll v, w;
};
struct node {
    ll dis, u;
};
bool cmp(node a, node b) {return a.dis > b.dis;}
node q[N * N]; int lq = 0;
ll ans[M][M]; 
int cnt[M];
std::vector<edge> st[N];
void dijkstra(int s) {
    q[++lq] = (node){0, s}; push_heap(q + 1, q + lq + 1, cmp);
    while(lq){
        ll u = q[1].u, ddist = q[1].dis; pop_heap(q + 1, q + (lq--) + 1, cmp);
        if (cnt[u] > k) continue;
        ans[u][++cnt[u]] = ddist;
        for (auto ed : st[u]) {
            ll v = ed.v, w = ed.w;
            q[++lq] = (node){(ddist + w), v};
            push_heap(q + 1, q + lq + 1, cmp);
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        st[u].push_back((edge){v, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if(j > cnt[i]){
                printf("inf ");
            }else{
                printf("%lld ", ans[i][j]);
            }
        }printf("\n");
    }
    return 0;
}

