#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mx(u) node[u].mx
#define tag(u) node[u].tag
#define mid ((l + r) >> 1)
const int N = 5e5 + 5;
int n, q;
struct Node {
    int mx;
    std::vector<int> tag;
} node[N * 4];
struct Tree {
    void pushdown(int u) {
        if (tag(u).size()) {
            for (auto v : tag(u)) {
                tag(ls(u)).emplace_back(v);
                tag(rs(u)).emplace_back(v);
                //				printf("[%d, %d] && [%d, %d], mx = {%d, %d}, v = %d\n", l, mid, mid
                //+ 1, r, mx(ls(u)), mx(rs(u)), v);
                if (mx(ls(u)) == v)
                    mx(ls(u))++;  // puts("!!!");
                if (mx(rs(u)) == v)
                    mx(rs(u))++;  // puts("!!!");
            }
            std::vector<int>().swap(tag(u));
            // tag(u).clear();
            // tag(u).shrink_to_fit();
        }
    }
    void pushup(int u) { mx(u) = std::max(mx(ls(u)), mx(rs(u))); }
    void modify(int u, int l, int r, int ql, int qr, int p) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            tag(u).emplace_back(p);
            if (mx(u) == p)
                mx(u)++;
            return;
        }
        pushdown(u);
        modify(ls(u), l, mid, ql, qr, p);
        modify(rs(u), mid + 1, r, ql, qr, p);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return mx(u);
        pushdown(u);
        return std::max(query(ls(u), l, mid, ql, qr), query(rs(u), mid + 1, r, ql, qr));
    }
    void print(int u, int l, int r) {
        printf("[%d, %d] -> mx %d\n", l, r, mx(u));
        if (l == r) {
            return;
        }
        pushdown(u);
        print(ls(u), l, mid), print(rs(u), mid + 1, r);
        pushup(u);
    }
} tree;
int main() {
    #ifdef ONLINE_JUDGE
    freopen("innocent.in", "r", stdin);
    freopen("innocent.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int op, l, r, x;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            scanf("%d", &x);
            tree.modify(1, 1, n, l, r, x);
        } else {
            printf("%d\n", tree.query(1, 1, n, l, r));
        }
        //		puts("------start------");
        //		tree.print(1, 1, n);
        //		puts("------end------");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}