#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 3e5 + 5, M = 55;
int L, K;
ll rec[N][M], pre[N];
struct Node {
    int l, r, a;
    ll b;
} pos[N];
std::queue<ll> que;
namespace pt80{
    #define ls(u) u << 1
    #define rs(u) u << 1 | 1
    #define nd(u) node[u]
    struct Node{
        ll f[M];
        ll& operator[](int x){return f[x];}
        Node(){memset(f, 0, sizeof(f));}
    }node[N], mdf;
    Node operator+(Node a, Node b){
        Node res;
        for (int i = 0; i <= K; i++) res[i] = std::max(a[i], b[i]);
        return res;
    }
    struct Tree{
        void pushup(int u){nd(u) = nd(ls(u)) + nd(rs(u));}
        void modify(int u, int l, int r, int pos, Node val){
            if(l > pos || r < pos) return;
            if(l == r){
                nd(u) = val;
                return;
            }
            int mid = (l + r) >> 1;
            modify(ls(u), l, mid, pos, val);
            modify(rs(u), mid + 1, r, pos, val);
            pushup(u);
        }
        ll query(int u, int l, int r, int ql, int qr, int v){
            if(l > qr || r < ql) return 0;
            if(ql <= l && r <= qr) return nd(u)[v];
            int mid = (l + r) >> 1;
            return std::max(query(ls(u), l, mid, ql, qr, v), query(rs(u), mid + 1, r, ql, qr, v));
        }
    }tree;
    void main(){
        for (int i = L; i; i--){
            for (int j = 0; j <= K; j++){
                if(i + pos[i].l > L){
                    rec[i][j] = pos[i].b * (pos[i].a <= j);
                }else{
                    rec[i][j] = tree.query(1, 1, L, i + pos[i].l, i + pos[i].r, j);
                    if(pos[i].a <= j) rec[i][j] = std::max(rec[i][j], tree.query(1, 1, L, i + pos[i].l, i + pos[i].r, j - pos[i].a) + pos[i].b);
                }
            }
            for (int j = 0; j <= K; j++) mdf[j] = rec[i][j];
            tree.modify(1, 1, L, i, mdf);
        }
        printf("%lld\n", tree.query(1, 1, L, 1, L, K));
    }
};
int main() {
    scanf("%d%d", &L, &K);
    for (int i = 1; i <= L; i++)
        scanf("%d%d%d%lld", &pos[i].l, &pos[i].r, &pos[i].a, &pos[i].b);
    pt80::main();
    fclose(stdin);
    fclose(stdout);
    return 0;
}