#include <cstdio>
#include <vector>
const int N = 5e5 + 5;
int n, m, q, p;
struct Op{
    int u, v, fu, fv;
};
struct Node{
    int v, w;
};
std::vector<Node> st[N];
struct Set{
    int fa[N], pop; Op op[N];
    void reset(int up) {for (int i = 1; i <= up; i++) fa[i] = i; pop = 0;}
    int find(int x) {return fa[x] == x ? x : find(fa[x]);}
    bool same(int a, int b) {return find(a) == find(b);}
    void merge(int a, int b) {
        int A = find(a), B = find(b);
        op[++pop] = {A, B, fa[A], fa[B]}; fa[find(a)] = find(b);
    }
    void fm(int a, int b) {if(!same(a, b)) merge(a, b);}
    void undo(){
        fa[op[pop].u] = op[pop].fu, fa[op[pop].v] = op[pop].fv, pop--;
    }
}s;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++){
        scanf("%d", &p);
        std::vector<int> edges; edges.clear();
        for (int j = 1; j <= p; j++){
            int id;
            scanf("%d", &id);
            edges.push_back(id);
        }
    }
    return 0;
}