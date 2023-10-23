#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define val(u) node[u].val
#define fac(u) node[u].fac
const int N = 2e5 + 5;
struct Node{
    int val, fac;
    Node operator+(Node a) const{
        return {a.val + val, a.fac + fac};
    }
}node[4 * N];
int n, m, b[N], loc[N], w, c[N];
struct Tree{
    // void pushup(int u){
    //     node[u].val += node[ls(u)].val + node[rs(u)].val, node[u].fac += node[ls(u)].fac + node[rs(u)].fac;
    // }
    // void pushdown(int u){
    //     node[ls(u)] = node[ls(u)] + node[u];
    //     node[rs(u)] = node[rs(u)] + node[u];
    //     // node[ls(u)] = node[rs(u)] = node[u];
    // }
    void modify(int u, int l, int r, int ql, int qr, Node val){
        if(qr < l || ql > r) return;
        if(ql <= l && r <= qr){
            return void(node[u] = node[u] + val);
        }
        // pushdown(u);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, val);
        modify(rs(u), mid + 1, r, ql, qr, val);
        // pushup(u);
    }
    Node query(int u, int l, int r, int q){
        if(q < l || q > r) return {0, 0};
        if(l == r) return node[u];
        // pushdown(u);
        int mid = (l + r) >> 1; 
        Node ans = query(ls(u), l, mid, q) + query(rs(u), mid + 1, r, q) + node[u];
        // Node ans = query(ls(u), l, mid, q) + query(rs(u), mid + 1, r, q);
        // pushup(u);
        // return pushup(u), ans;
        return ans;
    }
    void migrate(int i, int val){
        modify(1, 0, n - 1, 0, c[i] - i - 1, {(c[i] - i) * val, -val});
        modify(1, 0, n - 1, c[i] - i, n - i - 1, {(i - c[i]) * val, val});
        modify(1, 0, n - 1, n - i, n - i + c[i] - 1, {(c[i] - i + n) * val, -val});
        modify(1, 0, n - 1, n - i + c[i], n - 1, {(i - c[i] - n) * val, val});
    }
    void mdf(int u, int val){
        migrate(val, -1), c[val] = u, migrate(val, 1);
    }
}tree;
struct FileIO{
    FileIO(){
        freopen("distence.in", "r", stdin);
        freopen("distence.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 0, a; i < n; i++) scanf("%lld", &a), loc[a] = i;
    for (int i = 0; i < n; i++) scanf("%lld", b + i), b[i] = loc[b[i]], c[b[i]] = i, tree.migrate(b[i], 1);
    for (int i = 1, op, x, y, z; i <= m; i++){
        scanf("%lld", &op);
        if(op == 1){
            scanf("%lld", &z);
            (w += n - z) %= n;
        }else{
            scanf("%lld%lld", &x, &y), x--, y--;
            tree.mdf(x, b[y]), tree.mdf(y, b[x]), std::swap(b[x], b[y]);
        }
        Node ans = tree.query(1, 0, n - 1, w);
        printf("%lld\n", ans.val + ans.fac * w);
        // puts("b");
        // for (int i = 1; i <= 2 * n; i++) printf("%lld %lld\n", node[i].val, node[i].fac); putchar('\n');
        // for (int i = 0; i < n; i++) printf("%lld ", b[i]); putchar('\n');
    }
    return 0;
}