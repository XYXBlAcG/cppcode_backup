#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <random>
#include <map>
#define pir std::pair<int, int>
#define sz(u) node[u].size
#define ls(u) node[u].son[0]
#define rs(u) node[u].son[1]
#define has(u) node[u].hash
#define heap(u) node[u].heap
#define val(u) node[u].val
#define fa(u) node[u].fa
#define key(u) node[u].key

typedef unsigned long long lo;
const int N = 2e5 + 20, M = 99991;
// const lo mod = 1000000000000000003;
std::vector<int> st[N];
int n, a, b, m;
std::vector<int> str;
int pnode, root, ll[N], rr[N], mem[N], ans, fath[N], dfn[N], pdfn;
lo p[N];
std::mt19937 frand(114514);
std::map<lo, int> num;
template <typename T>
T ran(T a = 0, T b = 0x7fffffff){
    return (frand() % (b - a + 1)) + a;
}
void ad(lo x){if(!num[x]) ans++; num[x]++;}
void de(lo x){if(!(--num[x])) ans--;}
struct Node{
    int son[2];
    int heap, size;
    lo hash, val;
    int fa, key;
    inline void make(int val, int key){
        heap = ran(1, 0x3f3f3f3f), this->val = hash = val, size = 1, son[0] = son[1] = fa = 0;
        this->key = key;
    }
}node[N];
int find(int x){
    // printf("find %d\n", x);
    return (fa(x) == x || !fa(x)) ? x : find(fa(x));
}
void init(){
    p[0] = 1;
    for (int i = 1; i <= N - 5; i++)
        p[i] = p[i - 1] * M;
}
namespace Tree{
    inline int newnode(int val, int u){
        node[++pnode].make(val, u);
        return pnode;
    }
    inline void pushup(int cur){
        fa(ls(cur)) = fa(rs(cur)) = cur;
        sz(cur) = sz(ls(cur)) + sz(rs(cur)) + 1;
        has(cur) = has(rs(cur)) + val(cur) * p[sz(rs(cur))] + has(ls(cur)) * p[sz(rs(cur)) + 1];
    }
    pir split(int cur, int size){
        if(!cur) return {0, 0};
        fa(ls(cur)) = fa(rs(cur)) = 0;
        // if(sz(ls(cur)) + 1 <= size){
        if(key(cur) <= size){
            pir tmp = split(rs(cur), size);
            rs(cur) = tmp.first, pushup(cur);
            return {cur, tmp.second};
        }else{
            pir tmp = split(ls(cur), size);
            ls(cur) = tmp.second, pushup(cur);
            return {tmp.first, cur};
        }
    }
    inline int merge(int u, int v){
        if(!u || !v) return fa(u | v) = 0, u | v;
        if(heap(u) > heap(v)){
            fa(rs(u)) = fa(ls(u)) = 0;
            rs(u) = merge(rs(u), v), pushup(u);
            return u;
        }else{
            fa(ls(v)) = fa(rs(v)) = 0;
            ls(v) = merge(u, ls(v)), pushup(v);
            return v; 
        }
    }
    inline void recover(int cur){
        int fd = find(ll[fath[cur]]), fafd = find(ll[cur]);
        // printf("rec = %d %d %d\n", cur, fd, fafd);
        de(has(fd)), de(has(fafd));
        pir tmp = split(fd, ll[cur] - 1);
        // printf("rec tmp = %d %d\n", tmp.first, tmp.second);
        fd = merge(merge(tmp.first, fafd), tmp.second);
        ad(has(fd));
    }
    inline void del(int cur){
        int fd = find(ll[fath[cur]]);
        de(has(fd));
        pir tmp = split(fd, rr[cur]), tmp2 = split(tmp.first, ll[cur] - 1);
        // printf("del tmp = %d %d %d\n", tmp2.first, tmp2.second, tmp.second);
        // printf("del tmp2 = %d %d\n", tmp2.first, tmp2.second);
        fd = merge(tmp2.first, tmp.second);
        // printf("has = %llu\n", has(fd));
        ad(has(fd)), ad(has(tmp2.second));
    }
    inline void dfs(int u){
        if(!u) return;
        dfs(ls(u));
        printf("u -> %d sz = %d, val = %llu, hash = %llu, fa = %d, heap = %d\n", u, sz(u), val(u), has(u), fa(u), heap(u));
        dfs(rs(u));
    }
    void output(){
        puts("---------");
        dfs(root); putchar('\n');
        puts("---------");
    }
}
using namespace Tree;
void predfs(int u, int fa){
    // if(u != 1) fath[u] = fa;
    fath[u] = fa;
    // str.push_back(1);
    // dfn[u] = ++pdfn;
    ll[u] = ++pdfn;
    root = merge(root, newnode(1, pdfn));
    // printf("x %d -> %d\n", u, pdfn);
    // ll[u] = str.size();
    for (auto v : st[u]){
        if(v ^ fa){
            predfs(v, u);
        }
    }
    // str.push_back(2);
    rr[u] = ++pdfn;
    root = merge(root, newnode(2, pdfn));
    // printf("x %d -> %d\n", u, pdfn);
    // rr[u] = str.size();
}
// void del(int x){
//     int rt1 = find(lid[fath[x]]), rt2, rt3;
//     dec(node[rt1].has);
//     split(rt1, rid[x], rt1, rt3);
//     split(rt1, lid[x] - 1, rt1, rt2);
//     rt1 = merge(rt1, rt3);
//     inc(node[rt1].has), inc(node[rt2].has);
// }
// void ins(int x){
//     int rt1 = find(lid[fath[x]]), rt2 = find(lid[x]);
//     dec(node[rt1].has), dec(node[rt2].has);
//     int rt3;
//     split(rt1, lid[x] - 1, rt1, rt3);
//     rt1 = merge(merge(rt1, rt2), rt3);
//     inc(node[rt1].has);
// }
struct FileIO{
    FileIO(){
        freopen("trip.in", "r", stdin);
        freopen("trip.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
signed main(){
    scanf("%d", &n);
    init();
    for (int i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        st[a].push_back(b);
        st[b].push_back(a);
    }
    predfs(1, 0);
    // output();
    // for (int i = 0; i < (int)str.size(); i++){
    //     int v = str[i];
    //     root = merge(root, newnode(v, i));
    // }
    ad(has(root));
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        int op = 0, x = 0;
        scanf("%d%d", &op, &x);
        if(op == 1){
            del(x);
            mem[i] = x;
        }else{
            recover(mem[x]);
        }
        printf("%d\n", ans);
        // output();
    }
    return 0;
}
/*
del = 1 6 10
has = 5014856865883363318
2
del = 1 10 14
has = 199983
3
2
del = 1 5 6
has = 3828582512199544039
3
del = 8 10 12
has = 1999480045098696
3
3
2
*/