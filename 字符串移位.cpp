#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#define int long long
#define pir std::pair<int, int>
#define ls(u) node[u].ch[0]
#define rs(u) node[u].ch[1]
#define val(u) node[u].val
#define rank(u) node[u].rank
#define size(u) node[u].size
#define add(u) node[u].add
const int N = 1e5 + 5, M = 1e5 + 5;
int n, pnode, root;
struct Node{
    int ch[2], val, rank, size, add;
}node[N];
std::mt19937_64 frand(114);
int ran(int a = 1, int b = 0x3f3f3f3f3f3f3f3f){
    return frand() % (b - a + 1) + a;
}
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x * f;
}
template <typename T, size_t _Size>
struct Stack{
    T data[_Size]; int pdata = 0;
    void push(T b){data[++pdata] = b;}
    void pop(){if(pdata) pdata--;}
    T operator[](int x){return data[x];}
    T top(){return data[pdata];}
    int sz(){return pdata;}
    bool empty(){return pdata;}
    int* begin(){return &data[1];}
    int* end(){return &data[pdata + 1];}
};
Stack<int, M> sta;
struct Tree{
    void upd(int u){size(u) = size(ls(u)) + size(rs(u)) + 1;}
    int clone(int u){
        if(!u) return 0;
        if(sta.sz()) {
            int top = sta.top();
            sta.pop();
            node[top] = node[u];
            return top;
        }else {
            node[++pnode] = node[u];
            return pnode;
        }
        // printf("clone %lld -> %lld\n", u, pnode);
        // return pnode;
    }
    void pushdown(int u){
        if(!add(u)) return;
        ls(u) = clone(ls(u));
        rs(u) = clone(rs(u));
        // printf("val %lld from %lld add %lld\n", ls(u), val(ls(u)), add(u));
        // printf("val %lld from %lld add %lld\n", rs(u), val(rs(u)), add(u));
        (val(ls(u)) += add(u)) %= 26;
        (val(rs(u)) += add(u)) %= 26;
        (add(ls(u)) += add(u)) %= 26;
        (add(rs(u)) += add(u)) %= 26;
        add(u) = 0;
    }
    int newnode(int val){
        node[++pnode] = {{0, 0}, val, ran(), 1, 0};
        return pnode;
    }
    // pir split(int cur, int k){
    //     if(!cur) return {0, 0};
    //     pushdown(cur);
    //     if(size(ls(cur)) < k){
    //         pir tmp = split(rs(cur), k - size(ls(cur)) - 1);
    //         cur = clone(cur);
    //         rs(cur) = xx;
    //         upd(cur);
    //         return {cur, yy};
    //     }else{
    //         pir tmp = split(ls(cur), k);
    //         cur = clone(cur);
    //         ls(cur) = yy;
    //         upd(cur);
    //         return {xx, cur};
    //     }
    // }
    void split(int cur, int k, int& f, int& s){
        if(!cur) return void(f = s = 0);
        pushdown(cur);
        if(size(ls(cur)) < k){
            f = clone(cur);
            split(rs(cur), k - size(ls(cur)) - 1, rs(f), s);
            upd(f);
        }else{
            s = clone(cur);
            split(ls(cur), k, f, ls(s));
            upd(s);
        }
    }
    int merge(int a, int b){
        if(!a || !b) return a | b;
        int tmp = 0;
        if(rank(a) > rank(b)) pushdown(a), rs(tmp = clone(a)) = merge(rs(a), b);
        else pushdown(b), ls(tmp = clone(b)) = merge(a, ls(b));
        return upd(tmp), tmp;
    }
    void copy(int l, int r, int p){
        pir tmp3 = {0, 0};
        int xx = 0, yy = 0, zz = 0, aa = 0;
        split(root, r, xx, yy);
        split(xx, l - 1, zz, aa);
        split(root, p, tmp3.first, tmp3.second);
        root = merge(merge(tmp3.first, aa), tmp3.second);
    }
    void modify(int l, int r){
        int xx = 0, yy = 0, zz = 0, aa = 0;
        split(root, r, xx, yy);
        split(xx, l - 1, zz, aa);
        (val(aa) += 1) %= 26, (add(aa) += 1) %= 26;
        root = merge(zz, merge(aa, yy));
    }
    void recycle(int cur){
        if(!cur) return;
        node[cur] = {{0, 0}, 0, 0, 0, 0};
        sta.push(cur);
        recycle(ls(cur));
        recycle(rs(cur));
    }
    void del(int l, int r){
        int xx = 0, yy = 0, zz = 0, aa = 0;
        split(root, r, xx, yy);
        split(xx, l - 1, zz, aa);
        recycle(aa);
        root = merge(zz, yy);
    }
    void output(int u){
        if(!u) return;
        pushdown(u);
        output(ls(u));
        putchar(val(u) + 'a');
        output(rs(u));
    }
}tree;
std::string str;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::cin >> str;
    for (auto v : str) root = tree.merge(root, tree.newnode(v - 'a'));
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        int op = 0, s = 0, e = 0, p = 0; 
        // scanf("%lld", &op);
        op = read();
        if(op == 1){
            // scanf("%lld%lld%lld", &p, &s, &e);
            p = read(), s = read(), e = read();
            tree.copy(s, e, p);
        }else if(op == 2){
            // scanf("%lld%lld", &s, &e);
            s = read(), e = read();
            tree.del(s, e);
        }else if(op == 3){
            // scanf("%lld%lld", &s, &e);
            s = read(), e = read();
            tree.modify(s, e);
        }
        // printf("i = %lld\n", i);
        // tree.output(root);
        // putchar('\n');
    }
    tree.output(root);
    putchar('\n');
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
i = 1
meetkazusaandsingwhitealbumkazusa
i = 2
nffulbavtbandsingwhitealbumkazusa
i = 3
singwhitealbumkazusa
i = 4
singwhitealbumwhitekazusa
i = 5
singwhitealbumwithitekazusa
i = 6
singwhitealbumwithkazusa
singwhitealbumwithkazusa
*/

/*
i = 1
skdfjkdfhjkfhsjkhdf
i = 2
sdfjkdfjkdfhjkfhsjkhdf
i = 3
sfjkdfjkdfjkdfhjkfhsjkhdf
i = 4
sfjdfjkdfjkdfjkdfhjkfhsjkhdf
i = 5
dfjkdfjkdfjkdfhjkfhsjkhdf
i = 6
egklegklegjkdfhjkfhsjkhdf
i = 7
fhlmfhlmfhjkdfhjkfhsjkhdf
i = 8
gimngimngijkdfhjkfhsjkhdf
i = 9
ngimngijkdfhjkfhsjkhdf
i = 10
nimngimngijkdfhjkfhsjkhdf
nimngimngijkdfhjkfhsjkhdf
*/