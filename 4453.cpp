#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define sum(u) node[u].sum
#define mdf(u) node[u].mdf
typedef long long ll;
const int N = 5e5 + 15, mod = 998244353, M = 4, G = 5;
int n, m;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') 
        x = x * 10 + (ch - '0'), ch = getchar();
    return x * w;
}
struct Mat{
    int data[G][G];
    Mat(){memset(data, 0, sizeof(data));}
    inline int* operator[](int x){return data[x];}
    void print(){
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++)
                printf("%d ", data[i][j]);
            putchar('\n');
        }
    }
    inline void init(int data[G][G]){
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                this->data[i][j] = data[i][j];
    }
}a[N];
inline Mat operator+(Mat a, Mat b){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            a[i][j] = ((ll)a[i][j] + b[i][j]) % mod;
        }
    }
    return a;
}
inline Mat operator*(Mat a, Mat b){
    Mat res;
    for (int k = 0; k < M; k++){
        for (int i = 0; i < M; i++){
            ll tmp = a[i][k];
            for (int j = 0; j < M; j++)
                res[i][j] = ((ll)res[i][j] + tmp * b[k][j]) % mod;
        }
    }
    return res;
}
Mat base, A, B, C, D, E, F, ept;
void init(){
    int base_[G][G] = {{1, 0, 0, 0},
                       {0, 1, 0, 0}, 
                       {0, 0, 1, 0}, 
                       {0, 0, 0, 1}};
    base.init(base_);
    int a_[G][G] = {{1, 0, 0, 0},
                    {1, 1, 0, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 1}};
    A.init(a_);
    int b_[G][G] = {{1, 0, 0, 0},
                    {0, 1, 0, 0}, 
                    {0, 1, 1, 0}, 
                    {0, 0, 0, 1}};
    B.init(b_);
    int c_[G][G] = {{1, 0, 1, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};
    C.init(c_);
    int d_[G][G] = {{1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};
    D.init(d_);
    int e_[G][G] = {{1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};
    E.init(e_);
    int f_[G][G] = {{1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 1}};
    F.init(f_);
}
struct Node{
    Mat sum, mdf;
}node[N * 4];
struct Tree{
    inline void upd(int u){
        sum(ls(u)) = sum(ls(u)) * mdf(u);
        sum(rs(u)) = sum(rs(u)) * mdf(u);
        mdf(ls(u)) = mdf(ls(u)) * mdf(u);
        mdf(rs(u)) = mdf(rs(u)) * mdf(u);
        mdf(u) = base;
    }
    inline void pushdown(int u){
        upd(ls(u)), upd(rs(u));
    }
    inline void pushup(int u){
        sum(u) = sum(ls(u)) + sum(rs(u));
    }
    inline void build(int u, int l, int r){
        if(l == r){
            sum(u) = a[l];
            return;
        }
        mdf(u) = base;
        int mid = (l + r) >> 1;
        build(ls(u), l, mid);
        build(rs(u), mid + 1, r);
        pushup(u);
    }
    inline void modify(int u, int l, int r, int ql, int qr, Mat val){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr) {
            mdf(u) = mdf(u) * val;
            sum(u) = sum(u) * val;
            upd(u);
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(u);
        modify(ls(u), l, mid, ql, qr, val);
        modify(rs(u), mid + 1, r, ql, qr, val);
        pushup(u);
    }
    inline Mat query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return ept;
        if(ql <= l && r <= qr) return sum(u);
        int mid = (l + r) >> 1;
        pushdown(u);
        Mat ans = query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
        pushup(u);
        return ans;
    }
}tree;
signed main(){
    n = read();
    init();
    for (int i = 1; i <= n; i++)
        a[i][0][0] = read(), a[i][0][1] = read(), a[i][0][2] = read(), a[i][0][3] = 1;
    m = read();
    tree.build(1, 1, n);
    for (int i = 1, op = 0, l = 0, r = 0, v = 0; i <= m; i++){
        op = read(), l = read(), r = read();
        if(op <= 3){
            if(op == 1) tree.modify(1, 1, n, l, r, A);
            else if(op == 2) tree.modify(1, 1, n, l, r, B);
            else tree.modify(1, 1, n, l, r, C);
        }else if(op <= 6){
            v = read();
            if(op == 4) D[3][0] = v, tree.modify(1, 1, n, l, r, D);
            else if(op == 5) E[1][1] = v,tree.modify(1, 1, n, l, r, E);
            else F[3][2] = v, tree.modify(1, 1, n, l, r, F);
        }else{
            Mat res = tree.query(1, 1, n, l, r);
            printf("%d %d %d\n", res[0][0], res[0][1], res[0][2]);
        }
    }
    return 0;
}