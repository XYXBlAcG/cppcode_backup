#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define nd(u, v) node[u].ch[v]
using std::cin;
using std::cout;
using std::string;
const int N = 6e5 + 5;
int n, m, a[N], s[N], ed[N], cnt, rt[N];
struct Node{
    int ch[2];
}node[N];
template<typename T>
void read(T& x) {
    x = 0;
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= w;
}
struct Tree{
    void insert(int i, int k, int cur, int las){
        if(k < 0) return void(ed[cur] = i);
        int c = s[i] >> k & 1;
        if(las) nd(cur, !c) = nd(las, !c);
        nd(cur, c) = ++cnt;
        insert(i, k - 1, nd(cur, c), nd(las, c));
        ed[cur] = std::max(ed[nd(cur, 0)], ed[nd(cur, 1)]);
    }
    int query(int val, int k, int cur, int dwn){
        if(k < 0) return s[ed[cur]] ^ val;
        int c = val >> k & 1;
        if(ed[nd(cur, !c)] >= dwn) return query(val, k - 1, nd(cur, !c), dwn);
        return query(val, k - 1, nd(cur, c), dwn);
    }
}tree;
int main(){
    // std::ios::sync_with_stdio(0);
    // cin >> n >> m;
    // scanf("%d%d", &n, &m);
    read(n), read(m);
    tree.insert(0, 23, rt[0] = ++cnt, 0);
    ed[0] = -1;
    for (int i = 1; i <= n; i++)
        /*cin >> a[i]*/ /*scanf("%d", a + i)*/read(a[i]), s[i] = s[i - 1] ^ a[i], tree.insert(i, 23, rt[i] = ++cnt, rt[i - 1]);
    for (int i = 1, l = 0, r = 0, x = 0; i <= m; i++){
        char op;
        scanf("%c", &op);
        if(op == 'A'){
            // cin >> x;
            // scanf("%d", &x);
            read(x);
            ++n;
            s[n] = s[n - 1] ^ x;
            tree.insert(n, 23, rt[n] = ++cnt, rt[n - 1]);
        }else{
            // cin >> l >> r >> x;
            // scanf("%d%d%d", &l, &r, &x);
            read(l), read(r), read(x);
            // cout << tree.query(s[n] ^ x, 30, rt[r - 1], l - 1) << '\n';
            printf("%d\n", tree.query(s[n] ^ x, 23, rt[r - 1], l - 1));
        }
    }
    return 0;
}