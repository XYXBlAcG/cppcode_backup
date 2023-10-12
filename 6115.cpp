#include <cstdio>
#include <iostream>
#include <string>
#include <random>
#define int unsigned int
#define pir std::pair<int, int>
#define sz(u) node[u].size
#define ls(u) node[u].son[0]
#define rs(u) node[u].son[1]
#define has(u) node[u].hash
#define rank(u) node[u].rank
#define val(u) node[u].val
using std::cin;
using std::cout;
std::string str;
const int N = 150000 + 5, M = 99991;
int m, p[N], pnode, root;
std::mt19937 frand(time(0));
template <typename T>
T rando(T a = 0, T b = 0x7fffffff){
    return (frand() % (b - a + 1)) + a;
}
struct Node{
    int son[2];
    int val, rank, size, hash;
    inline void make(int val){rank = rando(0, 0x7fffffff), this->val = hash = val, size = 1, son[0] = son[1] = 0;}
}node[N];
struct Tree{
    inline int newnode(int val){
        node[++pnode].make(val);
        return pnode;
    }
    inline void pushup(int cur){
        sz(cur) = sz(ls(cur)) + sz(rs(cur)) + 1;
        has(cur) = has(rs(cur)) + val(cur) * p[sz(rs(cur))] + has(ls(cur)) * p[sz(rs(cur)) + 1];
    }
    pir split(int cur, int size){
        if(!cur) return {0, 0};
        if(sz(ls(cur)) + 1 <= size){
            pir tmp = split(rs(cur), size - sz(ls(cur)) - 1);
            rs(cur) = tmp.first, pushup(cur);
            return {cur, tmp.second};
        }else{
            pir tmp = split(ls(cur), size);
            ls(cur) = tmp.second, pushup(cur);
            return {tmp.first, cur};
        }
    }
    inline int merge(int u, int v){
        if(!u || !v) return u | v;
        if(rank(u) < rank(v)){
            rs(u) = merge(rs(u), v), pushup(u);
            return u;
        }else{
            ls(v) = merge(u, ls(v)), pushup(v);
            return v;
        }
    }
    inline void insert(int cur, int val){
        pir tmp = split(root, cur);
        root = merge(merge(tmp.first, newnode(val)), tmp.second);
    }
    inline void modify(int cur, int val){
        pir tmp = split(root, cur);
        pir l = split(tmp.first, cur - 1);
        val(l.second) = has(l.second) = val;
        root = merge(merge(l.first, l.second), tmp.second);
    }
    inline int query(int l, int r){
        pir tmp = split(root, r);
        pir tmp2 = split(tmp.first, l - 1);
        int ans = has(tmp2.second);
        root = merge(merge(tmp2.first, tmp2.second), tmp.second);
        return ans;
    }
    inline int qlr(int l, int r){
        if(l > r) std::swap(l, r);
        int L = 1, R = sz(root) - r + 1, ans = 0;
        while(L <= R){
            int mid = (L + R) >> 1;
            if(query(l, l + mid - 1) == query(r, r + mid - 1)) ans = mid, L = mid + 1;
            else R = mid - 1;
        }
        return ans;
    }
}tree;
void init(){
    p[0] = 1;
    for (int i = 1; i <= N - 5; i++)
        p[i] = p[i - 1] * M;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    init();
    cin >> str >> m;
    for (int i = 0; i < str.size(); i++)
        root = tree.merge(root, tree.newnode(str[i] - 'a' + 1));
    for (int i = 1; i <= m; i++){
        int x, y; char op, a;
        cin >> op;
        if(op == 'Q'){
            cin >> x >> y;
            cout << tree.qlr(x, y) << '\n';
        }else if(op == 'R'){
            cin >> x >> a;
            tree.modify(x, a - 'a' + 1);
        }else{
            cin >> x >> a;
            tree.insert(x, a - 'a' + 1);
        }
    }
    return 0;
}