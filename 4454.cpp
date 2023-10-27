#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define s(u) node[u].s
#define ll(u) node[u].ll
#define rr(u) node[u].rr
#define int long long
#define printf(...) std::cout << __VA_ARGS__ << '\n'
using std::cin;
using std::cout;
using std::string;
const int N = 3e5 + 12, mod = 1e9 + 7, G = 4, M = 3;
int n, q, a, b, A[N];
struct Mat{
    int data[G][G];
    int* operator[](int x){return data[x];}
    Mat(){memset(data, 0, sizeof(data));}
    void init(int data[G][G]){
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                this->data[i][j] = data[i][j];
    }
    Mat T(){
        Mat tmp;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                tmp[i][j] = data[j][i];
        return tmp;
    }
};
Mat base, ept, m1, a1, ff;
Mat operator+(Mat a, Mat b){
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            (a[i][j] += b[i][j]) %= mod;
    return a;
}
Mat operator*(Mat a, Mat b){
    Mat res; 
    for (int k = 0; k < M; k++)
        for (int i = 0; i < M; i++){
            int t = a[i][k];
            for (int j = 0; j < M; j++)
                (res[i][j] += t * b[k][j]) %= mod;
        }
    return res;
}
Mat operator^(Mat a, int x){
    Mat res = base;
    while(x){
        if(x & 1) res = res * a;
        a = a * a;
        x >>= 1;
    }
    return res;
}
int qp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int inv(int a){return qp(a, mod - 2);}
void init(){
    int base_[G][G] = {{1, 0, 0}, 
                       {0, 1, 0},
                       {0, 0, 1}};
    base.init(base_);
    int a1_[G][G] = {{1, a, b},
                     {1, 0, 0},
                     {0, 0, 1}};
    a1.init(a1_);
    int f_[G][G] = {{2, 0, 0},
                    {1, 0, 0},
                    {1, 0, 0}};
    ff.init(f_);
    if(a == 0){
        int m1_[G][G] = {{0, 1, 0},
                         {0, 1, mod - b},
                         {0, 0, 1}};
        m1.init(m1_);
    }else{
        int inva = inv(a);
        int m1_[G][G] = {{0, 1, 0},
                         {inva, mod - inva, mod - b * inva % mod},
                         {0, 0, 1}};
        m1.init(m1_);
    }
}
struct Node{
    Mat s, ll, rr;
}node[N << 2];
struct Tree{
    void upd(int u, Mat a, Mat b){
        ll(u) = a * ll(u), rr(u) = rr(u) * b;
        s(u) = a * s(u) * b;
    }
    void pushdown(int u){
        upd(ls(u), ll(u), rr(u)), upd(rs(u), ll(u), rr(u)), ll(u) = rr(u) = base;
    }
    void pushup(int u){
        s(u) = s(ls(u)) + s(rs(u));
    }
    void build(int u, int l, int r){
        ll(u) = rr(u) = base;
        if(l == r){
            s(u) = (a1 ^ (A[l - 1] - 1)) * ff * ff.T() * (a1.T() ^ (A[l + 1] - 3));
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, Mat a, Mat b){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr) return (void)upd(u, a, b);
        int mid = (l + r) >> 1;
        pushdown(u);
        modify(ls(u), l, mid, ql, qr, a, b);
        modify(rs(u), mid + 1, r, ql, qr, a, b);
        pushup(u);
    }
    Mat query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return ept;
        if(ql <= l && r <= qr) return s(u);
        int mid = (l + r) >> 1;
        pushdown(u);
        return query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
    }
}tree;
signed main(){
    std::ios::sync_with_stdio(0);
    cin >> n >> q >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    init();
    tree.build(1, 2, n - 1);
    for (int i = 1, l, r; i <= q; i++){
        string op; 
        cin >> op >> l >> r;
        if(op[0] == 'p'){
            tree.modify(1, 2, n - 1, l + 1, r + 1, a1, base);
            tree.modify(1, 2, n - 1, l - 1, r - 1, base, a1.T());
        }else if(op[0] == 'm'){
            tree.modify(1, 2, n - 1, l + 1, r + 1, m1, base);
            tree.modify(1, 2, n - 1, l - 1, r - 1, base, m1.T());
        }else{
            cout << tree.query(1, 2, n - 1, l + 1, r - 1)[0][0] << '\n';
        }
    }
    return 0;
}